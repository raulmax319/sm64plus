This is the changelog for the current development commit of the game. For the changelog for the public versions please check the Wiki!

# v2.2.0 (??/01/2022):

### Additions:
- Added the controller rumble feature from the Shindou version of the game. The strength of it can be adjusted from the "Input Mapping" page.
- Added 11 (12?) new preset color palettes for Mario.
- Added a way to give Mario's cap and shirt individual colors.
- Added settings to change Mario's glove colors.
- Added a setting to disable the "M" logo on Mario's cap.
- Added the "Save Lives" setting, which allows you to save the number of lives you got to your save file.
- Added the "Better Enemies" setting, which makes some of the enemies (specifically  Boos, clams, and tiny Goombas) less annoying to deal with.
- Added the "Fix Exploits" setting, which fixes several exploits in the game like the bomb clip, hands-free holding, and the Backwards Long Jump.

### Changes:
- Completely overhauled the custom camera mode. It should now feel much more natural to use and behave much closer to the cameras of more modern 3D platformers.
- Updated the codebase to include the latest commits to the sm64-port repository, and made countless technical changes and fixes in the process. This ideally shouldn't make any visible differences in gameplay.
- Made Mario crouch faster with the \"Improved Controls\" setting enabled.
- Made it easier to do long jumps with the \"Improved Controls\" setting.
- Made jumping out of water easier with the \"Improved Swimming\" setting.
- Made collecting a star with the "Stay in Course After Getting a Star" setting enabled refill your health.
- Replaced the "Disable Low-Poly Models" setting with a "Level of Detail" setting.
- Renamed the "Make It Easier to Talk to the NPCs" setting to "Better NPCs" for consistency.
- Removed the "Disable Repeat Boo Messages" setting, as it's now a part of the "Better Enemies" setting.
- Removed the "Fix BLJ" and "Fix the Bomb Clip" settings, as they are now a part of the "Fix Exploits" setting.
- Reorganized the settings a bit.
- Rewrote the descriptions of a majority of the settings.
- Altered the default presets slightly.

### Fixes:
- Fixed a bug that would cause the level progression to break when "Tie Bowser's Sub to Missions" and "Stay in Course After Getting a Star" settings are both enabled.
- Fixed custom player colors affecting other objects in the game.
- Made fixes mouse movement in the Mario's face screen.
- Made Mario's face not get affected by the custom player colors.
- Fixed some inconsistencies with some internal setting names, which would result in with unpredictable behavior.

### Launcher:
- Made the launcher load the recommended preset value when a setting is missing from the settings file. This should fix many issues caused by upgrading the game from older versions.
- Fixed incorrect preset loading behavior and reverted it back to how it functioned prior to v2.1.0.
- Made the launcher reload settings after closing the game.
- Fixed the menu position incorrectly moving around when you minimize the launcher window while it's in fullscreen.
- Added all the new option types for the new settings fields.
