#include "touch_manager.h"

//
// ======================================================
// TouchManager::TouchManager()
// ======================================================
//
// Inicializa dedos.
//
TouchManager::TouchManager()
{
    //
    // Nenhum dedo ativo.
    //
    for (int i = 0; i < MAX_FINGERS; i++)
    {
        fingers[i].active = false;
    }
}

//
// ======================================================
// TouchManager::processEvent()
// ======================================================
//
// Processa:
//
// - finger down
// - finger up
// - finger motion
//
void TouchManager::processEvent(SDL_Event& event)
{
    //
    // ==================================================
    // Finger down
    // ==================================================
    //
    if (event.type == SDL_EVENT_FINGER_DOWN)
    {
        //
        // Procura slot livre.
        //
        for (int i = 0; i < MAX_FINGERS; i++)
        {
            if (!fingers[i].active)
            {
                fingers[i].id =
                    event.tfinger.fingerID;

                //
                // SDL touch usa coordenadas
                // normalizadas (0.0 → 1.0).
                //
                fingers[i].x =
                    event.tfinger.x * 800;

                fingers[i].y =
                    event.tfinger.y * 600;

                fingers[i].active = true;

                break;
            }
        }
    }

    //
    // ==================================================
    // Finger up
    // ==================================================
    //
    if (event.type == SDL_EVENT_FINGER_UP)
    {
        for (int i = 0; i < MAX_FINGERS; i++)
        {
            if (
                fingers[i].active &&
                fingers[i].id ==
                event.tfinger.fingerID
            )
            {
                fingers[i].active = false;

                break;
            }
        }
    }

    //
    // ==================================================
    // Finger motion
    // ==================================================
    //
    if (event.type == SDL_EVENT_FINGER_MOTION)
    {
        for (int i = 0; i < MAX_FINGERS; i++)
        {
            if (
                fingers[i].active &&
                fingers[i].id ==
                event.tfinger.fingerID
            )
            {
                fingers[i].x =
                    event.tfinger.x * 800;

                fingers[i].y =
                    event.tfinger.y * 600;

                break;
            }
        }
    }
}

//
// ======================================================
// TouchManager::isTouching()
// ======================================================
//
// Verifica se algum dedo está
// tocando determinada área.
//
bool TouchManager::isTouching(
    float x,
    float y,
    float width,
    float height
)
{
    //
    // Verifica todos os dedos.
    //
    for (int i = 0; i < MAX_FINGERS; i++)
    {
        if (!fingers[i].active)
        {
            continue;
        }

        //
        // Colisão horizontal.
        //
        bool insideX =
            fingers[i].x >= x &&
            fingers[i].x <= x + width;

        //
        // Colisão vertical.
        //
        bool insideY =
            fingers[i].y >= y &&
            fingers[i].y <= y + height;

        //
        // Encontrou toque.
        //
        if (insideX && insideY)
        {
            return true;
        }
    }

    return false;
}