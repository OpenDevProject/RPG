#include "criacao_personagem.h"
#include "../utils/utils.h"

#include <string.h>

#include <stdio.h>
#include <stdlib.h>

static void inserirMachadoNoInventario(personagem_principal *personagem)
{
    item machado = ITEM_MACHADO;
    machado.quant = 1;
    item_AdicionarItemAoInventario(machado, personagem->inventario);
}

static int armaSelecionadaForMachado(personagem_principal *personagem)
{
    return personagem->armaSelecionada.code == 2;
}

static void inserirEspadaNoInventario(personagem_principal *personagem)
{
    item espada = ITEM_ESPADA;
    espada.quant = 1;
    item_AdicionarItemAoInventario(espada, personagem->inventario);
}

static int armaSelecionadaForEspada(personagem_principal *personagem)
{
    return personagem->armaSelecionada.code == 1;
}

static void adicionarItemsIniciais(personagem_principal *personagem)
{
    if (armaSelecionadaForEspada(personagem))
        inserirEspadaNoInventario(personagem);
    else if (armaSelecionadaForMachado(personagem))
        inserirMachadoNoInventario(personagem);
    else if (personagem->armaSelecionada.code == 3)
    {
        item punhal = ITEM_PUNHAL;
        punhal.quant = 1;
        item_AdicionarItemAoInventario(punhal, personagem->inventario);
    }
    else if (personagem->armaSelecionada.code == 4)
    {
        item arco = ITEM_ARCO;
        arco.quant = 1;
        item_AdicionarItemAoInventario(arco, personagem->inventario);
    }
    else if (personagem->armaSelecionada.code == 5)
    {
        item fogo = ITEM_FOGO;
        fogo.quant = 1;
        item_AdicionarItemAoInventario(fogo, personagem->inventario);
    }
    else if (personagem->armaSelecionada.code == 6)
    {
        item gelo = ITEM_GELO;
        gelo.quant = 1;
        item_AdicionarItemAoInventario(gelo, personagem->inventario);
    }

    item pocao = ITEM_POCAO;
    pocao.quant = 10;
    item_AdicionarItemAoInventario(pocao, personagem->inventario);
    item recuperarArmadura = ITEM_KIT_DE_ARMADURA;
    recuperarArmadura.quant = 5;
    item_AdicionarItemAoInventario(recuperarArmadura, personagem->inventario);
}

static void inicializarInventario(personagem_principal *personagem)
{
    item_CriarArrayItem(personagem->inventario);
    adicionarItemsIniciais(personagem);
}

static int criarGeloParaMago(personagem_principal *personagem)
{
    printf("Parabens, voce escolheu o gelo\n\n");
    arma_criarGelo(personagem);
}

static int opcaoEscolhidaEGelo(int opcao)
{
    return opcao == 2;
}

static int criarFogoParaMago(personagem_principal *personagem)
{
    printf("Parabens, voce escolheu o fogo\n\n");
    arma_criarFogo(personagem);
}

static int opcaoEscolhidaEFogo(int opcao)
{
    return opcao == 1;
}

static int escolherOpcaoDeElementosMago()
{
    int escolha;

    printf("Escolha seu elemento:\n[1] - Fogo\n[2] - Gelo\n");
    printf("escolha: ");
    scanf("%d", &escolha);
    system(CLEAR);
    clearBuffer();

    return escolha;
}

static void escolherElementosDeMago(personagem_principal *personagem)
{
    int escolha;
    escolha = escolherOpcaoDeElementosMago();

    if (opcaoEscolhidaEFogo(escolha))
        criarFogoParaMago(personagem);
    else if (opcaoEscolhidaEGelo(escolha))
        criarGeloParaMago(personagem);
}

static void inicializarPersonagemComoMago(personagem_principal *personagem)
{
    personagem_principal_criarMago(personagem);

    printf("Parabens, voce escolheu Guerreiro!\n");

    escolherElementosDeMago(personagem);
}

static void criarArcoParaCacador(personagem_principal *personagem)
{
    printf("Parabens, voce escolheu o arco\n\n");
    arma_criarArco(personagem);
}

static int opcaoEscolhidaEArco(int opcao)
{
    return opcao == 2;
}

static void criarPunhalParaCacador(personagem_principal *personagem)
{
    printf("Parabens, voce escolheu o punhal\n\n");
    arma_criarPunhal(personagem);
}

static int opcaoEscolhidaEPunhal(int opcao)
{
    return opcao == 1;
}

static int escolherOpcaoDeArmasCacador()
{
    int escolha;
    printf("Escolha sua arma:\n[1] - Punhal\n[2] - Arco\n");
    printf("escolha: ");
    scanf("%d", &escolha);
    system(CLEAR);
    clearBuffer();

    return escolha;
}

static void escolherArmasDeCacador(personagem_principal *personagem)
{
    int escolha;
    escolha = escolherOpcaoDeArmasCacador();

    if (opcaoEscolhidaEPunhal(escolha))
        criarPunhalParaCacador(personagem);
    else if (opcaoEscolhidaEArco(escolha))
        criarArcoParaCacador(personagem);
}

static void inicializarPersonagemComoCacador(personagem_principal *personagem)
{
    personagem_principal_criarCacador(personagem);

    printf("Parabens, voce escolheu Cacador\n");

    escolherArmasDeCacador(personagem);
}

static void criarMachadoParaGuerreiro(personagem_principal *personagem)
{
    printf("Parabens, voce escolheu o machado\n\n");
    arma_criarMachado(personagem);
}

static int opcaoEscolhidaEMachado(int opcao)
{
    return opcao == 2;
}

static void criarEspadaParaGuerreiro(personagem_principal *personagem)
{
    printf("Parabens, voce escolheu a espada\n\n");
    arma_criarEspada(personagem);
}

static int opcaoEscolhidaEEspada(int opcao)
{
    return opcao == 1;
}

static int escolherOpcaoDeArmasGuerreiro(personagem_principal *personagem)
{
    int escolha;
    printf("Escolha sua arma:\n[1] - Espada\n[2] - Machado\n");
    puts("Opcao: ");
    scanf("%d", &escolha);
    system(CLEAR);
    clearBuffer();

    return escolha;
}

static void escolherArmasDeGuerreiro(personagem_principal *personagem)
{
    int escolha;
    escolha = escolherOpcaoDeArmasGuerreiro(personagem);

    if (opcaoEscolhidaEEspada(escolha))
        criarEspadaParaGuerreiro(personagem);
    else if (opcaoEscolhidaEMachado(escolha))
        criarMachadoParaGuerreiro(personagem);
}

static void inicializarPersonagemComoGuerreiro(personagem_principal *personagem)
{
    personagem_principal_criarGuerreiro(personagem);

    printf("Parabens, voce escolheu Guerreiro!\n");

    escolherArmasDeGuerreiro(personagem);
}

static void escolherClasse(personagem_principal *personagem) //Aqui escolheremos a classe do nosso personagem
{
    while (personagem->classe != 1 && personagem->classe != 2 && personagem->classe != 3)
    {
        printf("Escolha sua classe:\n[1] - Guerreiro\n[2] - Cacador\n[3] - Mago\n"); //nossas opções
        printf("Escolha: ");
        scanf("%d", &personagem->classe);
        system(CLEAR);
        clearBuffer();
    }
}

void criarPersonagem(personagem_principal *personagem)
{
    int arma;
    escolherClasse(personagem);

    if (personagem->classe == 1)
        inicializarPersonagemComoGuerreiro(personagem);
    else if (personagem->classe == 2)
        inicializarPersonagemComoCacador(personagem);
    else if (personagem->classe == 3)
        inicializarPersonagemComoMago(personagem);

    inicializarInventario(personagem);
}