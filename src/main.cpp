#define RAYGUI_IMPLEMENTATION
#include "ui/Launcher.hpp"
#include "ui/Editor.hpp"
#include <string>

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
    if (projectPath.empty()) { // Si on lance le launcher
        InitWindow(LAUNCHER_WINDOW_WIDTH, LAUNCHER_WINDOW_HEIGHT, WINDOW_TITLE);
    } else {
        InitWindow(EDITOR_WINDOW_WIDTH, EDITOR_WINDOW_HEIGHT, WINDOW_TITLE);
    }
    SetTargetFPS(TARGET_FPS);


    //Démarrage du Launcher
    if (projectPath.empty()) {
        auto result = launcherInit();
    }

    CloseWindow();
    return 0;

}