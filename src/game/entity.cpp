#include "entity.h"

//
// ======================================================
// Entity::Entity()
// ======================================================
// Construtor da entidade.
//
// Define os valores padrões:
//
// - posição
// - velocidade
// - tamanho
// - cor
//
Entity::Entity()
{

    //
    // Posição inicial da entidade.
    //
    x = 100.0f;
    y = 100.0f;

    //
    // Velocidade de movimentação.
    //
    speed = 300.0f;

    //
    // Tamanho da entidade.
    //
    width = 50;
    height = 50;

    //
    // Cor padrão da entidade.
    // RGB:
    // 255,255,255 = branco
    //
    r = 255;
    g = 255;
    b = 255;

     //
    // ==================================================
    // Metadados padrão
    // ==================================================
    //
    // ID temporário.
    // Futuramente será automático.
    //
    id = 0;

    //
    // Tipo padrão.
    //
    type = EntityType::OBJECT;

    //
    // Entidade começa ativa.
    //
    active = true;
}

//
// ======================================================
// Entity::update()
// ======================================================
//
// Atualiza lógica interna da entidade.
//
// Atualmente vazia.
//
// Futuramente poderá conter:
//
// - animação
// - física
// - timers
// - estados
// - comportamento próprio
//
void Entity::update(float deltaTime)
{
    //
    // ==================================================
    // World bounds
    // ==================================================
    //
    // Impede entidade de sair do mundo.
    //
    if (x < 0)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = 0;
    }

    //
    // Limite horizontal.
    //
    if (x > 2000 - width)
    {
        x = 2000 - width;
    }

    //
    // Limite vertical.
    //
    if (y > 2000 - height)
    {
        y = 2000 - height;
    }
}

//
// ======================================================
// Entity::getX()
// ======================================================
// Retorna posição X da entidade.
//
float Entity::getX()
{
    return x;
}

//
// ======================================================
// Entity::getY()
// ======================================================
// Retorna posição Y da entidade.
//
float Entity::getY()
{
    return y;
}

//
// ======================================================
// Entity::draw()
// ======================================================
//
// Desenha entidade no mundo.
//
void Entity::draw(Renderer& renderer, Camera& camera)
    {
    //
    // ==================================================
    // Desenha entidade usando world position
    // ==================================================
    //
    // Renderer aplicará offset da câmera.
    //
    renderer.drawRect(
        x,
        y,
        width,
        height,
        r,
        g,
        b,
        camera
    );
}

//
// ======================================================
// Entity::setPosition()
// ======================================================
// Define nova posição da entidade.
//
void Entity::setPosition(float newX, float newY)
{
    x = newX;
    y = newY;
}

//
// ======================================================
// Entity::setColor()
// ======================================================
// Define nova cor da entidade.
//
// RGB:
// r = vermelho
// g = verde
// b = azul
//
void Entity::setColor(Uint8 newR, Uint8 newG, Uint8 newB)
{
    r = newR;
    g = newG;
    b = newB;
}

//
// ======================================================
// Entity::move()
// ======================================================
//
// Move a entidade aplicando deslocamento.
//
// dx
// → deslocamento horizontal
//
// dy
// → deslocamento vertical
//
void Entity::move(float dx, float dy)
{
    x += dx;
    y += dy;

    //
    // ==================================================
    // World bounds
    // ==================================================
    //
    // Impede sair do mapa.
    //
    if (x < 0)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = 0;
    }

    float mapWidth = 2000;

    float mapHeight = 2000;

    if (x > mapWidth - width)
    {
        x = mapWidth - width;
    }

    if (y > mapHeight - height)
    {
        y = mapHeight - height;
    }
}

//
// ======================================================
// Entity::getId()
// ======================================================
//
// Retorna ID da entidade.
//
int Entity::getId()
{
    return id;
}

//
// ======================================================
// Entity::getType()
// ======================================================
//
// Retorna tipo da entidade.
//
EntityType Entity::getType()
{
    return type;
}

//
// ======================================================
// Entity::isActive()
// ======================================================
//
// Verifica se entidade está ativa.
//
bool Entity::isActive()
{
    return active;
}

//
// ======================================================
// Entity::setType()
// ======================================================
//
// Define tipo da entidade.
//
void Entity::setType(EntityType newType)
{
    type = newType;
}

//
// ======================================================
// Entity::setActive()
// ======================================================
//
// Ativa/desativa entidade.
//
void Entity::setActive(bool state)
{
    active = state;
}

//
// ======================================================
// Entity::moveUp()
// ======================================================
//
// Move entidade para cima.
//
void Entity::moveUp(float deltaTime)
{
    y -= speed * deltaTime;
}

//
// ======================================================
// Entity::moveDown()
// ======================================================
//
// Move entidade para baixo.
//
void Entity::moveDown(float deltaTime)
{
    y += speed * deltaTime;
}

//
// ======================================================
// Entity::moveLeft()
// ======================================================
//
// Move entidade para esquerda.
//
void Entity::moveLeft(float deltaTime)
{
    x -= speed * deltaTime;
}

//
// ======================================================
// Entity::moveRight()
// ======================================================
//
// Move entidade para direita.
//
void Entity::moveRight(float deltaTime)
{
    x += speed * deltaTime;
}

//
// ======================================================
// Entity::getWidth()
// ======================================================
//
float Entity::getWidth()
{
    return width;
}

//
// ======================================================
// Entity::getHeight()
// ======================================================
//
float Entity::getHeight()
{
    return height;
}

