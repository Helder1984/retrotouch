#include "player.h"

//
// ======================================================
// Player::getX()
// ======================================================
//
// Retorna a posição horizontal do player.
//
// Usado para:
// - renderização
// - câmera
// - colisão
// - debug
//
float Player::getX()
{
    return x;
}

//
// ======================================================
// Player::getY()
// ======================================================
//
// Retorna a posição vertical do player.
//
// Usado para:
// - renderização
// - câmera
// - colisão
// - debug
//
float Player::getY()
{
    return y;
}