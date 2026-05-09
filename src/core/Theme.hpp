#ifndef THEME_HPP
#define THEME_HPP

#include "raylib.h"

struct ThemeData {
    Color BG_PRIMARY;
    Color BG_SECONDARY;
    Color TEXT_PRIMARY;
};

namespace Theme {
    inline ThemeData darkClassic = {
        {15, 15, 15, 255},
        {24, 24, 24, 255},
        {240, 240, 240, 255}
    };

    inline ThemeData* current = &darkClassic;
}

#endif