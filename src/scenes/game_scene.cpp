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
// - gameplay
// - HUD
// - touch
// - player
//
void GameScene::update(float deltaTime)
{
    //
    // ==================================================
    // Atualiza D-Pad
    // ==================================================
    //
    upButton.update(deltaTime);

    downButton.update(deltaTime);

    leftButton.update(deltaTime);

    rightButton.update(deltaTime);

    //
    // ==================================================
    // Atualiza action buttons
    // ==================================================
    //
    aButton.update(deltaTime);

    bButton.update(deltaTime);

    startButton.update(deltaTime);

    selectButton.update(deltaTime);

    //
    // ==================================================
    // HUD editor
    // ==================================================
    //
    if (hudEditMode)
    {
        upButton.updateDrag();

        downButton.updateDrag();

        leftButton.updateDrag();

        rightButton.updateDrag();

        aButton.updateDrag();

        bButton.updateDrag();

        startButton.updateDrag();

        selectButton.updateDrag();
    }

    //
    // ==================================================
    // Atualiza HUD layout
    // ==================================================
    //
    hudLayout.aButtonX =
        aButton.getX();

    hudLayout.aButtonY =
        aButton.getY();

    hudLayout.bButtonX =
        bButton.getX();

    hudLayout.bButtonY =
        bButton.getY();

    //
    // Salva layout.
    //
    hudLayout.save(
        "layout.cfg"
    );

    
    //
    // ==================================================
    // Gameplay
    // ==================================================
    //
    // Gameplay apenas quando
    // editor está desligado.
    //
    if (!hudEditMode)
    {
        //
        // Segurança.
        //
        if (!entities.empty())
        {
            playerController.update(
                entities[0],
                input,
                virtualInput,
                tileMap,
                deltaTime
            );

            //
            // ==================================================
            // Camera follow
            // ==================================================
            //
            // Faz câmera seguir player.
            //
            camera.follow(
                entities[0].getX(),
                entities[0].getY()
            );

            //
            // ==================================================
            // World bounds
            // ==================================================
            //
            // Impede câmera de sair
            // do mapa.
            //

            //
            // Limite esquerdo.
            //
            if (camera.getX() < 0)
            {
                camera.setX(0);
            }

            //
            // Limite superior.
            //
            if (camera.getY() < 0)
            {
                camera.setY(0);
            }

            //
            // ==================================================
            // Tamanho do mapa
            // ==================================================
            //
            float mapWidth = 2000;

            float mapHeight = 2000;

            //
            // ==================================================
            // Tamanho da tela
            // ==================================================
            //
            float screenWidth = 800;

            float screenHeight = 600;

            //
            // ==================================================
            // Limite direito
            // ==================================================
            //
            if (
                camera.getX() >
                mapWidth - screenWidth
            )
            {
                camera.setX(
                    mapWidth - screenWidth
                );
            }

            //
            // ==================================================
            // Limite inferior
            // ==================================================
            //
            if (
                camera.getY() >
                mapHeight - screenHeight
            )
            {
                camera.setY(
                    mapHeight - screenHeight
                );
            }
        }
    }

    //
    // ==================================================
    // Atualiza HUD layout
    // ==================================================
    hudLayout.aButtonX =
        aButton.getX();

    hudLayout.aButtonY =
        aButton.getY();

    hudLayout.bButtonX =
        bButton.getX();

    hudLayout.bButtonY =
        bButton.getY();

    //
    // ==================================================
    // Toggle HUD editor
    // ==================================================
    if (
        input &&
        input->toggleHudEditor
    )
    {
        hudEditMode =
            !hudEditMode;
    }

    //
    // Salva layout.
    //
    hudLayout.save(
        "layout.cfg"
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
    // ==================================================
    // Renderiza tilemap
    // ==================================================
    tileMap.render(
        *renderer,
        camera
    );

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

    //
    // ==================================================
    // HUD editor visual
    // ==================================================
    if (hudEditMode)
    {
        //
        // Barra superior.
        //
        renderer->drawScreenRect(
            0,
            0,
            800,
            40,
            120,
            40,
            40
        );
    }
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

//
// ======================================================
// GameScene::getTileMap()
// ======================================================
//
TileMap& GameScene::getTileMap()
{
    return tileMap;
}