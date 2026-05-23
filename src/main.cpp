//
// ======================================================
// Inclusão da classe principal da engine
// ======================================================
//
// app.h contém:
//
// - loop principal
// - renderer
// - input
// - entidades
// - sistemas principais da aplicação
//
#include "engine/app.h"

//
// ======================================================
// Função principal da aplicação
// ======================================================
//
// Todo programa C++ começa por aqui.
//
// argc
// → quantidade de argumentos
//
// argv
// → lista de argumentos recebidos
//
// Futuramente isso pode ser usado para:
//
// - modo debug
// - carregar configs
// - escolher perfil
// - iniciar em fullscreen
//
int main(int argc, char* argv[])
{
    //
    // ==================================================
    // Criação da aplicação
    // ==================================================
    //
    // Instancia a classe principal da engine.
    //
    App app;

    //
    // ==================================================
    // Inicialização da engine
    // ==================================================
    //
    // Inicializa:
    //
    // - SDL
    // - janela
    // - renderer
    // - entidades
    // - sistemas internos
    //
    // Se falhar:
    // encerra o programa.
    //
    if (!app.init())
    {
        return -1;
    }

    //
    // ==================================================
    // Loop principal
    // ==================================================
    //
    // Executa:
    //
    // - eventos
    // - update
    // - render
    //
    app.run();

    //
    // ==================================================
    // Encerramento do programa
    // ==================================================
    //
    // 0 = execução bem sucedida
    //
    return 0;
}