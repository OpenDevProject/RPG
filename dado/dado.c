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
int RolarDado(int seed)
{
    int dado;
    srand(seed);
    int numeroGerado = rand() % RANDOM_MAX;
    //printf("O seu resultado foi: %d", dado);
    if (numeroGerado >= 0 && numeroGerado <= 3)
    {
        dado = 0;
    }
    else if (numeroGerado >= 4 && numeroGerado <= 11)
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
    return dado;
}