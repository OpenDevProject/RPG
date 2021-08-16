#include "personagem_principal.h"

/**
 * @brief Cria um novo guerreiro e guarda eles no personagem
 * 
 * @param personagem O endereço do personagem a ser usado
 */
void personagem_principal_criarGuerreiro(personagem_principal *personagem)
{
    personagem->atk = 12;
    personagem->matk = 5;
    personagem->vida = 10;
    personagem->vidaMax = personagem->vida;
    personagem->def = 20;
    personagem->mana = 5;
}

/**
 * @brief Cria um novo caçador e guarda eles no personagem
 * 
 * @param personagem O endereço do personagem a ser usado
 */
void personagem_principal_criarCacador(personagem_principal *personagem)
{
    personagem->atk = 20;
    personagem->matk = 5;
    personagem->vida = 10;
    personagem->vidaMax = personagem->vida;
    personagem->def = 15;
    personagem->mana = 5;
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
    personagem->vidaMax = personagem->vida;
    personagem->def = 5;
    personagem->mana = 20;
}

/**
 * @brief Recupera uma certa quantidade de vida do personagem
 * 
 * @param vidaParaRecuperar Quantidade de vida para recuperar
 * @param personagem O endereco do personagem
 */
void personagem_recuperarVida(int vidaParaRecuperar, personagem_principal *personagem)
{
    personagem->vida += vidaParaRecuperar;
    if (personagem->vida > personagem->vidaMax)
        personagem->vida = personagem->vidaMax;
}