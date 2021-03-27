/*
  ==============================================================================

    AnimatedStar.cpp
    Created: 11 May 2019 8:11:34am
    Author:  Ric

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AnimatedStar.h"

//==============================================================================
AnimatedStar::AnimatedStar()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

	setSize(getWidth(), getHeight());
}

AnimatedStar::~AnimatedStar()
{
}

void AnimatedStar::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId)); 

	if (getHeight() > getWidth())
	{
		diameter = getWidth();
	}
	else
	{
		diameter = getHeight();
	}


	if (bigStar == true)
	{
		// draw "cross"
		g.setColour(mainColour1.withAlpha(alpha));
		RectangleList<int> rectList;
		Point<int> a(diameter / 2 - diameter / 8, 0);
		Point<int> b(diameter / 2 + diameter / 8, diameter);
		Rectangle <int> vert(a, b);
		rectList.add(vert);
		Point<int> c(a.getY(), a.getX());
		Point<int> d(b.getY(), b.getX());
		Rectangle <int> hori(c, d);
		rectList.add(hori);
		g.fillRectList(rectList);

		// draw "cross" outlines on right
		rectList.clear();
		g.setColour(outlineColour1.withAlpha(alpha));
		Point<int> e(diameter / 2 + diameter / 8, 0);
		Rectangle<int> l0(b, e.translated(-diameter / outlineWidthPercent, 0));
		rectList.add(l0);
		Point<int> f(diameter, diameter / 2 - diameter / 8);
		Rectangle<int> l1(d, f.translated(-diameter / outlineWidthPercent, 0));
		rectList.add(l1);
		g.fillRectList(rectList);

		// draw "cross" outlines on top
		rectList.clear();
		g.setColour(outlineColour2.withAlpha(alpha));
		Point<int> h(diameter / 2 + diameter / 8, 0);
		Rectangle<int> l2(a, h.translated(0, diameter / outlineWidthPercent));
		rectList.add(l2);
		Point<int> j(diameter, diameter / 2 - diameter / 8);
		Rectangle<int> l3(c, j.translated(0, diameter / outlineWidthPercent));
		rectList.add(l3);
		g.fillRectList(rectList);
	}

	g.setColour(mainColour2.withAlpha(alpha));

	// draw small square
	RectangleList<int> rectList;
	Point<int> a(diameter / 2 - diameter / 4, diameter / 2 - diameter / 4);
	Point<int> b(diameter / 2 + diameter / 4, diameter / 2 + diameter / 4);
	Rectangle <int> vert(a, b);
	rectList.add(vert);
	g.fillRectList(rectList);

	// draw small square right outlines
	g.setColour(outlineColour1.withAlpha(alpha));
	Point <int> e(diameter / 2 + diameter / 4, diameter / 2 - diameter / 4);
	Rectangle <int> l0(b, e.translated(-diameter / outlineWidthPercent, 0));
	g.fillRect(l0);

	// draw small square top outlines
	g.setColour(outlineColour2.withAlpha(alpha));
	Point <int> f(diameter / 2 + diameter / 4, diameter / 2 - diameter / 4);
	Rectangle <int> l1(a, f.translated(0, diameter / outlineWidthPercent));
	g.fillRect(l1);

}

void AnimatedStar::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void AnimatedStar::update()
{
	repaint();
}

void AnimatedStar::setMainColour1(Colour c)
{
	mainColour1 = c;
	repaint();
}

void AnimatedStar::setMainColour2(Colour c)
{
	mainColour2 = c;
	repaint();
}

void AnimatedStar::setOutlineColour1(Colour c)
{
	outlineColour1 = c;
	repaint();
}

void AnimatedStar::setOutlineColour2(Colour c)
{
	outlineColour2 = c;
	repaint();
}

void AnimatedStar::setTwinkle(bool t)
{
	twinkle = t;
	repaint();
}

void AnimatedStar::setBigStar(bool b)
{
	bigStar = b;
	repaint();
}

void AnimatedStar::setOutlineWidthPercent(int o)
{
	outlineWidthPercent = o;
	repaint();
}

void AnimatedStar::setAlpha(int a)
{
	alpha = uint8(a);
	repaint();
}

void AnimatedStar::initStar(Colour m1, Colour m2, Colour o1, Colour o2, bool t, bool b, int o, int a)
{
	setMainColour1(m1);
	setMainColour2(m2);
	setOutlineColour1(o1);
	setOutlineColour2(o2);
	setTwinkle(t);
	setBigStar(b);
	setOutlineWidthPercent(o);
	setAlpha(a);
}

