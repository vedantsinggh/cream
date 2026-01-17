#include "app.h"
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "ui/ui_layout.h"

void App::run()
{
    InitWindow(1280, 800, "cream");
    SetTargetFPS(60);

    rlImGuiSetup(true);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGuiStyle& s = ImGui::GetStyle();
    s.WindowPadding = ImVec2(8, 8);
    s.FrameRounding = 6.0f;
    s.TabRounding = 6.0f;
    s.ScrollbarRounding = 6.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({20, 20, 20, 255});

        rlImGuiBegin();
        DrawUILayout();
        rlImGuiEnd();

        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
}
