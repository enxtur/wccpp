# ccwc

ccwc counts various statistics of a text file, such as the number of lines, words, characters, and bytes. It takes command-line arguments to specify the operation and the file to be analyzed.

## Project Structure

```
cpp-tour/
├── Makefile          # Build configuration
├── README.md         # This file
├── src/              # Source files (.cpp)
│   ├── main.cpp      # Main entry point
│   └── utils.cpp     # Example utility functions
├── include/          # Header files (.h)
│   └── utils.h       # Example header
├── obj/              # Object files (generated)
└── bin/              # Executable files (generated)
```

## Building and Running

### Basic Commands

```bash
# Build the project
make

# Build and run
make run

# Clean build artifacts
make clean

# Show available targets
make help
```

### Build Variants

```bash
# Debug build (with debug symbols and no optimization)
make debug

# Release build (with optimization)
make release
```

## How to Extend

### Adding New Source Files

1. Add your `.cpp` files to the `src/` directory
2. Add corresponding `.h` files to the `include/` directory
3. The Makefile will automatically detect and compile new source files

### Adding Dependencies

1. Update the `LDFLAGS` variable in the Makefile for linking libraries
2. Update the `install-deps` target if you need system dependencies

### Customizing Build Options

- **Compiler**: Change the `CXX` variable
- **Flags**: Modify `CXXFLAGS` for compile-time options
- **Target Name**: Change the `TARGET` variable
- **Directories**: Modify directory variables (`SRCDIR`, `INCDIR`, etc.)

### Example: Adding a New Module

1. Create `src/math.cpp`:
   ```cpp
   #include "math.h"
   
   int factorial(int n) {
       return (n <= 1) ? 1 : n * factorial(n - 1);
   }
   ```

2. Create `include/math.h`:
   ```cpp
   #ifndef MATH_H
   #define MATH_H
   
   int factorial(int n);
   
   #endif // MATH_H
   ```

3. Include in `src/main.cpp`:
   ```cpp
   #include "math.h"
   ```

4. Build with `make` - the new files will be automatically included!

## Features

- **Automatic source detection**: Finds all `.cpp` files in `src/`
- **Dependency tracking**: Rebuilds only what's necessary
- **Multiple build types**: Debug and release configurations
- **Clean separation**: Headers, sources, objects, and binaries in separate directories
- **Easy extension**: Just add files and rebuild
- **Cross-platform**: Works on Linux, macOS, and Windows (with MinGW) 