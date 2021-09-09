#ifndef ESTADO_H
#define ESTADO_H

typedef struct inimigo inimigo;

typedef struct estado
{
    char nome[50];
    void (*executar)(inimigo *inimigoParaAplicar);
} estado;

void estado_criarQueimando(estado *this);
void estado_criarCongelado(estado *this);
void estado_criarNormal(estado *this);

#endif