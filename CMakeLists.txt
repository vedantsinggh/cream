cmake_minimum_required(VERSION 3.16)
project(cream LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(external/raylib)

add_executable(cream
    src/main.cpp
    src/app.cpp
    src/ui/ui_layout.cpp

    external/rlImGui/rlImGui.cpp
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_tables.cpp
)

target_include_directories(cream PRIVATE
    src
    external/imgui
    external/rlImGui
    external/raylib/src
)

target_link_libraries(cream raylib)
