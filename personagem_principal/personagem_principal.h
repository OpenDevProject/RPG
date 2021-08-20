#ifndef PERSONAGEM_PRINCIPAL_H
#define PERSONAGEM_PRINCIPAL_H

#include "../utils/utils.h"

#define MAX_STRING_NAME 10
#define MAX_INVENTARIO_SIZE 50

typedef struct arma
{
    char nomeArma[40];
    int dano;
    int code;
} arma;

typedef struct
{
    char nome[MAX_STRING_SIZE];
    int quant;
    int usavel;
} item;

typedef struct
{
    char nome[MAX_STRING_NAME];
    int classe;
    float atk;
    int matk;
    float vida;
    float vidaMax;
    int def;
    int mana;
    int velocidade;
    arma armaSelecionada;
    item inventario[MAX_INVENTARIO_SIZE];
} personagem_principal;

void personagem_principal_criarGuerreiro(personagem_principal *personagem);
void personagem_principal_criarCacador(personagem_principal *personagem);
void personagem_principal_criarMago(personagem_principal *personagem);
void personagem_recuperarVida(int vidaParaRecuperar, personagem_principal *personagem);

#define ITEM_VAZIO     \
    {                  \
        "VAZIO", -1, 0 \
    }
#define ITEM_POCAO            \
    {                         \
        "Pocao de vida", 0, 1 \
    }
#define ITEM_ESPADA    \
    {                  \
        "Espada", 0, 0 \
    }
#define ITEM_MACHADO    \
    {                   \
        "Machado", 0, 0 \
    }
#define ITEM_PUNHAL    \
    {                  \
        "Punhal", 0, 0 \
    }
#define ITEM_ARCO    \
    {                \
        "Arco", 0, 0 \
    }
#define ITEM_FOGO    \
    {                \
        "Fogo", 0, 0 \
    }
#define ITEM_GELO    \
    {                \
        "Gelo", 0, 0 \
    }

int item_encontrarVazioNoInventario(item inventario[]);
int item_encontrarItemNoInventario(item inventario[], item itemAProcurar);
void item_AdicionarItemAoInventario(item itemParaAdicionar, item inventario[]);
void item_UsarItemDoInventario(item itemParaUsar, personagem_principal *personagem, item inventario[]);
void item_RemoverItemDoInventario(item itemParaRemover, item inventario[]);
void item_CriarArrayItem(item inventario[]);

void arma_criarEspada(personagem_principal *personagem);
void arma_criarMachado(personagem_principal *personagem);
void arma_criarPunhal(personagem_principal *personagem);
void arma_criarArco(personagem_principal *personagem);
void arma_criarFogo(personagem_principal *personagem);
void arma_criarGelo(personagem_principal *personagem);

#endif