/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "AnimatedSky.h"
#include "AnimatedScene.h"

//==============================================================================
/**
*/
class FamilySircleAudioProcessorEditor  :	public AudioProcessorEditor, 
											private Timer,
											public TextEditor::Listener
{
public:
    FamilySircleAudioProcessorEditor (FamilySircleAudioProcessor&);
    ~FamilySircleAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void sliderValueChangeGain(Slider* slider);

	void textEditorReturnKeyPressed(TextEditor& t);
	void textOutputUpdate(String input, String reply);
	void textOutputUpdateDebug(String debug);
	String processTextInput(String s);

	AnimatedScene& getScene();

	void timerCallback() override;

private:
    FamilySircleAudioProcessor& processor;
	AnimatedScene scene;
	TextEditor textInput;
	TextEditor textOutput;

	Slider slideGain;
	Slider slideBlend;
	Array<Colour> metronomeColours{ Colours::greenyellow, Colours::orangered, Colours::orange, Colours::yellow,
										Colours::blue, Colours::purple, Colours::red, Colours::lightyellow,
									Colours::greenyellow, Colours::orangered, Colours::orange, Colours::yellow,
										Colours::blue, Colours::purple, Colours::red, Colours::lightyellow };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FamilySircleAudioProcessorEditor)
};
