/*
  ==============================================================================

    AnimatedSky.cpp
    Created: 11 May 2019 5:24:09pm
    Author:  Ric

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedSky.h"

//==============================================================================
AnimatedSky::AnimatedSky()
{
	moon.setFramesPerSecond(2);
	moon.setColour1(Colours::darkgrey);
	moon.setColour2(Colours::darkslategrey);
	addAndMakeVisible(moon);
	addAndMakeVisible(star0);
	addAndMakeVisible(star1);
	addAndMakeVisible(star2);
	addAndMakeVisible(star3);
	addAndMakeVisible(star4);
	addAndMakeVisible(star5);
	addAndMakeVisible(star6);
	addAndMakeVisible(star7);
	addAndMakeVisible(star8);
	addAndMakeVisible(star9);
	addAndMakeVisible(star10);
	addAndMakeVisible(star11);
	star0.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, true, 10, 100);
	star1.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, true, 10, 100);
	star2.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, true, 10, 100);
	star3.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, true, 10, 100);
	star4.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, true, 10, 100);
	star5.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, true, 10, 100);
	star6.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, false, 10, 100);
	star7.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, false, 10, 100);
	star8.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, false, 10, 100);
	star9.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, false, 10, 100);
	star10.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, false, 10, 100);
	star11.initStar(Colours::whitesmoke, Colours::floralwhite, Colours::red, Colours::purple, false, false, 10, 100);
}

AnimatedSky::~AnimatedSky()
{
}

void AnimatedSky::paint (Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void AnimatedSky::resized()
{
	moon.setBounds(500, 300, 200, 200);
	star0.setBounds(10, 40, 30, 30);
	star1.setBounds(400, 70, 15, 15);
	star2.setBounds(222, 406, 15, 15);
	star3.setBounds(99, 222, 20, 20);
	star4.setBounds(300, 144, 15, 15);
	star5.setBounds(153, 265, 25, 25);
	star6.setBounds(255, 133, 15, 15);
	star7.setBounds(506, 260, 15, 15);
	star8.setBounds(677, 40, 15, 15);
	star9.setBounds(53, 255, 15, 15);
	star10.setBounds(555, 132, 15, 15);
	star11.setBounds(455, 111, 15, 15);
}

void AnimatedSky::update()
{
}

AnimatedStar& AnimatedSky::getMetronomeStar()
{
	return star9;
}
