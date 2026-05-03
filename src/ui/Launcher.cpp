#include "Launcher.hpp"

const char* filters[] = {"*.numgine"};

std::optional<std::string> launcherInit() {
    TraceLog(LOG_INFO,    "Démarrage du Launcher");
    NFD_Init();
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("hello world.", 20, 20, 20, RAYWHITE);
            if (GuiButton({100, 100, 200, 50}, "Ouvrir projet")) {
                std::string validPath = "";

                while (validPath.empty()) {

                    nfdu8char_t *outPath;
                    nfdu8filteritem_t filters[1] = { { "Projet Numgine", "numgine" }};
                    nfdopendialogu8args_t args = {0};
                    args.filterList = filters;
                    args.filterCount = 1;

                    nfdresult_t result = NFD_OpenDialogU8_With(&outPath, &args);

                    if (result != NFD_OKAY) {
                        break;
                    }

                    TraceLog(LOG_INFO,    "Chemin trouvé : %s",outPath);

                    std::string path = outPath;
                    NFD_FreePathU8(outPath);

                    std::filesystem::path filePath(path);
                    if (filePath.extension() != ".numgine") {
                        TraceLog(LOG_WARNING,    "Le chemin trouvé n'a pas la bonne extension.");
                        break;
                    }
                    validPath = path;
                }

                if (!validPath.empty()) {
                    NFD_Quit();

                    return validPath;
                }
            }
            if (GuiButton({100, 200, 200, 50}, "Créer projet")) {
                
            }
        EndDrawing();
    }
    return std::nullopt;
}