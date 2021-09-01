#include "exit.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void imprimirMensagemDeSaida(int valorTimer)
{
    system(CLEAR);
    printf("Saindo...\n");
    printf("TIMER: %d\n", valorTimer);
    sleep(1);
}

int Exit()
{
    for (int i = 3; i >= 0; i--)
        imprimirMensagemDeSaida(i);
    
    return 0;
}