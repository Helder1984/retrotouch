#pragma once

#include "../render/renderer.h"
#include "../camera/camera.h"

//
// ======================================================
// TileMap
// ======================================================
//
// Responsável por:
//
// - armazenar tiles
// - desenhar mapa
// - definir tamanho do mundo
//
class TileMap
{
public:

    //
    // Constructor.
    //
    TileMap();

    //
    // ==================================================
    // render()
    // ==================================================
    //
    // Renderiza mapa.
    //
    void render(
        Renderer& renderer,
        Camera& camera
    );

    //
    // ==================================================
    // getWidth()
    // ==================================================
    //
    float getWidth();

    //
    // ==================================================
    // getHeight()
    // ==================================================
    //
    float getHeight();

private:

    //
    // Tamanho do tile.
    //
    int tileSize = 64;

    //
    // Quantidade de tiles.
    //
    int mapWidth = 40;

    int mapHeight = 40;
};