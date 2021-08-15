#include "menu_principal.h"

#include "../exit/exit.h"
#include "../utils/utils.h"

#include "../criacao_personagem/criacao_personagem.h"
#include "../introducao/introducao.h"
#include "../fase1/fase1.h"

#include <stdio.h>

/**
 * @brief Inicia a história do jogo
 * 
 * @param personagem O endereço do personagem para ser utilizado na história
 */
void IniciandoHistoria(personagem_principal *personagem)
{
    CriandoPersonagem(personagem);
    Introducao(*personagem);
    Fase1(personagem);
}

/**
 * @brief O menu principal mostrado no inicio do jogo
 * 
 * @param personagem O endereço do personagem para ser utilizado na história
 */
void MenuPrincipal(personagem_principal *personagem)
{
    int opcaoMenuPrincipal;

    do
    {
        puts("MENU PRINCIPAL");
        puts("[1] - Iniciar Jogo");
        puts("[2] - Créditos");
        puts("[3] - Sair");

        switch (opcaoMenuPrincipal)
        {

        case 1:
            IniciandoHistoria(personagem);
            break;

        case 2:
            puts("Créditos: Tiringa");
            break;

        case 3:
            Exit();
            break;

        default:
            TratamentoDeErro();
        }
    } while (1);
}