/*
#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
#include <dinput.h>

#include <ultra64.h>

#include "controller_api.h"
#include "game/settings.h"

// DirectInput stuff
extern HINSTANCE main_instance;
LPDIRECTINPUT8 lpdi = NULL;
LPDIRECTINPUTDEVICE8 lpdijoy = NULL;
GUID joystick_guid;
DIJOYSTATE joy_state;

BOOL CALLBACK enum_joysticks(LPCDIDEVICEINSTANCE lpddi, LPVOID guid_ptr) 
{
   *(GUID*)guid_ptr = lpddi->guidInstance; 

   return DIENUM_STOP;
}

static void directinput_init(void) {
    DirectInput8Create(main_instance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void **)&lpdi,NULL)

    lpdi->EnumDevices(DI8DEVCLASS_GAMECTRL, 
                     enum_joysticks, 
                     &joystick_guid, 
                     DIEDFL_ATTACHEDONLY); 

   LPDIRECTINPUTDEVICE lpdijoy_temp = NULL;

   lpdi->CreateDevice(joystick_guid, &lpdijoy, NULL);

   lpdijoy->SetCooperativeLevel(main_window_handle, 
	                  DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

   lpdijoy->SetDataFormat(&c_dfDIJoystick);

   DIPROPRANGE joy_axis_range;

   // Game expects stick coordinates within -80..80
   joy_axis_range.lMin = -80;
   joy_axis_range.lMax = 80;

   joy_axis_range.diph.dwSize       = sizeof(DIPROPRANGE); 
   joy_axis_range.diph.dwHeaderSize = sizeof(DIPROPHEADER); 
   joy_axis_range.diph.dwObj        = DIJOFS_X;
   joy_axis_range.diph.dwHow        = DIPH_BYOFFSET;

   lpdijoy->SetProperty(DIPROP_RANGE,&joy_axis_range.diph);

   // Same with the y axis
   joy_axis_range.lMin = -80;
   joy_axis_range.lMax = 80;

   joy_axis_range.diph.dwSize       = sizeof(DIPROPRANGE); 
   joy_axis_range.diph.dwHeaderSize = sizeof(DIPROPHEADER); 
   joy_axis_range.diph.dwObj        = DIJOFS_Y;
   joy_axis_range.diph.dwHow        = DIPH_BYOFFSET;

   lpdijoy->SetProperty(DIPROP_RANGE,&joy_axis_range.diph);

   DIPROPDWORD deadzone;

   deadzone.diph.dwSize       = sizeof(deadzone);
   deadzone.diph.dwHeaderSize = sizeof(deadzone.diph);
   deadzone.diph.dwObj        = DIJOFS_X;
   deadzone.diph.dwHow        = DIPH_BYOFFSET;

   deadzone.dwData            = gControllerLeftDeadzone;

   lpdijoy->SetProperty(DIPROP_DEADZONE,&deadzone.diph);

   deadzone.diph.dwSize       = sizeof(deadzone);
   deadzone.diph.dwHeaderSize = sizeof(deadzone.diph);
   deadzone.diph.dwObj        = DIJOFS_Y;
   deadzone.diph.dwHow        = DIPH_BYOFFSET;

   deadzone.dwData            = gControllerRightDeadzone;

   lpdijoy->SetProperty(DIPROP_DEADZONE,&deadzone.diph);

   lpdijoy->Acquire();
}

static void directinput_read(OSContPad *pad) {
    if (lpdijoy) {
        lpdijoy->Poll();
        lpdijoy->GetDeviceState(sizeof(DIJOYSTATE), (LPVOID)&joy_state);
    }
    else {
        memset(&joy_state, 0, sizeof(joy_state));
    } 

    if (joy_state.rgbButtons[0]) pad->button |= configButtonA;
    if (joy_state.rgbButtons[1]) pad->button |= configButtonB;
    if (joy_state.rgbButtons[2]) pad->button |= configButtonX;
    if (joy_state.rgbButtons[3]) pad->button |= configButtonY;
    if (joy_state.rgbButtons[4]) pad->button |= configButtonStart;
    if (joy_state.rgbButtons[5]) pad->button |= configButtonSelect;
    if (joy_state.rgbButtons[6]) pad->button |= configButtonL;
    if (joy_state.rgbButtons[7]) pad->button |= configButtonR;
    if (joy_state.rglSlider[0] > 16) pad->button |= configButtonZL;
    if (joy_state.rglSlider[1] > 16) pad->button |= configButtonZR;
    if (joy_state.rgbButtons[8]) pad->button |= configButtonThumbLeft;
    if (joy_state.rgbButtons[9]) pad->button |= configButtonThumbRight;

    if (joy_state.rgdwPOV[0]) pad->button |= L_JPAD;
    if (joy_state.rgdwPOV[1]) pad->button |= R_JPAD;
    if (joy_state.rgdwPOV[2]) pad->button |= U_JPAD;
    if (joy_state.rgdwPOV[3]) pad->button |= D_JPAD;

    if (!gImprovedCamera) {
        if (joy_state.lRx < -40) pad->button |= L_CBUTTONS;
        if (joy_state.lRy > 40) pad->button |= R_CBUTTONS;
    }
    if (!gVerticalCamera) {
        if (joy_state.lRx < -40) pad->button |= D_CBUTTONS;
        if (joy_state.lRy > 40) pad->button |= U_CBUTTONS;
    }

    pad->stick_x = joy_state.lX;
    pad->stick_y = joy_state.lY;

    if (gImprovedCamera) {
        pad->stick2_x = joy_state.lRx;
    }
    if (gVerticalCamera) {
        pad->stick2_y = joy_state.lRy;
    }
}

struct ControllerAPI controller_directinput = {
    directinput_init,
    directinput_read
};

#endif
*/