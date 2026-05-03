#include "Launcher.hpp"

const char* filters[] = {"*.numgine"};


void drawHeader(Font font) {
    // À REFAIRE POUR PAS AVOIR À METTRE LA FONT ICI
    // C'est un peu moche actuellement
    // mais woulah ça va être mieux après
    ClearBackground(DARKGRAY); 
    DrawTextEx(font, "Numgine", {20, 16}, 32, 1, WHITE);
}

std::optional<std::string> launcherInit(int monitorWidth, int monitorHeight) {
    
    // Utilisation de la police NotoSans
    // Je devrais probablement l'ajouter aux thèmes prochainement
    Font font = LoadFontEx("assets/fonts/NotoSans.ttf", 32, nullptr, 256);
    if (font.texture.id == GetFontDefault().texture.id) {
        TraceLog(LOG_WARNING,    "La police ne peut pas être trouvée.");
    }
    GuiSetFont(font);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 32); // Mettre la police dans raygui


    TraceLog(LOG_INFO,    "Démarrage du Launcher");
    NFD_Init();
    while (!WindowShouldClose())
    {
        BeginDrawing();
            drawHeader(font);
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
                    UnloadFont(font);
                    return validPath;
                }
            }
            if (GuiButton({100, 200, 200, 50}, "Créer projet")) {
                // todo
            }
        EndDrawing();
    }
    UnloadFont(font);
    return std::nullopt;
}