#ifndef INIMIGOS_H
#define INIMIGOS_H

typedef struct inimigo {
    char nome[10];
    int atk;
    int vida;
    int vidaMax;
    int def;
    int mana;
    int velocidade;
} inimigo;

void inimigo_criarGlobin(inimigo *goblin);

#endif