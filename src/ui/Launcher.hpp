#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP


#include <optional>
#include <string>
#include <filesystem>
#include "raylib.h"
#include "nfd.h"
#include "raygui.h"

std::optional<std::string> launcherInit(int monitorWidth, int monitorHeight);
constexpr int LAUNCHER_WINDOW_HEIGHT = 600;
constexpr int LAUNCHER_WINDOW_WIDTH = 600;

#endif