/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "TempoCalculator.h"

//==============================================================================
/**
*/
class FamilySircleAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FamilySircleAudioProcessor();
    ~FamilySircleAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

	bool updateCurrentTimeInfoFromHost(AudioPlayHead::CurrentPositionInfo& posInfo);

	int64 getBeatNumber();

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	//=============================================================================
	void increaseVolume(float inc);
	void decreaseVolume(float dec);
	float getVolume();

	void generateRandomVolumesArray();

	bool getRandomVolumeState();

	void setRandomVolumeState(bool state);
	float getRandomVolume(int index);

	TempoCalculator& getTempoCalc();

private:
	AudioPlayHead::CurrentPositionInfo lastPosInfo;
	float volume{ 0.5f };
	float previousVolume{ volume };
	float maxVolume{ 2.0f };
	TempoCalculator tempoCalc;
	Random r;
	bool randomVolumeState{ false };
	float* randomVolumes;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FamilySircleAudioProcessor)
};
