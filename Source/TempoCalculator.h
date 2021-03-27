/*
  ==============================================================================

    TempoCalculator.h
    Created: 12 May 2019 8:47:59pm
    Author:  Ric

  ==============================================================================
*/

#ifndef TEMPOCALCULATOR_H
#define TEMPOCALCULATOR_H

#include "../JuceLibraryCode/JuceHeader.h"

class TempoCalculator
{
public:

	TempoCalculator();
	~TempoCalculator();

	void init(double bpm, double sampleRate, int barDivider);
	void calculateNumberOfSamplesPerBeat();
	int calculateBeatNumber(int64 timeInSamples);
	int getBeatNumber();
	int getBarDivider();
	void setBarDivider(int bd);

private:
	struct TEMPOCALC_T
	{
		double bpm{ 120.0 };
		double sampleRate{ 44100.0 };
		int samplePerBlock{ 100 };
		int64 timeInSamples{ 0 };
		int barStep{ 0 };
		int barDivider{ 4 };
		int64 numberSamplesPerBeat{ 22050 };
	}; 
	TEMPOCALC_T tempoCalc{ 120, 44100, 100, int64 (0), 0, 4 };
};

#endif
