#include <ultra64.h>

s8 gBetterControls = 1;
s8 gDpadInput = 1;
s8 gAirTurn = 0;
s8 gDisableBLJ = 0;
s8 gDisableFallDamage = 0;
int gControllerDeadzone = 500;

s8 gCollisionFixes = 1;
s8 gRemoveAnnoyingWarps = 1;
s8 gDisableBooDialogue = 1;
s8 gSkipCutscenes = 0;
s8 gLeaveAnyTime = 0;
s8 gVisibleSecrets = 0;
s8 gFlexibleCannons = 0;
int gDontKick = 0;

s8 gModernWallJump = 1;
s8 gSunshineDive = 0;
s8 gOdysseyDive = 0;
s8 gFlashbackPound = 0;

s8 configFullscreen = 1;
int gCustomFullscreenResolution = 0;
int gFullscreenWidth = 1920;
int gFullscreenHeight = 1080;
int gFullscreenRefreshRate = 60;
int gWindowWidth = 1280;
int gWindowHeight = 720;
s8 gCustomInternalResolution = 1;
int gInternalResolutionWidth = 3840;
int gInternalResolutionHeight = 2160;
s8 gDrawPillarbox = 0;

s8 gDisableDrawDistance = 1;
s8 gNoLowPoly = 1;
int gDrawDistanceMultiplier = 4;
int gNoiseType = 0;
s8 gDisableFog = 0;
s8 gForceLowPoly = 0;
s8 gNearestNeighbor = 0;
s8 gFXMode = 0;

s8 gImprovedCamera = 1;
s8 gCenterCam = 1;
s8 gInvertedCamera = 0;
int gCameraSpeed = 32;
int gAdditionalCameraDistance = 0;
int gAdditionalFOV = 0;

int gNewHud = 2;
s8 gCenterHud = 0;
s8 gHUDFiltering = 0;
int gHUDUpscaling = 0;
s8 gAlwaysShowHealth = 0;
s8 gHideHud = 0;

s8 gTrapdoorSound = 1;

s8 gLifeMode = 0;
s8 gHardSave = 0;
s8 gHardcoreSave = 0;
s8 gGreenDemon = 0;
s8 gEncoreMode = 0;

s8 gDebugMovementMode = 0;

s8 gShow100CoinStar = 0;
int gTextureUpscaling = 0;

unsigned int configKeyA          = 0x26;
unsigned int configKeyB          = 0x33;
unsigned int configKeyStart      = 0x39;
unsigned int configKeyR          = 0x36;
unsigned int configKeyZ          = 0x25;
unsigned int configKeyCUp        = 0x148;
unsigned int configKeyCDown      = 0x150;
unsigned int configKeyCLeft      = 0x14B;
unsigned int configKeyCRight     = 0x14D;
unsigned int configKeyStickUp    = 0x11;
unsigned int configKeyStickDown  = 0x1F;
unsigned int configKeyStickLeft  = 0x1E;
unsigned int configKeyStickRight = 0x20;