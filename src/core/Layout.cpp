#include "Layout.hpp"

void Layout::actualize() {
    Width = GetScreenWidth();
    Height = GetScreenHeight();
    scaleX = (float)Width  / referenceWidth;
    scaleY = (float)Height / referenceHeight;
}

int Layout::positionScale(int val, float scale) {
    return (int)(val * scale);
}

Vector2 Layout::coordinateScale(int x, int y) {
    return {(float)positionScale(x, scaleX), (float)positionScale(y, scaleY)};
}

Vector2 Layout::coordinateCentered(int x, int y, int width, int height) {
    return {
        (float)(positionScale(x, scaleX) - ( positionScale(width, scaleX) / 2.0f )),
        (float)(positionScale(y, scaleY) - ( positionScale(height, scaleY) / 2.0f ))
    };
}