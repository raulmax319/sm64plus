# Super Mario 64 Port Thingy

Stuff from my earlier Super Mario 64 ABE ported to the PC port with a ton of new features. This README file is going to be replaced eventually with something more proper.

This repo does not include all assets necessary for compiling the game.
A prior copy of the game is required to extract the assets.

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

* You can apply the 60FPS patch by using `tools/apply_patch.sh "enhancements/60fps.patch"`. If you get an error, try using `pacman -S patch` first. **Combining the draw distance settings and the 60FPS patch causes certain items to update only at 30FPS!** Originally it caused the whole game to flicker like crazy and crash, this is the best fix I could figure out. Help needed to fix this.
* You can target OpenGL by using `make ENABLE_OPENGL=1`. **CURRENTLY NONFUNCTIONAL!** Help is also needed to fix this.
