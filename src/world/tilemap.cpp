#include "tilemap.h"

//
// ======================================================
// TileMap::TileMap()
// ======================================================
//
TileMap::TileMap()
{
}

//
// ======================================================
// TileMap::render()
// ======================================================
//
// Renderiza grid do mapa.
//
void TileMap::render(
    Renderer& renderer,
    Camera& camera
)
{
    //
    // Percorre linhas.
    //
    for (int y = 0; y < mapHeight; y++)
    {
        //
        // Percorre colunas.
        //
        for (int x = 0; x < mapWidth; x++)
        {
            //
            // Posição world.
            //
            float worldX =
                x * tileSize;

            float worldY =
                y * tileSize;

            //
            // Cor do tile.
            //
            Uint8 color = 50;

            //
            // Alterna tom.
            //
            if ((x + y) % 2 == 0)
            {
                color = 70;
            }

            //
            // Renderiza tile.
            //
            renderer.drawRect(
                worldX,
                worldY,
                tileSize,
                tileSize,
                color,
                color,
                color,
                camera
            );
        }
    }
}

//
// ======================================================
// TileMap::getWidth()
// ======================================================
//
float TileMap::getWidth()
{
    return mapWidth * tileSize;
}

//
// ======================================================
// TileMap::getHeight()
// ======================================================
//
float TileMap::getHeight()
{
    return mapHeight * tileSize;
}