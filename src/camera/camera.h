#pragma once

//
// ======================================================
// Classe Camera
// ======================================================
//
// Responsável por:
//
// - posição da câmera
// - viewport do mundo
// - conversão world space → screen space
//
// A câmera NÃO desenha.
//
// Ela apenas define:
//
// "qual parte do mundo aparece na tela"
//
// ======================================================

class Camera
{
public:

    //
    // ==================================================
    // Constructor
    // ==================================================
    //
    // Inicializa câmera na posição padrão.
    //
    Camera();

    //
    // ==================================================
    // follow()
    // ==================================================
    //
    // Faz câmera seguir um alvo.
    //
    // targetX
    // → posição X do alvo
    //
    // targetY
    // → posição Y do alvo
    //
    void follow(float targetX, float targetY);

    //
    // ==================================================
    // getX()
    // ==================================================
    //
    // Retorna posição X da câmera.
    //
    float getX();

    //
    // ==================================================
    // getY()
    // ==================================================
    //
    // Retorna posição Y da câmera.
    //
    float getY();
    
    //
    // ==================================================
    // setX()
    // ==================================================
    //
    // Define posição X.
    //
    void setX(float newX);

    //
    // ==================================================
    // setY()
    // ==================================================
    //
    // Define posição Y.
    //
    void setY(float newY);
    
private:

    //
    // ==================================================
    // Posição da câmera no mundo
    // ==================================================
    //
    float x;
    float y;

    //
    // ==================================================
    // Velocidade de smoothing da câmera
    // ==================================================
    //
    // Controla quão rápido a câmera
    // alcança o alvo.
    //
    float smoothSpeed;

    //
    // ==================================================
    // Tamanho do mundo
    // ==================================================
    //
    // Define limites máximos do mapa.
    //
    float worldWidth;

    float worldHeight;
};