
#!/usr/bin/env bash

# Stop if a command fails or an unset variable is used.
set -euo pipefail

# Find the project root (the directory containing this script).
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Allow a different compiler to be selected through the CXX variable.
CXX="${CXX:-g++}"

# Check that the compiler is installed.
if ! command -v "$CXX" >/dev/null 2>&1; then
    echo "Error: C++ compiler '$CXX' was not found."
    echo "Install g++ before building this project."
    exit 1
fi

# Create the build directory if it doesn't exist.
mkdir -p "$PROJECT_DIR/build"

echo "Cookin up some heat rn..."

# Compile the project.
"$CXX" \
    -std=c++20 \
    -Wall \
    -Wextra \
    -static \
    -I"$PROJECT_DIR/src" \
    "$PROJECT_DIR/src/main.cpp" \
    "$PROJECT_DIR/src/Sounds/ExampleSound.cpp" \
    "$PROJECT_DIR/src/Waves/SineWave.cpp" \
    -o "$PROJECT_DIR/build/dj"

echo "Chefed it up fam"
echo "Executable: build/dj"
