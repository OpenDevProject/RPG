#include "fase1.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../personagem_principal/personagem_principal.h"

/**
 * @brief Codigo que execute a fase 1
 * 
 * @param personagem O endereco que guarda os dados do personagem
 */
void Fase1(personagem_principal *personagem)
{
    puts("[rei] Voce e o mercenario contratado? ");
    sleep(1);
    puts("[jogador] Sim, estou aqui pela missao de execuçao do Dragao Aither.");
    sleep(1.5);
    puts("[rei] Ja matou algum monstro? ");
    sleep(1);
    puts("[jogador] Alguns pequenos");
    sleep(1);
    puts("[rei] E voce esta confiante em completar essa missao?");
    sleep(1.5);
    puts("[jogador] Para tudo ha uma primeira vez, me esforçarei para trazer uma escama de Aither para voce.");
    sleep(2);
    puts("[rei] Voce deve começar matando os tres Wyverns guardiões para se provar competente o suficiente.");
    sleep(2.5);
    puts("[rei] Nao enviaremos jovens inexperientes para sua morte!");
    sleep(2);
    puts("[rei] Leve essa espada e algumas poções para sua aventura na Floresta Mydra, na qual voce executara o primeiro Wyvern, Radamanthys.");
    
    item espada = ITEM_ESPADA;
    espada.quant = 1;
    
    item pocao = ITEM_POCAO;
    pocao.quant = 10;
    
    item_AdicionarItemAoInventario(espada, personagem->inventario);
    item_AdicionarItemAoInventario(pocao, personagem->inventario);

    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
    {
        printf("%s - %d\n", personagem->inventario[i].nome, personagem->inventario[i].quant);
    }
    

    sleep(2.5);
    puts("(Apos receber a espada e as poções voce parte para a Floresta Mydra para enfrentar Radamanthys.)");
    sleep(1);
    puts("(No caminho para a floresta Mydra voce encontra uma placa descrevendo os perigosos monstros.)");
    sleep(1);
    puts("--------------------- Goblins -------------------");
    puts("--------------------- Slime ---------------------");
    puts("--------------------- Orcs ----------------------");
    puts("--------------------- Bruxa ---------------------");
    puts("--------------------- Elfo ----------------------");
    puts("--------------------- Grifo ---------------------");
    puts("-------------- Radamanthys, Wyvern --------------");
    sleep(1);
    puts("[jogador] Entao essa e a Floresta Mydra!");
    sleep(1);
    puts("(O ventro sopra e nosso heroi percebe o quao profunda e escura e a floresta.) ");
    sleep(1.5);
    puts("(Eis que surge um [adversario] )");
    sleep(1);
    puts("[adversario]");
    sleep(1);
}
