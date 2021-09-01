#include "menu_principal.h"

#include "../exit/exit.h"
#include "../utils/utils.h"

#include "../criacao_personagem/criacao_personagem.h"
#include "../introducao/introducao.h"
#include "../fase1/fase1.h"

#include <stdio.h>
#include <unistd.h>

void IniciandoHistoria(personagem_principal *personagem)
{

  criarPersonagem(personagem);
  Introducao(personagem);
  SLEEP;
  Fase1(personagem);
}

void MenuPrincipal(personagem_principal *personagem)
{
  int opcaoMenuPrincipal;

  do
  {

    puts("MENU PRINCIPAL");
    puts("[1] - Iniciar Jogo");
    puts("[2] - Creditos");
    puts("[3] - Sair");
    printf("Escolha: ");

    scanf("%d", &opcaoMenuPrincipal);
    system(CLEAR);
    clearBuffer();

    switch (opcaoMenuPrincipal)
    {

    case 1:
      IniciandoHistoria(personagem);
      break;

    case 2:
      puts("Creditos: Tiringa");
      break;

    case 3:
      Exit();
      return;
      break;

    default:
      TratamentoDeErro();
    }
  } while (opcaoMenuPrincipal);
}