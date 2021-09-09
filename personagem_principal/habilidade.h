#ifndef HABILIDADE_H
#define HABILIDADE_H

#include "../estado/estado.h"

typedef struct habilidade
{
    char nome[50];
    float custoDeMana;
    estado estadoParaAplicar;
} habilidade;

#endif