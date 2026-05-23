#pragma once

//
// ======================================================
// Classe Input
// ======================================================
//
// Responsável por capturar e armazenar
// estados do teclado.
//
// Atualmente o sistema controla:
//
// - W
// - A
// - S
// - D
//
// Futuramente poderá incluir:
//
// - mouse
// - gamepad
// - touch
// - hotkeys
// - macros
// - rebinding
// - múltiplos dispositivos
//
class Input
{
public:

    //
    // ==================================================
    // Estados das teclas
    // ==================================================
    //
    // true  = pressionada
    // false = solta
    //

    //
    // Movimento para cima.
    // Tecla W.
    //
    bool up;

    //
    // Movimento para baixo.
    // Tecla S.
    //
    bool down;

    //
    // Movimento para esquerda.
    // Tecla A.
    //
    bool left;

    //
    // Movimento para direita.
    // Tecla D.
    //
    bool right;

    //
    // ==================================================
    // Construtor
    // ==================================================
    //
    // Inicializa estados do input.
    //
    Input();

    //
    // ==================================================
    // update()
    // ==================================================
    //
    // Atualiza estado atual do teclado.
    //
    // Deve ser chamado a cada frame.
    //
    void update();
};