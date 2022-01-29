// configfile.c - handles loading and saving the configuration options
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "configfile.h"
#include "../game/settings.h"
#include "../game/main.h"

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

enum ConfigOptionType {
    CONFIG_TYPE_BOOL,
    CONFIG_TYPE_UINT,
    CONFIG_TYPE_FLOAT,
    CONFIG_TYPE_SECTION
};

struct ConfigOption {
    const char *name;
    enum ConfigOptionType type;
    union {
        bool *boolValue;
        unsigned int *uintValue;
        float *floatValue;
    };
};

static const struct ConfigOption options[] = {
    { .name = "DISPLAY", .type = CONFIG_TYPE_SECTION },
    { .name = "fullscreen", .type = CONFIG_TYPE_BOOL, .boolValue = &configFullscreen },
    { .name = "default_monitor", .type = CONFIG_TYPE_UINT, .uintValue = &configDefaultMonitor },
    { .name = "window_width", .type = CONFIG_TYPE_UINT, .uintValue = &configWindowWidth },
    { .name = "window_height", .type = CONFIG_TYPE_UINT, .uintValue = &configWindowHeight },
    { .name = "custom_fullscreen_resolution", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomFullscreenResolution },
    { .name = "fullscreen_width", .type = CONFIG_TYPE_UINT, .uintValue = &configFullscreenWidth },
    { .name = "fullscreen_height", .type = CONFIG_TYPE_UINT, .uintValue = &configFullscreenHeight },
#if defined(_WIN32) || defined(_WIN64)
    { .name = "custom_internal_resolution", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomInternalResolution },
    { .name = "internal_resolution_width", .type = CONFIG_TYPE_UINT, .uintValue = &configInternalResolutionWidth },
    { .name = "internal_resolution_height", .type = CONFIG_TYPE_UINT, .uintValue = &configInternalResolutionHeight },
#endif
    { .name = "graphics_backend", .type = CONFIG_TYPE_UINT, .uintValue = &configGraphicsBackend },

    { .name = "AUDIO", .type = CONFIG_TYPE_SECTION },
    { .name = "overall_volume", .type = CONFIG_TYPE_FLOAT, .floatValue = &configOverallVolume },
    { .name = "music_volume", .type = CONFIG_TYPE_FLOAT, .floatValue = &configSeqVolume[0] },
    { .name = "jingle_volume", .type = CONFIG_TYPE_FLOAT, .floatValue = &configSeqVolume[1] },
    { .name = "sound_volume", .type = CONFIG_TYPE_FLOAT, .floatValue = &configSeqVolume[2] },

    { .name = "GRAPHICS", .type = CONFIG_TYPE_SECTION },
    { .name = "60fps", .type = CONFIG_TYPE_BOOL, .boolValue = &config60FPS },
    { .name = "disable_draw_distance", .type = CONFIG_TYPE_BOOL, .boolValue = &configDisableDrawDistance },
    { .name = "draw_distance_multiplier", .type = CONFIG_TYPE_FLOAT, .floatValue = &configDrawDistanceMultiplier },
    { .name = "level_of_detail", .type = CONFIG_TYPE_UINT, .uintValue = &configLevelOfDetail },
    { .name = "texture_filtering", .type = CONFIG_TYPE_UINT, .uintValue = &configTextureFiltering },
    { .name = "noise_type", .type = CONFIG_TYPE_UINT, .uintValue = &configNoiseType },
    { .name = "force_4by3", .type = CONFIG_TYPE_BOOL, .boolValue = &configForce4by3 },

    { .name = "CONTROLS", .type = CONFIG_TYPE_SECTION },
    { .name = "improved_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &configImprovedControls },
    { .name = "improved_swimming", .type = CONFIG_TYPE_BOOL, .boolValue = &configImprovedSwimming },
    { .name = "improved_hanging", .type = CONFIG_TYPE_BOOL, .boolValue = &configImprovedHanging },
    { .name = "enemy_bouncing", .type = CONFIG_TYPE_BOOL, .boolValue = &configEnemyBouncing },
    { .name = "dpad_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &configDpadControls },
    { .name = "full_air_control", .type = CONFIG_TYPE_BOOL, .boolValue = &configFullAirControl },
    { .name = "fix_blj", .type = CONFIG_TYPE_BOOL, .boolValue = &configDisableBLJ },

    { .name = "GAMEPLAY", .type = CONFIG_TYPE_SECTION },
    { .name = "fix_collision_bugs", .type = CONFIG_TYPE_BOOL, .boolValue = &configFixCollisionBugs },
    { .name = "fix_various_bugs", .type = CONFIG_TYPE_BOOL, .boolValue = &configFixVariousBugs },
    { .name = "make_some_items_respawn", .type = CONFIG_TYPE_BOOL, .boolValue = &configRespawnCertainItems },
    { .name = "remove_annoying_warps", .type = CONFIG_TYPE_BOOL, .boolValue = &configRemoveAnnoyingWarps },
    { .name = "improve_powerups", .type = CONFIG_TYPE_BOOL, .boolValue = &configImprovePowerups },
    { .name = "better_blast_away_the_wall", .type = CONFIG_TYPE_BOOL, .boolValue = &configBetterBlastAwayTheWall },
    { .name = "disable_repeat_boo_messages", .type = CONFIG_TYPE_BOOL, .boolValue = &configDisableBooDialogue },
    { .name = "make_it_easier_to_talk_to_the_npcs", .type = CONFIG_TYPE_BOOL, .boolValue = &configTalkEasier },
    { .name = "disable_fall_damage", .type = CONFIG_TYPE_BOOL, .boolValue = &configDisableFallDamage },
    { .name = "allow_leaving_the_level_at_any_time", .type = CONFIG_TYPE_BOOL, .boolValue = &configLeaveAnyTime },
    { .name = "make_secrets_visible", .type = CONFIG_TYPE_BOOL, .boolValue = &configVisibleSecrets },
    { .name = "fix_the_bomb_clip", .type = CONFIG_TYPE_BOOL, .boolValue = &configFixBombClip },

    { .name = "PROGRESSION", .type = CONFIG_TYPE_SECTION },
    { .name = "tie_bowsers_sub_to_missions", .type = CONFIG_TYPE_BOOL, .boolValue = &configBowsersSub },
    { .name = "stay_in_course_after_getting_a_star", .type = CONFIG_TYPE_UINT, .uintValue = &configStayInCourse },
    { .name = "skip_mission_select", .type = CONFIG_TYPE_BOOL, .boolValue = &configSkipMissionSelect },
    { .name = "auto_switch_to_the_next_mission", .type = CONFIG_TYPE_BOOL, .boolValue = &configSwitchToNextMission },
    { .name = "skip_cutscenes", .type = CONFIG_TYPE_BOOL, .boolValue = &configSkipCutscenes },

    { .name = "CAMERA", .type = CONFIG_TYPE_SECTION },
    { .name = "center_camera_button", .type = CONFIG_TYPE_BOOL, .boolValue = &configCenterCameraButton },
    { .name = "horizontal_analog_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &gImprovedCamera },
    { .name = "vertical_analog_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &gVerticalCamera },
    { .name = "invert_horizontal_camera_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &gInvertedCamera },
    { .name = "invert_vertical_camera_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &gInvertedVerticalCamera },
    { .name = "analog_camera_speed", .type = CONFIG_TYPE_FLOAT, .floatValue = &gCameraSpeed },
    { .name = "additional_camera_distance", .type = CONFIG_TYPE_FLOAT, .floatValue = &gAdditionalCameraDistance },
    { .name = "additional_fov", .type = CONFIG_TYPE_FLOAT, .floatValue = &gAdditionalFOV },

    { .name = "CUSTOM CAMERA", .type = CONFIG_TYPE_SECTION },
    { .name = "custom_camera_mode", .type = CONFIG_TYPE_UINT, .uintValue = &configCustomCameraMode },
    { .name = "auto_pan_custom_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomCameraPan },
    { .name = "auto_tilt_custom_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomCameraTilt },
    { .name = "auto_rotate_custom_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomCameraRotation },
    { .name = "custom_camera_collisions", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomCameraCollisions },
    { .name = "default_custom_camera_distance", .type = CONFIG_TYPE_FLOAT, .floatValue = &configCustomCameraDistanceDefault },
    { .name = "zoomed_out_custom_camera_distance", .type = CONFIG_TYPE_FLOAT, .floatValue = &configCustomCameraDistanceZoomedOut },

    { .name = "HUD AND UI", .type = CONFIG_TYPE_SECTION },
    { .name = "add_quit_option", .type = CONFIG_TYPE_BOOL, .boolValue = &configQuitOption },
    { .name = "hud_layout", .type = CONFIG_TYPE_UINT, .uintValue = &configHudLayout },
    { .name = "4by3_hud", .type = CONFIG_TYPE_BOOL, .boolValue = &config4by3Hud },
    { .name = "show_the_collected_stars", .type = CONFIG_TYPE_BOOL, .boolValue = &gHudStars },
    { .name = "add_zeroes_to_counters", .type = CONFIG_TYPE_BOOL, .boolValue = &configAddZeroes },
    { .name = "always_show_the_100_coin_star", .type = CONFIG_TYPE_BOOL, .boolValue = &gShow100CoinStar },
    { .name = "always_show_the_health_meter", .type = CONFIG_TYPE_BOOL, .boolValue = &gAlwaysShowHealth },
    { .name = "hud_filtering", .type = CONFIG_TYPE_BOOL, .boolValue = &gHUDFiltering },
    { .name = "hide_hud", .type = CONFIG_TYPE_BOOL, .boolValue = &gHideHud },

    { .name = "MOUSE", .type = CONFIG_TYPE_SECTION },
    { .name = "mouse_support", .type = CONFIG_TYPE_BOOL, .boolValue = &gMouseCam },
    { .name = "mouse_sensitivity", .type = CONFIG_TYPE_FLOAT, .floatValue = &gMouseSensitivity },
    { .name = "left_mouse_button_action", .type = CONFIG_TYPE_UINT, .uintValue = &configMouseLeft },
    { .name = "right_mouse_button_action", .type = CONFIG_TYPE_UINT, .uintValue = &configMouseRight },
    { .name = "middle_mouse_button_action", .type = CONFIG_TYPE_UINT, .uintValue = &configMouseMiddle },
    { .name = "mouse_wheel_up_action", .type = CONFIG_TYPE_UINT, .uintValue = &configMouseWheelUp },
    { .name = "mouse_wheel_down_action", .type = CONFIG_TYPE_UINT, .uintValue = &configMouseWheelDown },

    { .name = "EXTRA MOVES", .type = CONFIG_TYPE_SECTION },
    { .name = "wall_sliding", .type = CONFIG_TYPE_BOOL, .boolValue = &gWallSliding },
    { .name = "ground_pound_jump", .type = CONFIG_TYPE_BOOL, .boolValue = &gGroundPoundJump },
    { .name = "sunshine_dive_hop", .type = CONFIG_TYPE_BOOL, .boolValue = &gSunshineDive },
    { .name = "odyssey_ground_pound_dive", .type = CONFIG_TYPE_BOOL, .boolValue = &gOdysseyDive },
    { .name = "odyssey_rolling", .type = CONFIG_TYPE_BOOL, .boolValue = &configRolling },
    { .name = "flashback_ground_pound", .type = CONFIG_TYPE_BOOL, .boolValue = &gFlashbackPound },

    { .name = "RESTORATIONS", .type = CONFIG_TYPE_SECTION },
    { .name = "enable_the_unused_pyramid_cutscene", .type = CONFIG_TYPE_BOOL, .boolValue = &configUnusedPyramidCutscene },
    { .name = "restore_unused_sound_effects", .type = CONFIG_TYPE_BOOL, .boolValue = &configRestoreUnusedSounds },
    { .name = "restore_mother_penguins_sad_eyes", .type = CONFIG_TYPE_BOOL, .boolValue = &gPenguinSadEyes },
    { .name = "replace_triple_jump_with_twirl", .type = CONFIG_TYPE_BOOL, .boolValue = &gTwirlTripleJump },
    { .name = "use_beta_like_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &configBetaLikeCamera },
    { .name = "make_mario_sparkle_at_course_start", .type = CONFIG_TYPE_BOOL, .boolValue = &gSpawnSparkles },
    { .name = "replace_keys_with_stars_when_collected", .type = CONFIG_TYPE_BOOL, .boolValue = &gReplaceKeysWithStars },
    
    { .name = "BONUS MODES", .type = CONFIG_TYPE_SECTION },
    { .name = "infinite_lives_mode", .type = CONFIG_TYPE_UINT, .uintValue = &gLifeMode },
    { .name = "encore_mode", .type = CONFIG_TYPE_UINT, .uintValue = &gEncoreMode },
    { .name = "green_demon_mode", .type = CONFIG_TYPE_UINT, .uintValue = &gGreenDemon },
    { .name = "no_healing_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gNoHealingMode },
    { .name = "hard_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gHardSave },
    { .name = "daredevil_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gDaredevilSave },
    { .name = "permadeath_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gHardcoreSave },
    { .name = "casual_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gCasualMode },

    { .name = "COLORS", .type = CONFIG_TYPE_SECTION },
    { .name = "color_hat_main_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHatRLight },
    { .name = "color_hat_main_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHatGLight },
    { .name = "color_hat_main_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHatBLight },
    { .name = "color_hat_shading_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHatRDark },
    { .name = "color_hat_shading_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHatGDark },
    { .name = "color_hat_shading_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHatBDark },
    { .name = "color_overalls_main_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorOverallsRLight },
    { .name = "color_overalls_main_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorOverallsGLight },
    { .name = "color_overalls_main_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorOverallsBLight },
    { .name = "color_overalls_shading_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorOverallsRDark },
    { .name = "color_overalls_shading_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorOverallsGDark },
    { .name = "color_overalls_shading_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorOverallsBDark },
    { .name = "color_shoes_main_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorShoesRLight },
    { .name = "color_shoes_main_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorShoesGLight },
    { .name = "color_shoes_main_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorShoesBLight },
    { .name = "color_shoes_shading_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorShoesRDark },
    { .name = "color_shoes_shading_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorShoesGDark },
    { .name = "color_shoes_shading_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorShoesBDark },
    { .name = "color_skin_main_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorSkinRLight },
    { .name = "color_skin_main_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorSkinGLight },
    { .name = "color_skin_main_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorSkinBLight },
    { .name = "color_skin_shading_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorSkinRDark },
    { .name = "color_skin_shading_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorSkinGDark },
    { .name = "color_skin_shading_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorSkinBDark },
    { .name = "color_hair_main_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHairRLight },
    { .name = "color_hair_main_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHairGLight },
    { .name = "color_hair_main_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHairBLight },
    { .name = "color_hair_shading_r", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHairRDark },
    { .name = "color_hair_shading_g", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHairGDark },
    { .name = "color_hair_shading_b", .type = CONFIG_TYPE_UINT, .uintValue = &configColorHairBDark },

    { .name = "CHEATS", .type = CONFIG_TYPE_SECTION },
    { .name = "level_select", .type = CONFIG_TYPE_BOOL, .boolValue = &gDebugLevelSelect },
    { .name = "debug_movement_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gDebugMovementMode },
    { .name = "debug_cap_changer", .type = CONFIG_TYPE_BOOL, .boolValue = &gDebugCapChanger },
    { .name = "moon_jump", .type = CONFIG_TYPE_UINT, .uintValue = &configMoonJump },
    { .name = "blj_everywhere", .type = CONFIG_TYPE_UINT, .uintValue = &configBLJEverywhere },
    { .name = "god_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &configGodMode },
    { .name = "hyperspeed_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &configHyperspeedMode },
    { .name = "no_cannon_limits", .type = CONFIG_TYPE_BOOL, .boolValue = &gFlexibleCannons },
    { .name = "coins_required_for_the_coin_stars", .type = CONFIG_TYPE_UINT, .uintValue = &configCoinStarCoins },

    { .name = "FOR FUN", .type = CONFIG_TYPE_SECTION },
    { .name = "paper_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gPaperMode },
    { .name = "fx_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gFXMode },
#if defined(_WIN32) || defined(_WIN64)
    { .name = "wireframe_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gWireframeMode },
#endif
    { .name = "disable_lighting", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableLighting },

    { .name = "ADVANCED", .type = CONFIG_TYPE_SECTION },
    { .name = "show_debug_display", .type = CONFIG_TYPE_BOOL, .boolValue = &gShowDebugText },
    { .name = "show_debug_profiler", .type = CONFIG_TYPE_BOOL, .boolValue = &gShowProfiler },
    { .name = "fullscreen_refresh_rate", .type = CONFIG_TYPE_UINT, .uintValue = &configFullscreenRefreshRate },

    { .name = "INPUT MAPPING", .type = CONFIG_TYPE_SECTION },
    { .name = "button_a", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonA },
    { .name = "button_b", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonB },
    { .name = "button_x", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonX },
    { .name = "button_y", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonY },
    { .name = "button_start", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonStart },
    { .name = "button_select", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonSelect },
    { .name = "button_l", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonL },
    { .name = "button_r", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonR },
    { .name = "button_zl", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonZL },
    { .name = "button_zr", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonZR },
    { .name = "button_thumbleft", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonThumbLeft },
    { .name = "button_thumbright", .type = CONFIG_TYPE_UINT, .uintValue = &configButtonThumbRight },
    { .name = "left_analog_stick_deadzone", .type = CONFIG_TYPE_UINT, .uintValue = &gControllerLeftDeadzone },
    { .name = "right_analog_stick_deadzone", .type = CONFIG_TYPE_UINT, .uintValue = &gControllerRightDeadzone },

    { .name = "KEY MAPPING", .type = CONFIG_TYPE_SECTION },
    { .name = "key_a", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyA },
    { .name = "key_b", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyB },
    { .name = "key_start", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyStart },
    { .name = "key_l", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyL },
    { .name = "key_r", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyR },
    { .name = "key_z", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyZ },
    { .name = "key_cup", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyCUp },
    { .name = "key_cdown", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyCDown },
    { .name = "key_cleft", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyCLeft },
    { .name = "key_cright", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyCRight },
    { .name = "key_stickup", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyStickUp },
    { .name = "key_stickdown", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyStickDown },
    { .name = "key_stickleft", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyStickLeft },
    { .name = "key_stickright", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyStickRight },
    { .name = "key_walktrigger", .type = CONFIG_TYPE_UINT, .uintValue = &configKeyWalk },
};

// Reads an entire line from a file (excluding the newline character) and returns an allocated string
// Returns NULL if no lines could be read from the file
static char *read_file_line(FILE *file) {
    char *buffer;
    size_t bufferSize = 8;
    size_t offset = 0; // offset in buffer to write

    buffer = malloc(bufferSize);
    while (1) {
        // Read a line from the file
        if (fgets(buffer + offset, bufferSize - offset, file) == NULL) {
            free(buffer);
            return NULL; // Nothing could be read.
        }
        offset = strlen(buffer);
        assert(offset > 0);

        // If a newline was found, remove the trailing newline and exit
        if (buffer[offset - 1] == '\n') {
            buffer[offset - 1] = '\0';
            break;
        }

        if (feof(file)) // EOF was reached
            break;

        // If no newline or EOF was reached, then the whole line wasn't read.
        bufferSize *= 2; // Increase buffer size
        buffer = realloc(buffer, bufferSize);
        assert(buffer != NULL);
    }

    return buffer;
}

// Returns the position of the first character we shouldn't ignore
static char *skip_whitespace(char *str) {
    while (isspace(*str) || *str == '=' || *str == '\"')
        str++;
    return str;
}

// NULL-terminates the current whitespace-delimited word, and returns a pointer to the next word
static char *word_split(char *str) {
    // Precondition: str must not point to whitespace
    assert(!isspace(*str));

    if (*str == '\"')
        str++;

    // Find either the next whitespace char or end of string
    while (!isspace(*str) && *str != '\0' && *str != '=' && *str != '\"')
        str++;
    if (*str == '\0') // End of string
        return str;

    // Terminate current word
    *(str++) = '\0';

    // Skip whitespace to next word
    return skip_whitespace(str);
}

// Splits a string into words, and stores the words into the 'tokens' array
// 'maxTokens' is the length of the 'tokens' array
// Returns the number of tokens parsed
static unsigned int tokenize_string(char *str, int maxTokens, char **tokens) {
    int count = 0;

    str = skip_whitespace(str);
    while (str[0] != '\0' && count < maxTokens) {
        if ((str[count] == ';') || (str[count] == '#'))
            break;
        if (str[count] == '\"') {
            str[count]++;
        }
        tokens[count] = str;
        str = word_split(str);
        count++;
    }
    return count;
}

// Loads the config file specified by 'filename'
void configfile_load(const char *filename) {
    FILE *file;
    char *line;

    printf("Loading configuration from '%s'\n", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        // Create a new config file and save defaults
        printf("Config file '%s' not found. Creating it.\n", filename);
        configfile_save(filename);
        return;
    }

    // Go through each line in the file
    while ((line = read_file_line(file)) != NULL) {
        char *p = line;
        char *tokens[2];
        int numTokens;

        while (isspace(*p))
            p++;
        if ((*p == '[') || (*p == '\n'))
            continue;
        numTokens = tokenize_string(p, 2, tokens);
        if (numTokens != 0) {
            if (numTokens == 2) {
                const struct ConfigOption *option = NULL;

                for (unsigned int i = 0; i < ARRAY_LEN(options); i++) {
                    if (strcmp(tokens[0], options[i].name) == 0) {
                        option = &options[i];
                        break;
                    }
                }
                if (option == NULL)
                    printf("unknown option '%s'\n", tokens[0]);
                else {
                    switch (option->type) {
                        case CONFIG_TYPE_BOOL:
                            if (strcmp(tokens[1], "true") == 0)
                                *option->boolValue = true;
                            else if (strcmp(tokens[1], "false") == 0)
                                *option->boolValue = false;
                            break;
                        case CONFIG_TYPE_UINT:
                            sscanf(tokens[1], "%u", option->uintValue);
                            break;
                        case CONFIG_TYPE_FLOAT:
                            sscanf(tokens[1], "%f", option->floatValue);
                            break;
                        default:
                            assert(0); // bad type
                    }
                    printf("option: '%s', value: '%s'\n", tokens[0], tokens[1]);
                }
            } else
                puts("error: expected value");
        }
        free(line);
    }

    fclose(file);
}

// Writes the config file to 'filename'
void configfile_save(const char *filename) {
    FILE *file;

    char *dir = malloc(128);

    printf("Saving configuration to '%s'\n", filename);

#ifdef __linux__
    strcat(dir, "/");
    char* copy = strdup(filename);
    strcat(dir, strtok(copy + 1, "/"));
    free(copy);
    mkdir(dir, 0777);
#endif

    file = fopen(filename, "w");
    if (file == NULL) {
        // error
        return;
    }

    for (unsigned int i = 0; i < ARRAY_LEN(options); i++) {
        const struct ConfigOption *option = &options[i];

        switch (option->type) {
            case CONFIG_TYPE_BOOL:
                fprintf(file, "%s = \"%s\"\n", option->name, *option->boolValue ? "true" : "false");
                break;
            case CONFIG_TYPE_UINT:
                fprintf(file, "%s = \"%u\"\n", option->name, *option->uintValue);
                break;
            case CONFIG_TYPE_FLOAT:
                fprintf(file, "%s = \"%f\"\n", option->name, *option->floatValue);
                break;
            case CONFIG_TYPE_SECTION:
                /*if (i != 0)
                    fprintf(file, "\n", option->name);*/
                fprintf(file, "[%s]\n", option->name);
                break;
            default:
                assert(0); // unknown type
        }
    }

    fclose(file);
}
