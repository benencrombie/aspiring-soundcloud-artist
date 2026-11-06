/////////////////////////////////////////////////
//
// Filename: SineWave.h
//
// Description: Header for sine waveform
//
// Author: Benen Crombie
//
/////////////////////////////////////////////////

#pragma once

#include "IWave.h"
#include <numbers>

class SineWave : public IWave
{
  private:
    double frequency;            // Pitch, Hz
    double amplitude;            // Noramlized; [0.0, 1.0]
    double sampleRate = 44100.0; // Resolution of capture, Hz.
    double phase      = 0.0;     // Tracked position within waveform, Radians

  public:
    /**
     * @brief Sine wave class constructor
     * @param freq Frequency in Hz
     * @param amp Amplitude, [0, 1.0]
     * @param sr Sample rate in Hz
     */
    SineWave(double freq, double amp, double sr);

    /**
     * @brief Method ot create a generated sample
     * @param void
     * @return audio sample
     */
    double generateSample() override;

    /**
     * @brief Method ot change the waveform's frequency
     * @param frequency target freq in Hz
     * @return void
     */
    void setFrequency(double frequency) override;

    /**
     * @brief Method to change the waveform's amplitude
     * @param amplitude target amplitude between 0.0 and 1.0
     * @return void
     */
    void setAmplitude(double amplitude) override;
};