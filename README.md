# aspiring-soundcloud-artist

I'm an aspiring soundcloud artist, but worse.

### Dependencies

This project uses the GCC/G++ compiler for C++. 

The project currently uses the C++ standard library and does not require any external audio libraries.

Optionally, use gdp for debug.

### Installing dependencies

### Building the project

Make the build script executable (only required once):

```bash
chmod +x build.sh
```

Build the project:

```bash
./build.sh
```

Run the executable (name declared in shell script):

```bash
./build/dj
```

Or one shot the last two: 

```bash
./build.sh && ./build/dj
```

The build script automatically creates the `build/` directory and places the compiled executable inside it.

Generated WAV files are written to the `output/` directory.