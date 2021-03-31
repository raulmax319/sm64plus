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
    { .name = "custom_fullscreen_resolution", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomFullscreenResolution },
    { .name = "fullscreen_width", .type = CONFIG_TYPE_UINT, .uintValue = &configFullscreenWidth },
    { .name = "fullscreen_height", .type = CONFIG_TYPE_UINT, .uintValue = &configFullscreenHeight },
    { .name = "fullscreen_refresh_rate", .type = CONFIG_TYPE_UINT, .uintValue = &configFullscreenRefreshRate },
    { .name = "window_width", .type = CONFIG_TYPE_UINT, .uintValue = &configWindowWidth },
    { .name = "window_height", .type = CONFIG_TYPE_UINT, .uintValue = &configWindowHeight },
    { .name = "custom_internal_resolution", .type = CONFIG_TYPE_BOOL, .boolValue = &configCustomInternalResolution },
    { .name = "internal_resolution_width", .type = CONFIG_TYPE_UINT, .uintValue = &configInternalResolutionWidth },
    { .name = "internal_resolution_height", .type = CONFIG_TYPE_UINT, .uintValue = &configInternalResolutionHeight },
    { .name = "force_4by3", .type = CONFIG_TYPE_BOOL, .boolValue = &configForce4by3 },

    { .name = "CONTROLS", .type = CONFIG_TYPE_SECTION },
    { .name = "improved_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &gImprovedControls },
    { .name = "backward_speed_cap", .type = CONFIG_TYPE_BOOL, .boolValue = &gBackwardSpeedCap },
    { .name = "dpad_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &gDpadControls },
    { .name = "full_air_control", .type = CONFIG_TYPE_BOOL, .boolValue = &gFullAirControl },
    { .name = "disable_blj", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableBLJ },
    { .name = "disable_fall_damage", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableFallDamage },
    { .name = "analog_stick_deadzone", .type = CONFIG_TYPE_UINT, .uintValue = &gControllerDeadzone },

    { .name = "TWEAKS", .type = CONFIG_TYPE_SECTION },
    { .name = "stay_in_level_after_getting_a_star", .type = CONFIG_TYPE_UINT, .uintValue = &gStayInLevel },
    { .name = "fix_collision_errors", .type = CONFIG_TYPE_BOOL, .boolValue = &gCollisionFixes },
    { .name = "fix_manta_ray_rings", .type = CONFIG_TYPE_BOOL, .boolValue = &gFixMantaRayRings },
    { .name = "make_blue_coin_switches_respawn", .type = CONFIG_TYPE_BOOL, .boolValue = &gRespawnBlueCoinSwitch },
    { .name = "remove_annoying_warps", .type = CONFIG_TYPE_BOOL, .boolValue = &gRemoveAnnoyingWarps },
    { .name = "improve_metal_mario", .type = CONFIG_TYPE_BOOL, .boolValue = &gImprovedMetalCap },
    { .name = "disable_repeat_boo_messages", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableBooDialogue },
    { .name = "make_it_easier_to_talk_to_the_npcs", .type = CONFIG_TYPE_BOOL, .boolValue = &gTalkEasier },
    { .name = "add_a_quit_option_to_the_pause_menu", .type = CONFIG_TYPE_BOOL, .boolValue = &gQuitOption },
    { .name = "allow_leaving_the_level_at_any_time", .type = CONFIG_TYPE_BOOL, .boolValue = &gLeaveAnyTime },
    { .name = "show_the_100_coin_star_in_star_select", .type = CONFIG_TYPE_BOOL, .boolValue = &gShow100CoinStar },
    { .name = "make_secrets_visible", .type = CONFIG_TYPE_BOOL, .boolValue = &gVisibleSecrets },
    { .name = "allow_the_cannons_to_rotate_more", .type = CONFIG_TYPE_BOOL, .boolValue = &gFlexibleCannons },
    { .name = "skip_cutscenes", .type = CONFIG_TYPE_BOOL, .boolValue = &gSkipCutscenes },

    { .name = "CAMERA", .type = CONFIG_TYPE_SECTION },
    { .name = "analog_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &gImprovedCamera },
    { .name = "center_camera_button", .type = CONFIG_TYPE_BOOL, .boolValue = &gCenterCameraButton },
    { .name = "manual_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &gManualCamera },
    { .name = "invert_camera_controls", .type = CONFIG_TYPE_BOOL, .boolValue = &gInvertedCamera },
    { .name = "analog_camera_speed", .type = CONFIG_TYPE_FLOAT, .floatValue = &gCameraSpeed },
    { .name = "additional_camera_distance", .type = CONFIG_TYPE_FLOAT, .floatValue = &gAdditionalCameraDistance },
    { .name = "additional_fov", .type = CONFIG_TYPE_FLOAT, .floatValue = &gAdditionalFOV },

    { .name = "GRAPHICS", .type = CONFIG_TYPE_SECTION },
    { .name = "60fps", .type = CONFIG_TYPE_BOOL, .boolValue = &g60FPS },
    { .name = "disable_draw_distance", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableDrawDistance },
    { .name = "disable_low_poly_mario", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableLowPoly },
    { .name = "draw_distance_multiplier", .type = CONFIG_TYPE_FLOAT, .floatValue = &gDrawDistanceMultiplier },
    { .name = "noise_type", .type = CONFIG_TYPE_UINT, .uintValue = &gNoiseType },

    { .name = "HUD", .type = CONFIG_TYPE_SECTION },
    { .name = "hud_style", .type = CONFIG_TYPE_UINT, .uintValue = &gHudStyle },
    { .name = "4by3_hud", .type = CONFIG_TYPE_BOOL, .boolValue = &gCenterHud },
    { .name = "hud_filtering", .type = CONFIG_TYPE_BOOL, .boolValue = &gHUDFiltering },
    { .name = "hud_upscaling", .type = CONFIG_TYPE_UINT, .uintValue = &gHUDUpscaling },
    { .name = "always_show_the_health_meter", .type = CONFIG_TYPE_BOOL, .boolValue = &gAlwaysShowHealth },
    { .name = "show_the_you_got_a_star_text", .type = CONFIG_TYPE_BOOL, .boolValue = &gStarGetText },
    { .name = "hide_hud", .type = CONFIG_TYPE_BOOL, .boolValue = &gHideHud },

    { .name = "EXTRA MOVES", .type = CONFIG_TYPE_SECTION },
    { .name = "wall_sliding", .type = CONFIG_TYPE_BOOL, .boolValue = &gWallSliding },
    { .name = "ground_pound_jump", .type = CONFIG_TYPE_BOOL, .boolValue = &gGroundPoundJump },
    { .name = "sunshine_dive_hop", .type = CONFIG_TYPE_BOOL, .boolValue = &gSunshineDive },
    { .name = "odyssey_ground_pound_dive", .type = CONFIG_TYPE_BOOL, .boolValue = &gOdysseyDive },
    { .name = "flashback_ground_pound", .type = CONFIG_TYPE_BOOL, .boolValue = &gFlashbackPound },

    { .name = "RESTORATIONS", .type = CONFIG_TYPE_SECTION },
    { .name = "enable_the_unused_pyramid_cutscene", .type = CONFIG_TYPE_BOOL, .boolValue = &gPyramidCutscene },
    { .name = "enable_the_unused_trapdoor_sound", .type = CONFIG_TYPE_BOOL, .boolValue = &gTrapdoorSound },
    { .name = "replace_triple_jump_with_twirl", .type = CONFIG_TYPE_BOOL, .boolValue = &gTwirlTripleJump },
    { .name = "make_mario_sparkle_at_level_start", .type = CONFIG_TYPE_BOOL, .boolValue = &gSpawnSparkles },
    { .name = "replace_keys_with_stars_when_collected", .type = CONFIG_TYPE_BOOL, .boolValue = &gReplaceKeysWithStars },
    
    { .name = "BONUS MODES", .type = CONFIG_TYPE_SECTION },
    { .name = "infinite_lives_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gLifeMode },
    { .name = "encore_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gEncoreMode },
    { .name = "green_demon_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gGreenDemon },
    { .name = "hard_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gHardSave },
    { .name = "daredevil_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gDaredevilSave },
    { .name = "permadeath_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gHardcoreSave },

    { .name = "FOR FUN", .type = CONFIG_TYPE_SECTION },
    { .name = "fx_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gFXMode },
    { .name = "disable_lighting", .type = CONFIG_TYPE_BOOL, .boolValue = &gDisableLighting },
    { .name = "force_use_low_poly_mario", .type = CONFIG_TYPE_BOOL, .boolValue = &gForceLowPoly },
    { .name = "nearest_neighbor_filtering", .type = CONFIG_TYPE_BOOL, .boolValue = &gNearestNeighbor },

    { .name = "DEBUG", .type = CONFIG_TYPE_SECTION },
    { .name = "level_select", .type = CONFIG_TYPE_BOOL, .boolValue = &gDebugLevelSelect },
    { .name = "show_debug_display", .type = CONFIG_TYPE_BOOL, .boolValue = &gShowDebugText },
    { .name = "debug_movement_mode", .type = CONFIG_TYPE_BOOL, .boolValue = &gDebugMovementMode },
    { .name = "debug_cap_changer", .type = CONFIG_TYPE_BOOL, .boolValue = &gDebugCapChanger },
    { .name = "show_debug_profiler", .type = CONFIG_TYPE_BOOL, .boolValue = &gShowProfiler },
    { .name = "vertical_analog_camera", .type = CONFIG_TYPE_BOOL, .boolValue = &gVerticalCamera },
    { .name = "texture_upscaling", .type = CONFIG_TYPE_UINT, .uintValue = &gTextureUpscaling },

    { .name = "XINPUT MAPPING", .type = CONFIG_TYPE_SECTION },
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

    char *str = malloc(128);
    strcpy(str, getenv("LOCALAPPDATA"));
    strcat(str, filename);

    file = fopen(str, "r");
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

    printf("Saving configuration to '%s'\n", filename);

    char *str = malloc(128);
    strcpy(str, getenv("LOCALAPPDATA"));
    strcat(str, filename);

    file = fopen(str, "w");
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
