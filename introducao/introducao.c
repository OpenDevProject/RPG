#include "introducao.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <unistd.h>

/**
 * @brief Função que executa a introdução
 * 
 * @param personagem Os dados do personagem principal
 */
void Introducao(personagem_principal personagem)
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
    SLEEP;
    printf(" - meu nome eh %s\n", personagem.nome );
    SLEEP;
    puts(" - Certo, vamos, o rei precisa de voce. ");
    SLEEP;
    puts("(Voce cavalga ate a cidade do reino para se encontrar com o rei.) ");
    SLEEP;
}