//incluindo biblitecas e outros arquivos dentro do código, contidos em pastas .c e .h

#include "menu_principal.h"

#include "../exit/exit.h"
#include "../utils/utils.h"

#include "../criacao_personagem/criacao_personagem.h"
#include "../introducao/introducao.h"
#include "../fase1/fase1.h"

#include <stdio.h>
#include <unistd.h>

/**
 * @brief Inicia a história do jogo
 * 
 * @param personagem O endereço do personagem para ser utilizado na história
 */
void IniciandoHistoria(personagem_principal *personagem)//função que inicia a história
{
  CriandoPersonagem(personagem);//função que cria nosso personagem
  Introducao(personagem);//introdução da história
  SLEEP;// pausa dramática       >>>>   :O   <<<<
  //Fim de introdução, inicia a fase1
  Fase1(personagem);// Fase1
}

/**
 * @brief O menu principal mostrado no inicio do jogo
 * 
 * @param personagem O endereço do personagem para ser utilizado na história
 */
void MenuPrincipal(personagem_principal *personagem)//menu do jogo
{
  int opcaoMenuPrincipal;

  do
  {
    //mensagens que aparecerão no menu principal
    puts("MENU PRINCIPAL");
    puts("[1] - Iniciar Jogo");
    puts("[2] - Creditos");
    puts("[3] - Sair");
    printf("Escolha: ");

    scanf("%d", &opcaoMenuPrincipal);
    system(CLEAR); // limpa o terminal(onde o código roda por enquanto), não polui nosso sistema com muita informação
    clearBuffer(); // isso aqui eu não lembro nn :P

    switch (opcaoMenuPrincipal)
    {
    //opcoes do personagem, aqui estarão onde serão chamadas as funções escolhidas pelo personagem
    case 1:
      IniciandoHistoria(personagem);//aqui chamamos nossa função de iniciar a história, definida lá em cima, na linha 20.
      break;

    case 2:
      puts("Creditos: Tiringa");//Créditos do nosso Deus, tiringa, o Rei
      break;

    case 3:
      Exit();// esta função irá dar return 0 na maim, finalizará o jogo
      return;
      break;

    default:
      TratamentoDeErro();// função para opções inválidas, por exemplo, aqui temos opções 1, 2 e 0...
                         // se o usuário digitar algo diferente, o computador saberá como prosseguir.
    }
  } while (opcaoMenuPrincipal);
}