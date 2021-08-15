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
    puts(" - Você está aí?");
    sleep( 1.5 );
    puts(" - Nós precisamos de você, o rei mandou chamá-lo");
    sleep( 1 );
    puts(" - Por favor, você é nossa única esperança...");
    sleep( 2 );
    puts(" - Qual é o seu nome? ");
    sleep( 1 );
    printf(" - meu nome é: %s\n", personagem.nome );
    puts("Certo, vamos, o rei precisa de você. ");
    puts("(Você cavalga até a cidade do reino para se encontrar com o rei.) ");
}