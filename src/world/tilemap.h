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

    //
    // ==================================================
    // isSolidTile()
    // ==================================================
    //
    // Verifica se tile é sólido.
    //
    bool isSolidTile(
        int tileX,
        int tileY
    );

    //
    // ==================================================
    // isColliding()
    // ==================================================
    //
    // Verifica colisão world.
    //
    bool isColliding(
        float x,
        float y,
        float width,
        float height
    );

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