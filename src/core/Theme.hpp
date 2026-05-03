#ifndef THEME_HPP
#define THEME_HPP

#include "raylib.h"

struct ThemeData {
    Color BG_PRIMARY;
    Color TEXT_PRIMARY;
};

namespace Theme {
    inline ThemeData darkClassic = {
        {0,0,0,255},
        {255,255,255,255}
    };

    inline ThemeData* current = &darkClassic;
}

#endif