#include "introducao.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <unistd.h>

/**
 * @brief Função que executa a introdução
 * 
 * @param personagem Os dados do personagem principal
 */
void Introducao(personagem_principal *personagem)
{
    puts(" - Ei! Ei!");
    SLEEP;
    puts(" - Voce esta ai?");
    SLEEP;
    puts(" - Nos precisamos de voce, o rei mandou chama-lo");
    SLEEP;
    puts(" - Por favor, voce e nossa unica esperanca...");
    SLEEP;
    puts(" - Qual e o seu nome? ");
    printf(" - Meu nome eh: ");
    scanf("%s", personagem->nome);
    //RemoverNovaLinhaDaString(temps);
    while (strlen(personagem->nome) > 10)
    {
        printf("\nO nome do personagem so pode ter ate 10 caracteres.\n");
        printf("Meu nome eh: ");

        scanf("%s", personagem->nome);
        system(CLEAR);
        ;
    }
    SLEEP;
    puts(" - Certo, vamos, o rei precisa de voce. ");
    printf("\n");
    SLEEP;
    puts("(Voce cavalga ate a cidade do reino para se encontrar com o rei.) ");
    printf("\n");
    SLEEP;
}