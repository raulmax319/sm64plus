#include <ultra64.h>

extern char* gTitleString;

extern s8 configFullscreen;
#if defined(_WIN32) || defined(_WIN64)
extern s8 configCustomFullscreenResolution;
extern unsigned int configFullscreenWidth;
extern unsigned int configFullscreenHeight;
extern unsigned int configFullscreenRefreshRate;
#endif
extern unsigned int configWindowWidth;
extern unsigned int configWindowHeight;
#if defined(_WIN32) || defined(_WIN64)
extern s8 configCustomInternalResolution;
extern unsigned int configInternalResolutionWidth;
extern unsigned int configInternalResolutionHeight;
#endif
extern unsigned int configGraphicsBackend;

extern float configSeqVolume[];

extern s8 g60FPS;
extern s8 gDisableDrawDistance;
extern float gDrawDistanceMultiplier;
extern s8 gDisableLowPoly;
extern unsigned int gTextureFiltering;
extern unsigned int gNoiseType;
extern s8 configForce4by3;

extern s8 gImprovedControls;
extern s8 gBackwardSpeedCap;
extern s8 gImprovedHanging;
extern s8 gDpadControls;
extern s8 gFullAirControl;
extern s8 gDisableBLJ;
extern s8 gDisableFallDamage;

extern s8 gFixVariousBugs;
extern s8 gRespawnBlueCoinSwitch;
extern s8 gRemoveAnnoyingWarps;
extern s8 gImprovePowerups;
extern s8 gDisableBooDialogue;
extern s8 gTalkEasier;
extern s8 gQuitOption;
extern unsigned int gStayInLevel;
extern s8 gSkipStarSelect;
extern s8 gRestartLevelAfterStar;
extern s8 gLeaveAnyTime;
extern s8 gVisibleSecrets;
extern s8 gFlexibleCannons;
extern s8 gSkipCutscenes;

extern s8 gImprovedCamera;
extern s8 gCenterCameraButton;
extern unsigned int gManualCamera;
extern s8 gSmarterManualCamera;
extern s8 gInvertedCamera;
extern float gCameraSpeed;
extern float gAdditionalCameraDistance;
extern float gAdditionalFOV;

extern unsigned int gHudStyle;
extern s8 gCenterHud;
extern s8 gHUDFiltering;
extern s8 gHudStars;
extern s8 gShow100CoinStar;
extern s8 gAlwaysShowHealth;
extern s8 gHideHud;

extern s8 gMouseCam;
extern float gMouseSensitivity;
extern unsigned int configMouseLeft;
extern unsigned int configMouseRight;
extern unsigned int configMouseMiddle;
extern unsigned int configMouseWheelUp;
extern unsigned int configMouseWheelDown;

extern s8 gWallSliding;
extern s8 gGroundPoundJump;
extern s8 gSunshineDive;
extern s8 gOdysseyDive;
extern s8 gFlashbackPound;

extern s8 gPyramidCutscene;
extern s8 gUnusedSounds;
extern s8 gPenguinSadEyes;
extern s8 gTwirlTripleJump;
extern s8 gSpawnSparkles;
extern s8 gReplaceKeysWithStars;

extern unsigned int gLifeMode;
extern unsigned int gEncoreMode;
extern s8 gGreenDemon;
extern s8 gHardSave;
extern s8 gDaredevilSave;
extern s8 gHardcoreSave;
extern s8 gCasualMode;

extern s8 gPaperMode;
extern s8 gFXMode;
#if defined(_WIN32) || defined(_WIN64)
extern s8 gWireframeMode;
#endif
extern s8 gDisableLighting;
extern s8 gForceLowPoly;

extern s8 gDebugMovementMode;
extern s8 gDebugCapChanger;
extern s8 gMoonJump;
extern s8 gVerticalCamera;

extern unsigned int configButtonA;
extern unsigned int configButtonB;
extern unsigned int configButtonX;
extern unsigned int configButtonY;
extern unsigned int configButtonStart;
extern unsigned int configButtonSelect;
extern unsigned int configButtonL;
extern unsigned int configButtonR;
extern unsigned int configButtonZL;
extern unsigned int configButtonZR;
extern unsigned int configButtonThumbLeft;
extern unsigned int configButtonThumbRight;
extern unsigned int gControllerLeftDeadzone;
extern unsigned int gControllerRightDeadzone;

extern unsigned int configKeyA;
extern unsigned int configKeyB;
extern unsigned int configKeyStart;
extern unsigned int configKeyL;
extern unsigned int configKeyR;
extern unsigned int configKeyZ;
extern unsigned int configKeyCUp;
extern unsigned int configKeyCDown;
extern unsigned int configKeyCLeft;
extern unsigned int configKeyCRight;
extern unsigned int configKeyStickUp;
extern unsigned int configKeyStickDown;
extern unsigned int configKeyStickLeft;
extern unsigned int configKeyStickRight;
extern unsigned int configKeyWalk;

extern s16 gCollectedStar;
extern s8 gMarioWillDie;
extern s8 stay_in_level();
extern s8 restart_level_after_star();