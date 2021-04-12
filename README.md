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

**A:** It seems like reinstalling MSYS2 and deleting the SM64Plus folder fixes the issues for most people. Disabling your antivirus could also help in some cases.

One other alternative you have is to use [sm64pcBuilder2](https://sm64pc.info/sm64pcbuilder2/) instead to build the game. Or you can also just compile the game manually, following the instructions from below.

If these don't help, you can ask for help on our Discord server. **Don't ask for help without following these steps first, and don't ask me help about sm64pcBuilder2 or building manually.**

<br>

**Q:** I could build, but the game doesn't launch.

**A:** You can try rebuilding the game from the main menu. When asked to clear your build files, say yes.

<br>

**Q:** The game is running too fast!

**A:** You can try to limit the game's FPS using Nvidia's control panel or other 3rd party tools. Make sure that you limit the "sm64.us.f3dex2e.exe"'s frame rate, and not the launcher's.

<br>

**Q:** My controller doesn't work in the game. What do I do?

**A:** The game itself doesn't have support for DirectInput controllers yet. You can add it to your Steam library, which seems to make most controllers work. You can also use a tool like DS4Windows, BetterJoyForCemu, or 360ce depending on your controller.

<br>

**Q:** Can I use mods with this? What about Render96?

**A:** You can use custom model mods using [sm64pcBuilder2](https://sm64pc.info/sm64pcbuilder2/). There is no support for texture mods yet however. There is no support for Render96 too, and there are no current plans for adding support specifically for it here.

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
- Moved the "Nearest Neighbor Filtering" setting to the "Graphics" tab.
- Made it so that the launcher now can change button prompts depending on if you're using a keyboard or gamepad.
- Made it take longer to reload all the settings from presets to prevent accidental reloads.
- Added the C-buttons to the list of reassignable buttons for controllers.
- Removed some keys from the key selection options.
- Certain animations got tweaked.

**Game itself:**
- Added the "Graphics Backend" setting, which makes it possible to switch between Direct3D11 and Direct3D12 without rebuilding.
- Added the "Improved Hanging" setting, which makes movement when hanging on ceilings faster, and removes the requirement of holding A.
- Added the "Restore Mother Penguin's Sad Eyes" setting, which restores the unused, sad looking eye texture for the mother penguin.
- Added the "Casual Mode" setting, which makes Mario not lose any health when underwater, and reduces all damage taken by half.
- Added the "Paper Mode" setting, which makes Mario thin like a paper.
- Added the "Wireframe Mode" setting. Guess what this one does.
- Added a bunch of mouse related settings. You can now control the camera and navigate some of the menus using your mouse.
- Added a key which makes Mario walk slower. This is to compensate for the lack of analog controls with a keyboard.
- Split the "Analog Stick Deadzone" setting into two, one for each analog stick.
- "Fix Various Bugs" now fixes more bugs.
- Changed the "Improved Metal Mario" setting to "Improved Powerups". It now also makes underwater shells last longer and makes Metal Mario's interactions with enemies and hazards more consistent.
- Changed the "Restore the Unused Trapdoor Sound" to "Restore Unused Sound Effects". It also now brings back the sound effects that were supposed to play during the Bowser defeat cutscenes.
- Added more options for the "Infinite Lives Mode" and "Encore Mode" settings, allowing further customizability.
- Made it so that when Hard Mode is active Mario loses health slower underwater, and faster in toxic gas.
- Some tweaks have been made to the "Improved Controls", "Wall Sliding", and "Odyssey Ground Pound Dive" settings.
- Made it so that when getting a star in a sub-area while the "Stay in Level After Getting a Star" setting is on, now you're asked if you want to keep playing or not.
- In addition to above, the lonely mushroom in TTM doesn't kick you out or cause a forced restart anymore.
- Fixed various issues regarding the "Manual Camera" setting.
- Made the game window be centered on main display at the game start.
- Reverted the level select level order back to original and fixed a crash casued by missing characters.
- Added Linux support thanks to [TheEssem](https://github.com/TheEssem).
- Fixed various issues.

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
