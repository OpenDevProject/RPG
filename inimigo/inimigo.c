#include "inimigo.h"
#include <string.h>

void inimigo_criarGlobin(inimigo *goblin)
{
    strcpy(goblin->nome, "Goblin");
    goblin->atk = 7;
    goblin->def = 2;
    goblin->mana = 0;
    goblin->velocidade = 5;
    goblin->vida = 4;
    goblin->vidaMax = goblin->vida;
}