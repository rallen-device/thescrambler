/*
  ==============================================================================

    AnimatedScene.cpp
    Created: 11 May 2019 6:00:25pm
    Author:  Ric

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedScene.h"

//==============================================================================
AnimatedScene::AnimatedScene()
{
	addAndMakeVisible(sky);
}

AnimatedScene::~AnimatedScene()
{
}

void AnimatedScene::paint (Graphics& g)
{
	g.fillAll(Colours::transparentBlack);
	// fill the flooooor
	g.setColour(Colours::lightslategrey);
	g.fillRect(float (0), float (getHeight() * skyPercent), float (getWidth()), float (getHeight()));
}

void AnimatedScene::resized()
{
	sky.setBounds(float (0), float (0), float (getWidth()), float (getHeight() * skyPercent));
}

void AnimatedScene::update()
{
	repaint();
}

AnimatedSky& AnimatedScene::getSky()
{
	return sky;
}
