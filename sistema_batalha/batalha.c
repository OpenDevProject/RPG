#include "batalha.h"
#include "../utils/utils.h"
#include "../dado/dado.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Sair do sistema de batalha
 * 
 * @param personagem O endereço do personagem utilizado
 */
void batalha_fsair(personagem_principal *personagem, inimigo *inimigoParaBatalha)
{
  // Duas formas de sair
  // A primeira é se a vida do personagem for menor que zero
  // Isso significará que ele terá sido derrotado e o jogo finalizará
  if (personagem->vida <= 0)
  {
    printf("GAME OVER!\n\nVoce foi derrotado!\nTente novamente!\n");
    sleep(5);
    exit(0);
  }
  // Caso ele não tenha sido derrotado o inimigo foi
  // Nesse caso apenas irá imprimir uma mensagem de vitória e pedirá para pressionar enter
  else
  {
    printf("Voce derrotou o %s!\n", inimigoParaBatalha->nome);
    printf("Voce ganhou %.1f de xp.\n", inimigoParaBatalha->quantidadeExp);
    personagem_aumentarExp(personagem, inimigoParaBatalha->quantidadeExp);
    printf("Pressione enter para proseguir!\n\n");
    clearBuffer();
    getchar();
  }
}

/**
 * @brief Tratamento de erro para a batalha
 * 
 * @param personagem O endereço do personagem utilizado na batalha
 * @param inimigoParaBatalha O endereço do inimigo utilizado na batalha
 * @param usandoItem Um valor booleano que dirá se está usando um item ou não
 */
void tratamento(personagem_principal *personagem, inimigo *inimigoParaBatalha, int usandoItem)
{
  // Aqui existem duas possibilidades, uma que se refere se o item está sendo utilizado
  // e a outra se for um erro comum

  // Caso esteja usando o item (ou seja ele seja igual a 1)
  if (usandoItem)
  {
    puts("Esse item nao pode ser utilizado!");
  }
  // Se não será apenas uma opção inválida
  else
  {
    puts("Opcao invalida!");
  }
  sleep(1.5);
  system(CLEAR);
  batalha_menu(personagem, inimigoParaBatalha);
}

/**
 * @brief Executa o ataque do personagem controlado pelo jogador
 * 
 * @param personagem O endereço do personagem usado no combate
 * @param inimigoParaBatalha O endereço do inimigo usado no combate
 * @return int Retorna um valor 0 se tiver sido executado com sucesso
 */
int batalha_personagemAtaca(personagem_principal *personagem, inimigo *inimigoParaBatalha)
{
  int dado = RolarDado(time(NULL) + 12);

  switch (dado)
  {
  case 0:
    printf("O %s se esquivou.\n\n", inimigoParaBatalha->nome);
    break;

  case 1:
    printf("%s ataca o %s - dano %f\n", personagem->nome, inimigoParaBatalha->nome, personagem->armaSelecionada.dano);
    inimigoParaBatalha->vida = inimigoParaBatalha->vida - personagem->armaSelecionada.dano;
    if (inimigoParaBatalha->vida <= 0)
    {
      batalha_fsair(personagem, inimigoParaBatalha);
      return 0;
    }
    break;

  case 2:
    printf("%s ataca o %s - dano %f\n", personagem->nome, inimigoParaBatalha->nome, personagem->armaSelecionada.dano);
    inimigoParaBatalha->vida = inimigoParaBatalha->vida - personagem->armaSelecionada.dano;
    if (inimigoParaBatalha->vida <= 0)
    {
      batalha_fsair(personagem, inimigoParaBatalha);
      return 0;
    }
    break;

  case 3:
    printf("%s ataca o %s com um critico - dano %f\n", personagem->nome, inimigoParaBatalha->nome, personagem->armaSelecionada.dano);
    inimigoParaBatalha->vida = inimigoParaBatalha->vida - (personagem->armaSelecionada.dano * 1.5);
    if (inimigoParaBatalha->vida <= 0)
    {
      batalha_fsair(personagem, inimigoParaBatalha);
      return 0;
    }
    break;

  default:
    return 1;
    break;
  }
}

int batalha_inimigoAtaca(personagem_principal *personagem, inimigo *inimigoParaBatalha)
{
  int dado = RolarDado(time(NULL) + 35);

  int danoCausado = inimigoParaBatalha->atk - personagem->def;

  personagem_diminuirDef(personagem, inimigoParaBatalha->atk);

  if (danoCausado <= 0)
  {
    printf("Sua armadura te protegeu do dano\n");
    return 0;
  }

  switch (dado)
  {
  case 0:
    printf("%s se esquivou.\n", personagem->nome);
    break;

  case 1:
    printf("%s ataca o %s - dano %f\n", inimigoParaBatalha->nome, personagem->nome, personagem->armaSelecionada.dano);
    personagem->vida = personagem->vida - danoCausado;
    if (personagem->vida <= 0)
    {
      batalha_fsair(personagem, inimigoParaBatalha);
      return 0;
    }
    break;

  case 2:
    printf("%s ataca o %s - dano %f\n", inimigoParaBatalha->nome, personagem->nome, personagem->armaSelecionada.dano);
    personagem->vida = personagem->vida - danoCausado;
    if (personagem->vida <= 0)
    {
      batalha_fsair(personagem, inimigoParaBatalha);
      return 0;
    }
    break;

  case 3:
    printf("%s ataca o %s com um critico - dano %f\n", inimigoParaBatalha->nome, personagem->nome, personagem->armaSelecionada.dano);
    personagem->vida = personagem->vida - (danoCausado * 1.5);
    if (personagem->vida <= 0)
    {
      batalha_fsair(personagem, inimigoParaBatalha);
      return 0;
    }
    break;

  default:
    break;
  }
}

// int batalha_personagemAtaca_Magia(personagem_principal *personagem, inimigo *inimigoParaBatalha)
// {
//   int dado = RolarDado(time(NULL) + 12);

//   switch (dado)
//   {
//   case 0:
//     printf("O %s se esquivou.\n", inimigoParaBatalha->nome);
//     break;

//   case 1:
//     inimigoParaBatalha->vida = inimigoParaBatalha->vida - personagem->armaSelecionada.dano;
//     printf("%s ataca o %s\n", personagem->nome, inimigoParaBatalha->nome);
//     if (inimigoParaBatalha->vida <= 0)
//     {
//       batalha_fsair(personagem, inimigoParaBatalha);
//       return 0;
//     }
//     break;

//   case 2:
//     inimigoParaBatalha->vida = inimigoParaBatalha->vida - personagem->armaSelecionada.dano;
//     printf("%s ataca o %s\n", personagem->nome, inimigoParaBatalha->nome);
//     if (inimigoParaBatalha->vida <= 0)
//     {
//       batalha_fsair(personagem, inimigoParaBatalha);
//       return 0;
//     }
//     break;

//   case 3:
//     inimigoParaBatalha->vida = inimigoParaBatalha->vida - (personagem->armaSelecionada.dano * 1.5);
//     printf("%s ataca o %s com um critico\n", personagem->nome, inimigoParaBatalha->nome);
//     if (inimigoParaBatalha->vida <= 0)
//     {
//       batalha_fsair(personagem, inimigoParaBatalha);
//       return 0;
//     }
//     break;

//   default:
//     return 1;
//     break;
//   }

//   inimigoParaBatalha->vida = inimigoParaBatalha->vida - personagem->matk;
//   personagem->vida -= personagem->mana;
//   if (inimigoParaBatalha->vida <= 0)
//   {
//     batalha_fsair(personagem, inimigoParaBatalha);
//     cringe();
//     return 0;
//   }
//   batalha_menu(personagem, inimigoParaBatalha);
// }

// int batalha_inimigoAtaca_Magia(personagem_principal *personagem, inimigo *inimigoParaBatalha)
// {
//   int dado = RolarDado();
//   printf("Esse foi o seu resultado: %d\n", dado);
//   personagem->vida = personagem->vida - inimigoParaBatalha->matk;
//   inimigoParaBatalha->mana -= inimigoParaBatalha->matk;
//   if (personagem->vida <= 0)
//   {
//     batalha_fsair(personagem, inimigoParaBatalha);
//     cringe();
//     return 0;
//   }
//   batalha_menu(personagem, inimigoParaBatalha);
// }

int batalha_inventario(personagem_principal *personagem, inimigo *inimigoParaBatalha)
{
  int i = 0, opcao, validos[MAX_INVENTARIO_SIZE];
  for (i; i < MAX_INVENTARIO_SIZE; i++)
  {
    if (strcmp(personagem->inventario[i].nome, "VAZIO") != 0 && personagem->inventario[i].quant != -1)
    {
      printf("[%d] - %s - %d\n", i + 1, personagem->inventario[i].nome, personagem->inventario[i].quant);
      validos[i] = i + 1;
    }
  }
  printf("[%d] - %s\n", 0, "Sair");
  scanf("%d", &opcao);
  clearBuffer();
  if (opcao == 0)
  {
    batalha_menu(personagem, inimigoParaBatalha);
    return 0;
  }
  for (int j = 0; j < MAX_INVENTARIO_SIZE; j++)
  {
    if (opcao == validos[j] && personagem->inventario[opcao - 1].usavel)
    {
      item_UsarItemDoInventario(personagem->inventario[opcao - 1], personagem, personagem->inventario);
      return 1;
    }
  }
  tratamento(personagem, inimigoParaBatalha, 1);
  return 0;
}

// typedef struct
// {
//     char nome[MAX_STRING_SIZE];
//     int quant;
//     int usavel;
// } item;

// ITEM_ESPADA {NOME:"Espada", QUANT:0, USAVEL:0}

void batalha_menu(personagem_principal *personagem, inimigo *inimigoParaBatalha) // Colocar o inimigo aqui
{
  int opcao, utilizouAlgo;

  puts("================");
  printf("VIDA DO %s: %.1f\n", personagem->nome, personagem->vida);
  printf("VIDA DO %s: %.1f\n", inimigoParaBatalha->nome, inimigoParaBatalha->vida);
  puts("================");
  printf("\n");
  printf("XP atual: %.1f pontos\n", personagem->exp);
  printf("XP nescessario para subir de nivel: %.1f pontos\n\n", (personagem->expParaProxNivel - personagem->exp));
  printf("Armadura atual: %d\n", personagem->def);
  printf("\n");
  puts("================");
  puts("Digite uma opcao");
  puts("[1] - Atacar");
  puts("[2] - Inventario");
  // puts("[3] - Sair");
  puts("================");
  clearBuffer();
  printf("Escolha: ");
  scanf("%d", &opcao);
  system(CLEAR);
  if (personagem->velocidade > inimigoParaBatalha->velocidade)
  {
    switch (opcao)
    {
    case 1:
      batalha_personagemAtaca(personagem, inimigoParaBatalha);
      if (inimigoParaBatalha->vida <= 0)
        break;
      batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      batalha_menu(personagem, inimigoParaBatalha);

      break;
    case 2:
      utilizouAlgo = batalha_inventario(personagem, inimigoParaBatalha);
      if (!utilizouAlgo)
      {
        batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      }
      batalha_menu(personagem, inimigoParaBatalha);
      break;
    // case 3:
    //     batalha_fsair(personagem);

    //     break;
    default:
      tratamento(personagem, inimigoParaBatalha, 0);
    }
  }
  else
  {
    switch (opcao)
    {
    case 1:
      batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      batalha_personagemAtaca(personagem, inimigoParaBatalha);

      if (inimigoParaBatalha->vida <= 0)
        break;

      batalha_menu(personagem, inimigoParaBatalha);

      break;
    case 2:
      utilizouAlgo = batalha_inventario(personagem, inimigoParaBatalha);
      if (!utilizouAlgo)
      {
        batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      }
      batalha_menu(personagem, inimigoParaBatalha);
      break;
    // case 3:
    //     batalha_fsair(personagem);

    //     break;
    default:
      tratamento(personagem, inimigoParaBatalha, 0);
    }
  }

  // Checar se player morreu ou monster morreu e executar o batalha_menu novamente
  // baseado nisso
}
