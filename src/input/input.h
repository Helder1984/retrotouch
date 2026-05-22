#pragma once

class Input
{
public:
    bool up;
    bool down;
    bool left;
    bool right;

    Input();

    void update();
};