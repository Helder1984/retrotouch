#pragma once

#include <SDL3/SDL.h>

class Input
{
public:
    void update();

    bool quitRequested() const;

private:
    bool quit = false;
};