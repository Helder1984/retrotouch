#pragma once

class Entity
{
public:
    float x;
    float y;

    float speed;

    Entity();

    void update(float deltaTime, bool up, bool down, bool left, bool right);
};