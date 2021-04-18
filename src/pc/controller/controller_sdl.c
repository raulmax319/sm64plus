#if !defined(_WIN32) && !defined(_WIN64)

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include <SDL2/SDL.h>

#include <ultra64.h>

#include "controller_api.h"

#include "game/settings.h"

#define DEADZONE_LEFT gControllerLeftDeadzone * 10
#define DEADZONE_RIGHT gControllerRightDeadzone * 10

static bool init_ok;
static SDL_GameController *sdl_cntrl;

static void controller_sdl_init(void) {
    if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0) {
        fprintf(stderr, "SDL init error: %s\n", SDL_GetError());
        return;
    }

    init_ok = true;
}

static void controller_sdl_read(OSContPad *pad) {
    if (!init_ok) {
        return;
    }

    SDL_GameControllerUpdate();

    if (sdl_cntrl != NULL && !SDL_GameControllerGetAttached(sdl_cntrl)) {
        SDL_GameControllerClose(sdl_cntrl);
        sdl_cntrl = NULL;
    }
    if (sdl_cntrl == NULL) {
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            if (SDL_IsGameController(i)) {
                sdl_cntrl = SDL_GameControllerOpen(i);
                if (sdl_cntrl != NULL) {
                    break;
                }
            }
        }
        if (sdl_cntrl == NULL) {
            return;
        }
    }

    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_START)) pad->button |= configButtonStart;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_BACK)) pad->button |= configButtonSelect;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_LEFTSHOULDER)) pad->button |= configButtonL;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) pad->button |= configButtonR;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_A)) pad->button |= configButtonA;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_B)) pad->button |= configButtonB;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_X)) pad->button |= configButtonX;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_Y)) pad->button |= configButtonY;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_LEFTSTICK)) pad->button |= configButtonThumbLeft;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_RIGHTSTICK)) pad->button |= configButtonThumbRight;

    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_DPAD_UP)) pad->button |= U_JPAD;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_DPAD_DOWN)) pad->button |= D_JPAD;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) pad->button |= L_JPAD;
    if (SDL_GameControllerGetButton(sdl_cntrl, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) pad->button |= R_JPAD;

    int16_t leftx = SDL_GameControllerGetAxis(sdl_cntrl, SDL_CONTROLLER_AXIS_LEFTX);
    int16_t lefty = SDL_GameControllerGetAxis(sdl_cntrl, SDL_CONTROLLER_AXIS_LEFTY);
    int16_t rightx = SDL_GameControllerGetAxis(sdl_cntrl, SDL_CONTROLLER_AXIS_RIGHTX);
    int16_t righty = SDL_GameControllerGetAxis(sdl_cntrl, SDL_CONTROLLER_AXIS_RIGHTY);

    int16_t ltrig = SDL_GameControllerGetAxis(sdl_cntrl, SDL_CONTROLLER_AXIS_TRIGGERLEFT);
    int16_t rtrig = SDL_GameControllerGetAxis(sdl_cntrl, SDL_CONTROLLER_AXIS_TRIGGERRIGHT);

#ifdef TARGET_WEB
    // Firefox has a bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1606562
    // It sets down y to 32768.0f / 32767.0f, which is greater than the allowed 1.0f,
    // which SDL then converts to a int16_t by multiplying by 32767.0f, which overflows into -32768.
    // Maximum up will hence never become -32768 with the current version of SDL2,
    // so this workaround should be safe in compliant browsers.
    if (lefty == -32768) {
        lefty = 32767;
    }
    if (righty == -32768) {
        righty = 32767;
    }
#endif

    if (gImprovedCamera) {
        uint32_t magnitude_sq2 = (uint32_t)(rightx * rightx);
        if (magnitude_sq2 > (uint32_t)(DEADZONE_RIGHT * DEADZONE_RIGHT)) {
            pad->stick2_x = rightx / 409;
        }
    }
    else {
        if (rightx < -0x4000) pad->button |= L_CBUTTONS;
        if (rightx > 0x4000) pad->button |= R_CBUTTONS;
    }

    if (gVerticalCamera) {
        uint32_t magnitude_sq2 = (uint32_t)(righty * righty);
        if (magnitude_sq2 > (uint32_t)(DEADZONE_RIGHT * DEADZONE_RIGHT)) {
            pad->stick2_y = righty / 409;
        }
    }
    else {
        if (righty < -0x4000) pad->button |= U_CBUTTONS;
        if (righty > 0x4000) pad->button |= D_CBUTTONS;
    }

    if (ltrig > 30 * 256) pad->button |= configButtonZL;
    if (rtrig > 30 * 256) pad->button |= configButtonZR;

    uint32_t magnitude_sq = (uint32_t)(leftx * leftx) + (uint32_t)(lefty * lefty);
    if (magnitude_sq > (uint32_t)(DEADZONE_LEFT * DEADZONE_LEFT)) {
        // Game expects stick coordinates within -80..80
        // 32768 / 409 = ~80
        pad->stick_x = leftx / 409;
        pad->stick_y = -lefty / 409;
    }
}

struct ControllerAPI controller_sdl = {
    controller_sdl_init,
    controller_sdl_read
};

#endif
