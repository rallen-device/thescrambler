/*
  ==============================================================================

    AnimatedMoon.h
    Created: 9 May 2019 9:31:26pm
    Author:  Ric

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AnimatedMoon    : public AnimatedAppComponent
{
public:
	AnimatedMoon();
    ~AnimatedMoon();

    void paint (Graphics&) override;
    void resized() override;
	void update() override;

	void setColour1(Colour c);
	void setColour2(Colour c);

private:
	int radius{ 1 };
	Colour moonColour1{ 00, 255, 00 };
	Colour moonColour2{ 255, 00, 00 };
	int maxNumSteps{ 20 };
	int step{ 0 };
	bool stepSwitch{ false };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimatedMoon)
};
