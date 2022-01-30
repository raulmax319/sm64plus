#ifndef CONTROLLER_API
#define CONTROLLER_API

#include <ultra64.h>

struct ControllerAPI {
    void (*init)(void);
    void (*read)(OSContPad *pad);
    void (*rumble_play)(float str, float time);
    void (*rumble_stop)(void);
};

void controller_rumble_play(float str, float time);
void controller_rumble_stop(void);

#endif
