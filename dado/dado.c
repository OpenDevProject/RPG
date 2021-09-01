#include "dado.h"

#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_MAX 21

#define RESULTADO_MINIMO 0
#define RESULTADO_NORMAL 1
#define RESULTADO_BOM 2
#define RESULTADO_CRITICO 3

static int gerarResultadoComValorDado(int valorDado)
{
    if (valorDado >= 0 && valorDado <= 3)
        return RESULTADO_MINIMO;
    else if (valorDado >= 4 && valorDado <= 11)
        return RESULTADO_NORMAL;
    else if (valorDado >= 12 && valorDado <= 17)
        return RESULTADO_BOM;
    else if (valorDado >= 18 && valorDado <= 20)
        return RESULTADO_CRITICO;
}

static int girarDado(int seed)
{
    srand(seed);
    return rand() % RANDOM_MAX;
}

int RolarDado(int seed)
{
    int dado = girarDado(seed);

    printf("\nO resultado foi: %d\n", dado);

    return gerarResultadoComValorDado(dado);
}