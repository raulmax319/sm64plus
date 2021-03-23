# Super Mario 64 Port Thingy

Super Mario 64 Port Thingy is a fork of [sm64-port](https://github.com/sm64-port/sm64-port) that aims to add features that will fix the issues in the base game and enhance the gameplay, while keeping the vanilla feel of the game.

These features include (but not limited to):
- 60FPS support via interpolation.
- More responsive controls.
- Improved camera.
- Additional moves for Mario.
- Graphical improvements.
- Game design tweaks.
- Optional extra modes.
- Bug fixes.

To learn about all the options, visit the [Wiki](https://github.com/MorsGames/sm64-port/wiki).

This repo does **not** include all the assets necessary for compiling the game. A prior copy of the game is required to extract the assets. Binaries of the game will **not** be distributed for this very reason.

That being said, there is an official launcher that will help you build the game and configure its settings easily. You can download it from the releases section. It is for Windows only.

You can also build the game manually if you prefer to, or if you're not on a Windows platform. To do that, follow the instructions in the [Wiki](https://github.com/MorsGames/sm64-port/wiki).

## Building native executables

### Windows

1. Install and update MSYS2, following the directions listed on https://www.msys2.org/.
2. Launch MSYS2 MinGW and install required packages depending on your machine (do **NOT** launch "MSYS2 MSYS"):
  * 64-bit: Launch "MSYS2 MinGW 64-bit" and install: `pacman -S git make python3 mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-glew`
  * 32-bit (will also work on 64-bit machines): Launch "MSYS2 MinGW 32-bit" and install: `pacman -S git make python3 mingw-w64-i686-gcc mingw-w64-i686-SDL2 mingw-w64-i686-glew`
  * Do **NOT** install `gcc`.
3. Clone the repo with `git clone https://github.com/MorsGames/sm64-port.git`, then enter it with `cd sm64-port`.
4. Place a *Super Mario 64* ROM called `baserom.us.z64` into the project folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
6. The executable binary will be located at `build/us_pc/sm64.us.f3dex2e.exe`.

### Linux

1. Install prerequisites (Ubuntu) with `sudo apt install -y git build-essential pkg-config libusb-1.0-0-dev libsdl2-dev`.
2. Clone the repo with `git clone https://github.com/MorsGames/sm64-port.git`.
3. Place a Super Mario 64 ROM called `baserom.us.z64` into the project folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
5. The executable binary will be located at `build/us_pc/sm64.<VERSION>.f3dex2e`.

## Additional options

* You can apply the 60FPS patch by using `tools/apply_patch.sh "enhancements/60fps.patch"`. If you get an error, try using `pacman -S patch` first.
* You can target OpenGL by using `make ENABLE_OPENGL=1`. **CURRENTLY NONFUNCTIONAL!** Help is needed to fix this!

## Credits.
- **Mors:** Most things.
- **[sm64-port](https://github.com/sm64-port/sm64-port) Team:** The port that was used as a base for this project.
- **[SM64 Decompilation](https://github.com/n64decomp/sm64) Team:** The original decompilation used for this project.
- **Emil:** The original 60FPS patch.
- **Kaze Emanuar:** Providing certain bug fixes.

Parts of [sm64ex](https://github.com/sm64pc/sm64ex) were also used as reference for this project.

Please let me know if I'm forgetting to credit you.
