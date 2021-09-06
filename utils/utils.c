#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

void clearBuffer()
{
    setbuf(stdin, NULL);
}

void TratamentoDeErro()
{
    printf("Digite uma opcao valida!!!\n");
}

void RemoverNovaLinhaDaString(char string[])
{
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}


void cringe(){
    printf("uma pena, voce eh CRINGE!!!!!\n");
}