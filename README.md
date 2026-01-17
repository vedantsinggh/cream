# Cream

Cream is a **native code editor** written in **C++**, focused on performance, control, and clean architecture.  
It is an experimental project exploring how modern editors are built without web stacks or heavy frameworks.

> Status: Work in progress

---

## Tech Stack

- **C++17**
- **Raylib** — windowing, input, GPU rendering
- **Dear ImGui (docking branch)** — UI layout and panels
- **CMake** — build system

---

## Features (Current)

- Native window and rendering
- Dockable, resizable editor layout
- Sidebar, editor area, and bottom panel
- Clean project structure

---

## Planned

- Text editor core integration
- Syntax highlighting
- File explorer
- Multiple buffers and tabs

---

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
./cream
````

---

## Notes

Linux-first project intended for learning editor internals and native UI systems.

