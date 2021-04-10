#ifndef CONTROLLER_KEYBOARD_H
#define CONTROLLER_KEYBOARD_H

#include <stdbool.h>
#include "controller_api.h"

#ifdef __cplusplus
extern "C" {
#endif
bool keyboard_on_key_down(int scancode);
bool keyboard_on_key_up(int scancode);
void keyboard_on_all_keys_up(void);
void keyboard_on_mouse_move(long x, long y);
void keyboard_on_mouse_press(s8 left, s8 right, s8 middle, s8 wheel);
#ifdef __cplusplus
}
#endif

extern struct ControllerAPI controller_keyboard;

#endif
