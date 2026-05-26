#include "game_scene.h"
#include <cstdio>

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
    // Carrega HUD layout
    // ==================================================
    hudLayout.load(
        "layout.cfg"
    );

    //
    // Salva layout padrão.
    //
    hudLayout.save(
        "layout.cfg"
    );
    
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

    upButton.setTouchManager(
        touchManager
    );
    
    upButton.setVirtualButton(
        VirtualButton::UP
    );
    
    upButton.setPosition(
        hudLayout.dpadX + 80,
        hudLayout.dpadY
    );

    upButton.setSize(
        hudLayout.dpadButtonSize,
        hudLayout.dpadButtonSize
    );

    // ---------------- DOWN ----------------
    downButton.setInput(input);

    downButton.setVirtualInput(
        &virtualInput
    );

    downButton.setTouchManager(
        touchManager
    );

    downButton.setVirtualButton(
        VirtualButton::DOWN
    );

    downButton.setPosition(
        hudLayout.dpadX + 80,
        hudLayout.dpadY + 160
    );

    downButton.setSize(
        hudLayout.dpadButtonSize,
        hudLayout.dpadButtonSize
    );

    // ---------------- LEFT ----------------
    leftButton.setInput(input);

    leftButton.setVirtualInput(
        &virtualInput
    );

    leftButton.setTouchManager(
        touchManager
    );

    leftButton.setVirtualButton(
        VirtualButton::LEFT
    );

    leftButton.setPosition(
        hudLayout.dpadX,
        hudLayout.dpadY + 80
    );

    leftButton.setSize(
        hudLayout.dpadButtonSize,
        hudLayout.dpadButtonSize
    );

    // ---------------- RIGHT ----------------
    rightButton.setInput(input);

    rightButton.setVirtualInput(
        &virtualInput
    );

    rightButton.setTouchManager(
        touchManager
    );

    rightButton.setVirtualButton(
        VirtualButton::RIGHT
    );

    rightButton.setPosition(
        hudLayout.dpadX + 160,
        hudLayout.dpadY + 80
    );

    rightButton.setSize(
        hudLayout.dpadButtonSize,
        hudLayout.dpadButtonSize
    );

    //
    // ==================================================
    // Botão A
    // ==================================================
    aButton.setPosition(
        hudLayout.aButtonX,
        hudLayout.aButtonY
    );

    aButton.setSize(
        hudLayout.actionButtonSize,
        hudLayout.actionButtonSize
    );

    aButton.setColor(
        0,
        200,
        0
    );

    aButton.setVirtualInput(
        &virtualInput
    );

    aButton.setTouchManager(
        touchManager
    );

    aButton.setVirtualButton(
        VirtualButton::A
    );

    //
    // ==================================================
    // Botão B
    // ==================================================
    bButton.setPosition(
        hudLayout.bButtonX,
        hudLayout.bButtonY
    );

    bButton.setSize(
        hudLayout.actionButtonSize,
        hudLayout.actionButtonSize
    );
    bButton.setColor(
        200,
        0,
        0
    );

    bButton.setVirtualInput(
        &virtualInput
    );

    bButton.setTouchManager(
        touchManager
    );

    bButton.setVirtualButton(
        VirtualButton::B
    );

    //
    // ==================================================
    // START
    // ==================================================
    startButton.setPosition(
        hudLayout.startX,
        hudLayout.startY
    );

    startButton.setSize(
        hudLayout.systemButtonWidth,
        hudLayout.systemButtonHeight
    );

    startButton.setColor(
        80,
        80,
        80
    );

    startButton.setVirtualInput(
        &virtualInput
    );

    startButton.setTouchManager(
        touchManager
    );

    startButton.setVirtualButton(
        VirtualButton::START
    );

    //
    // ==================================================
    // SELECT
    // ==================================================
    selectButton.setPosition(
        hudLayout.selectX,
        hudLayout.selectY
    );

    selectButton.setSize(
        hudLayout.systemButtonWidth,
        hudLayout.systemButtonHeight
    );

    selectButton.setColor(
        80,
        80,
        80
    );

    selectButton.setVirtualInput(
        &virtualInput
    );

    selectButton.setTouchManager(
        touchManager
    );

    selectButton.setVirtualButton(
        VirtualButton::SELECT
    );


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
    // Atualiza action buttons
    // ==================================================
    aButton.update(deltaTime);

    bButton.update(deltaTime);

    startButton.update(deltaTime);

    selectButton.update(deltaTime);

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

    //
    // ==================================================
    // Renderiza action buttons
    // ==================================================
    aButton.render(*renderer);

    bButton.render(*renderer);

    startButton.render(*renderer);

    selectButton.render(*renderer);
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

//
// ======================================================
// GameScene::setTouchManager()
// ======================================================
//
// Define sistema multitouch.
//
void GameScene::setTouchManager(
    TouchManager* newTouchManager
)
{
    touchManager = newTouchManager;
}