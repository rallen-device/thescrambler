/*
  ==============================================================================

    AnimatedMoon.cpp
    Created: 9 May 2019 9:31:26pm
    Author:  Ric

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedMoon.h"

//==============================================================================
AnimatedMoon::AnimatedMoon()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
	setSize(getWidth(), getHeight());
}

AnimatedMoon::~AnimatedMoon()
{
}

void AnimatedMoon::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
	float interpolate = float(step) / float(maxNumSteps);
	Colour c = moonColour1.interpolatedWith(moonColour2, interpolate);
	g.setColour(c);
	if (getHeight() > getWidth())
	{
		radius = getWidth();
	}
	else
	{
		radius = getHeight();
	}
	Point<float> p(0, 0);
	g.fillEllipse(p.x, p.y, float (radius), float (radius));
}

void AnimatedMoon::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void AnimatedMoon::update()
{
	if (stepSwitch == true)
	{
		if (step < maxNumSteps)
		{
			step++;
		}
		else
		{
			stepSwitch = false;
		}
		if (step == maxNumSteps)
		{
			stepSwitch = false;
		}
	}
	else
	{
		if (step > 0)
		{
			step--;
		}
		else
		{
			stepSwitch = true;
		}
		if (step == 0)
		{
			stepSwitch = true;
		}
	}
	repaint ();
}

void AnimatedMoon::setColour1(Colour c)
{
	moonColour1 = c;
}

void AnimatedMoon::setColour2(Colour c)
{
	moonColour2 = c;
}
