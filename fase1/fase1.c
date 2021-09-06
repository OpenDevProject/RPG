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
              puts("(Escolha invalida, tente novamente.)\n\n");
              printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n\n");
              printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n\n");
              printf("Escolha: ");
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
              printf("(Voce terminou de praticar na parte externa)\n\n");
              SLEEP;
              printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n");
              printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n\n");
              scanf("%d", &escolha);
              system(CLEAR);
              while (escolha != 1 && escolha != 2)
              {
                     puts("(Escolha invalida, tente novamente.)\n\n");
                     printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar a parte media ou praticar mais na parte externa?)\n");
                     printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n\n");
                     scanf("%d", &escolha);
                     system(CLEAR);
              }
       }
}

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
       printf("Uma placa eh avistada, surrada, antiga, quebrada mas legivel\n");
       printf("--------------------- Goblins -------------------\n");
       printf("--------------------- Slime ---------------------\n");
       printf("--------------------- Orcs ----------------------\n");
       printf("--------------------- Bruxa ---------------------\n");
       printf("--------------------- Elfo ----------------------\n");
       printf("--------------------- Grifo ---------------------\n");
       printf("-------------- Radamanthys, Wyvern --------------\n\n");
       SLEEP;
       printf("[%s] Entao essa e a Floresta Mydra...\n\n", personagem->nome);
       SLEEP;
       printf("[%s] Entendo...\n\n", personagem->nome);
       SLEEP;
       printf("(Voce repara na mata extremamente fechada, escuta ruidos e barulhos estranhos vindo de dentro\n"
              "da escuridao profunda)\n\n");
       SLEEP;
       printf("[%s] Agora faz sentido, pessoas mais fracas dizerem que esta eh a tal floresta amaldicoada.\n\n", personagem->nome);
       SLEEP;
       printf("(Voce continua andando, deve continuar em busca de seu objetivo)\n\n");
       SLEEP;
       printf("[%s] Que barulho estranho, um tanto nojento, essa merda parece vir de todos os lados\n\n", personagem->nome);
       SLEEP;
       printf("(Um slime pula em sua direcao, ele quase te acerta)\n\n");
       printf("[%s] Eu sabia que tinha escutado esse seu som irritante de algum lugar,\n" 
                    "sua especie de monstro continua asquerosa como sempre.\n\n", personagem->nome);
       SLEEP;
       printf("(Ao se preparar para a batalha, o inimigo rapidamente pula de volta)\n "
              "(So deu tempo de se esquivar novamente)\n\n");
       SLEEP;
       printf("[%s] Como voces sao rapidos, vamos ver do que eh capaz\n\n", personagem->nome);
       SLEEP;

       inimigo_criarSlime(&inimigoPrincipal);
       batalha_menu(personagem, &inimigoPrincipal);

       printf("[%s] Continuam fracos, uma pena, adoraria me divertir um pouco mais.\n\n", personagem->nome);
       SLEEP;
       printf("(Hora de seguir em frente, no caminho, gritos de desespero podem ser escutados, mas longe, como a uns 10km de distancia\n"
              "Ou sera coisa da sua cabeca? serao os gritos de quem ja morreu neste lugar?\n"
              "Enfim, isso nao te afeta, voce segue em frente sem hesitar)\n\n");
       SLEEP;
       printf("(Depois de 20 minutos percorrendo o caminho dificil da floresta voce se depara com um\n"
              "vilarejo com casas pequenas aparentemente abandonado)\n\n");
       SLEEP;
       printf("(Curioso voce entra nele tentando nao fazer barulho e escuta \n"
              "um ruido em seu interior)\n\n");
       SLEEP;
       printf("Socorro!\n\n");
       SLEEP;
       printf("(Ao chegar numa especie de praca no centro do vilarejo, voce ve \n"
              "uma garota amarrada a uma Estatua de Dragao tentando soltar-se, portanto voce tenta ajuda-la)\n\n");
       SLEEP;
       printf("[%s] O que aconteceu? E quem e voce?\n\n", personagem->nome);
       SLEEP;
       printf("[Garota] O que voce esta fazendo parado precisamos sair daqui agora\n\n");
       SLEEP;
       printf("(Voce corta as cordas e a liberta)\n");
       printf("[%s] Entao vamos logo, isso nao parece ser um lugar seguro.\n\n", personagem->nome);
       SLEEP;
       printf("(Voce comeca a ouvir barulhos de passos em suas costas e percebe que \n"
              "esta encuralado por uma cidade inteira de Goblins irritados)\n\n");
       printf("[%s]Olha so quem nos encontramos... eram voces que eu tava procurando.\n\n", personagem->nome);
       SLEEP;
       printf("(Carregando armas enormes 12 Goblins correm em suas direcoes,\n"
              "voces nao tem saida a nao ser lutar contra eles)\n\n");
       SLEEP;
       printf("[%s] Eh bom que voce saiba lutar, isso vai ser dificil se apenas eu souber.\n\n", personagem->nome);
       SLEEP;
       printf("[Garota] E claro que eu sei, entrar nessa floresta sem saber se \n"
              "defender e setenca de morte, entretanto eles roubaram minha coisas estou desarmada\n\n");
       SLEEP;
       printf("[%s] Pegue isso, deve lhe servir por enquanto.\n\n", personagem->nome);
       SLEEP;
       printf("(Logo apos esse rapido dialogo voces comecam a batalhar, matando um por um)\n\n");
       SLEEP;

       SLEEP;
       printf("[%s] Cade suas coisas?\n\n", personagem->nome);
       SLEEP;
       printf("[Garota] Estao no forte deles\n\n");
       SLEEP;
       printf("[%s] Tem varias armas la, qual delas?\n\n", personagem->nome);
       SLEEP;
       printf("[Garota] A unica com tamanho normal.\n\n");
       SLEEP;
       printf("[%s] Realmente...\n\n", personagem->nome);
       SLEEP;
       printf("(Voces entram no forte e parece tudo baguncado e sujo,\n"
              "e logo encontram as coisas da garota)\n\n");
       SLEEP;
       printf("[%s] Voce ainda nao falou seu nome.\n\n", personagem->nome);
       SLEEP;
       printf("[Garota] Ah, eu sou Olivia, e voce?\n\n");
       SLEEP;
       printf("[%s] Eu sou %s, mercenario contratado para acabar com os goblins deste lugar\n\n", personagem->nome, personagem->nome);
       SLEEP;
       printf("[%s] O que voce veio fazer aqui na Floresta Mydra?\n\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Matar o Wyvern Radamanthys\n\n");
       SLEEP;
       printf("[%s] Entendo, bem, eu seguirei meu objetivo, ate a proxima \n", personagem->nome);
       SLEEP;
       printf("[Olivia] Espere! Eu... Posso ir com vc?\n\n");
       SLEEP;
       printf("[%s] Voce e mercenaria tambem?\n\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Nao,por isso gostaria de ir com voce, voce parece ter bem mais experiencia que eu.\n\n");
       SLEEP;
       printf("[%s] Eu ganharia alguma coisa com isso?\n\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Bom... talvez eu possa ajudar voce nas batalhas.\n");
       SLEEP;
       printf("[%s] Certo, so evite falar demais, assim que um de nos completar o seu objetivo, nos separaremos\n\n", personagem->nome);
       SLEEP;
       printf("[Olivia] Sim sim, tudo bem.\n\n");
       SLEEP;
       printf("(Apos a conversa voces seguem em frente, ela um passo atras de voce, e um pouco calada observando tudo ao redor)\n\n");
       SLEEP;
       printf("(Voce tem duas opcoes, quer continuar sua jornada e adentrar\n"
              "a parte media ou praticar mais na parte externa?)\n");
       printf("[1] - Continuar para a parte media\n[2] - Treinar mais na parte externa\n\n");
       scanf("%d", &escolha);
       seguirEmFrenteOuPraticar(escolha, &inimigoPrincipal, personagem);
       SLEEP;
       // Inicio da parte media
       printf("(Espero que voce esteja pronto, a partir da parte media mais monstros sao adicionados)\n\n");
       SLEEP;
       printf("(Ao adentrar a floresta voce percebe um aumento na densidade de arvores, suas copas sao mais cheias e\n"
              "seus troncos mais grossos fazendo com que apenas finos raios de luz atravessem. Os ventos correm\n"
              "pelo seu cabelo junto com o balancar das incontaveis folhas)\n\n");
       SLEEP;
       printf("(Voce continua sua caminhada cautelosamente quando escuta passos.)\n\n");
       SLEEP;
       printf("(Apos se esconder atras de um arbusto voce avista um grupo de goblins caminhando e logo atras um enorme ser.)\n\n");
       SLEEP;
       printf("(Sua pele eh verde escura e seus olhos sao alaranjados,\n"
              "seus musculos, repletos de veias, exalam vigor e seus passos sao estrondosos)\n\n");
       SLEEP;
       printf("(De acordo com os livros que voce leu em sua infancia, voce chega a conclusao que esta de frente para um Orc.)\n\n");
       SLEEP;

       printf("ESSE JOGO AINDA ESTA EM DESENVOLVIMENTO!\n");
       printf("CASO QUEIRA ACOMPANHAR O DESENVOLVIMENTO ACESSE: https://github.com/OpenDevProject/RPG\n");
       printf("DIGITE ENTER PARA CONTINUAR...\n");
       getchar();
}
