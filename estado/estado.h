#ifndef ESTADO_H
#define ESTADO_H

typedef struct estado
{
    char nome[50];
    void (*executar)();
} estado;


#endif