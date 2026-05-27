#pragma once

//
// ======================================================
// Enum VirtualButton
// ======================================================
//
// Representa botões virtuais.
//
// Futuramente:
//
// - controles touch
// - gamepad
// - emulador
// - gestures
//
// ======================================================

enum class VirtualButton
{
    NONE,

    UP,
    DOWN,
    LEFT,
    RIGHT,

    A,
    B,

    START,
    SELECT
};

//
// ======================================================
// Classe VirtualInput
// ======================================================
//
// Camada de input virtual.
//
// Responsável por:
//
// - armazenar estados
// - desacoplar input físico
// - enviar comandos ao jogo
// - enviar comandos ao emulador
//
// ======================================================

class VirtualInput
{
public:

    //
    // Constructor.
    //
    VirtualInput();

    //
    // ==================================================
    // setButton()
    // ==================================================
    //
    // Define estado de botão virtual.
    //
    void setButton(
        VirtualButton button,
        bool pressed
    );

    //
    // ==================================================
    // isPressed()
    // ==================================================
    //
    // Verifica estado do botão.
    //
    bool isPressed(VirtualButton button);

    //
    // ==================================================
    // Get button state
    // ==================================================
    //
    // Retorna estado do botão.
    //
    bool getButton(
        VirtualButton button
    );

private:

    //
    // ==================================================
    // Estados dos botões
    // ==================================================
    //
    bool up;

    bool down;

    bool left;

    bool right;

    bool a;

    bool b;

    bool start;

    bool select;
};