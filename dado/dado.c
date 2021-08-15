#include "dado.h"

#include <stdio.h>
#include <stdlib.h>

#define RANDOM_MAX 21

/**
 * @brief Rola um dado com um valor de até 20
 * 
 * @return int Retorna o valor do dado rolado
 */
int RolarDado()
{
    int dado;
    printf("O resultado foi: ", rand() % RANDOM_MAX);
    return dado;
}