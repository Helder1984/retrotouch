@echo off

if not exist build mkdir build

g++ ^
src/main.cpp ^
src/engine/app.cpp ^
src/render/renderer.cpp ^
src/input/input.cpp ^
src/game/entity.cpp ^
src/controllers/*.cpp ^
src/camera/*.cpp ^
src/scenes/*.cpp ^
src/ui/*.cpp ^
src/virtual_input/*.cpp ^
src/touch/*.cpp ^
src/layout/hud_layout.cpp ^
-ISDL3-3.4.8/x86_64-w64-mingw32/include ^
-LSDL3-3.4.8/x86_64-w64-mingw32/lib ^
-lSDL3 ^
-o build/retrotouch.exe

copy SDL3-3.4.8\x86_64-w64-mingw32\bin\SDL3.dll build\

echo.
echo =========================
echo Build concluido!
echo =========================
pause