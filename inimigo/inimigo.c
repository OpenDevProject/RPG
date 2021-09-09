#include "inimigo.h"

#include <string.h>

void inimigo_criarGlobin(inimigo *goblin)
{
    strcpy(goblin->nome, "Goblin");
    goblin->atk = 20;
    goblin->matk = 0;
    goblin->def = 40;
    goblin->mana = 0;
    goblin->velocidade = 67;
    goblin->vida = 80;
    goblin->vidaMax = 68;
    goblin->quantidadeExp = 2;
    estado_criarNormal(&goblin->estadoAtual);
}

void inimigo_criarSlime(inimigo *slime)
{
    strcpy(slime->nome, "Slime");
    slime->atk = 10;
    slime->matk = 0;
    slime->def = 20;
    slime->mana = 0;
    slime->velocidade = 70;
    slime->vida = 80;
    slime->vidaMax = 80;
    slime->quantidadeExp = 1;
    estado_criarNormal(&slime->estadoAtual);
}

void inimigo_criarOrc(inimigo *orc)
{
    strcpy(orc->nome, "Orc");
    orc->atk = 100;
    orc->matk = 0;
    orc->def = 40;
    orc->mana = 0;
    orc->velocidade = 30;
    orc->vida = 160;
    orc->vidaMax = 160;
    orc->quantidadeExp = 10;
    estado_criarNormal(&orc->estadoAtual);
}

void inimigo_criarBruxa(inimigo *bruxa)
{
    strcpy(bruxa->nome, "Bruxa");
    bruxa->atk = 70;
    bruxa->matk = 16;
    bruxa->def = 20;
    bruxa->mana = 150;
    bruxa->velocidade = 70;
    bruxa->vida = 120;
    bruxa->vidaMax = 120;
    bruxa->quantidadeExp = 20;
    estado_criarNormal(&bruxa->estadoAtual);
}

void inimigo_criarElfo(inimigo *elfo)
{
    strcpy(elfo->nome, "Elfo");
    elfo->atk = 75;
    elfo->matk = 10;
    elfo->def = 80;
    elfo->mana = 10;
    elfo->velocidade = 110;
    elfo->vida = 110;
    elfo->vidaMax = 110;
    elfo->quantidadeExp = 15;
    estado_criarNormal(&elfo->estadoAtual);
}

void inimigo_criarGrifo(inimigo *grifo)
{
    strcpy(grifo->nome, "Grifo");
    grifo->atk = 120;
    grifo->matk = 5;
    grifo->def = 120;
    grifo->mana = 5;
    grifo->velocidade = 120;
    grifo->vida = 240;
    grifo->vidaMax = 14;
    grifo->quantidadeExp = 30;
    estado_criarNormal(&grifo->estadoAtual);
}

void inimigo_criarRadamanthys(inimigo *radamanthys)
{
    strcpy(radamanthys->nome, "Radamanthys");
    radamanthys->atk = 400;
    radamanthys->matk = 10;
    radamanthys->def = 100;
    radamanthys->mana = 10;
    radamanthys->velocidade = 200;
    radamanthys->vida = 300;
    radamanthys->vidaMax = 15;
    radamanthys->quantidadeExp = 50;
    estado_criarNormal(&radamanthys->estadoAtual);
}