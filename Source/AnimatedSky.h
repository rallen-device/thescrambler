/*
  ==============================================================================

    AnimatedSky.h
    Created: 11 May 2019 5:24:09pm
    Author:  Ric

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedMoon.h"
#include "AnimatedStar.h"

//==============================================================================
/*
*/
class AnimatedSky    : public AnimatedAppComponent
{
public:
    AnimatedSky();
    ~AnimatedSky();

    void paint (Graphics&) override;
    void resized() override;
	void update() override;

	AnimatedStar& getMetronomeStar ();

private:
	AnimatedMoon moon;
	AnimatedStar star0;
	AnimatedStar star1;
	AnimatedStar star2;
	AnimatedStar star3;
	AnimatedStar star4;
	AnimatedStar star5;
	AnimatedStar star6;
	AnimatedStar star7;
	AnimatedStar star8;
	AnimatedStar star9;
	AnimatedStar star10;
	AnimatedStar star11;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimatedSky)
};
