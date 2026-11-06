//////////////////////////////
//
// Filename: WavWrite.h
//
// Description: Converts
//
// AI generated
//
//////////////////////////////

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

// Writes mono, 16-bit PCM WAV files.
class WavWriter
{
  public:
    static bool write(const std::string &filename, const std::vector<double> &samples,
                      int sampleRate)
    {
        // Each sample uses 2 bytes (16 bits).
        const std::uint16_t bitsPerSample = 16;
        const std::uint16_t numChannels   = 1;

        const std::uint32_t dataSize =
            static_cast<std::uint32_t>(samples.size() * sizeof(std::int16_t));

        const std::uint32_t byteRate = sampleRate * numChannels * bitsPerSample / 8;

        const std::uint16_t blockAlign = numChannels * bitsPerSample / 8;

        std::ofstream file(filename, std::ios::binary);

        if (!file)
        {
            return false;
        }

        // WAV files store multi-byte values in little-endian order.
        auto write16 = [&file](std::uint16_t value)
        {
            file.put(static_cast<char>(value & 0xFF));
            file.put(static_cast<char>((value >> 8) & 0xFF));
        };

        auto write32 = [&file](std::uint32_t value)
        {
            file.put(static_cast<char>(value & 0xFF));
            file.put(static_cast<char>((value >> 8) & 0xFF));
            file.put(static_cast<char>((value >> 16) & 0xFF));
            file.put(static_cast<char>((value >> 24) & 0xFF));
        };

        // RIFF header
        file.write("RIFF", 4);
        write32(36 + dataSize);
        file.write("WAVE", 4);

        // Format chunk
        file.write("fmt ", 4);
        write32(16); // PCM format chunk size
        write16(1);  // 1 = PCM
        write16(numChannels);
        write32(sampleRate);
        write32(byteRate);
        write16(blockAlign);
        write16(bitsPerSample);

        // Audio data chunk
        file.write("data", 4);
        write32(dataSize);

        // Convert each floating-point sample to a 16-bit integer.
        for (double sample : samples)
        {
            // Keep samples in the valid audio range.
            sample = std::clamp(sample, -1.0, 1.0);

            // Convert -1.0 ... +1.0 into signed 16-bit PCM.
            const auto pcmSample = static_cast<std::int16_t>(std::round(sample * 32767.0));

            write16(static_cast<std::uint16_t>(pcmSample));
        }

        return file.good();
    }
};
