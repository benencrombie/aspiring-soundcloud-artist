/////////////////////////////////////////////////
//
// Filename: SineWave.cpp
//
// Description: Sine waveform module
//
// Author: Benen Crombie
//
/////////////////////////////////////////////////

#include "SineWave.h"
#include <cmath>
#include <numbers>

SineWave::SineWave(double freq, double amp, double sr)
    : frequency(freq), amplitude(amp), sampleRate(sr)
{
    // Constructor body, empty for now
}

double SineWave::generateSample()
{
    // Generate output, simple sin func
    double output = amplitude * std::sin(phase);

    // Increment phase. Complete cycle is 2pi radians, freq/sr is cycles per sample
    // Therefore the phase increment for every sample is below
    phase += 2.0 * std::numbers::pi * frequency / sampleRate;

    // Phase wraps every 2 * pi radians
    if (phase >= 2.0 * std::numbers::pi)
    {
        phase -= 2.0 * std::numbers::pi;
    }

    // Return the generated sample, next time this is called, phase is updated
    return output;
}

void SineWave::setFrequency(double freq)
{
    // Exposed means of changing wave frequency
    // TODO theres no input validation yet (i.e., no rejecting frequencies beyond Nyquist freq.)
    frequency = freq;
}

void SineWave::setAmplitude(double amp)
{
    // Exposed means of changing wave amplitude
    // TODO no input validation, just clamp between 0.0 and 1.0
    amplitude = amp;
}