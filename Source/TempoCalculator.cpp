/*
  ==============================================================================

    TempoCalculator.cpp
    Created: 12 May 2019 8:47:59pm
    Author:  Ric

  ==============================================================================
*/

#include "TempoCalculator.h"

TempoCalculator::TempoCalculator()
{
}

TempoCalculator::~TempoCalculator()
{
}

void TempoCalculator::init(double bpm, double sampleRate, int barDivider)
{
	tempoCalc.bpm = bpm;
	tempoCalc.sampleRate = sampleRate;
	tempoCalc.barDivider = barDivider;
	calculateNumberOfSamplesPerBeat();
}

void TempoCalculator::calculateNumberOfSamplesPerBeat()
{
	tempoCalc.numberSamplesPerBeat = int64(((float(60) / float(tempoCalc.bpm)) * tempoCalc.sampleRate)
		/ (float(tempoCalc.barDivider) / float(4)));
}

int TempoCalculator::calculateBeatNumber(int64 timeInSamples)
{
	tempoCalc.timeInSamples = timeInSamples;
	tempoCalc.barStep = (tempoCalc.timeInSamples / tempoCalc.numberSamplesPerBeat) % tempoCalc.barDivider;
	return tempoCalc.barStep;
}

int TempoCalculator::getBeatNumber()
{
	return tempoCalc.barStep;
}

int TempoCalculator::getBarDivider()
{
	return tempoCalc.barDivider;
}

void TempoCalculator::setBarDivider(int bd)
{
	DBG(bd);
	if (tempoCalc.barDivider > 16)
	{
		bd = 16;
	}
	if (tempoCalc.barDivider < 1)
	{
		bd = 1;
	}
	DBG(bd);
	tempoCalc.barDivider = bd;
	calculateNumberOfSamplesPerBeat();
}
