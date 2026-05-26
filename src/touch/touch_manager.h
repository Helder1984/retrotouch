#pragma once

#include <SDL3/SDL.h>

//
// ======================================================
// Struct TouchFinger
// ======================================================
//
// Representa um dedo na tela.
//
// SDL suporta múltiplos dedos simultâneos.
//
// ======================================================

struct TouchFinger
{
    //
    // ID do dedo.
    //
    SDL_FingerID id;

    //
    // Posição.
    //
    float x;

    float y;

    //
    // Estado.
    //
    bool active;
};

//
// ======================================================
// Classe TouchManager
// ======================================================
//
// Gerencia:
//
// - multitouch
// - dedos ativos
// - touch state
//
// ======================================================

class TouchManager
{
public:

    //
    // Constructor.
    //
    TouchManager();

    //
    // ==================================================
    // processEvent()
    // ==================================================
    //
    // Processa eventos touch SDL.
    //
    void processEvent(SDL_Event& event);

    //
    // ==================================================
    // isTouching()
    // ==================================================
    //
    // Verifica se existe dedo
    // em determinada área.
    //
    bool isTouching(
        float x,
        float y,
        float width,
        float height
    );

private:

    //
    // ==================================================
    // Limite inicial de dedos
    // ==================================================
    //
    static const int MAX_FINGERS = 10;

    //
    // Dedos ativos.
    //
    TouchFinger fingers[MAX_FINGERS];
};