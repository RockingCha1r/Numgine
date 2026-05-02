cmake_minimum_required(VERSION 3.20)
project(Numgine CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
    GIT_SHALLOW    TRUE
)
FetchContent_Declare(
    tinyfiledialogs
    GIT_REPOSITORY https://github.com/native-toolkit/libtinyfiledialogs.git
    GIT_TAG        master
    GIT_SHALLOW    TRUE
)
FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG        4.0
    GIT_SHALLOW    TRUE
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib tinyfiledialogs raygui)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ui/Launcher.cpp
    src/ui/Editor.cpp
    ${tinyfiledialogs_SOURCE_DIR}/tinyfiledialogs.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${tinyfiledialogs_SOURCE_DIR}
    ${raygui_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)