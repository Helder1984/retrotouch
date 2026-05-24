# SDL3 Prototype

## Goal

Create the first graphical/input prototype for RetroTouch.

---

## Current Features

- SDL3 window creation
- Event loop
- Mouse click detection

---

## Technologies

- C++
- SDL3
- MSYS2 UCRT64
- GCC/G++

---

## Build Command

```bash
g++ main.cpp -o app $(pkg-config --cflags --libs sdl3)