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

## FAQ

**Q:** I can't build. I'm getting an error!
**A:** You can try a few things. Try reinstalling MSYS2 and deleting the SM64Plus folder first. Disabling your antivirus could help as well. If all else fails, just restart your computer. If those don't help, you can ask for help on the Discord server.

**Q:** I could build, but the game doesn't launch.
**A:** You can rebuild the game from the main menu. When asked to clear your build files, say yes. If this doesn't work, also try restarting your computer.

**Q:** The game is running too fast!
**A:** You can try to limit the game's FPS using Nvidia's control panel or other 3rd party tools. Make sure that you limit the "sm64.us.f3dex2e.exe"'s frame rate, and not the launcher.

**Q:** My controller works in the launcher, but not in the actual game. What do I do?
**A:** The game itself doesn't have support for DirectInput controllers yet. You need to use a tool like DS4Windows, BetterJoyForCemu, or 360ce depending on your controller. Or alternatively, you can also put the game in your Steam library and play it that way, Steam takes care of all that for you.

**Q:** Can I use mods with this? What about Render96?
**A:** There's no support for mods for other SM64 PC port forks, and there will never be unfortunately. This includes Render96 too. As for texture packs, support for them is planned for the future.

**Q:** Can I have a logo of the game?
**A:** Sure. Shoutouts to @Benial for doing such a good job with it.

**Q:** Is there Linux or Mac support?
**A:** Nope. It might get Linux support in the future, but not yet.

**Q:** Is your game safe?
**A:** Yeah. If your antivirus is giving you any warnings, it's most likely false. You especially shouldn't trust Chrome on this kind of stuff.

**Q:** Will Nintendo take this game down?
**A:** https://twitter.com/OfficialMFGG/status/1121019925521489920

## Keep in mind...

This repo does **not** include all the assets necessary for compiling the game. A prior copy of the game is required to extract the assets. Binaries of the game will **not** be distributed for this very reason.

That being said, there is an official launcher that will help you build the game and configure its settings easily. You can download it from [MFGG]([once it's out](https://www.mfgg.net/?act=resdb&param=02&c=2&id=38190)). It is for 64-bit Windows systems only.

You can also build the game manually if you prefer to do so, or if you're not on a Windows platform. To do that, follow the following instructions.

Features that _might_ get added in the future:
- Discord Rich Presence support
- Smoother vertical camera movement
- Rumble
- Odyssey-like rolling
- Custom texture pack support
- Full OpenGL and SDL support

## Changelog

### v1.0.1 (06/04/2021):
Launcher:
- Disabled DirectInput support because the game itself doesn't support it yet, which causes confusion.
- Made it possible to reload all settings from the presets menu.
- Made it possible to build the game while MSYS2 is installed on a different location.
- Made keyboard configuration less cumbersome.
- Made the wording during the initial setup a bit clearer.

Game itself:
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
3. Clone the repo with `git clone https://github.com/MorsGames/sm64-port.git`, then enter it with `cd sm64-port`.
4. Place a *Super Mario 64* ROM called `baserom.us.z64` into the project folder for asset extraction.
5. Run `make` to build. You can add `-j4` to improve build speed (hardware dependent based on the amount of CPU cores available).
6. The executable binary will be located at `build/us_pc/sm64.us.f3dex2e.exe`.

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