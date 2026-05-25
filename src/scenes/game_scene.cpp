#include "game_scene.h"

//
// ======================================================
// GameScene::init()
// ======================================================
//
// Inicializa gameplay.
//
void GameScene::init()
{
    //
    // ==================================================
    // Cria player
    // ==================================================
    //
    Entity player;

    player.setType(EntityType::PLAYER);

    entities.push_back(player);

    //
    // ==================================================
    // Cria NPC
    // ==================================================
    //
    Entity npc;

    npc.setPosition(400, 200);

    npc.setColor(255, 0, 0);

    npc.setType(EntityType::NPC);

    entities.push_back(npc);

    //
    // ==================================================
    // Configura D-Pad
    // ==================================================

    // ---------------- UP ----------------
    upButton.setInput(input);

    upButton.setVirtualInput(
        &virtualInput
    );

    upButton.setVirtualButton(
        VirtualButton::UP
    );

    upButton.setPosition(120, 380);

    // ---------------- DOWN ----------------
    downButton.setInput(input);

    downButton.setVirtualInput(
        &virtualInput
    );

    downButton.setVirtualButton(
        VirtualButton::DOWN
    );

    downButton.setPosition(120, 500);

    // ---------------- LEFT ----------------
    leftButton.setInput(input);

    leftButton.setVirtualInput(
        &virtualInput
    );

    leftButton.setVirtualButton(
        VirtualButton::LEFT
    );

    leftButton.setPosition(20, 440);

    // ---------------- RIGHT ----------------
    rightButton.setInput(input);

    rightButton.setVirtualInput(
        &virtualInput
    );

    rightButton.setVirtualButton(
        VirtualButton::RIGHT
    );

    rightButton.setPosition(220, 440);  
}

//
// ======================================================
// GameScene::update()
// ======================================================
//
// Atualiza:
//
// - input virtual
// - player
// - câmera
// - UI
//
void GameScene::update(float deltaTime)
{
    //
    // ==================================================
    // Atualiza D-Pad virtual
    // ==================================================
    //
    // Touch buttons atualizam VirtualInput.
    //
    upButton.update(deltaTime);

    downButton.update(deltaTime);

    leftButton.update(deltaTime);

    rightButton.update(deltaTime);

    //
    // ==================================================
    // Combina teclado + touch
    // ==================================================
    //
    // Keyboard também alimenta VirtualInput.
    //
    if (input->up)
    {
        virtualInput.setButton(
            VirtualButton::UP,
            true
        );
    }

    if (input->down)
    {
        virtualInput.setButton(
            VirtualButton::DOWN,
            true
        );
    }

    if (input->left)
    {
        virtualInput.setButton(
            VirtualButton::LEFT,
            true
        );
    }

    if (input->right)
    {
        virtualInput.setButton(
            VirtualButton::RIGHT,
            true
        );
    }

    //
    // ==================================================
    // Atualiza player
    // ==================================================
    //
    playerController.update(
        entities[0],
        virtualInput,
        deltaTime
    );

    //
    // ==================================================
    // Atualiza entidades
    // ==================================================
    //
    // Atualiza bounds e lógica.
    //
    for (auto& entity : entities)
    {
        entity.update(deltaTime);
    }

    //
    // ==================================================
    // Atualiza câmera
    // ==================================================
    //
    camera.follow(
        entities[0].getX(),
        entities[0].getY()
    );
}

//
// ======================================================
// GameScene::render()
// ======================================================
//
// Renderiza gameplay.
//
void GameScene::render()
{
    //
    // Renderiza entidades.
    //
    for (auto& entity : entities)
    {
        if (entity.isActive())
        {
            entity.draw(
                *renderer,
                camera
            );
        }
    }

    //
    // ==================================================
    // Renderiza D-Pad
    // ==================================================
    upButton.render(*renderer);

    downButton.render(*renderer);

    leftButton.render(*renderer);

    rightButton.render(*renderer);
}

//
// ======================================================
// GameScene::shutdown()
// ======================================================
//
// Finaliza gameplay.
//
void GameScene::shutdown()
{
}

//
// ======================================================
// GameScene::setRenderer()
// ======================================================
//
// Define renderer.
//
void GameScene::setRenderer(Renderer* newRenderer)
{
    renderer = newRenderer;
}

//
// ======================================================
// GameScene::setInput()
// ======================================================
//
// Define input.
//
void GameScene::setInput(Input* newInput)
{
    input = newInput;
}