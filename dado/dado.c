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
    printf("O resultado foi: %d\n", rand() % RANDOM_MAX);
    if ( rand() % RANDOM_MAX >= 0 && rand() % RANDOM_MAX <= 5){
        dado = 0;

    }
    else if ( rand() % RANDOM_MAX >= 6 && rand() % RANDOM_MAX <= 11 ){
        dado = 1;

    }
    else if ( rand() % RANDOM_MAX >= 12 && rand() % RANDOM_MAX <= 17 ){
        dado = 2;

    }
    else if ( rand() % RANDOM_MAX >= 18 && rand() % RANDOM_MAX <= 20 ){
        dado = 3;
        
    }

    return dado;
}