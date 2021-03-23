/*
  ==============================================================================

    AnimatedStar.h
    Created: 11 May 2019 8:11:34am
    Author:  Ric

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AnimatedStar    : public AnimatedAppComponent
{
public:
    AnimatedStar();
    ~AnimatedStar();

    void paint (Graphics&) override;
    void resized() override;
	void update() override;

	//custom funcs
	void setMainColour1(Colour c);
	void setMainColour2(Colour c);
	void setOutlineColour1(Colour c);
	void setOutlineColour2(Colour c);
	void setTwinkle(bool t);
	void setBigStar(bool b);
	void setOutlineWidthPercent(int o);
	void setAlpha(int a);
	void initStar(Colour m1, Colour m2, Colour o1, Colour o2, bool t, bool b, int o, int a);

private:
	int diameter{ 50 };
	int outlineWidthPercent{ 10 };
	uint8 alpha{ 100 };
	Colour mainColour1{ Colours::floralwhite };
	Colour mainColour2{ Colours::ghostwhite };
	Colour outlineColour1{ Colours::palevioletred };
	Colour outlineColour2{ Colours::blueviolet };
	bool twinkle{ false };
	bool bigStar{ true };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimatedStar)
};
