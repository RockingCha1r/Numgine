#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include "raylib.h"

namespace Layout {
    inline int Width = 0;
    inline int Height = 0;

    inline int referenceWidth = 1920;
    inline int referenceHeight = 1080;

    inline float scaleX = 1.0f;
    inline float scaleY = 1.0f;

    void actualize();
    int positionScale(int val, float scale);
    Vector2 coordinateScale(int x, int y);
    Vector2 coordinateCentered(int x, int y, int width, int height);
    Rectangle scaledRect(int x, int y, int width, int height);

    void setReference(int width, int height);

}


#endif