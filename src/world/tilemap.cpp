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
    // ==================================================
    // Visible tile range
    // ==================================================
    //
    // Calcula quais tiles
    // estão visíveis.
    //
    int startX =
        camera.getX() / tileSize;

    int startY =
        camera.getY() / tileSize;

    //
    // +2 evita falhas
    // nas bordas.
    //
    int endX =
        startX + 15;

    int endY =
        startY + 12;

    //
    // Segurança.
    //
    if (startX < 0)
    {
        startX = 0;
    }

    if (startY < 0)
    {
        startY = 0;
    }

    if (endX > mapWidth)
    {
        endX = mapWidth;
    }

    if (endY > mapHeight)
    {
        endY = mapHeight;
    }

    //
    // ==================================================
    // Renderiza apenas tiles visíveis
    // ==================================================
    //
    for (int y = startY; y < endY; y++)
    {
        for (int x = startX; x < endX; x++)
        {
            //
            // Posição world.
            //
            float worldX =
                x * tileSize;

            float worldY =
                y * tileSize;

            //
            // Cor base.
            //
            Uint8 color = 50;

            //
            // Alterna padrão.
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