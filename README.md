# SM64 Plus

SM64 Plus is a fork of [sm64-port](https://github.com/sm64-port/sm64-port) that focuses on customizability and aims to add features that not only fix some of the issues found in the base game but also enhance the gameplay overall with extra options.

These features include (but not limited to):
- More responsive controls
- Improved camera
- Extended moveset
- The ability to continue the level after getting a star
- Optional extra modes
- 60FPS support via interpolation
- Various bug fixes

Download the launcher from MFGG: https://www.mfgg.net/?act=resdb&param=02&c=2&id=38190

If you need support, please head to the Super Mario Flashback official Discord server: http://discord.mors-games.com/

This repo does **not** include all the assets necessary for compiling the game. A prior copy of the game is required to extract the assets. Binaries of the game itself will **not** be distributed for this very reason.

You can also build the game manually if you prefer to do so, or if you're not on a Windows platform. To do that, follow the instructions below.

Features that _might_ get added in the future:
- Smoother vertical camera movement.
- Rumble support.
- Odyssey-like spin jump.
- Full OpenGL and SDL support.
- Full Linux support for the launcher.
- Maybe even N64 support?

## FAQ

[You can find the FAQ here.](https://github.com/MorsGames/sm64plus/blob/master/FAQ.md)

## Changelog

### v2.0.0 (??/??/2021):
**Launcher:**
- Now you can enter numbers to number fields directly instead of scrolling for 1000 years.

**Additions:**
- Added the "Better "Blast Away the Wall"" setting.

**Changes:**
- The "Fix Various Bugs" setting now fixes more bugs present within the game. Sorry speedrunners.
- Made "Backward Speed Cap" a part of "Improved Controls".
- Split "Improved Controls" into "Improved Controls" and "Improved Swimming".
- Removed "XL Mode".
- Removed the CCM easter egg.
- Renamed and relocated certain settings.
- Fixed various minor bugs and oversights.

### v1.1.3.3 (07/06/2021):
**Fixes:**
- Fixed the underwater shells disappearing after getting grabbed.
- Made the ground pound behavior same as the base game when "Improved Controls" is disabled.
- Fixed a potential bug involving collecting a star after dying.

### v1.1.3.2 (01/05/2021):
**Fixes:**
- [Fixed the use of non-portable printf, which caused the textures not to load under certain Linux distros.](https://github.com/MorsGames/sm64plus/pull/24)
- [Allowed passing the gfx directory as a command line argument on Linux.](https://github.com/MorsGames/sm64plus/pull/25)
- [Fixed the game not properly exiting on Linux.](https://github.com/sm64-port/sm64-port/pull/35)

### v1.1.3.1 (23/04/2021):
**Fixes:**
- Fixed the broken encore palette for Wet Dry World.

### v1.1.3 (23/04/2021):
**Launcher:**
- Added the new settings to the launcher.
- Changed some of the descriptions.
- Replaced "True" and "False" with "On" and "Off".
- Made it clearer when a setting has multiple options.
- Made it so that the launcher now tries to fix the broken texture issue automatically.
- Fixed the debug key combo that didn't work previously.

**Additions:**
- Added a "Default Monitor" setting for Windows.
- Added "No Healing Mode", which makes it so that the only way to heal Mario is to collect a Power Star.
- Added "XL Mode" as a hidden setting, which replaces coins with potato chips.

**Changes:**
- Made it so that "Restore Mother Penguin's Sad Eyes" enables something else too. :)
- Added an extra option for the "Moon Jump" setting that fixes the glitches caused by it.
- Increased the amount of damage taken from cold water in Hard Mode.

**Fixes:**
- Fixed broken explosion graphics.
- Fixed the star inside the cage in Dire Dire Docks causing you to get stuck when you have "Stay in Level" on.
- Made it so that the default graphics backend is always D3D11.
- Fixed issues regarding Linux support, so the game finally compiles under Linux.

### v1.1.2.1 (14/04/2021):
**Fixes:**
- Removed the mysterious 121st and 122nd stars.
- Fixed some issues regarding file select text.

### v1.1.2 (14/04/2021):
**Launcher:**
- Added the new settings to the launcher.
- The launcher now deletes the "gfx" folder right before the initial building process.

**Additions:**
- Added "Moon Jump" as a debug setting.

**Changes:**
- Changed the "Nearest Neighbor Filtering" setting to "Texture Filtering", which includes 3-point filtering as an option as well.
- Made it so that missing textures now use a black and purple checkerboard pattern, similarly to the launcher.
  
**Fixes:**
- Fixed an error on Linux builds (hopefully).

### v1.1.1 (13/04/2021):
**Launcher:**
- Made the launcher automatically copy the texture files to the right place right before launching the game.
- Added a secret key combination to delete all the game files.
- Renamed "Pull and Rebuild" to "Pull & Rebuild". Exciting!

**Additions:**
- Added an error message to the game if the "gfx" folder can't be found.

**Changes:**
- Changed the "Exit to Desktop" text to "Quit to Desktop".
- Made the game always use "%LOCALAPPDATA%\SM64Plus" as the working directory to simplify the code mess.
  
**Fixes:**
- Fixed minor texture errors.

### v1.1.0 (13/04/2021):
**Launcher:**
- Added the new settings to the launcher.
- Moved the "Nearest Neighbor Filtering" setting to the "Graphics" tab.
- Made it so that the launcher now can change button prompts depending on if you're using a keyboard or gamepad.
- Made it take longer to reload all the settings from presets to prevent accidental reloads.
- Added the C-buttons to the list of reassignable buttons for controllers.
- Removed some keys from the key selection options.
- Certain animations got tweaked.

**Additions:**
- Added experimental support for texture packs. Read the FAQ to learn how to use them.
- Added the "Graphics Backend" setting, which makes it possible to switch between Direct3D11 and Direct3D12 without rebuilding.
- Added the "Improved Hanging" setting, which makes movement when hanging on ceilings faster, and removes the requirement of holding A.
- Added the "Restore Mother Penguin's Sad Eyes" setting, which restores the unused, sad looking eye texture for the mother penguin.
- Added the "Casual Mode" setting, which makes Mario not lose any health when underwater, and reduces all damage taken by half.
- Added the "Paper Mode" setting, which makes Mario thin like a paper.
- Added the "Wireframe Mode" setting. Guess what this one does.
- Added a bunch of mouse related settings. You can now control the camera and navigate some of the menus using your mouse.
- Added a key which makes Mario walk slower. This is to compensate for the lack of analog controls with a keyboard.

**Changes:**
- Changed the way the textures are loaded.
- Removed the "HUD Upscaling" and "Texture Upscaling" settings. They were already pretty laggy, but with the introduction of texture packs they aren't necessary.
- Split the "Analog Stick Deadzone" setting into two, one for each analog stick.
- Changed the "Improved Metal Mario" setting to "Improved Powerups". It now also makes underwater shells last longer and makes Metal Mario's interactions with enemies and hazards more consistent.
- Changed the "Restore the Unused Trapdoor Sound" to "Restore Unused Sound Effects". It also now brings back the sound effects that were supposed to play during the Bowser defeat cutscenes.
- Made it so that "Fix Various Bugs" now fixes more bugs.
- Added more options for the "Infinite Lives Mode" and "Encore Mode" settings, allowing further customizability.
- Made it so that when Hard Mode is active Mario loses health slower underwater, and faster in toxic gas.
- Tweaked some of the Encore Mode palettes.
- Made some tweaks to the "Improved Controls", "Wall Sliding", and "Odyssey Ground Pound Dive" settings.
- Made it so that when getting a star in a sub-area with the "Stay in Level After Getting a Star" setting is on, you're now asked if you want to keep playing or not.
- In addition to above, the lonely mushroom in TTM doesn't kick you out or cause a forced restart anymore.
- Made the game window be centered on main display at the game start.
- [Added basic Linux support.](https://github.com/MorsGames/sm64plus/pull/4) Still needs further testing.

**Fixes:**
- Fixed the broken audio volume settings.
- Fixed palette errors in Encore Mode.
- Fixed various issues regarding the "Manual Camera" setting.
- Reverted the level select level order back to original and fixed a crash casued by missing characters.
- Fixed various other issues.

### v1.0.1 (06/04/2021):
**Launcher:**
- Disabled DirectInput support because the game itself doesn't support it yet, which causes confusion.
- Made it possible to reload all settings from the presets menu.
- Made it possible to build the game while MSYS2 is installed on a different location.
- Made keyboard configuration less cumbersome.
- Made the wording during the initial setup a bit clearer.

**Fixes:**
- Fixed certain enemies (like Pokeys and Goomba triplets) not spawning when the draw distance is disabled.
- Fixed King Whomp's collisions not unloading after his defeat.
- Did other minor fixes.

### v1.0.0 (05/04/2021)
- Initial release.

## Manual Building

### Windows

1. Install and update MSYS2, following the directions listed on https://www.msys2.org/.
2. Launch MSYS2 MinGW and install required packages depending on your machine (do **NOT** launch "MSYS2 MSYS"):
  * 64-bit: Launch "MSYS2 MinGW 64-bit" and install: `pacman -S git make python3 mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-glew`
  * 32-bit (untested, but should also work on 64-bit machines): Launch "MSYS2 MinGW 32-bit" and install: `pacman -S git make python3 mingw-w64-i686-gcc mingw-w64-i686-SDL2 mingw-w64-i686-glew`
  * Do not install `gcc`.
3. Clone the repo with `git clone https://github.com/MorsGames/sm64plus.git`, then enter it with `cd sm64plus`.
4. Place a *SM64* ROM called `baserom.us.z64` into the repository folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
6. The executable binary will be located at `build/us_pc/sm64.us.f3dex2e.exe`.

### Linux

1. Install the prerequisites:
  * On Debian / Ubuntu: `sudo apt install -y git build-essential pkg-config libusb-1.0-0-dev libsdl2-dev`
  * On Arch / Manjaro: `sudo pacman -S base-devel python sdl2 glew`
  * On Fedora: `sudo dnf install make gcc python3 glew-devel SDL2-devel`
2. Clone the repo with `git clone https://github.com/MorsGames/sm64plus.git`.
3. Place a SM64 ROM called `baserom.us.z64` into the repository folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
6. The executable binary will be located at `build/us_pc/sm64.us.f3dex2e`.

Please keep in mind that the Linux version of the game is missing some settings, such as "Wireframe Mode" and all mouse related settings.

## Additional options

* On non-Windows platforms, you can passing the path to the `gfx` directory as the first argument to the executable; by default it's generated at `build/us_pc/gfx`.

## Credits.
- **Mors:** Most new things you see here.
- **[Benial](https://twitter.com/Benial17):** Logo.
- **[sm64-port](https://github.com/sm64-port/sm64-port) Team:** The port that was used as a base for this project.
- **[A bunch of clever folks](https://github.com/n64decomp/sm64):** The original decompilation used for the port.
- **Emil:** The original 60FPS patch.
- **Kaze Emanuar:** Providing certain bug fixes.
- And everyone who sent pull requests or reported issues. :)

Parts of [sm64ex](https://github.com/sm64pc/sm64ex) were also used as a reference for this project.

Special thanks to Superstarxalien, Benial, Triforce141, MrMovie, and Shubs for testing and feedback.

Please let me know if I'm forgetting to credit you.
