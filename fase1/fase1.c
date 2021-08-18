#include "fase1.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../utils/utils.h"
#include "../sistema_batalha/batalha.h"
#include "../inimigo/inimigo.h"
#include "../personagem_principal/personagem_principal.h"

/**
 * @brief Codigo que execute a fase 1
 * 
 * @param personagem O endereco que guarda os dados do personagem
 */
void Fase1(personagem_principal *personagem)
{
    inimigo inimigoPrincipal;
    puts("[rei] Voce e o mercenario contratado? ");
    SLEEP;
    puts("[jogador] Sim, estou aqui pela missao de execucao do Dragao Aither.");
    SLEEP;
    puts("[rei] Ja matou algum monstro? ");
    SLEEP;
    puts("[jogador] Alguns pequenos");
    SLEEP;
    puts("[rei] E voce esta confiante em completar essa missao?");
    SLEEP;
    puts("[jogador] Para tudo ha uma primeira vez, me esforcarei para trazer uma escama de Aither para voce.");
    SLEEP;
    puts("[rei] Voce deve comecar matando os tres Wyverns guardioes para se provar competente o suficiente.");
    SLEEP;
    puts("[rei] Nao enviaremos jovens inexperientes para sua morte!");
    SLEEP;
    puts("[rei] Leve essa espada e algumas pocoes para sua aventura na Floresta Mydra,\n"
    "na qual voce executara o primeiro Wyvern, Radamanthys.");
    
    item espada = ITEM_ESPADA;
    espada.quant = 1;
    
    item pocao = ITEM_POCAO;
    pocao.quant = 10;
    
    item_AdicionarItemAoInventario(espada, personagem->inventario);
    item_AdicionarItemAoInventario(pocao, personagem->inventario);

    SLEEP;
    puts("(Apos receber a espada e as pocoes voce parte para a Floresta Mydra para enfrentar Radamanthys.)");
    SLEEP;
    puts("(No caminho para a floresta Mydra voce encontra uma placa descrevendo os perigosos monstros.)");
    SLEEP;
    puts("--------------------- Goblins -------------------");
    puts("--------------------- Slime ---------------------");
    puts("--------------------- Orcs ----------------------");
    puts("--------------------- Bruxa ---------------------");
    puts("--------------------- Elfo ----------------------");
    puts("--------------------- Grifo ---------------------");
    puts("-------------- Radamanthys, Wyvern --------------");
    SLEEP;
    puts("[jogador] Entao essa e a Floresta Mydra!");
    SLEEP;
    puts("(O ventro sopra e nosso heroi percebe o quao profunda e escura e a floresta.) ");
    SLEEP;
    puts("(Eis que um Slime roxo gosmento pula em sua direcao com rapidez,\n" 
    "voce so tem tempo de se esquivar e se joga para esquerda)");
    SLEEP;
    puts("[jogador] Realmente nao mentiram quando falaram que os Slimes são muito rapidos,\n"
    "entao eles devem expelir acido pela boca");
    SLEEP;
    printf("Voce se levante, limpa o braço esquerdo que ficou coberto de lama e\n" 
    "pega sua arma e percebe que mais ao fundo no meio das arvores surgem mais slimes,\n"
    "voce conta por cima e sao no minimo 5\n");
    SLEEP;
    printf("Os dois Slimes da frente Lancaram acidos na sua direcao ");
    inimigo_criarSlime(&inimigoPrincipal);
    batalha_menu(personagem, &inimigoPrincipal);
    printf("Apos ganhar o combate contra os Slimes e ter perdido partes de sua roupa Voce segue pelo caminho torcendo para que nao apareca nenhum slime\n");
    printf("Depois de 20 minutos adentrando a floresta voce se depara com um vilarejo com casas pesquenas aparentemente abandonado\n");
    printf("Curioso voce entra nele tentando não fazer barulho e escuta um ruido em seu interior\n");
    printf("Socrr...\n");
    printf("ao chegar numa especie de praca no centro do vilarejo Voce ve uma garota presa a uma Estatua de Dragao tentando gritar e vai tentar ajuda-la\n");
    printf("Entao voce tira o pano da boca dela\n");
    printf("[jogador] O que aconteceu? E quem e voce?\n");
    printf("[Garota] O que voce esta fazendo parado precisamos sair daqui agora\n");
    printf("Voce começa a ouvir barulhos de passos em suas costas e percebe que esta encuralado por uma cidade inteira de Goblins nada simpaticos\n");
    printf("Carregando armas enormes 12 Goblins correm em suas direcoes, voces nao tem saida a nao ser lutar contra eles\n");
    printf("[jogador] voce sabe lutar?\n");
    printf("[Garota] E claro que eu sei, entrar nessa floresta sem saber se defender e setenca de morte, entretanto eles roubaram minha coisas estou desarmada\n");
    printf("[jogador] Toma essa arma emprestada por enquanto\n");
    printf("Logo apos esse rapido dialogo voces comecam a batalhar se ajudando\n");


    printf("Essa foi por pouco, mas voces conseguem derrotar todos os Goblins\n");
    printf("[jogador] cade suas coisas?\n");
    printf("[Garota] ta no forte deles\n");
    printf("[jogador] Tem varias qual delas?\n");
    printf("[Garota] A unica com tamanho normal\n");
    printf("[jogador] AHHHH\n");
    printf("Voces entrao no forte e parece tudo baguncado e sujo e logo encontram a coisa da garota\n");
    printf("[jogador] Voce ainda nao falou seu nome\n");
    printf("[Garota] Ah, eu sou Olivia, e voce?\n");
    printf("[jogador], o que voce veio fazer aqui na Floresta Mydra?\n");
    printf("[Olivia] Matar o Dragao Aither\n");
    printf("[jogador] Que? nao faz sentido eu que fui escolhido pelo Rei para matar ele\n");
    printf("[Olivia] Entao pelo visto voce nao e o unico\n");
    printf("[jogador] Voce e mercenaria tambem?\n");
    printf("[Olivia] Nao, eu sou da guarda do Rei e me ofereci para matar o Dragao\n");
    printf("");
    printf("");
}
