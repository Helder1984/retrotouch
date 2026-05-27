#pragma once

#include "scene.h"

#include "../render/renderer.h"
#include "../input/input.h"
#include "../camera/camera.h"
#include "../game/entity.h"
#include "../controllers/player_controller.h"
#include "../ui/touch_button.h"
#include "../virtual_input/virtual_input.h"
#include "../layout/hud_layout.h"

#include <vector>

//
// ======================================================
// Classe GameScene
// ======================================================
//
// Scene principal de gameplay.
//
// Responsável por:
//
// - entidades
// - câmera
// - gameplay
// - rendering do mundo
//
// ======================================================

class GameScene : public Scene
{
public:

    //
    // Inicializa gameplay.
    //
    void init() override;

    //
    // Atualiza gameplay.
    //
    void update(float deltaTime) override;

    //
    // Renderiza gameplay.
    //
    void render() override;

    //
    // Finaliza gameplay.
    //
    void shutdown() override;

    //
    // ==================================================
    // setRenderer()
    // ==================================================
    //
    // Define renderer da scene.
    //
    void setRenderer(Renderer* newRenderer);

    //
    // ==================================================
    // setInput()
    // ==================================================
    //
    // Define input da scene.
    //
    void setInput(Input* newInput);

    //
    // Define TouchManager.
    //
    void setTouchManager(
        TouchManager* newTouchManager
    );

private:

    //
    // Renderer principal.
    //
    Renderer* renderer = nullptr;

    //
    // Sistema de input.
    //
    Input* input = nullptr;

    //
    // Sistema de câmera.
    //
    Camera camera;

    //
    // Entidades do mundo.
    //
    std::vector<Entity> entities;

    //
    // Controller do player.
    //
    PlayerController playerController;

    //
    // ==================================================
    // D-Pad virtual
    // ==================================================
    //
    // Botões direcionais.
    //
    TouchButton upButton;

    TouchButton downButton;

    TouchButton leftButton;

    TouchButton rightButton;

    //
    // ==================================================
    // Action buttons
    // ==================================================
    //
    // Botões de ação estilo GBA.
    //
    TouchButton aButton;

    TouchButton bButton;

    TouchButton startButton;

    TouchButton selectButton;

    //
    // Sistema de virtual input.
    //
    VirtualInput virtualInput;

    //
    // Sistema multitouch.
    //
    TouchManager* touchManager = nullptr;

    //
    // ==================================================
    // HUD layout
    // ==================================================
    //
    // Configuração visual do HUD.
    //
    HUDLayout hudLayout;

    //
    // ==================================================
    // HUD editor mode
    // ==================================================
    //
    // Permite mover botões.
    //
    bool hudEditMode = false;
};