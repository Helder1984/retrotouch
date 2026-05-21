#pragma once

#include "../render/renderer.h"

class App
{
public:
    bool init();
    void run();
    void shutdown();

private:
    bool running = true;
    Renderer renderer;
};