# RetroTouch Architecture

## Core Concept

RetroTouch is an adaptive input abstraction layer designed to transform retro handheld games into mobile-native experiences.

---

## High-Level Architecture

```text
Touch Input
    ↓
Gesture Interpreter
    ↓
Input Mapper
    ↓
Virtual GBA Input
    ↓
mGBA Core
    ↓
Game
```

---

## Main Components

### Touch Layer
Responsible for:
- Touch events
- Overlay rendering
- Multitouch support

### Gesture System
Responsible for:
- Swipe detection
- Hold detection
- Gesture interpretation

### Input Mapper
Responsible for:
- Translating touch into GBA inputs
- Mapping gestures to actions

### Contextual UI
Responsible for:
- Dynamic layouts
- Battle UI adaptation
- Menu-aware controls

---

## Initial Scope

Focused on:
- Pokémon FireRed
- Android
- RPG gameplay adaptation