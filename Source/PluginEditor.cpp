/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#pragma warning (disable: 4100)
//==============================================================================
FamilySircleAudioProcessorEditor::FamilySircleAudioProcessorEditor (FamilySircleAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

	/*slideGain.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	slideGain.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 10);
	slideGain.setRange(0.0, 2.0);
	slideGain.setValue(1.0);
	addAndMakeVisible(slideGain);*/
	// add back ground scene
	addAndMakeVisible(scene);

	// add user interface text input box
	addAndMakeVisible(textInput);
	textInput.setAlwaysOnTop(true);
	textInput.setTextToShowWhenEmpty("Type your hello down here...", Colours::navajowhite);
	textInput.setColour(TextEditor::ColourIds::textColourId, Colours::navajowhite);
	textInput.addListener(this);

	// setup text output box (for debug)
	addAndMakeVisible(textOutput);
	textOutput.setReadOnly(true);
	textOutput.setTextToShowWhenEmpty("Welcome to The Scrambler... Say hello!", Colours::navajowhite);
	textOutput.setMultiLine(true);
	textOutput.setScrollBarThickness(2);
	textOutput.setColour(TextEditor::ColourIds::textColourId, Colours::navajowhite);

	// set overall size
	setSize(800, 500);
	startTimerHz(30);
}

FamilySircleAudioProcessorEditor::~FamilySircleAudioProcessorEditor()
{
}

//==============================================================================
void FamilySircleAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Welcome to \"The Scrambler\"...", getLocalBounds(), Justification::centredBottom, 1);
}

void FamilySircleAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
	slideGain.setBounds(getLocalBounds());
	scene.setBounds(getLocalBounds());
	textInput.setBounds(50, getHeight() - 50, getWidth() - 100, 20);
	textOutput.setBounds(getWidth() - 250, 10, 240, 200);
}

void FamilySircleAudioProcessorEditor::sliderValueChangeGain(Slider* slide)
{

}

void FamilySircleAudioProcessorEditor::textEditorReturnKeyPressed(TextEditor& t)
{
	String reply = processTextInput(t.getText());
	textOutputUpdate(t.getText(), reply);
	t.setText(String("                                           "));
	t.clear();
	t.setText(String(""));
}

void FamilySircleAudioProcessorEditor::textOutputUpdate(String input, String reply)
{
	String concat;
	
	textOutput.setCaretPosition(0);
	textOutput.setColour(TextEditor::ColourIds::textColourId, Colours::navajowhite);
	concat = "$ " + input + "\n";
	textOutput.insertTextAtCaret(concat);

	textOutput.setColour(TextEditor::ColourIds::textColourId, Colours::antiquewhite);
	textOutput.setCaretPosition(0);
	if (!reply.compare(""))
	{
		reply = "I'm not sure really... Ask me something else";
	}
	concat = "'" + reply + "'" + "\n";
	textOutput.insertTextAtCaret(concat);

	for (int i = 0; i < 10; i++)
	{
		textOutput.scrollDown();
	}
}

void FamilySircleAudioProcessorEditor::textOutputUpdateDebug(String debug)
{
	textOutput.setCaretPosition(0);
	textOutput.setColour(TextEditor::ColourIds::textColourId, Colours::greenyellow);

	String concat = debug + "\n";
	textOutput.insertTextAtCaret(concat);
}

String FamilySircleAudioProcessorEditor::processTextInput(String s)
{
	String hello = "hello";
	if (s.toLowerCase().contains(hello))
	{
		String ret = "Hello to you too. Try randomising the volume! Type 'random volume on'";
		return ret;
	}
	else if (s.toLowerCase().contains("vol"))
	{
		if (s.toLowerCase().contains("up"))
		{
			processor.increaseVolume(0.2f);
			String ret = "Volume increased: " + String(processor.getVolume());
			return ret;
		}
		else if (s.toLowerCase().contains("down"))
		{
			processor.decreaseVolume(0.2f);
			String ret = "Volume decreased: " + String(processor.getVolume());
			return ret;
		}
	}
	if (s.toLowerCase().contains("rand"))
	{
		if (s.toLowerCase().contains("vol"))
		{
			String ret = "";
			if (s.toLowerCase().contains("on"))
			{
				if (processor.getRandomVolumeState() == true)
				{
					ret = "Random volume already on, type 'rand vol redo' to change it up";
					return ret;
				}
				else
				{
					processor.setRandomVolumeState(true);
					processor.generateRandomVolumesArray();
					ret = "Random volumes set: ";
					for (int i = 0; i < processor.getTempoCalc().getBarDivider(); i++)
					{
						ret = ret + " " + String(processor.getRandomVolume(i), 2);
					}
					ret = ret + "\nTry changing the number of beats per bar with 'rand vol bar \"x\"' \
								where x is a number between 1 and 16, or 'rand vol redo' to redo the volumes";
					return ret;
				}
			}
			else if (s.toLowerCase().contains("off"))
			{
				processor.setRandomVolumeState(false);
				ret = "Random volumes turned off";
				return ret;
			}
			else if (s.toLowerCase().contains("re"))
			{
				if (processor.getRandomVolumeState() == false)
				{
					ret = "Random volume off, type 'rand vol on' to switch on";
					return ret;
				}
				else
				{
					processor.setRandomVolumeState(true);
					processor.generateRandomVolumesArray();
					ret = "Random volumes reset: ";
					for (int i = 0; i < processor.getTempoCalc().getBarDivider(); i++)
					{
						ret = ret + " " + String(processor.getRandomVolume(i), 2);
					}
					return ret;
				}
			}
			else if (s.toLowerCase().contains("beat") || s.toLowerCase().contains("bar"))
			{
				int bd = s.trimEnd().getTrailingIntValue();
				if (bd != NULL)
				{
					processor.getTempoCalc().setBarDivider(bd);
					ret = "Number of beats for rand vol set to " + String (processor.getTempoCalc().getBarDivider());
					return ret;
				}
			}
		}
	}
	return "";
}

AnimatedScene& FamilySircleAudioProcessorEditor::getScene()
{
	return scene;
}


void FamilySircleAudioProcessorEditor::timerCallback()
{
	scene.getSky().getMetronomeStar().setMainColour2(metronomeColours[(processor.getBeatNumber())]);
}



