#include "hud_layout.h"

#include <fstream>

//
// ======================================================
// HUDLayout::save()
// ======================================================
//
// Salva layout em arquivo.
//
bool HUDLayout::save(
    const std::string& path
)
{
    //
    // Abre arquivo.
    //
    std::ofstream file(path);

    //
    // Verifica erro.
    //
    if (!file.is_open())
    {
        return false;
    }

    //
    // ==================================================
    // D-Pad
    // ==================================================
    //
    file << "dpadX=" << dpadX << "\n";

    file << "dpadY=" << dpadY << "\n";

    //
    // ==================================================
    // A Button
    // ==================================================
    //
    file << "aButtonX=" << aButtonX << "\n";

    file << "aButtonY=" << aButtonY << "\n";

    //
    // ==================================================
    // B Button
    // ==================================================
    //
    file << "bButtonX=" << bButtonX << "\n";

    file << "bButtonY=" << bButtonY << "\n";

    //
    // ==================================================
    // START
    // ==================================================
    //
    file << "startX=" << startX << "\n";

    file << "startY=" << startY << "\n";

    //
    // ==================================================
    // SELECT
    // ==================================================
    //
    file << "selectX=" << selectX << "\n";

    file << "selectY=" << selectY << "\n";

    //
    // Fecha arquivo.
    //
    file.close();

    return true;
}

//
// ======================================================
// HUDLayout::load()
// ======================================================
//
// Carrega layout.
//
// Atualmente:
// - versão simples
// - apenas verifica se arquivo existe
//
// Futuramente:
// - parser completo
// - JSON
// - profiles
// - presets
//
bool HUDLayout::load(
    const std::string& path
)
{
    //
    // Abre arquivo.
    //
    std::ifstream file(path);

    //
    // Se não existe:
    //
    // cria padrão.
    //
    if (!file.is_open())
    {
        save(path);

        return true;
    }

    //
    // Futuro parser virá aqui.
    //
    file.close();

    return true;
}