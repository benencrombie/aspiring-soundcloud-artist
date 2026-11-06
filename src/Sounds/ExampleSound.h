/////////////////////////////////////////////////
//
// Filename: ExampleSound.h
//
// Description: Example sounds built from basic waves
//
// Author: Benen Crombie
//
/////////////////////////////////////////////////

#pragma once

#include <filesystem>

namespace ExampleSound
{
// Renders a 3 second 440 Hz sine tone to <outputDir>/test.wav.
// Returns true on success.
bool renderSineTone(const std::filesystem::path &outputDir);
} // namespace ExampleSound