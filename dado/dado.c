#include "dado.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_MAX 21

/**
 * @brief Rola um dado com um valor de até 20
 * 
 * @return int Retorna o valor do dado rolado
 */
int RolarDado()
{
    int dado;
    srand(time(NULL));
    int numeroGerado = rand() % RANDOM_MAX;
    if (numeroGerado >= 0 && numeroGerado <= 5)
    {
        dado = 0;
    }
    else if (numeroGerado >= 6 && numeroGerado <= 11)
    {
        dado = 1;
    }
    else if (numeroGerado >= 12 && numeroGerado <= 17)
    {
        dado = 2;
    }
    else if (numeroGerado >= 18 && numeroGerado <= 20)
    {
        dado = 3;
    }
    printf("O resultado foi: %d\n", dado);
    return dado;
}