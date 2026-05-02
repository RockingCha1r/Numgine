#include "Launcher.hpp"

const char* filters[] = {"*.numgine"};

std::optional<std::string> launcherInit() {
    TraceLog(LOG_INFO,    "Démarrage du Launcher");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("hello world.", 20, 20, 20, RAYWHITE);
            if (GuiButton({100, 100, 200, 50}, "Ouvrir projet")) {
                
                const char* path = tinyfd_openFileDialog("Ouvrir un projet", "", 1, filters, "Projet Numgine", 0);

                // ATTENTION
                // ÇA FAIT CRASH À CAUSE DES FILTRES
                // JE SAIS PAS POURQUOI
                // FAUT QUE JE RÈGLE CETTE MERDE

                if (path) {
                    return path;
                } else {
                    return "ERROR_USER_CANCELLED";
                }
            }
            if (GuiButton({100, 200, 200, 50}, "Créer projet")) {
                
            }
        EndDrawing();
    }
    return std::nullopt;
}