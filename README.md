# RetroTouch

RetroTouch is an experimental framework focused on improving interaction with retro game emulators through customizable overlays, touch controls, contextual UI, and advanced input abstraction.

The project is being developed with a strong focus on:

- modular architecture
- accessibility
- emulator integration
- low-latency input systems
- RPG-friendly interaction design

---

# Vision

RetroTouch aims to create a modern interaction layer for retro emulators, especially for RPG games such as Pokémon FireRed.

The long-term goal is to provide:

- virtual touch controls
- contextual overlays
- gesture support
- dynamic UI layouts
- customizable control schemes
- accessibility-focused interaction systems

---

# Current Status

Current development focus:

```txt
Gameplay Architecture Layer
```

Implemented systems:

- SDL3 window system
- render pipeline
- input system
- entity system
- delta time
- controller architecture
- entity metadata system
- gameplay/engine separation

---

# Current Architecture

```txt
Input
   ↓
Controllers
   ↓
Entities
   ↓
Renderer
```

---

# Project Structure

```txt
src/
│
├── engine/
│   ├── app.h
│   └── app.cpp
│
├── render/
│   ├── renderer.h
│   └── renderer.cpp
│
├── input/
│   ├── input.h
│   └── input.cpp
│
├── game/
│   ├── entity.h
│   └── entity.cpp
│
├── controllers/
│   ├── player_controller.h
│   └── player_controller.cpp
│
└── main.cpp
```

---

# Current Features

## Engine Foundation

- SDL3 initialization
- window creation
- renderer abstraction
- update/render loop
- delta time system

---

## Input System

- keyboard input polling
- WASD movement
- input abstraction foundation

---

## Entity System

- entity rendering
- movement system
- metadata system
- activation state
- entity categorization

---

## Controller Architecture

The project uses a decoupled controller system.

Example:

```txt
Input
   ↓
PlayerController
   ↓
Entity
```

This architecture prepares the project for:

- gamepad support
- touch input
- macro systems
- emulator integration
- accessibility layers

---

# Technologies

- C++
- SDL3
- MinGW64
- Git
- GitHub

---

# Build Instructions

## Requirements

- MinGW64
- SDL3
- Windows

---

## Build

Run:

```powershell
.\build.bat
```

The script will:

- compile the project
- link SDL3
- generate executable
- copy SDL3.dll

---

# Running

After build:

```txt
build/retrotouch.exe
```

---

# Development Philosophy

RetroTouch is being developed with a focus on:

- clean architecture
- modular systems
- separation of responsibilities
- scalability
- maintainability

---

# Planned Features

## Input Framework

- keyboard abstraction
- gamepad abstraction
- touch abstraction
- input remapping
- macro systems

---

## Overlay System

- virtual buttons
- draggable controls
- dynamic layouts
- contextual UI
- gesture support

---

## Emulator Integration

- mGBA integration
- custom input injection
- emulator overlays
- contextual RPG interfaces

---

## Mobile Support

- Android integration
- touch latency optimization
- DPI scaling
- mobile UI adaptation

---

# Current Roadmap Position

```txt
Phase 1 — Gameplay Architecture
```

Next major milestone:

```txt
Camera System
```

---

# Long-Term Goals

- customizable overlay framework
- accessibility-first emulator interaction
- advanced touch systems
- dynamic RPG interfaces
- mobile-friendly emulator UI

---

# Repository Goals

This repository serves as:

- active development environment
- architecture study project
- emulator interaction research
- real-time systems learning project

---

# License

Project currently under development.
License definition will be added in future versions.