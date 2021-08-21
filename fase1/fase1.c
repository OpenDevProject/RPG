#include "fase1.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "../utils/utils.h"
#include "../sistema_batalha/batalha.h"
#include "../inimigo/inimigo.h"
#include "../personagem_principal/personagem_principal.h"

void seguirEmFrenteOuPraticar(int escolha, inimigo *inimigoPrincipal, personagem_principal *personagem)
{
       while (escolha != 1 && escolha != 2)
       {
              puts("(Escolha invalida, tente novamente.)\n");
              printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n");
              printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n");
              scanf("%d", &escolha);
              system(CLEAR);
       }
       while (escolha == 2)
       {
              // Pegar random quantidade de inimigos, até 5, aleatórios para o jogador upar(implementar limite de status up)
              // Soma dos status na parte externa = 750
              for (int i = 0; i < rand() % 6; i++)
              {
                     if (rand() % 3 == 1)
                     {
                            inimigo_criarSlime(inimigoPrincipal);
                            batalha_menu(personagem, inimigoPrincipal);
                     }
                     else
                     {
                            inimigo_criarGlobin(inimigoPrincipal);
                            batalha_menu(personagem, inimigoPrincipal);
                     }
              }
              printf("(Voce terminou de praticar na parte externa)\n");
              SLEEP;
              printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n");
              printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n");
              scanf("%d", &escolha);
              system(CLEAR);
              while (escolha != 1 && escolha != 2)
              {
                     puts("(Escolha invalida, tente novamente.)\n");
                     printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n");
                     printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n");
                     scanf("%d", &escolha);
                     system(CLEAR);
              }
       }
};

/**
 * @brief Codigo que execute a fase 1
 * 
 * @param personagem O endereco que guarda os dados do personagem
 */
void Fase1(personagem_principal *personagem)
{
       srand(time(NULL));
       int escolha;
       inimigo inimigoPrincipal;
       seguirEmFrenteOuPraticar(-1, &inimigoPrincipal, personagem);
       printf("[rei] Voce eh o mercenario contratado? \n");
       SLEEP;
       printf("[%s] Sim, estou aqui pela missao de execucao do Dragao Aither.\n", personagem->nome);
       SLEEP;
       printf("[rei] Ja matou algum monstro? \n");
       SLEEP;
       printf("[%s] Alguns pequenos\n", personagem->nome);
       SLEEP;
       printf("[rei] E voce esta confiante em completar essa missao?\n");
       SLEEP;
       printf("[%s] Para tudo ha uma primeira vez, me esforcarei\n"
              "para trazer uma escama de Aither para voce.\n",
              personagem->nome);
       SLEEP;
       printf("[rei] Voce deve comecar matando os tres Wyverns guardioes\n");
       printf("para se provar competente o suficiente.\n");
       SLEEP;
       printf("[rei] Nao enviaremos jovens inexperientes para sua morte!\n");
       SLEEP;
       printf("[rei] Leve essa %s e algumas pocoes para sua aventura na Floresta Mydra,\n", personagem->armaSelecionada.nomeArma);
       printf("na qual voce executara o primeiro Wyvern, Radamanthys.\n");

       if (personagem->armaSelecionada.code == 1)
       {
              item espada = ITEM_ESPADA;
              espada.quant = 1;
              item_AdicionarItemAoInventario(espada, personagem->inventario);
       }
       else if (personagem->armaSelecionada.code == 2)
       {
              item machado = ITEM_MACHADO;
              machado.quant = 1;
              item_AdicionarItemAoInventario(machado, personagem->inventario);
       }
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
              ;
              item gelo = ITEM_GELO;
              gelo.quant = 1;
              item_AdicionarItemAoInventario(gelo, personagem->inventario);
       }

       item pocao = ITEM_POCAO;
       pocao.quant = 10;

       item_AdicionarItemAoInventario(pocao, personagem->inventario);
       SLEEP;
       printf("(Apos receber a(o) %s e as pocoes voce parte \n"
              "para a Floresta Mydra para enfrentar Radamanthys.)\n",
              personagem->armaSelecionada.nomeArma);
       SLEEP;
       printf("(No caminho para a floresta Mydra voce encontra \n"
              "uma placa descrevendo os perigosos monstros.)\n");
       SLEEP;
       printf("--------------------- Goblins -------------------\n");
       printf("--------------------- Slime ---------------------\n");
       printf("--------------------- Orcs ----------------------\n");
       printf("--------------------- Bruxa ---------------------\n");
       printf("--------------------- Elfo ----------------------\n");
       printf("--------------------- Grifo ---------------------\n");
       printf("-------------- Radamanthys, Wyvern --------------\n");
       SLEEP;
       SLEEP;
       printf("[%s] Entao essa e a Floresta Mydra!\n", personagem->nome);
       SLEEP;
       printf("(O vento sopra e nosso heroi percebe o quao profunda e escura eh a floresta.) \n");
       SLEEP;
       printf("(Eis que um Slime roxo gosmento pula em sua direcao com rapidez,\n"
              "voce so tem tempo de se esquivar e se joga para esquerda)\n");
       SLEEP;
       printf("[%s] Realmente nao mentiram quando falaram que os Slimes sao muito rapidos,\n"
              "entao eles devem expelir acido pela boca\n",
              personagem->nome);
       SLEEP;
       printf("(Voce se levanta, limpa o braco esquerdo que ficou coberto de lama e\n");
       printf("pega sua arma e percebe que mais ao fundo no meio das arvores surgem mais slimes,\n");
       SLEEP;
       printf("voce conta por cima e sao no minimo 5. Os dois Slimes da frente Lancaram acidos na sua direcao)\n");
       SLEEP;

       inimigo_criarSlime(&inimigoPrincipal);
       batalha_menu(personagem, &inimigoPrincipal);

       printf("(Apos ganhar o combate contra os Slimes e ter perdido partes de\n"
              " sua roupa Voce segue pelo caminho torcendo para que nao apareca nenhum slime)\n");
       SLEEP;
       printf("(Depois de 20 minutos adentrando a floresta voce se depara com um\n"
              "vilarejo com casas pequenas aparentemente abandonado)\n");
       SLEEP;
       printf("(Curioso voce entra nele tentando nao fazer barulho e escuta \n"
              "um ruido em seu interior)\n");
       SLEEP;
       printf("Socorro!\n");
       SLEEP;
       printf("(Ao chegar numa especie de praca no centro do vilarejo, voce ve \n"
              "uma garota amarrada a uma Estatua de Dragao tentando soltar-se, portanto voce tenta ajuda-la)\n");
       SLEEP;
       printf("(Voce cortar as cordas e a liberta)\n");
       SLEEP;
       printf("[%s] O que aconteceu? E quem e voce?\n", personagem->nome);
       SLEEP;
       printf("[Garota] O que voce esta fazendo parado precisamos sair daqui agora\n");
       SLEEP;
       printf("(Voce comeca a ouvir barulhos de passos em suas costas e percebe que \n"
              "esta encuralado por uma cidade inteira de Goblins nada simpaticos)\n");
       SLEEP;
       printf("(Carregando armas enormes 12 Goblins correm em suas direcoes,\n"
              "voces nao tem saida a nao ser lutar contra eles)\n");
       SLEEP;
       printf("[%s] voce sabe lutar?\n", personagem->nome);
       SLEEP;
       printf("[Garota] E claro que eu sei, entrar nessa floresta sem saber se \n"
              "defender e setenca de morte, entretanto eles roubaram minha coisas estou desarmada\n");
       SLEEP;
       printf("[%s] Toma essa arma emprestada por enquanto\n", personagem->nome);
       SLEEP;
       printf("(Logo apos esse rapido dialogo voces comecam a batalhar se ajudando)\n");
       SLEEP;

       SLEEP;
       printf("(Essa foi por pouco, mas voces conseguem derrotar todos os Goblins)\n");
       SLEEP;
       printf("[%s] cade suas coisas?\n", personagem->nome);
       SLEEP;
       printf("[Garota] ta no forte deles\n");
       SLEEP;
       printf("[%s] Tem varias qual delas?\n", personagem->nome);
       SLEEP;
       printf("[Garota] A unica com tamanho normal\n");
       SLEEP;
       printf("[%s] Realmente...\n", personagem->nome);
       SLEEP;
       printf("(Voces entram no forte e parece tudo baguncado e sujo,\n"
              "e logo encontram as coisas da garota)\n");
       SLEEP;
       printf("[%s] Voce ainda nao falou seu nome\n", personagem->nome);
       SLEEP;
       printf("[Garota] Ah, eu sou Olivia, e voce?\n");
       SLEEP;
       printf("[%s] Prazer, meu nome eh %s\n", personagem->nome, personagem->nome);
       SLEEP;
       printf("[%s] O que voce veio fazer aqui na Floresta Mydra?\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Matar o Wyvern Radamanthys\n");
       SLEEP;
       printf("[%s] Que? nao faz sentido... \n"
              "Eu que fui escolhido pelo Rei para matar ele\n",
              personagem->nome);
       SLEEP;
       printf("[Olivia] Entao pelo visto voce nao e o unico\n");
       SLEEP;
       printf("[%s] Voce e mercenaria tambem?\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Nao, eu sou da guarda do Rei e me ofereci para matar o Wyvern\n");
       SLEEP;
       printf("(Voce pensa em perguntar se o objetivo dela eh a execucao do Dragao Aither,\n"
              "mas decide nao expor seus pensamentos)\n");
       SLEEP;
       printf("[%s] Enfim, tenho que continuar com minha caminhada, foi um prazer conhece-la\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Igualmente, mas seja cauteloso. A partir da parte media da floresta Mydra\n"
              "os monstros ficam muito mais fortes e numerosos.\n");
       SLEEP;
       printf("[%s] Parte media?\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Voce nao sabe nem disso? A floresta Mydra eh dividida em tres partes:\n"
              "interior, media e externa. Quao mais fundo voce estiver, mais perigoso sera.\n"
              "Logicamente, o wyvern se encontra na parte mais profunda da floresta\n");
       SLEEP;
       printf("[%s] Entendo. Obrigado pela informacao e boa sorte em sua jornada\n", personagem->nome);
       SLEEP;
       printf("(Apos a conversa voces se despedem e seguem seus caminhos)\n");
       SLEEP;
       printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n");
       printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n");
       scanf("%d", &escolha);
       seguirEmFrenteOuPraticar(escolha, &inimigoPrincipal, personagem);
       // Inicio da parte media
       printf("(Espero que voce esteja pronto, a partir da parte media mais monstros sao adicionados)\n");
       SLEEP;
       printf("(Ao adentrar a floresta voce percebe um aumento na densidade de arvores, suas copas sao mais cheias e\n"
              "seus troncos mais grossos fazendo com que apenas finos raios de luz atravessem. Os ventos correm\n"
              "pelo seu cabelo junto com o balancar das incontaveis folhas)\n");
       SLEEP;
       printf("(Voce continua sua caminhada cautelosamente quando escuta passos.)\n");
       SLEEP;
       printf("(Apos se esconder atras de um arbusto voce avista um grupo de goblins caminhando e logo atras um enorme ser.)\n");
       SLEEP;
       printf("(Sua pele eh verde escura e seus olhos sao alaranjados,\n"
              "seus musculos, repletos de veias, exalam vigor e seus passos sao estrondosos)\n");
       SLEEP;
       printf("(De acordo com os livros que voce leu em sua infancia, voce chega a conclusao que esta de frente para um Orc.)\n");
       SLEEP;

       // só um aviso depois de terminar o jogo
       printf("ESSE JOGO AINDA ESTA EM DESENVOLVIMENTO!\n\n");
       printf("CASO QUEIRA ACOMPANHAR O DESENVOLVIMENTO ACESSE: https://github.com/OpenDevProject/RPG\n\n");
       printf("DIGITE ENTER PARA CONTINUAR...\n\n");
       getchar();
}
