#pragma once

//
// ======================================================
// Classe Scene
// ======================================================
//
// Classe base para todas as scenes.
//
// Exemplos:
//
// - menu
// - gameplay
// - overlay
// - configurações
//
// ======================================================

class Scene
{
public:

    //
    // ==================================================
    // init()
    // ==================================================
    //
    // Inicializa recursos da scene.
    //
    virtual void init() = 0;

    //
    // ==================================================
    // update()
    // ==================================================
    //
    // Atualiza lógica da scene.
    //
    virtual void update(float deltaTime) = 0;

    //
    // ==================================================
    // render()
    // ==================================================
    //
    // Renderiza elementos da scene.
    //
    virtual void render() = 0;

    //
    // ==================================================
    // shutdown()
    // ==================================================
    //
    // Libera recursos da scene.
    //
    virtual void shutdown() = 0;

    //
    // Destructor virtual
    //
    virtual ~Scene() {}
};