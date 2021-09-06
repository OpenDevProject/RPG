#include "personagem_principal.h"
#include "../utils/utils.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void personagem_principal_criarGuerreiro(personagem_principal *personagem)
{
    personagem->atk = 108;
    personagem->matk = 45;
    personagem->level = 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = 10;
    personagem->vida = 89;
    personagem->vidaMax = personagem->vida;
    personagem->def = 177;
    personagem->defMax = personagem->def;
    personagem->mana = 45;
    personagem->velocidade = 36;
    personagem->armaSelecionada.code = 1;
}

void personagem_principal_criarCacador(personagem_principal *personagem)
{
    personagem->atk = 178;
    personagem->matk = 46;
    personagem->level = 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = 10;
    personagem->vida = 89;
    personagem->vidaMax = 10;
    personagem->def = 62;
    personagem->defMax = personagem->def;
    personagem->mana = 46;
    personagem->velocidade = 79;
    personagem->armaSelecionada.code = 3;
}

void personagem_principal_criarMago(personagem_principal *personagem)
{
    personagem->atk = 24;
    personagem->matk = 151;
    personagem->vida = 89;
    personagem->level = 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = 10;
    personagem->vidaMax = 10;
    personagem->def = 35;
    personagem->defMax = personagem->def;
    personagem->mana = 151;
    personagem->velocidade = 50;
    personagem->armaSelecionada.code = 5;
}

static int vidaUltrapassaVidaMaxima(int vidaAtual, int vidaMaxima)
{
    return vidaAtual > vidaMaxima;
}

void personagem_recuperarVida(int vidaParaRecuperar, personagem_principal *personagem)
{
    personagem->vida = personagem->vida + vidaParaRecuperar;
    if (vidaUltrapassaVidaMaxima(personagem->vida, personagem->vidaMax))
        personagem->vida = personagem->vidaMax;
}

void personagem_aumentarStatus(personagem_principal *personagem)
{
    int pontosDisponiveis = 2;
    personagem->level = personagem->level + 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = personagem->expParaProxNivel * 2;

    printf("Parabens, voce aumentou de nivel\n");
    printf("Escolha onde investir os pontos disponiveis!\n");
    while (pontosDisponiveis > 0)
    {
        printf("Quandidade de pontos disponiveis: %d\n", pontosDisponiveis);
        int opcaoEscolhida;
        do
        {
            printf("Digite a opcao dos status para aumentar\n");
            printf("[1] atk\n");
            printf("[2] matk\n");
            printf("[3] vida\n");
            printf("[4] defesa\n");
            printf("[5] mana\n");
            printf("[6] velocidade\n");
            printf("Status para aumentar: ");
            scanf("%d", &opcaoEscolhida);

            switch (opcaoEscolhida)
            {
            case 1:
                personagem->atk = personagem->atk + 20;
                pontosDisponiveis--;
                break;
            case 2:
                personagem->matk = personagem->matk + 20;

                break;
            case 3:
                personagem->vida = personagem->vida + 20;
                personagem->vida = personagem->vidaMax + 20;
                pontosDisponiveis--;
                break;
            case 4:
                personagem->def = personagem->def + 20;
                personagem->defMax = personagem->defMax + 20;
                pontosDisponiveis--;
                break;
            case 5:
                personagem->mana = personagem->mana + 20;
                pontosDisponiveis--;
            case 6:
                personagem->velocidade = personagem->velocidade + 20;
                pontosDisponiveis--;
                break;
            default:
                TratamentoDeErro();
                break;
            }
            system(CLEAR);
        } while (opcaoEscolhida < 1 || opcaoEscolhida > 6);
    }
}

void personagem_aumentarExp(personagem_principal *personagem, float exp)
{
    personagem->exp = personagem->exp + exp;
    if (personagem->exp >= personagem->expParaProxNivel)
        personagem_aumentarStatus(personagem);
}

void personagem_recuperarDef(personagem_principal *personagem, int quantidadeParaRecuperar)
{
    personagem->def = personagem->def + quantidadeParaRecuperar;
    if (personagem->def > personagem->defMax)
        personagem->def = personagem->defMax;
}

void personagem_diminuirDef(personagem_principal *personagem, int quantidadeDeDano)
{
    personagem->def = personagem->def - quantidadeDeDano;
    if (personagem->def < 0)
        personagem->def = 0;
}

void arma_criarEspada(personagem_principal *personagem)
{
    arma *armaAtual = &personagem->armaSelecionada;
    armaAtual->code = 1;
    armaAtual->dano = 1 * (personagem->atk);
    strcpy(armaAtual->nomeArma, "Espada");
}

void arma_criarMachado(personagem_principal *personagem)
{
    arma *armaAtual = &personagem->armaSelecionada;
    armaAtual->code = 2;
    armaAtual->dano = 1.4 * (personagem->atk);
    strcpy(armaAtual->nomeArma, "Machado");
}

void arma_criarPunhal(personagem_principal *personagem)
{
    arma *armaAtual = &personagem->armaSelecionada;
    armaAtual->code = 3;
    armaAtual->dano = 1.05 * (personagem->atk);
    strcpy(armaAtual->nomeArma, "Punhal");
}

void arma_criarArco(personagem_principal *personagem)
{
    arma *armaAtual = &personagem->armaSelecionada;
    armaAtual->code = 4;
    armaAtual->dano = 0.95 * (personagem->atk);
    strcpy(armaAtual->nomeArma, "Arco");
}

void arma_criarFogo(personagem_principal *personagem)
{
    arma *armaAtual = &personagem->armaSelecionada;
    armaAtual->code = 5;
    armaAtual->dano = 1.2 * (personagem->matk);
    strcpy(armaAtual->nomeArma, "Fogo");
}

void arma_criarGelo(personagem_principal *personagem)
{
    arma *armaAtual = &personagem->armaSelecionada;
    armaAtual->code = 6;
    armaAtual->dano = 1.1 * (personagem->matk);
    strcpy(armaAtual->nomeArma, "Gelo");
}