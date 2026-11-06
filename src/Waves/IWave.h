/////////////////////////////////////////////////
//
// Filename: IWwave.h
//
// Description: Interface file for all wave types
//
// Author: Benen Crombie
//
/////////////////////////////////////////////////

#pragma once

/**
 * Abstract base class for all wave forms
 */
class IWave
{
  public:
    /**
     * Object destructor, manages cleanup of waves created and destroyed within a session
     */
    virtual ~IWave() = default;

    /**
     * Method to actually build out the sample using wave attributes
     */
    virtual double generateSample() = 0;

    /**
     * Method to set the frequency of the wave (Hz)
     */
    virtual void setFrequency(double frequency) = 0;

    /**
     * Method to set the amplitude of the wave (Normalized between 0.0 and 1.0)
     */
    virtual void setAmplitude(double amplitude) = 0;
};