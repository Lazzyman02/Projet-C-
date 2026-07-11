# SFML Setup and Build Fix Documentation

## Project
- Workspace: C:\Users\HP\Desktop\Projet C++
- Main source file: main.cpp
- Build tool: g++ with MinGW/MSYS2 on Windows

## Problem
The project initially failed because the compiler could not find the SFML headers:
- `SFML/Graphics.hpp: No such file or directory`

This was caused by a missing or incorrect build configuration for the SFML include and library paths.

## Root Cause
The build setup was not passing the correct SFML include directory and linker libraries to the compiler. In addition, the sample code used an older SFML event-loop API that did not match the installed SFML version.

## What Was Fixed

### 1. Updated the source code
The event loop in main.cpp was updated to use the current SFML API:
- Replaced the old `sf::Event event; while (window.pollEvent(event))` pattern
- Switched to the newer `std::optional<sf::Event>` style

### 2. Updated the Makefile
The Makefile now:
- uses `g++`
- includes the correct SFML include directory
- links against the correct SFML libraries
- builds an executable named `main.exe`

### 3. Updated VS Code build settings
The build task in `.vscode/tasks.json` now also passes:
- the SFML include path
- the SFML library path
- the required SFML libraries

## Build Commands Used
The project was verified with this compile command:

```powershell
g++.exe -std=c++17 -IC:/msys64/ucrt64/include main.cpp -o main.exe -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lfreetype -lwinmm -lgdi32
```

## Installed Dependency
SFML was installed for the MinGW/ucrt64 toolchain using MSYS2:

```powershell
C:\msys64\usr\bin\bash.exe -lc "pacman -S --noconfirm mingw-w64-ucrt-x86_64-sfml"
```

## Verification
The setup was verified by:
1. compiling the project successfully
2. launching the generated executable successfully

## Files Modified
- main.cpp
- Makefile
- .vscode/tasks.json

## Notes
If you later add more SFML-based files, keep using the same include and link flags so the project continues to build correctly.
