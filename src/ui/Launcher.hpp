#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP


#include <optional>
#include <string>
#include "raylib.h"
#include "tinyfiledialogs.h"
#include "raygui.h"

std::optional<std::string> launcherInit();
constexpr int LAUNCHER_WINDOW_HEIGHT = 600;
constexpr int LAUNCHER_WINDOW_WIDTH = 600;

#endif