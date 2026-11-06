/////////////////////////////////////////////////
//
// Filename: main.cpp
//
// Description: Orchestrates all sounds
//
// Author: Benen Crombie
//
/////////////////////////////////////////////////

#include <filesystem>

#include "Sounds/ExampleSound.h"

namespace fs = std::filesystem;

int main()
{
    // main.cpp lives in <root>/src/, so two parent_path() calls reach <root>.
    const fs::path projectRoot = fs::path(__FILE__).parent_path().parent_path();
    const fs::path outputDir   = projectRoot / "outputs";

    // Make sure the output directory exists.
    fs::create_directories(outputDir);

    // Render each sound. Stop with an error code if any fail.
    bool ok = true;

    ok = ok && ExampleSound::renderSineTone(outputDir);
    // Add more sounds here, e.g.:
    // ok = ok && KickDrum::render(outputDir);

    return ok ? 0 : 1;
}