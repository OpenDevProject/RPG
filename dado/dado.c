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
    dado = rand() % RANDOM_MAX;
    printf("O seu resultado foi: %d\n", dado);
    if (dado >= 0 && dado <= 3)
    {
        printf("Resultado minimo!\n");
        dado = 0;
    }
    else if (dado >= 4 && dado <= 11)
    {
        printf("Resultado normal!\n");
        dado = 1;
    }
    else if (dado >= 12 && dado <= 17)
    {
        printf("Resultado bom!\n");
        dado = 2;
    }
    else if (dado >= 18 && dado <= 20)
    {
        printf("Resultado critic!\n");
        dado = 3;
    }
    return dado;
}