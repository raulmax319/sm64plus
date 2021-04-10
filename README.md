# Super Mario 64 Plus

Super Mario 64 Plus is a fork of [sm64-port](https://github.com/sm64-port/sm64-port) that focuses on customizability and aims to add features that not only fix some of the issues found in the base game but also enhance the gameplay overall with extra options.

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
- Discord Rich Presence support
- Smoother vertical camera movement
- Rumble
- Odyssey-like rolling
- Custom texture pack support
- Full OpenGL and SDL support

## FAQ

**Q:** I can't build. I'm getting an error!

**A:** You can try a few things. Try reinstalling MSYS2 and deleting the SM64Plus folder first. Disabling your antivirus could help as well. If all else fails, just restart your computer. If those don't help, you can ask for help on the Discord server.

<br>

**Q:** I could build, but the game doesn't launch.

**A:** It seems like reinstalling MSYS2 and deleting the SM64Plus folder fixes the issues for most people. Disabling your antivirus could also help in some cases. If all else fails, you can try the old "restarting your computer" trick.

If you're still stuck after trying all that, you can post your error to the #help-me channel of the Discord server.

<br>

**Q:** The game is running too fast!

**A:** You can try to limit the game's FPS using Nvidia's control panel or other 3rd party tools. Make sure that you limit the "sm64.us.f3dex2e.exe"'s frame rate, and not the launcher.

<br>

**Q:** My controller doesn't work in the game. What do I do?

**A:** The game itself doesn't have support for DirectInput controllers yet. You can add it to your Steam library, which seems to make most controllers work. You can also use a tool like DS4Windows, BetterJoyForCemu, or 360ce depending on your controller.

<br>

**Q:** Can I use mods with this? What about Render96?

**A:** There's no official support for mods for other PC port forks, and there (most likely) will never be unfortunately. This includes Render96 too, there are no current plans for adding support for it here.

<br>

**Q:** Can I have a logo of the game?

**A:** [Sure](https://cdn.discordapp.com/attachments/828684639618203688/828756298643931176/sm64plus-centred.png). Shoutouts to @Benial for doing such a good job with it.

<br>

**Q:** Is there Linux or Mac support?

**A:** Nope. It might get Linux support in the future, but not yet.

<br>

**Q:** Is your game safe?

**A:** Yeah. If your antivirus is giving you any warnings, it's most likely false. You especially shouldn't trust Chrome on this kind of stuff.

<br>

**Q:** Will Nintendo take this game down?

**A:** https://twitter.com/OfficialMFGG/status/1121019925521489920

## Changelog

### v1.1.0 (??/04/2021):
**Launcher:**
- Added the new settings to the launcher.
- Made it take longer to reload settings from the launcher.

**Game itself:**
- Added the "Graphics Backend" setting, which makes it possible to switch between Direct3D11 and Direct3D12 without rebuilding.
- Added "Increase Underwater Shell Time", which makes the underwater shells last longer.
- Added "Casual Mode", which makes Mario not lose any health when underwater, and reduces all damage taken by half.
- Added a bunch of mouse related settings. You can now control the camera and some of the menus with your mouse.
- Added a key which makes Mario walk slower. This is to compensate for the lack of analog controls with a keyboard.
- Added "Paper Mode", which makes Mario thin like a paper.
- Added "Wireframe Mode". Guess what this one does.
- Split the "Analog Stick Deadzone" setting into two, one for each analog stick.
- Added more options for the "Infinite Lives Mode" and "Encore Mode" settings, allowing further customizability.
- Made Mario lose health slower when underwater during hard mode.
- Tweaked wall jumping to be stronger when wall sliding is enabled.
- Ground pound diving is also made faster now.
- Made Metal Mario more consistent with the "Improved Metal Mario" setting.
- Made the window center on the screen at game start.
- Reverted the level select level order back to original and fixed a crash casued by missing characters.
- Added Linux support thanks to [TheEssem](https://github.com/TheEssem).
- Fixed other various minor bugs.

### v1.0.1 (06/04/2021):
**Launcher:**
- Disabled DirectInput support because the game itself doesn't support it yet, which causes confusion.
- Made it possible to reload all settings from the presets menu.
- Made it possible to build the game while MSYS2 is installed on a different location.
- Made keyboard configuration less cumbersome.
- Made the wording during the initial setup a bit clearer.

**Game itself:**
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
4. Place a *Super Mario 64* ROM called `baserom.us.z64` into the repository folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
6. The executable binary will be located at `build/us_pc/sm64.us.f3dex2e.exe`.

### Linux (Untested!)

1. Install prerequisites (Ubuntu) with `sudo apt install -y git build-essential pkg-config libusb-1.0-0-dev libsdl2-dev`.
2. Clone the repo with `git clone https://github.com/MorsGames/sm64plus.git`.
3. Place a Super Mario 64 ROM called `baserom.us.z64` into the repository folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
5. The executable binary will be located at `build/us_pc/sm64.us.f3dex2e`.

## Additional options

* You can target OpenGL by using `make ENABLE_OPENGL=1`. **CURRENTLY NONFUNCTIONAL DUE TO ISSUES WITH SDL!** Help is needed to fix this!

## Credits.
- **Mors:** Most new things you see here.
- **Benial:** Logo.
- **[sm64-port](https://github.com/sm64-port/sm64-port) Team:** The port that was used as a base for this project.
- **[A bunch of clever folks](https://github.com/n64decomp/sm64):** The original decompilation used for the port.
- **Emil:** The original 60FPS patch.
- **Kaze Emanuar:** Providing certain bug fixes.

Parts of [sm64ex](https://github.com/sm64pc/sm64ex) were also used as a reference for this project.

Special thanks to Superstarxalien, Benial, Triforce141, MrMovie, and Shubs for testing and feedback.

Please let me know if I'm forgetting to credit you.
