#include "inimigo.h"
#include <string.h>

void inimigo_criarGlobin(inimigo *goblin)
{
    strcpy(goblin->nome, "Goblin");
    goblin->atk = 2;
    goblin->def = 2;
    goblin->mana = 0;
    goblin->velocidade = 5;
    goblin->vida = 4;
    goblin->vidaMax = 4;
}

void inimigo_criarSlime(inimigo *slime)
{
    strcpy(slime->nome, "Slime");
    slime->atk = 1;
    slime->def = 2;
    slime->mana = 0;
    slime->velocidade = 7;
    slime->vida = 4;
    slime->vidaMax = 4;
}

void inimigo_criarOrc(inimigo *orc)
{
    strcpy(orc->nome, "Orc");
    orc->atk = 1;
    orc->def = 2;
    orc->mana = 0;
    orc->velocidade = 5;
    orc->vida = 4;
    orc->vidaMax = 4;
}

void inimigo_criarBruxa(inimigo *bruxa)
{
    strcpy(bruxa->nome, "Bruxa");
    bruxa->atk = 1;
    bruxa->def = 2;
    bruxa->mana = 0;
    bruxa->velocidade = 7;
    bruxa->vida = 4;
    bruxa->vidaMax = 4;
}

void inimigo_criarElfo(inimigo *elfo)
{
    strcpy(elfo->nome, "Elfo");
    elfo->atk = 1;
    elfo->def = 2;
    elfo->mana = 0;
    elfo->velocidade = 7;
    elfo->vida = 4;
    elfo->vidaMax = 4;
}

void inimigo_criarGrifo(inimigo *grifo)
{
    strcpy(grifo->nome, "Grifo");
    grifo->atk = 1;
    grifo->def = 2;
    grifo->mana = 0;
    grifo->velocidade = 7;
    grifo->vida = 4;
    grifo->vidaMax = 4;
}