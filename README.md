# SN8F5702 SDCC template

This is a sample LED blink project to illustrate development for Sonix SN8F5xxx family of 8051-compatible microcontrollers with open-source tools

## Used software

- SDCC compiler:
  - Windows: [use the official installer](https://sdcc.sourceforge.net/index.php#Download).
  - Linux: install from your package manager, e.g. `apt update && apt install sdcc`
- Make:
  - Windows: download [build tools from xPack](https://github.com/xpack-dev-tools/windows-build-tools-xpack/releases), extract, and add `bin` directory to your `PATH` environment variable.
  - Linux: install from your package manager, e.g. `apt update && apt install make`
- SonixFlash flash tool:
  - Download it from the [official repository](https://github.com/silicagel777/SonixFlash) and add to your `PATH` environment variable
- Visual Studio Code
  - Download it from the [official website](https://code.visualstudio.com/) and install the [C++ extension](https://code.visualstudio.com/docs/languages/cpp). You may also install the [quick-run-panel](https://marketplace.visualstudio.com/items/?itemName=davehart.quick-run-panel) plugin to have easily-accessible buttons for build tasks.

## Usage examples

- Run `make` to build firmware
- Run `make flash PORT=<SERIAL_PORT>` to flash the MCU using SonixFlash
- Run `make clean` to clean build directory

This project comes with sample VS Code settings in `.vscode` directory, review them and adapt to your liking.
