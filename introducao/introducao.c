#include "introducao.h"

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
    sleep( 1.5 );
    puts(" - Voce esta ai?");
    sleep( 1.5 );
    puts(" - Nós precisamos de voce, o rei mandou chama-lo");
    sleep( 1 );
    puts(" - Por favor, voce e nossa unica esperança...");
    sleep( 2 );
    puts(" - Qual e o seu nome? ");
    sleep( 1 );
    printf(" - meu nome e: %s\n", personagem.nome );
    puts("Certo, vamos, o rei precisa de voce. ");
    puts("(Voce cavalga ate a cidade do reino para se encontrar com o rei.) ");
}