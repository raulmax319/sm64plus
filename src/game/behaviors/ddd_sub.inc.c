// ddd_sub.c.inc

void bhv_bowsers_sub_loop(void) {
    if (configStayInCourse == 2)
    {
        if (!configBowsersSub && (save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_2 | SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR))) 
        {
            obj_mark_for_deletion(o);
        }
        return;
    }

    if ((configBowsersSub && gCurrActNum >= 2) ||
    (!configBowsersSub && (save_file_get_flags() & (SAVE_FLAG_HAVE_KEY_2 | SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR))))
        obj_mark_for_deletion(o);
}