# RetroTouch Architecture

---

# Overview

RetroTouch is being developed as a modular input and overlay framework focused on improving interaction with retro game emulators, especially for RPG games.

The project architecture is designed around:

- modular systems
- decoupled gameplay logic
- reusable engine components
- scalable input abstraction
- future emulator integration

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

# Core Principles

## 1. Separation of Responsibilities

Each system has a single responsibility.

Example:

- Input handles keyboard state
- Controllers interpret commands
- Entities represent world objects
- Renderer draws objects on screen

---

## 2. Decoupled Gameplay

Gameplay logic is separated from engine systems.

This allows:

- easier maintenance
- modularity
- future emulator integration
- multiple input sources
- accessibility systems

---

## 3. Real-Time Architecture

The engine uses:

- update loop
- render loop
- delta time
- frame-independent movement

This is essential for:

- overlays
- touch systems
- emulator synchronization
- low latency interaction

---

# Engine Layers

---

## Engine Layer

Core low-level systems.

### Current Systems

### Renderer

Responsible for:

- SDL renderer initialization
- screen clearing
- rectangle rendering
- frame presentation

Files:

```txt
src/render/renderer.h
src/render/renderer.cpp
```

---

### Input

Responsible for:

- keyboard state
- input polling
- directional controls

Files:

```txt
src/input/input.h
src/input/input.cpp
```

---

### App Core

Responsible for:

- initialization
- game loop
- update/render pipeline
- SDL event handling

Files:

```txt
src/engine/app.h
src/engine/app.cpp
```

---

# Gameplay Layer

High-level gameplay systems.

---

## Entity System

Entities represent objects inside the world.

Current features:

- position
- movement
- rendering
- color
- metadata
- activation state

Files:

```txt
src/game/entity.h
src/game/entity.cpp
```

---

## Entity Metadata System

Each entity contains:

```txt
id
type
active
```

### Entity Types

```txt
PLAYER
NPC
ENEMY
OBJECT
UI
```

This prepares the engine for:

- collision systems
- scene systems
- interaction systems
- emulator overlays
- contextual UI

---

## Controller System

Controllers interpret input and control entities.

Current implementation:

```txt
PlayerController
```

Architecture:

```txt
Input
   ↓
PlayerController
   ↓
Entity
```

Files:

```txt
src/controllers/player_controller.h
src/controllers/player_controller.cpp
```

---

# Rendering Pipeline

Current render flow:

```txt
App::render()
    ↓
Renderer::clear()
    ↓
Entity::draw()
    ↓
Renderer::drawRect()
    ↓
Renderer::present()
```

---

# Update Pipeline

Current update flow:

```txt
App::update()
    ↓
PlayerController::update()
    ↓
Entity::update()
```

---

# Timing System

The engine uses delta time for frame-independent movement.

Current implementation:

```txt
deltaTime = (currentTime - lastTime) / 1000.0f;
```

Benefits:

- stable movement
- FPS independence
- emulator synchronization readiness

---

# Current Folder Structure

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

# Build System

The project currently uses a custom batch build script.

Responsibilities:

- compile source files
- link SDL3
- generate executable
- copy SDL3.dll

File:

```txt
build.bat
```

---

# Current Technical Status

Implemented:

- SDL window
- renderer system
- entity system
- input system
- delta time
- controller architecture
- metadata system
- gameplay separation

---

# Planned Systems

---

## Camera System

Will introduce:

- world space
- screen space
- scrolling
- viewport handling

---

## Scene System

Will manage:

- menus
- overlays
- emulator scenes
- configuration screens

---

## Entity Manager

Future replacement for:

```cpp
std::vector<Entity>
```

Will support:

- spawning
- destruction
- pooling
- lookup systems

---

## Collision System

Planned for:

- UI interaction
- touch zones
- overlay buttons
- contextual controls

---

## Event System

Will support:

- command mapping
- macro triggers
- input rebinding
- gameplay events

---

# Emulator Integration Vision

RetroTouch is being designed to eventually support:

- mGBA integration
- custom input injection
- touch overlays
- contextual emulator UI
- RPG-friendly interaction systems

---

# Long-Term Goals

- modular overlay framework
- accessibility-focused emulator interaction
- customizable control layouts
- mobile support
- gesture-based controls
- dynamic RPG interfaces

---

# Current Development Focus

```txt
Gameplay Architecture Layer
```

---

# Next Major Milestone

```txt
Camera System
```

This will unlock:

- scrolling worlds
- viewport abstraction
- overlay positioning
- emulator scaling support
- UI anchoring
- world-space rendering