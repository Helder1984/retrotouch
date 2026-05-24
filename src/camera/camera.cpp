#include "camera.h"

//
// ======================================================
// Camera Constructor
// ======================================================
//
// Inicializa câmera na origem do mundo.
//
Camera::Camera()
{
    x = 0.0f;
    y = 0.0f;

    //
    // Velocidade padrão da câmera.
    //
    smoothSpeed = 5.0f;

    //
    // ==================================================
    // Tamanho inicial do mundo
    // ==================================================
    //
    // Futuramente isso virá:
    //
    // - mapa
    // - scene
    // - tilemap
    //
    worldWidth = 2000.0f;

    worldHeight = 2000.0f;
}

//
// ======================================================
// Camera::follow()
// ======================================================
//
// Faz câmera seguir alvo suavemente.
//
// Usa interpolation/smoothing.
//
// Isso cria:
//
// - movimento suave
// - câmera cinematográfica
// - sensação profissional
//
void Camera::follow(float targetX, float targetY)
{
    //
    // ==================================================
    // Centralização da câmera
    // ==================================================
    //
    // A câmera só começa mover
    // depois que o player passa
    // do centro da tela.
    //
    // Isso evita:
    //
    // - câmera negativa
    // - player sumindo
    // - viewport quebrada
    //
    float targetCameraX = x;

    float targetCameraY = y;

    //
    // Centro horizontal.
    //
    if (targetX > 400)
    {
        targetCameraX = targetX - 400;
    }

    //
    // Centro vertical.
    //
    if (targetY > 300)
    {
        targetCameraY = targetY - 300;
    }
    //
    // ==================================================
    // Smooth interpolation
    // ==================================================
    //
    // Aproxima câmera do alvo gradualmente.
    //
    x += (targetCameraX - x) * 0.1f * smoothSpeed;

    y += (targetCameraY - y) * 0.1f * smoothSpeed;

    //
    // ==================================================
    // World bounds
    // ==================================================
    //
    // Impede câmera de sair do mapa.
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
    // 800
    // → largura da janela
    //
    if (x > worldWidth - 800)
    {
        x = worldWidth - 800;
    }

    //
    // 600
    // → altura da janela
    //
    if (y > worldHeight - 600)
    {
        y = worldHeight - 600;
    }
}

//
// ======================================================
// Camera::getX()
// ======================================================
//
// Retorna posição X da câmera.
//
float Camera::getX()
{
    return x;
}

//
// ======================================================
// Camera::getY()
// ======================================================
//
// Retorna posição Y da câmera.
//
float Camera::getY()
{
    return y;
}