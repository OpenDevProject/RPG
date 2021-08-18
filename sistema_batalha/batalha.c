#include "batalha.h"
#include "../utils/utils.h"
#include "../dado/dado.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int flush()
{
  puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  return 0;
}

void batalha_fsair(personagem_principal *personagem)
{
  if (personagem->vida <= 0)
  {
    printf("GAME OVER!\n\nVoce foi derrotado!\nTente novamente!\n");
    sleep(5);
    exit(0);
  }
  else
  {
    printf("Voce derrotou seu adversario!\nDigite qualquer tecla para proseguir!\n");
    getchar();
  }
}

void tratamento(personagem_principal *personagem, inimigo *inimigoParaBatalha, int usandoItem)
{
  if (usandoItem)
  {
    puts("Esse item nao pode ser utilizado!");
  }
  else
  {
    puts("Opcao invalida!");
  }
  sleep(1.5);
  flush();
  batalha_menu(personagem, inimigoParaBatalha);
}

int batalha_personagemAtaca(personagem_principal *personagem, inimigo *inimigoParaBatalha)
{
  int dado = RolarDado();
  inimigoParaBatalha->vida = inimigoParaBatalha->vida - personagem->atk;
  if (inimigoParaBatalha->vida <= 0)
  {
    batalha_fsair(personagem);
    return 0;
  }
  batalha_menu(personagem, inimigoParaBatalha);
}

int batalha_inimigoAtaca(personagem_principal *personagem, inimigo *inimigoParaBatalha)
{
  int dado = RolarDado();
  printf("Esse foi o seu resultado: %d\n", dado);
  personagem->vida = personagem->vida - inimigoParaBatalha->atk;
  if (personagem->vida <= 0)
  {
    batalha_fsair(personagem);
    return 0;
  }
  batalha_menu(personagem, inimigoParaBatalha);
}

// void batalha_atacar_com_arma(personagem_principal *personagem, inimigo *inimigoParaBatalha, int inimigoEMaisRapido)
// {
//     if (personagem->arma == espada)
//     {
//         if (dado == 0)
//         {
//             printf("Voce tirou o dano minimo!\nSeu ataque com a espada foi fraco, seu inimigo se defendeu\n\nDano sera 0");
//         }
//         else if (dado == 1)
//         {
//             printf("Voce tirou o dano medio.\nSeu ataque com espada tirou dano de 25%% da vida de seu inimigo\n\n");
//         }
//         else if (dado == 2)
//         {
//             printf("Voce tirou dano alto.\nSeu ataque com espada tirou dano de 45%% da vida de seu inimigo.\n\n");
//         }
//         else if (dado == 3)
//         {
//             printf("Voce tirou dano i, parabens!!\n Seu ataque com espada tirou dano de 75%% da vida de seu inimigo.\n\n");
//         }
//     }
//     else if (arma == machado)
//     {
//         if (dado == 0)
//         {
//             printf("Voce tirou o dano minimo!\nSeu ataque com a machado foi fraco, seu inimigo se defendeu\n\nDano sera 0");
//         }
//         else if (dado == 1)
//         {
//             printf("Voce tirou o dano medio.\nSeu ataque com machado tirou dano de 30%% da vida de seu inimigo\n\n");
//         }
//         else if (dado == 2)
//         {
//             printf("Voce tirou dano alto.\nSeu ataque com machado tirou dano de 50%% da vida de seu inimigo.\n\n");
//         }
//         else if (dado == 3)
//         {
//             printf("Voce tirou dano critico, parabens!!\n Seu ataque com machado tirou dano de 83%% da vida de seu inimigo.\n\n");
//         }
//     }
//     else if (arma == arco)
//     {
//         if (dado == 0)
//         {
//             printf("Voce tirou o dano minimo!\nSeu ataque com a arco foi fraco, seu inimigo se defendeu\n\nDano sera 0");
//         }
//         else if (dado == 1)
//         {
//             printf("Voce tirou o dano medio.\nSeu ataque com arco tirou dano de 20%% da vida de seu inimigo\n\n");
//         }
//         else if (dado == 2)
//         {
//             printf("Voce tirou dano alto.\nSeu ataque com arco tirou dano de 35%% da vida de seu inimigo.\n\n");
//         }
//         else if (dado == 3)
//         {
//             printf("Voce tirou dano critico, parabens!!\n Seu ataque com arco tirou dano de 55%% da vida de seu inimigo.\n\n");
//         }
//     }
//     else if (arma == punhal)
//     {
//         if (dado == 0)
//         {
//             printf("Voce tirou o dano minimo!\nSeu ataque com a punhal foi fraco, seu inimigo se defendeu\n\nDano será 0");
//         }
//         else if (dado == 1)
//         {
//             printf("Voce tirou o dano medio.\nSeu ataque com punhal tirou dano de 25%% da vida de seu inimigo\n\n");
//         }
//         else if (dado == 2)
//         {
//             printf("Voce tirou dano alto.\nSeu ataque com punhal tirou dano de 40%% da vida de seu inimigo.\n\n");
//         }
//         else if (dado == 3)
//         {
//             printf("Voce tirou dano critico, parabens!!\n Seu ataque com punhal tirou dano de 65%% da vida de seu inimigo.\n\n");
//         }
//         else if (arma == fogo)
//         {
//             if (dado == 0)
//             {
//                 printf("Voce tirou o dano minimo!\nSeu ataque com fogo foi fraco, seu inimigo se defendeu\n\nDano será 0");
//             }
//             else if (dado == 1)
//             {
//                 printf("Voce tirou o dano medio.\nSeu ataque com fogo tirou dano de 30%% da vida de seu inimigo\n\n");
//             }
//             else if (dado == 2)
//             {
//                 printf("Voce tirou dano alto.\nSeu ataque com fogo tirou dano de 50%% da vida de seu inimigo.\n\n");
//             }
//             else if (dado == 3)
//             {
//                 printf("Voce tirou dano critico, parabens!!\n Seu ataque com fogo tirou dano de 70%% da vida de seu inimigo.\n\n");
//             }
//         }
//         else if (arma == gelo)
//         {
//             if (dado == 0)
//             {
//                 printf("Voce tirou o dano minimo!\nSeu ataque com a punhal foi fraco, seu inimigo se defendeu\n\nDano será 0");
//             }
//             else if (dado == 1)
//             {
//                 printf("Voce tirou o dano medio.\nSeu ataque com punhal tirou dano de 28%% da vida de seu inimigo\n\n");
//             }
//             else if (dado == 2)
//             {
//                 printf("Voce tirou dano alto.\nSeu ataque com punhal tirou dano de 43%% da vida de seu inimigo.\n\n");
//             }
//             else if (dado == 3)
//             {
//                 printf("Voce tirou dano critico, parabens!!\n Seu ataque com punhal tirou dano de 68%% da vida de seu inimigo.\n\n");
//             }
//         }
//     }
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

  printf("VIDA DO %s: %d\n", personagem->nome, personagem->vida);
  printf("VIDA DO %s: %d\n", inimigoParaBatalha->nome, inimigoParaBatalha->vida);

  puts("================");
  puts("Digite uma opcao");
  puts("[1] - Atacar");
  puts("[2] - Inventario");
  // puts("[3] - Sair");
  puts("================");
  scanf("%d", &opcao);
  clearBuffer();
  /*
    Comparar speed para decidir quem joga primeiro.
    if player.speed>monster.speed{
      switch para decidir acao do player
      checar se monster morreu e tomar decisao
      acao do monster
      checar se player morreu e tomar decisao
    }else{
      acao do monster
      checar se player morreu e tomar decisao
      switch para decidir acao do player
      checar se monster morreu e tomar decisao
    }
    */
  if (personagem->velocidade > inimigoParaBatalha->velocidade)
  {
    switch (opcao)
    {
    case 1:
      batalha_personagemAtaca(personagem, inimigoParaBatalha);
      if (inimigoParaBatalha->vida <= 0)
        break;
      batalha_inimigoAtaca(personagem, inimigoParaBatalha);

      break;
    case 2:
      utilizouAlgo = batalha_inventario(personagem, inimigoParaBatalha);
      if (utilizouAlgo)
      {
        batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      }
      break;
    // case 3:
    //     batalha_fsair(personagem);

    //     break;
    default:
      tratamento(personagem, inimigoParaBatalha, 0);
    }
    if (inimigoParaBatalha->vida <= 0)
    {
    }
  }
  else
  {
    switch (opcao)
    {
    case 1:
      batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      batalha_personagemAtaca(personagem, inimigoParaBatalha);

      break;
    case 2:
      utilizouAlgo = batalha_inventario(personagem, inimigoParaBatalha);
      if (utilizouAlgo)
      {
        batalha_inimigoAtaca(personagem, inimigoParaBatalha);
      }
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
