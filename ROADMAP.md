# RetroTouch Roadmap

---

# Phase 0 — Foundation

## Infrastructure

- [x] Git setup
- [x] GitHub setup
- [x] Repository structure
- [x] Development workflow
- [x] Initial documentation structure

---

## Engine Foundation

- [x] Basic SDL initialization
- [x] Window creation
- [x] Main loop architecture
- [x] Render system
- [x] Delta time system
- [x] Basic entity system
- [x] Input system
- [x] Player movement
- [x] Multiple entities
- [x] Entity metadata system
- [x] Active/inactive entities
- [x] Entity typing system
- [x] Controller architecture
- [x] Gameplay/engine separation

---

# Phase 1 — Sandbox Prototypes

## SDL Sandbox

- [x] Basic SDL window
- [x] Event loop
- [x] Mouse click detection
- [x] Virtual button rendering prototype
- [x] Initial input abstraction experiments

---

## Gameplay Architecture

- [x] PlayerController
- [x] Entity rendering loop
- [x] Entity update loop
- [ ] Camera system
- [ ] Scene system
- [ ] Entity manager
- [ ] Collision system
- [ ] Event system

---

# Phase 2 — Emulator Research

## mGBA Integration Research

- [ ] Compile mGBA
- [ ] Understand GBA input system
- [ ] Locate keyboard input pipeline
- [ ] Study emulator event flow
- [ ] Test custom input injection
- [ ] Research frame timing synchronization
- [ ] Prototype external input layer

---

# Phase 3 — RetroTouch Core

## Input Framework

- [ ] Keyboard abstraction
- [ ] Gamepad abstraction
- [ ] Touch abstraction
- [ ] Command mapper
- [ ] Action binding system
- [ ] Rebind system
- [ ] Input profiles
- [ ] Macro system

---

## Overlay System

- [ ] Virtual button system
- [ ] Draggable controls
- [ ] Dynamic layouts
- [ ] Overlay renderer
- [ ] Context-aware controls
- [ ] Gesture system
- [ ] Multi-touch support
- [ ] Input feedback system

---

# Phase 4 — RPG Adaptation

## Pokémon FireRed Prototype

- [ ] Pokémon FireRed integration
- [ ] Battle UI adaptation
- [ ] Menu touch support
- [ ] Dynamic control layouts
- [ ] Contextual overlays
- [ ] Auto-hide controls
- [ ] Touch inventory navigation
- [ ] Dialogue interaction system

---

# Phase 5 — Mobile Integration

## Android Layer

- [ ] Android integration
- [ ] SDL Android pipeline
- [ ] Performance optimization
- [ ] Touch latency improvements
- [ ] UI customization
- [ ] DPI scaling
- [ ] Safe area system
- [ ] Mobile renderer optimization

---

# Phase 6 — Advanced Systems

## Advanced Features

- [ ] Saveable layouts
- [ ] Cloud profiles
- [ ] Accessibility system
- [ ] Macro recording
- [ ] Gesture editor
- [ ] Overlay themes
- [ ] Plugin system
- [ ] Emulator compatibility layer

---

# Current Status

Current Focus:
Gameplay Architecture Layer

---

# Current Engine Architecture

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

# Next Recommended Step

Camera System

Because it unlocks:

- world space
- screen space
- scrolling
- overlays
- viewport management
- emulator scaling
- touch positioning
- UI anchoring