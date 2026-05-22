#include "entity.h"

Entity::Entity()
{
    x = 100.0f;
    y = 100.0f;

    speed = 200.0f;
}

void Entity::update(float deltaTime, bool up, bool down, bool left, bool right)
{
    if (up)
        y -= speed * deltaTime;

    if (down)
        y += speed * deltaTime;

    if (left)
        x -= speed * deltaTime;

    if (right)
        x += speed * deltaTime;
}
