#define RAYGUI_IMPLEMENTATION
#include "ui/Launcher.hpp"
#include "ui/Editor.hpp"
#include <string>
#include <algorithm>

constexpr int   TARGET_FPS    = 60;
constexpr auto  WINDOW_TITLE  = "Numgine";

int main(int argc, char* argv[])
{
    std::string projectPath = "";

    for (int i = 1; i < argc; i++) {

        //Argument "-project /..." pour démarrer sans passer par le launcher.
        if (std::string(argv[i]) == "-project" && i + 1 < argc) {
            projectPath = argv[i + 1];
            TraceLog(LOG_INFO,    "Démarrage sans passer par le Launcher.");
        }
    }
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    //Création de la fenêtre
    InitWindow(1, 1, WINDOW_TITLE);

    int monitorWidth  = GetMonitorWidth(GetCurrentMonitor());
    int monitorHeight = GetMonitorHeight(GetCurrentMonitor());
    float scale = (float)monitorHeight / 1080.0f;

    //Choix de la taille de la fenêtre
    if (projectPath.empty()) { // Si on lance le launcher

        SetWindowSize(std::min(600,(int)(LAUNCHER_WINDOW_WIDTH*scale)), std::min(600,(int)(LAUNCHER_WINDOW_HEIGHT*scale)));
        SetWindowPosition(monitorWidth / 2 - (int)(LAUNCHER_WINDOW_WIDTH*scale) / 2, monitorHeight / 2 - (int)(LAUNCHER_WINDOW_HEIGHT*scale) / 2);
    } else {
        SetWindowSize(EDITOR_WINDOW_WIDTH, EDITOR_WINDOW_HEIGHT);
    }
    SetTargetFPS(TARGET_FPS);

    

    //Démarrage du Launcher
    if (projectPath.empty()) {
        auto result = launcherInit(monitorWidth, monitorHeight);
    }

    CloseWindow();
    return 0;

}