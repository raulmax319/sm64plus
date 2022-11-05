This is the changelog for the current development commit of the game. For the changelog for the public versions please check the Wiki!

# v3.0.0 (??/01/2022):

### Additions:
- Added the controller rumble feature from the Shindou version of the game. The strength of it can be adjusted from the "Input Mapping" page.
- Added 11 new preset color palettes for Mario, and added more customization settings for custom Mario colors.
- Added a setting to disable the "M" logo on Mario's cap.
- Added the "Save the Lives Count" setting, which allows you to save the number of lives you got to your save file.
- Added the "Better Enemies" setting, which makes some of the enemies better to deal with.
- Added the "Fix Exploits" setting, which fixes several exploits in the game like the bomb clip, hands-free holding, and the Backwards Long Jump.

### Changes:
- Completely overhauled the "Stay in Course After Getting a Star" setting. You no longer get kicked out of a course after defeating a boss or getting any of the stars. This should make the whole experience way more seamless. The original behavior of the setting is still available if you enable hidden settings.
- Completely overhauled the custom camera mode. It should now feel much more natural to use and behave much closer to the cameras of more modern 3D platformers. To streamline things many of related customization settings have been removed.
- Changed how controller button mapping works to make it more user-friendly. This makes button mapping way harder without the use of the launcher, however.
- Made Mario crouch faster with the "Improved Controls" setting enabled.
- Made it easier to do long jumps with the "Improved Controls" setting.
- Made jumping out of water easier with the "Improved Swimming" setting.
- Made collecting a star with the "Stay in Course After Getting a Star" setting refill your health.
- Tweaked the difficulty of the "Constant Chase!" mode option for the "Green Demon" mode, and made it way more forgiving as a whole. For those who want an experience closer to how it was before, now there's an "Unfair Chase!!!" option as well.
- Replaced the "Disable Low-Poly Models" setting with a "Level of Detail" setting.
- Renamed the "Make It Easier to Talk to the NPCs" setting to "Better NPCs" for consistency.
- Removed the "Disable Repeat Boo Messages" setting, as it's now a part of the "Better Enemies" setting.
- Removed the "Fix BLJ" and "Fix the Bomb Clip" settings, as they are now a part of the "Fix Exploits" setting.
- Reorganized the settings a bit.
- Rewrote the descriptions of a majority of the settings.
- Altered the default presets slightly.
- Updated the codebase to include the latest commits to the sm64-port repository, and made countless technical changes and fixes in the process. This ideally shouldn't make any visible differences in gameplay.

### Fixes:
- Fixed a bug that would cause the level progression to break when "Tie Bowser's Sub to Missions" and "Stay in Course After Getting a Star" settings are both enabled.
- Fixed custom player colors affecting other objects in the game.
- Made fixes to mouse movement in the Mario's face screen.
- Made Mario's face not get affected by the custom player colors.
- Fixed the "Press Start" text overlapping the HUD when the "Show the Collected Stars" setting is enabled.
- Prevented being able to control the camera during the demo.
- Made the mouse cursor not disappear in front of the game window when the game doesn't have focus.
- Fixed inconsistencies with some internal setting names.

### Launcher:
- Made various small improvements to the launcher.
- Completely overhauled the way controller button mapping works. Now you have to assign buttons to actions, not the other way around. This should make it much easier to remap non-standard controllers for the game.
- Made the launcher load the recommended preset value when a setting is missing from the settings file. This should fix many issues caused by upgrading the game from older versions.
- Fixed incorrect preset loading behavior and reverted it back to how it functioned prior to v2.1.0.
- Made the launcher reload settings after closing the game.
- Fixed the menu position incorrectly moving around when you minimize the launcher window while it's in fullscreen.
- Fixed the launched game appearing behind the launcher window.
- Fixed many more minor bugs.