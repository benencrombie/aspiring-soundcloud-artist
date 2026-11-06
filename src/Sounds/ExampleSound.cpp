/////////////////////////////////////////////////
//
// Filename: ExampleSound.cpp
//
// Description: Example sounds built from basic waves
//
// Author: Benen Crombie
//
/////////////////////////////////////////////////

#include "Sounds/ExampleSound.h"

#include <iostream>
#include <vector>

#include "Producer/WavWriter.h"
#include "Waves/SineWave.h"

namespace ExampleSound
{
bool renderSineTone(const std::filesystem::path &outputDir)
{
    // Audio configuration
    const int sampleRate         = 44100;
    const double durationSeconds = 3.0;

    // Calculate how many samples we need.
    const int totalSamples = static_cast<int>(sampleRate * durationSeconds);

    // 440 Hz frequency, 0.5 amplitude, 44100 Hz sample rate.
    SineWave oscillator(440.0, 0.5, sampleRate);

    // Store all generated samples here.
    std::vector<double> audioSamples;
    audioSamples.reserve(totalSamples);

    // Generate the audio.
    for (int i = 0; i < totalSamples; ++i)
    {
        audioSamples.push_back(oscillator.generateSample());
    }

    // Write the samples to a WAV file.
    const std::filesystem::path outputFile = outputDir / "test.wav";
    const bool success = WavWriter::write(outputFile.string(), audioSamples, sampleRate);

    if (success)
    {
        std::cout << "WAV file created\n";
        std::cout << "Location: " << outputFile << "\n";
    }
    else
    {
        std::cout << "Failed to create WAV file at: " << outputFile << "\n";
    }

    return success;
}
} // namespace ExampleSound