#pragma once

class Player
{
public:
    void update(float deltaTime);
    void render();

private:
    float x = 100.0f;
    float y = 100.0f;

    float speed = 300.0f;
};