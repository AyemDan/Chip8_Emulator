# Chip8_Emulator
## Overview
Chip8_Emulator is a simple emulator for the CHIP-8 programming language, designed to run CHIP-8 programs and games. The CHIP-8 is a virtual machine that was originally used on 1970s microcomputers and is popular for learning about emulation and low-level programming.

## Features
- Emulates the CHIP-8 instruction set.
- Supports loading and running CHIP-8 ROMs.
- Implements a basic display, input, and sound system.

## Requirements
- A modern C++ compiler (e.g., GCC, Clang, or MSVC).
- SDL2 library for graphics and input handling.

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/Chip8_Emulator.git
    cd Chip8_Emulator
    ```
2. Install SDL2 if not already installed. Refer to the [SDL2 installation guide](https://wiki.libsdl.org/Installation).
3. Build the project:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage
1. Place your CHIP-8 ROM files in the `roms` directory.
2. Run the emulator with a ROM file:
    ```bash
    ./chip8_emulator path/to/rom.ch8
    ```

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to improve the emulator.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Thanks to the CHIP-8 community for their resources and documentation.
- Inspired by various CHIP-8 emulation projects and tutorials.
- Special thanks to SDL2 for providing a great library for graphics and input handling.
