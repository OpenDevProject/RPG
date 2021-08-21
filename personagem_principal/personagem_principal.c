#include "personagem_principal.h"

#include <string.h>
#include <stdio.h>

/**
 * @brief Cria um novo guerreiro e guarda eles no personagem
 * 
 * @param personagem O endereço do personagem a ser usado
 */
void personagem_principal_criarGuerreiro(personagem_principal *personagem)
{
    personagem->atk = 12;
    personagem->matk = 5;
    personagem->level = 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = 10;
    personagem->vida = 10;
    personagem->vidaMax = personagem->vida;
    personagem->def = 20;
    personagem->mana = 5;
    personagem->velocidade = 4;
    personagem->armaSelecionada.code = 1;
}

/**
 * @brief Cria um novo caçador e guarda eles no personagem
 * 
 * @param personagem O endereço do personagem a ser usado
 */
void personagem_principal_criarCacador(personagem_principal *personagem)
{
    personagem->atk = 16;
    personagem->matk = 5;
    personagem->level = 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = 10;
    personagem->vida = 10;
    personagem->vidaMax = 10;
    personagem->def = 5;
    personagem->mana = 5;
    personagem->velocidade = 8;
    personagem->armaSelecionada.code = 3;
}

/**
 * @brief Cria um novo mago e guarda eles no personagem
 * 
 * @param personagem O endereço do personagem a ser usado
 */
void personagem_principal_criarMago(personagem_principal *personagem)
{
    personagem->atk = 5;
    personagem->matk = 20;
    personagem->vida = 10;
    personagem->level = 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = 10;
    personagem->vidaMax = 10;
    personagem->def = 5;
    personagem->mana = 20;
    personagem->velocidade = 6;
    personagem->armaSelecionada.code = 5;
}

/**
 * @brief Recupera uma certa quantidade de vida do personagem
 * 
 * @param vidaParaRecuperar Quantidade de vida para recuperar
 * @param personagem O endereco do personagem
 */
void personagem_recuperarVida(int vidaParaRecuperar, personagem_principal *personagem)
{
    personagem->vida = personagem->vida + vidaParaRecuperar;
    if (personagem->vida > personagem->vidaMax)
        personagem->vida = personagem->vidaMax;
}

void personagem_aumentarStatus(personagem_principal *personagem)
{
    int pontosDisponiveis = 2;
    personagem->level = personagem->level + 1;
    personagem->exp = 0;
    personagem->expParaProxNivel = personagem->expParaProxNivel * 2;

    while(pontosDisponiveis > 0)
    {
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
                personagem->atk = personagem->atk + 1;
                pontosDisponiveis--;
                break;
            case 2:
                personagem->matk = personagem->matk + 1;
                
                break;
            case 3:
                personagem->vida = personagem->vida + 1;
                pontosDisponiveis--;
                break;
            case 4:
                personagem->def = personagem->def + 1;
                pontosDisponiveis--;
                break;
            case 5:
                personagem->mana = personagem->mana + 1;
                pontosDisponiveis--;
            case 6:
                personagem->velocidade = personagem->velocidade + 1;
                pontosDisponiveis--;
                break;
            default:
                break;
            }
        } while (opcaoEscolhida < 1 || opcaoEscolhida > 6);
    }
}

void personagem_aumentarExp(personagem_principal *personagem, float exp)
{
    personagem->exp = personagem->exp + 1;
    if (personagem->exp >= personagem->expParaProxNivel)
        personagem_aumentarStatus(personagem);
}

void arma_criarEspada(personagem_principal *personagem)
{
    personagem->armaSelecionada.code = 1;
    personagem->armaSelecionada.dano = 1 * (personagem->atk);
    strcpy(personagem->armaSelecionada.nomeArma, "Espada");
}

void arma_criarMachado(personagem_principal *personagem)
{
    personagem->armaSelecionada.code = 2;
    personagem->armaSelecionada.dano = 1.4 * (personagem->atk);
    strcpy(personagem->armaSelecionada.nomeArma, "Machado");
}

void arma_criarPunhal(personagem_principal *personagem)
{
    personagem->armaSelecionada.code = 3;
    personagem->armaSelecionada.dano = 1.05 * (personagem->atk);
    strcpy(personagem->armaSelecionada.nomeArma, "Punhal");
}

void arma_criarArco(personagem_principal *personagem)
{
    personagem->armaSelecionada.code = 4;
    personagem->armaSelecionada.dano = 0.95 * (personagem->atk);
    strcpy(personagem->armaSelecionada.nomeArma, "Arco");
}

void arma_criarFogo(personagem_principal *personagem)
{
    personagem->armaSelecionada.code = 5;
    personagem->armaSelecionada.dano = 1.2 * (personagem->atk);
    strcpy(personagem->armaSelecionada.nomeArma, "Fogo");
}

void arma_criarGelo(personagem_principal *personagem)
{
    personagem->armaSelecionada.code = 6;
    personagem->armaSelecionada.dano = 1.1 * (personagem->atk);
    strcpy(personagem->armaSelecionada.nomeArma, "Gelo");
}