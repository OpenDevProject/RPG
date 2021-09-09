#include "estado.h"

#include "../inimigo/inimigo.h"

#include <string.h>

static void estado_aplicarQueimando(inimigo *inimigoParaAplicar)
{
    inimigoParaAplicar->vida = inimigoParaAplicar->vida * 0.85;
}

void estado_criarQueimando(estado *this)
{
    strcpy(this->nome, "Queimando");
    this->executar = &estado_aplicarQueimando;
}

static void estado_aplicarCongelado(inimigo *inimigoParaAplicar)
{
    inimigoParaAplicar->velocidade = inimigoParaAplicar->velocidade * 0.70;
}

void estado_criarCongelado(estado *this)
{
    strcpy(this->nome, "Congelado");
    this->executar = &estado_aplicarCongelado;
}

void estado_criarNormal(estado *this)
{
    strcpy(this->nome, "Normal");
    this->executar = NULL;
}