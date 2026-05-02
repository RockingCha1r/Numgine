#include "Launcher.hpp"

std::optional<std::string> launcherInit() {
    TraceLog(LOG_INFO,    "Démarrage du Launcher");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("hello world.", 20, 20, 20, RAYWHITE);
        EndDrawing();
    }
    return std::nullopt;
}