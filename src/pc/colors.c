#include "game/settings.h"

#define DEF_COLOR_LIGHT(name, r, g, b) \
    name[0][0] = r; name[0][1] = g; name[0][2] = b;
#define DEF_COLOR_DARK(name, r, g, b) \
    name[1][0] = r; name[1][1] = g; name[1][2] = b;

#define DEF_COLOR_RED(name) \
    name[0][0] = 255; name[0][1] = 39; name[0][2] = 0; \
    name[1][0] = 111; name[1][1] = 0; name[1][2] = 23;
#define DEF_COLOR_BLUE(name) \
    name[0][0] = 0; name[0][1] = 95; name[0][2] = 255; \
    name[1][0] = 23; name[1][1] = 0; name[1][2] = 127;
#define DEF_COLOR_WHITE(name) \
    name[0][0] = 255; name[0][1] = 255; name[0][2] = 255; \
    name[1][0] = 107; name[1][1] = 111; name[1][2] = 127;
#define DEF_COLOR_SHOES(name) \
    name[0][0] = 127; name[0][1] = 63; name[0][2] = 13; \
    name[1][0] = 63; name[1][1] = 11; name[1][2] = 3;
#define DEF_COLOR_SKIN(name) \
    name[0][0] = 254; name[0][1] = 199; name[0][2] = 127; \
    name[1][0] = 145; name[1][1] = 91; name[1][2] = 55;
#define DEF_COLOR_HAIR(name) \
    name[0][0] = 115; name[0][1] = 43; name[0][2] = 0; \
    name[1][0] = 63; name[1][1] = 11; name[1][2] = 0;

    
#define DEF_COLOR_GREEN(name) \
    name[0][0] = 31; name[0][1] = 255; name[0][2] = 0; \
    name[1][0] = 0; name[1][1] = 111; name[1][2] = 23;
#define DEF_COLOR_BLUE_ALT(name) \
    name[0][0] = 95; name[0][1] = 0; name[0][2] = 255; \
    name[1][0] = 39; name[1][1] = 0; name[1][2] = 127;
#define DEF_COLOR_YELLOW(name) \
    name[0][0] = 255; name[0][1] = 223; name[0][2] = 0; \
    name[1][0] = 127; name[1][1] = 95; name[1][2] = 0;
#define DEF_COLOR_PURPLE(name) \
    name[0][0] = 95; name[0][1] = 0; name[0][2] = 255; \
    name[1][0] = 63; name[1][1] = 0; name[1][2] = 127;
#define DEF_COLOR_ORANGE(name) \
    name[0][0] = 255; name[0][1] = 127; name[0][2] = 0; \
    name[1][0] = 127; name[1][1] = 55; name[1][2] = 0;
#define DEF_COLOR_BLACK(name) \
    name[0][0] = 63; name[0][1] = 67; name[0][2] = 73; \
    name[1][0] = 0; name[1][1] = 0; name[1][2] = 0;

void set_colors() {

    switch (configColorPalette) {
        case 1: // Default Mario
            DEF_COLOR_LIGHT(configColorCap, 255, 0, 0);
            DEF_COLOR_DARK (configColorCap, 127, 0, 0);

            DEF_COLOR_LIGHT(configColorShirt, 255, 0, 0);
            DEF_COLOR_DARK (configColorShirt, 127, 0, 0);

            DEF_COLOR_LIGHT(configColorOveralls, 0, 0, 255);
            DEF_COLOR_DARK (configColorOveralls, 0, 0, 127);
            
            DEF_COLOR_LIGHT(configColorGloves, 255, 255, 255);
            DEF_COLOR_DARK (configColorGloves, 127, 127, 127);
            
            DEF_COLOR_LIGHT(configColorShoes, 114, 28, 14);
            DEF_COLOR_DARK (configColorShoes, 57, 14, 7);
            
            DEF_COLOR_LIGHT(configColorSkin, 254, 193, 121);
            DEF_COLOR_DARK (configColorSkin, 127, 96, 60);
            
            DEF_COLOR_LIGHT(configColorHair, 115, 6, 0);
            DEF_COLOR_DARK (configColorHair, 57, 3, 0);
            break;

        case 2: // Mario Tweaked
            DEF_COLOR_RED(configColorCap);

            DEF_COLOR_RED(configColorShirt);

            DEF_COLOR_BLUE(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;

        case 3: // Fire Mario
            DEF_COLOR_RED(configColorCap);

            DEF_COLOR_WHITE(configColorShirt);

            DEF_COLOR_RED(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;
        
        case 4: // Classic Mario
            DEF_COLOR_RED(configColorCap);

            DEF_COLOR_BLUE(configColorShirt);

            DEF_COLOR_RED(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;
            
        case 5: // SMW Mario
            DEF_COLOR_LIGHT(configColorCap, 215, 51, 103);
            DEF_COLOR_DARK (configColorCap, 127, 19, 47);

            DEF_COLOR_LIGHT(configColorShirt, 215, 51, 103);
            DEF_COLOR_DARK (configColorShirt, 127, 19, 47);

            DEF_COLOR_LIGHT(configColorOveralls, 95, 171, 175);
            DEF_COLOR_DARK (configColorOveralls, 39, 67, 139);
            
            DEF_COLOR_LIGHT(configColorGloves, 255, 255, 255);
            DEF_COLOR_DARK (configColorGloves, 165, 129, 81);
            
            DEF_COLOR_LIGHT(configColorShoes, 195, 151, 67);
            DEF_COLOR_DARK (configColorShoes, 67, 43, 11);
            
            DEF_COLOR_LIGHT(configColorSkin, 255, 159, 147);
            DEF_COLOR_DARK (configColorSkin, 195, 99, 63);
            
            DEF_COLOR_LIGHT(configColorHair, 0, 0, 0);
            DEF_COLOR_DARK (configColorHair, 0, 0, 0);
            break;

        case 6: // Luigi
            DEF_COLOR_GREEN(configColorCap);

            DEF_COLOR_GREEN(configColorShirt);

            DEF_COLOR_BLUE_ALT(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;

        case 7: // Fire Luigi
            DEF_COLOR_GREEN(configColorCap);

            DEF_COLOR_WHITE(configColorShirt);

            DEF_COLOR_GREEN(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;

        case 8: // Classic Luigi
            DEF_COLOR_GREEN(configColorCap);

            DEF_COLOR_BLUE_ALT(configColorShirt);

            DEF_COLOR_GREEN(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;

        case 9: // SMW Luigi
            DEF_COLOR_LIGHT(configColorCap, 0, 255, 120);
            DEF_COLOR_DARK (configColorCap, 0, 135, 59);

            DEF_COLOR_LIGHT(configColorShirt, 0, 255, 120);
            DEF_COLOR_DARK (configColorShirt, 0, 135, 59);

            DEF_COLOR_LIGHT(configColorOveralls, 131, 71, 255);
            DEF_COLOR_DARK (configColorOveralls, 83, 19, 187);
            
            DEF_COLOR_LIGHT(configColorGloves, 255, 255, 255);
            DEF_COLOR_DARK (configColorGloves, 165, 129, 81);
            
            DEF_COLOR_LIGHT(configColorShoes, 195, 151, 67);
            DEF_COLOR_DARK (configColorShoes, 67, 43, 11);
            
            DEF_COLOR_LIGHT(configColorSkin, 255, 159, 147);
            DEF_COLOR_DARK (configColorSkin, 195, 99, 63);
            
            DEF_COLOR_LIGHT(configColorHair, 0, 0, 0);
            DEF_COLOR_DARK (configColorHair, 0, 0, 0);
            break;

        case 10: // Wario
            DEF_COLOR_YELLOW(configColorCap);

            DEF_COLOR_YELLOW(configColorShirt);

            DEF_COLOR_PURPLE(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_GREEN(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;

        case 11: // Waluigi
            DEF_COLOR_PURPLE(configColorCap);

            DEF_COLOR_PURPLE(configColorShirt);

            DEF_COLOR_BLACK(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_ORANGE(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;

        case 12: // Hernesto
            DEF_COLOR_LIGHT(configColorCap, 89, 103, 255);
            DEF_COLOR_DARK (configColorCap, 43, 35, 153);

            DEF_COLOR_LIGHT(configColorShirt, 89, 103, 255);
            DEF_COLOR_DARK (configColorShirt, 43, 35, 153);

            DEF_COLOR_RED(configColorOveralls);

            DEF_COLOR_WHITE(configColorGloves);

            DEF_COLOR_SHOES(configColorShoes);

            DEF_COLOR_SKIN(configColorSkin);

            DEF_COLOR_HAIR(configColorHair);
            break;
    }
}