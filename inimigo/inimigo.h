#ifndef INIMIGOS_H
#define INIMIGOS_H

typedef struct estado estado;

#include "../estado/estado.h"

typedef struct inimigo {
    char nome[10];
    int atk;
    int matk;
    float vida;
    float vidaMax;
    int def;
    int mana;
    int velocidade;
    float quantidadeExp;
    estado estadoAtual;
} inimigo;

void inimigo_criarGlobin(inimigo *goblin);
void inimigo_criarSlime(inimigo *slime);
void inimigo_criarOrc(inimigo *orc);
void inimigo_criarElfo(inimigo *elfo);
void inimigo_criarBruxa(inimigo *bruxa);
void inimigo_criarGrifo(inimigo *grifo);

#endif