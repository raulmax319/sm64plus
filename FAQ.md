# Frequently Asked Questions

Before trying any of these suggestions for the commonly faced issues, please make sure that your launcher and the game itself is at the latest version.

The game's current version is **v2.0.1**, and the launcher's current version is **v2.0.1.1**.

<br>

## **Q:** I can't build. I'm getting an error!

**A:** It seems like reinstalling [MSYS2](https://www.msys2.org/) and deleting the "sm64plus" folder fixes the issues for most people. Disabling your antivirus could also help in some cases.

One other alternative you have is to use [sm64pcBuilder2](https://sm64pc.info/sm64pcbuilder2/) instead to build the game. Or you can also just compile the game manually, following the instructions from the [README file](https://github.com/MorsGames/sm64plus/blob/master/README.md).

If these don't help, you can ask for help on our [Discord server](http://discord.mors-games.com/). **Don't ask for help without following these steps first, and don't ask me help about sm64pcBuilder2 or building manually.**

Also please remember that most of the time these issues are caused by MSYS2, so we might not be able to always help you.

<br>

## **Q:** I could build, but the game doesn't launch.

**A:** You can try rebuilding the game from the main menu. When asked to clear your build files, say yes. If that doesn't work, just start over with the whole building process.

<br>

## **Q:** The game is running too fast!

**A:** You can try to limit the game's FPS using Nvidia's control panel or other 3rd party tools. Make sure that you limit `sm64.us.f3dex2e.exe`'s frame rate, and not the launcher's.

<br>

## **Q:** My controller doesn't work in the game. What do I do?

**A:** The game supports many different types of controllers, but it's impossible to have 100% compatibility with all of them. Here are a few things you can try:

- You can download [gamecontrollerdb.txt](https://raw.githubusercontent.com/gabomdq/SDL_GameControllerDB/master/gamecontrollerdb.txt) and put it in `sm64plus/build/us_pc/` folder without changing its name. It includes mappings for most game controllers out there and the game is configured to load it automatically.
- You can add the game to your Steam library, which seems to make most controllers work. 
- You can use tools like DS4Windows, BetterJoyForCemu, or 360ce to map them to Xinput, which does work.

<br>

## **Q:** Some of the textures appear black and purple, how do I fix this?

**A:** Hold "left", "right", and "backspace" keys down for 5 seconds in the title screen of the launcher. On non-Windows platforms, you can also try passing the path to the `gfx` directory as the first argument to the executable; by default it's generated at `sm64plus/build/us_pc/gfx`.

<br>

## **Q:** How do I access the hidden settings?

**A:** Hold down backspace or select on the "Press Any Key" screen until the screen goes white.

<br>

## **Q:** Can I have the logo of the game?

**A:** [Sure.](https://cdn.discordapp.com/attachments/828684639618203688/828756298643931176/sm64plus-centred.png) Shoutouts to [Benial](https://twitter.com/Benial17) for doing such a good job with it. :)

<br>

## **Q:** Can I use mods with this? 

**A:** You can install custom texture packs by copying the texture files to the "C:\Users\YourUsername\AppData\Local\SM64Plus\gfx" folder. If you're asked to replace any files, say yes.

The folder layout and file names for the textures is same as what most other PC port forks use. Also, if the texture pack you're using doesn't have segmented skybox textures, you won't be able to see any differences with how the skybox looks.

As for custom models, you can install those easily using [sm64pcBuilder2](https://sm64pc.info/sm64pcbuilder2/).

<br>

## **Q:** What about Render96?

**A:** The official Render96 texture pack works with SM64Plus, with the exception of skybox textures. The models do not to work at this moment, however. If you're willing to take on the challenge, it should be possible to fix the errors and make them work, but don't expect that to be a trivial task.

<br>

## **Q:** Can you add \*insert feature here\*?

**A:** It depends. I try not to add new assets, like new models, textures etc., and just use the ones provided by the ROM. I also try not to modify the levels just to keep the scope of the project small.

For other things, feel free to request anything to me on [Discord](http://discord.mors-games.com/), if I like the idea I might add it in eventually with an update.

<br>

## **Q:** Can you add online multiplayer?

**A:** No.

Adding online multiplayer to any game is already a rather difficult task, but adding it to a game that's not already built with multiplayer in mind is even harder. So that alone would take as much effort as everything else that's already in this fork, combined.

There's also [another fork](https://github.com/djoslin0/sm64ex-coop) of the PC port that aims to add online co-op into the game, so you might as well try that instead. That being said, I haven't tried it myself, nor know the people behind it so I can't say much else about it.

<br>

## **Q:** Can you make a Mario Sunshine Plus / \*insert game here\* Plus?

**A:** Also no.

These fan projects take a ton of effort to make, and are things I make during my free time. I can't really take on such a commitment just because a few people asked me to. If I'm already interested in making something, I'll probably make it eventually.

<br>

## **Q:** Is there Linux or Mac support?

**A:** The game can be manually compiled for Linux, and a Linux version of the launcher is planned. There's no Mac support planned.

<br>

## **Q:** Is your game safe?

**A:** Yeah. If your antivirus is giving you any warnings, it's most likely false. You especially shouldn't trust Chrome as it tends to mark things as suspicious very often.

<br>

## **Q:** Will Nintendo take this game down?

**A:** Nintendo hasn't taken down any of the other PC port forks yet, so I doubt it.

[There's also this Twitter thread to consider.](https://twitter.com/OfficialMFGG/status/1121019925521489920)