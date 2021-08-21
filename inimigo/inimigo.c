#include "inimigo.h"
#include <string.h>

void inimigo_criarGlobin(inimigo *goblin)
{
    strcpy(goblin->nome, "Goblin");
    goblin->atk = 2;
    goblin->matk = 0;
    goblin->def = 2;
    goblin->mana = 0;
    goblin->velocidade = 5;
    goblin->vida = 4;
    goblin->vidaMax = 4;
    goblin->quantidadeExp = 1;
}

void inimigo_criarSlime(inimigo *slime)
{
    strcpy(slime->nome, "Slime");
    slime->atk = 1;
    slime->matk = 0;
    slime->def = 2;
    slime->mana = 0;
    slime->velocidade = 7;
    slime->vida = 8;
    slime->vidaMax = 8;
    slime->quantidadeExp = 1;
}

void inimigo_criarOrc(inimigo *orc)
{
    strcpy(orc->nome, "Orc");
    orc->atk = 12;
    orc->matk = 0;
    orc->def = 10;
    orc->mana = 0;
    orc->velocidade = 7;
    orc->vida = 16;
    orc->vidaMax = 16;
    orc->quantidadeExp = 1;
}

void inimigo_criarBruxa(inimigo *bruxa)
{
    strcpy(bruxa->nome, "Bruxa");
    bruxa->atk = 6;
    bruxa->matk = 16;
    bruxa->def = 2;
    bruxa->mana = 15;
    bruxa->velocidade = 11;
    bruxa->vida = 12;
    bruxa->vidaMax = 12;
    bruxa->quantidadeExp = 1;
}

void inimigo_criarElfo(inimigo *elfo)
{
    strcpy(elfo->nome, "Elfo");
    elfo->atk = 8;
    elfo->matk = 10;
    elfo->def = 9;
    elfo->mana = 10;
    elfo->velocidade = 12;
    elfo->vida = 9;
    elfo->vidaMax = 9;
    elfo->quantidadeExp = 1;
}

void inimigo_criarGrifo(inimigo *grifo)
{
    strcpy(grifo->nome, "Grifo");
    grifo->atk = 15;
    grifo->matk = 5;
    grifo->def = 12;
    grifo->mana = 5;
    grifo->velocidade = 16;
    grifo->vida = 14;
    grifo->vidaMax = 14;
    grifo->quantidadeExp = 1;
}

void inimigo_criarRadamanthys(inimigo *radamanthys)
{
    strcpy(radamanthys->nome, "Radamanthys");
    radamanthys->atk = 15;
    radamanthys->matk = 10;
    radamanthys->def = 13;
    radamanthys->mana = 10;
    radamanthys->velocidade = 14;
    radamanthys->vida = 15;
    radamanthys->vidaMax = 15;
    radamanthys->quantidadeExp = 3;
}