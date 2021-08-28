#include "dado.h"

#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_MAX 21 //definindo o valor máximo para o dado, 21 para cehgar em 20 e deixar um sobrando

/**
 * @brief Rola um dado com um valor de até 20
 * 
 * @return int Retorna o valor do dado rolado
 */
int RolarDado(int seed)
{
    int dado;
    srand(seed); //muda o numero gerado sempre que o codigo roda
    dado = rand() % RANDOM_MAX;
    printf("\nO resultado foi: %d\n", dado);
    if (dado >= 0 && dado <= 3)
    {
        printf("Resultado minimo!\n\n");
        cringe();
        dado = 0;
    }
    else if (dado >= 4 && dado <= 11)
    {
        printf("Resultado normal!\n\n");
        dado = 1;
    }
    else if (dado >= 12 && dado <= 17)
    {
        printf("Resultado bom!\n\n");
        dado = 2;
    }
    else if (dado >= 18 && dado <= 20)
    {
        printf("Resultado critico!\n\n");
        dado = 3;
    }
    return dado;
}