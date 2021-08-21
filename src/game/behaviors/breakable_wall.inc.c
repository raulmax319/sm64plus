// breakable_wall.c.inc

void bhv_wf_breakable_wall_loop(void) {
    if (gMarioStates[0].action == ACT_SHOT_FROM_CANNON) {
        cur_obj_become_tangible();
        if (obj_check_if_collided_with_object(o, gMarioObject)) {
            if (cur_obj_has_behavior(bhvWfBreakableWallRight))
                play_puzzle_jingle();
            if (configBetterBlastAwayTheWall && cur_obj_has_behavior(bhvWfBreakableWallLeft))
                play_sound(SOUND_MARIO_DOH, gMarioState->marioObj->header.gfx.cameraToObject);
            create_sound_spawner(SOUND_GENERAL_WALL_EXPLOSION);
            o->oInteractType = 8;
            if (configBetterBlastAwayTheWall && cur_obj_has_behavior(bhvWfBreakableWallRight)) {
                set_mario_action(gMarioState, ACT_SPAWN_SPIN_AIRBORNE, 0);
                set_camera_mode(gMarioState->area->camera, gMarioState->area->camera->defMode, 1);
                gMarioState->vel[1] = 32.0f;
            }
            else
                o->oDamageOrCoinValue = 1;
            obj_explode_and_spawn_coins(80.0f, 0);
        }
    } else
        cur_obj_become_intangible();
}
