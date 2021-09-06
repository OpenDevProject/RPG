#include "menu_principal.h"

#include "../exit/exit.h"
#include "../utils/utils.h"

#include "../criacao_personagem/criacao_personagem.h"
#include "../introducao/introducao.h"
#include "../fase1/fase1.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INICIAR_HISTORIA 1
#define CREDITOS 2
#define SAIR 3

int creditos()
{
  puts("Creditos: Tiringa");
  return CREDITOS;
}

int IniciandoHistoria(personagem_principal *personagem)
{
  criarPersonagem(personagem);
  Introducao(personagem);
  SLEEP;
  Fase1(personagem);
  
  return INICIAR_HISTORIA;
}

int escolherOpcao()
{
  int valorDigitado;
  scanf("%d", &valorDigitado);

  system(CLEAR);
  clearBuffer();

  return valorDigitado;
}

void imprimirMenu()
{
  puts("MENU PRINCIPAL");
  puts("[1] - Iniciar Jogo");
  puts("[2] - Creditos");
  puts("[3] - Sair");
  printf("Escolha: ");
}

int executarMenuPrincipal(personagem_principal *personagem)
{
  int opcaoEscolhida;

  imprimirMenu();

  opcaoEscolhida = escolherOpcao();

  if (opcaoEscolhida == INICIAR_HISTORIA)
    return IniciandoHistoria(personagem);
  else if (opcaoEscolhida == CREDITOS)
    return creditos();
  else if (opcaoEscolhida == SAIR)
    return SAIR;
}

void MenuPrincipal(personagem_principal *personagem)
{
  while (executarMenuPrincipal(personagem) != SAIR);

  Exit();
}