#include "ui_layout.h"
#include "imgui.h"
#include "imgui_internal.h"

void DrawFileExplorer()
{
    ImGui::Begin("Files");

    if (ImGui::TreeNode("src"))
    {
        ImGui::Selectable("main.cpp");
        ImGui::TreePop();
    }

    ImGui::End();
}

void DrawEditorTabs()
{
    ImGui::Begin("Editor");
    ImGui::Text("This is text editor");
    ImGui::End();
}

void DrawBottomPanel()
{
    ImGui::Begin("terminal");
    ImGui::Text("This is terminal");
    ImGui::End();
}

static void BuildDockLayout(ImGuiID dockspace_id)
{
    ImGui::DockBuilderRemoveNode(dockspace_id); // clear existing
    ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);

    ImGuiID dock_main = dockspace_id;

    ImGuiID dock_left;
    ImGuiID dock_bottom;
    ImGuiID dock_center;

    dock_left = ImGui::DockBuilderSplitNode(
        dock_main, ImGuiDir_Left, 0.20f, nullptr, &dock_main);

    dock_bottom = ImGui::DockBuilderSplitNode(
        dock_main, ImGuiDir_Down, 0.25f, nullptr, &dock_main);

    dock_center = dock_main;

    ImGui::DockBuilderDockWindow("Files", dock_left);
    ImGui::DockBuilderDockWindow("Editor", dock_center);
    ImGui::DockBuilderDockWindow("terminal", dock_bottom);

    ImGui::DockBuilderFinish(dockspace_id);
}

void DrawUILayout()
{
    static bool first_time = true;

    ImGui::Begin("RootDockspace",
        nullptr,
        ImGuiWindowFlags_NoDocking |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove);

    ImGuiID dockspace_id = ImGui::GetID("MainDockspace");
    ImGui::DockSpace(dockspace_id);

    if (first_time)
    {
        BuildDockLayout(dockspace_id);
        first_time = false;
    }

    ImGui::End();

    DrawFileExplorer();
    DrawEditorTabs();
    DrawBottomPanel();
}
