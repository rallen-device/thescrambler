/*
  ==============================================================================

    AnimatedScene.h
    Created: 11 May 2019 6:00:25pm
    Author:  Ric

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedSky.h"

//==============================================================================
/*
*/
class AnimatedScene    : public AnimatedAppComponent
{
public:
    AnimatedScene();
    ~AnimatedScene();

    void paint (Graphics&) override;
    void resized() override;
	void update() override;

	AnimatedSky& getSky();

private:
	AnimatedSky sky;
	float skyPercent{ 0.8f };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimatedScene)
};
