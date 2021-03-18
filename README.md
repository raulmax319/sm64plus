# Super Mario 64 Port Thingy

Stuff from my earlier Super Mario 64 ABE ported to the PC port with a ton of new features. This README file is going to be replaced eventually with something more proper.

This repo does not include all assets necessary for compiling the game.
A prior copy of the game is required to extract the assets.

## Building native executables

### Linux

1. Install prerequisites (Ubuntu): `sudo apt install -y git build-essential pkg-config libusb-1.0-0-dev libsdl2-dev`.
2. Clone the repo: `git clone https://github.com/MorsGames/sm64-port.git`.
3. Place a Super Mario 64 ROM called `baserom.<VERSION>.z64` into the project folder for asset extraction. For `VERSION` only `us` is properly supported.
4. Run `make` to build. Add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
5. The executable binary will be located at `build/<VERSION>_pc/sm64.<VERSION>.f3dex2e`.

### Windows

1. Install and update MSYS2, following the directions listed on https://www.msys2.org/.
2. Launch MSYS2 MinGW and install required packages depending on your machine (do **NOT** launch "MSYS2 MSYS"):
  * 64-bit: Launch "MSYS2 MinGW 64-bit" and install: `pacman -S git make python3 mingw-w64-x86_64-gcc`
  * 32-bit (will also work on 64-bit machines): Launch "MSYS2 MinGW 32-bit" and install: `pacman -S git make python3 mingw-w64-i686-gcc`
  * Do **NOT** install `gcc`.
3. Clone the repo: `git clone https://github.com/MorsGames/sm64-port.git` and enter it `cd sm64-port`.
4. Place a *Super Mario 64* ROM called `baserom.<VERSION>.z64` into the project folder for asset extraction. For `VERSION` only `us` is properly supported.
5. Run `make` to build. Add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
6. The executable binary will be located at `build/<VERSION>_pc/sm64.<VERSION>.f3dex2e.exe`.