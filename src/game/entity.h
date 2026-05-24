#pragma once

//
// ======================================================
// Inclusão do Renderer
// ======================================================
//
// A Entity utiliza o Renderer para desenhar
// a si mesma na tela.
//
#include "../render/renderer.h"

//
// ======================================================
// Tipos de entidade
// ======================================================
//
// Define categorias de entidades do jogo.
//
// Futuramente será usado para:
//
// - colisão
// - IA
// - filtros
// - eventos
// - networking
// - save/load
//
enum class EntityType
{
    PLAYER,
    NPC,
    ENEMY,
    OBJECT,
    UI
};

//
// ======================================================
// Classe Entity
// ======================================================
//
// Representa um objeto do jogo.
//
// Toda entidade pode possuir:
//
// - posição
// - tamanho
// - cor
// - velocidade
// - lógica
// - renderização
//
// Futuramente essa classe poderá representar:
//
// - player
// - NPCs
// - inimigos
// - botões virtuais
// - objetos do cenário
// - elementos de UI
//
class Entity
{
public:

    //
    // ==================================================
    // Construtor
    // ==================================================
    //
    // Inicializa valores padrões da entidade.
    //
    Entity();

    //
    // ==================================================
    // update()
    // ==================================================
    //
    // Atualiza lógica interna da entidade.
    //
    // IMPORTANTE:
    //
    // A Entity NÃO conhece mais:
    //
    // - teclado
    // - input
    // - WASD
    //
    // Isso agora pertence aos Controllers.
    //
    void update(float deltaTime);

    //
    // ==================================================
    // draw()
    // ==================================================
    //
    // Desenha entidade usando:
    //
    // - renderer
    // - câmera
    //
    void draw(Renderer& renderer, Camera& camera);

    //
    // ==================================================
    // setPosition()
    // ==================================================
    //
    // Define nova posição da entidade.
    //
    void setPosition(float newX, float newY);

    //
    // ==================================================
    // setColor()
    // ==================================================
    //
    // Define nova cor da entidade.
    //
    // RGB:
    // r = vermelho
    // g = verde
    // b = azul
    //
    void setColor(Uint8 newR, Uint8 newG, Uint8 newB);

    //
    // ==================================================
    // getX()
    // ==================================================
    //
    // Retorna posição X.
    //
    float getX();

    //
    // ==================================================
    // getY()
    // ==================================================
    //
    // Retorna posição Y.
    //
    float getY();

    //
    // ==================================================
    // Dados públicos da entidade
    // ==================================================
    //

    //
    // Largura da entidade.
    //
    int width;

    //
    // Altura da entidade.
    //
    int height;

    //
    // Componentes de cor RGB.
    //
    Uint8 r;
    Uint8 g;
    Uint8 b;

    //
    // ==================================================
    // Metadados da entidade
    // ==================================================
    //
    // Informações de gerenciamento da entidade.
    //
    int id;

    EntityType type;

    bool active;

    //
    // ==================================================
    // move()
    // ==================================================
    //
    // Move a entidade usando deslocamento.
    //
    // dx
    // → movimento horizontal
    //
    // dy
    // → movimento vertical
    //
    void move(float dx, float dy);

    //
    // ==================================================
    // getId()
    // ==================================================
    //
    // Retorna ID da entidade.
    //
    int getId();

    //
    // ==================================================
    // getType()
    // ==================================================
    //
    // Retorna tipo da entidade.
    //
    EntityType getType();

    //
    // ==================================================
    // isActive()
    // ==================================================
    //
    // Verifica se entidade está ativa.
    //
    bool isActive();

    //
    // ==================================================
    // setType()
    // ==================================================
    //
    // Define tipo da entidade.
    //
    void setType(EntityType newType);

    //
    // ==================================================
    // setActive()
    // ==================================================
    //
    // Ativa/desativa entidade.
    //
    void setActive(bool state);
private:

    //
    // ==================================================
    // Posição da entidade
    // ==================================================
    //

    //
    // Coordenada horizontal.
    //
    float x;

    //
    // Coordenada vertical.
    //
    float y;

    //
    // ==================================================
    // Velocidade
    // ==================================================
    //
    // Define velocidade de movimentação.
    //
    float speed;
};