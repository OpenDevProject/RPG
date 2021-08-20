#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * @brief Limpa o buffer para remover a nova linha do scanf
 * 
 */
void clearBuffer()
{
    setbuf(stdin, NULL);
}

/**
 * @brief Executa o tratamento de erro
 * 
 */
void TratamentoDeErro()
{
    printf("Digite uma opcao valida!!!\n");
}

/**
 * @brief Remove a nova linha da string
 * 
 * @param string A string para remover a nova linha
 */
void RemoverNovaLinhaDaString(char string[])
{
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
}

void cringe(){
    printf("uma pena, voce eh CRINGE!!!!!\n");
}