/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#pragma warning (disable: 4100)
//==============================================================================
FamilySircleAudioProcessor::FamilySircleAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	randomVolumes = new float [16] { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
}

FamilySircleAudioProcessor::~FamilySircleAudioProcessor()
{
}

//==============================================================================
const String FamilySircleAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FamilySircleAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FamilySircleAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FamilySircleAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FamilySircleAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FamilySircleAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FamilySircleAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FamilySircleAudioProcessor::setCurrentProgram (int index)
{
}

const String FamilySircleAudioProcessor::getProgramName (int index)
{
    return {};
}

void FamilySircleAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FamilySircleAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	DBG("Prepare to play");
	r.setSeedRandomly();
}

void FamilySircleAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FamilySircleAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FamilySircleAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	static int count = 0;
	static int beatCount = 0;

    ScopedNoDenormals noDenormals;

    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

	auto numSamples = buffer.getNumSamples();

	updateCurrentTimeInfoFromHost(lastPosInfo);

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	count = count + 1;
	
	if (count == 50)
	{
		count = 0;
	}
	
	if (randomVolumeState == true)
	{
		volume = randomVolumes[tempoCalc.getBeatNumber()];
	}
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
		buffer.applyGainRamp(channel, 0, numSamples, previousVolume, volume);

        // ..do something to the data...
    }
	previousVolume = volume;
	beatCount = tempoCalc.getBeatNumber();
}

bool FamilySircleAudioProcessor::updateCurrentTimeInfoFromHost(AudioPlayHead::CurrentPositionInfo& posInfo)
{
	if (auto * ph = getPlayHead())
	{
		AudioPlayHead::CurrentPositionInfo newTime;
		if (ph->getCurrentPosition(newTime))
		{
			posInfo = newTime;
			tempoCalc.init(posInfo.bpm, getSampleRate(), tempoCalc.getBarDivider());
			tempoCalc.calculateBeatNumber(posInfo.timeInSamples);
			return true;
		}
	}
	lastPosInfo.resetToDefault();
	return false;
}

int64 FamilySircleAudioProcessor::getBeatNumber()
{
	return tempoCalc.getBeatNumber();
}

//==============================================================================
bool FamilySircleAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FamilySircleAudioProcessor::createEditor()
{
    return new FamilySircleAudioProcessorEditor (*this);
}

//==============================================================================
void FamilySircleAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FamilySircleAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void FamilySircleAudioProcessor::increaseVolume(float inc)
{
	volume += inc;
	if (volume > maxVolume)
		volume = maxVolume;
}

void FamilySircleAudioProcessor::decreaseVolume(float dec)
{
	volume -= dec;
	if (volume < 0)
		volume = 0;
}

float FamilySircleAudioProcessor::getVolume()
{
	return volume;
}

void FamilySircleAudioProcessor::generateRandomVolumesArray()
{
	r.setSeedRandomly();
	for (int i = 0; i < 16; i++)
	{
		randomVolumes[i] = r.nextFloat();
	}
}

bool FamilySircleAudioProcessor::getRandomVolumeState()
{
	return randomVolumeState;
}

void FamilySircleAudioProcessor::setRandomVolumeState(bool state)
{
	randomVolumeState = state;
}

TempoCalculator& FamilySircleAudioProcessor::getTempoCalc()
{
	return tempoCalc;
}

float FamilySircleAudioProcessor::getRandomVolume(int index)
{
	return randomVolumes [index];
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FamilySircleAudioProcessor();
}
