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
    printf("[rei] Voce eh o mercenario contratado? \n");
    SLEEP;
    printf("[%s] Sim, estou aqui pela missao de execucao do Dragao Aither.\n", personagem->nome);
    SLEEP;
    printf("[rei] Ja matou algum monstro? \n");
    SLEEP;
    printf("[%s] Alguns pequenos\n", personagem->nome);
    cringe();
    SLEEP;
    printf("[rei] E voce esta confiante em completar essa missao?\n");
    SLEEP;
    printf("[%s] Para tudo ha uma primeira vez, me esforcarei\n"
           "para trazer uma escama de Aither para voce.\n", personagem->nome);
    SLEEP;
    printf("[rei] Voce deve comecar matando os tres Wyverns guardioes\n");
    printf("para se provar competente o suficiente.\n");
    SLEEP;
    printf("[rei] Nao enviaremos jovens inexperientes para sua morte!\n");
    SLEEP;
    printf("[rei] Leve essa %s e algumas pocoes para sua aventura na Floresta Mydra,\n", personagem->nomeArma);
    printf("na qual voce executara o primeiro Wyvern, Radamanthys.\n");

    if (personagem->arma == 1)
    {
        item espada = ITEM_ESPADA;
        espada.quant = 1;
        item_AdicionarItemAoInventario(espada, personagem->inventario);
    }
    else if (personagem->arma == 2)
    {
        item machado = ITEM_MACHADO;
        machado.quant = 1;
        item_AdicionarItemAoInventario(machado, personagem->inventario);
    }
    else if (personagem->arma == 3)
    {
        item punhal = ITEM_PUNHAL;
        punhal.quant = 1;
        item_AdicionarItemAoInventario(punhal, personagem->inventario);
    }
    else if (personagem->arma == 4)
    {
        item arco = ITEM_ARCO;
        arco.quant = 1;
        item_AdicionarItemAoInventario(arco, personagem->inventario);
    }
    else if (personagem->arma == 5)
    {
        item fogo = ITEM_FOGO;
        fogo.quant = 1;
        item_AdicionarItemAoInventario(fogo, personagem->inventario);
    }
    else if (personagem->arma == 6)
    {;
        item gelo = ITEM_GELO;
        gelo.quant = 1;
        item_AdicionarItemAoInventario(gelo, personagem->inventario);
    }

    item pocao = ITEM_POCAO;
    pocao.quant = 10;

    item_AdicionarItemAoInventario(pocao, personagem->inventario);
    SLEEP;
    printf("(Apos receber a(o) %s e as pocoes voce parte \n"
           "para a Floresta Mydra para enfrentar Radamanthys.)\n",
           personagem->nomeArma);
    SLEEP;
    printf("(No caminho para a floresta Mydra voce encontra \n"
           "uma placa descrevendo os perigosos monstros.)\n");
    SLEEP;
    printf("--------------------- Goblins -------------------\n");
    printf("--------------------- Slime ---------------------\n");
    printf("--------------------- Orcs ----------------------\n");
    printf("--------------------- Bruxa ---------------------\n");
    printf("--------------------- Elfo ----------------------\n");
    printf("--------------------- Grifo ---------------------\n");
    printf("-------------- Radamanthys, Wyvern --------------\n");
    SLEEP;
    SLEEP;
    printf("[%s] Entao essa e a Floresta Mydra!\n", personagem->nome);
    SLEEP;
    printf("(O vento sopra e nosso heroi percebe o quao profunda e escura eh a floresta.) \n");
    SLEEP;
    printf("(Eis que um Slime roxo gosmento pula em sua direcao com rapidez,\n"
           "voce so tem tempo de se esquivar e se joga para esquerda)\n");
    SLEEP;
    printf("[%s] Realmente nao mentiram quando falaram que os Slimes são muito rapidos,\n"
           "entao eles devem expelir acido pela boca",
           personagem->nome);
    SLEEP;
    printf("Voce se levanta, limpa o braço esquerdo que ficou coberto de lama e\n");
    printf("pega sua arma e percebe que mais ao fundo no meio das arvores surgem mais slimes,\n");
    SLEEP;
    printf("voce conta por cima e sao no minimo 5\n");
    printf("Os dois Slimes da frente Lancaram acidos na sua direcao\n ");
    SLEEP;

    inimigo_criarSlime(&inimigoPrincipal);
    batalha_menu(personagem, &inimigoPrincipal);

    printf("Apos ganhar o combate contra os Slimes e ter perdido partes de\n"
           " sua roupa Voce segue pelo caminho torcendo para que nao apareca nenhum slime\n");
    SLEEP;
    printf("Depois de 20 minutos adentrando a floresta voce se depara com um\n"
           "vilarejo com casas pesquenas aparentemente abandonado\n");
    SLEEP;
    printf("Curioso voce entra nele tentando não fazer barulho e escuta \n"
           "um ruido em seu interior\n");
    SLEEP;
    printf("Socorro...\n");
    SLEEP;
    printf("ao chegar numa especie de praca no centro do vilarejo, voce ve \n"
           "uma garota presa a uma Estatua de Dragao tentando gritar e vai tentar ajuda-la\n");
    SLEEP;
    printf("Entao voce tira o pano da boca dela\n");
    SLEEP;
    printf("[%s] O que aconteceu? E quem e voce?\n", personagem->nome);
    SLEEP;
    printf("[Garota] O que voce esta fazendo parado precisamos sair daqui agora\n");
    SLEEP;
    printf("Voce começa a ouvir barulhos de passos em suas costas e percebe que \n"
           "esta encuralado por uma cidade inteira de Goblins nada simpaticos\n");
    SLEEP;
    printf("Carregando armas enormes 12 Goblins correm em suas direcoes,\n"
           "voces nao tem saida a nao ser lutar contra eles\n");
    SLEEP;
    printf("[%s] voce sabe lutar?\n", personagem->nome);
    SLEEP;
    printf("[Garota] E claro que eu sei, entrar nessa floresta sem saber se \n"
           "defender e setenca de morte, entretanto eles roubaram minha coisas estou desarmada\n");
    SLEEP;
    printf("[%s] Toma essa arma emprestada por enquanto\n", personagem->nome);
    SLEEP;
    printf("Logo apos esse rapido dialogo voces comecam a batalhar se ajudando\n");
    SLEEP;

    SLEEP;
    printf("Essa foi por pouco, mas voces conseguem derrotar todos os Goblins\n");
    SLEEP;
    printf("[%s] cade suas coisas?\n", personagem->nome);
    SLEEP;
    printf("[Garota] ta no forte deles\n");
    SLEEP;
    printf("[%s] Tem varias qual delas?\n", personagem->nome);
    SLEEP;
    printf("[Garota] A unica com tamanho normal\n");
    SLEEP;
    printf("[%s] AHHHH\n", personagem->nome);
    SLEEP;
    printf("Voces entrao no forte e parece tudo baguncado e sujo,\n"
           "e logo encontram as coisas da garota\n");
    SLEEP;
    printf("[%s] Voce ainda nao falou seu nome\n", personagem->nome);
    SLEEP;
    printf("[Garota] Ah, eu sou Olivia, e voce?\n");
    SLEEP;
    printf("[%s], o que voce veio fazer aqui na Floresta Mydra?\n", personagem->nome);
    SLEEP;
    printf("[Olivia] Matar o Dragao Aither\n");
    SLEEP;
    printf("[%s] Que? nao faz sentido... \n"
           "Eu que fui escolhido pelo Rei para matar ele\n", personagem->nome);
    SLEEP;
    printf("[Olivia] Entao pelo visto voce nao e o unico\n");
    SLEEP;
    printf("[%s] Voce e mercenaria tambem?\n", personagem->nome);
    SLEEP;
    printf("[Olivia] Nao, eu sou da guarda do Rei e me ofereci para matar o Dragao\n");
    SLEEP;
    printf("\n");
    printf("\n");
}
