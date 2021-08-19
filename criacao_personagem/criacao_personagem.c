#include "criacao_personagem.h"
#include "../utils/utils.h"

#include <string.h>

#include <stdio.h>

/**
 * @brief Pede para o usuário escolher uma classe
 * 
 * @param personagem O endereço do personagem a ser alterado a classe
 */
void escolherClasse(personagem_principal *personagem)
{
    printf("Escolha sua classe:\n[1] - Guerreiro\n[2] - Cacador\n[3] - Mago\n");

    scanf("%d", &personagem->classe);
    clearBuffer();
}

/**
 * @brief Executa o processo de criação de personagem
 * 
 * @param personagem O endereço do personagem para inserir os dados
 */
void CriandoPersonagem(personagem_principal *personagem)
{
    int arma;
    printf("Digite o nome do seu personagem: ");

    scanf("%s", personagem->nome);
    //RemoverNovaLinhaDaString(temps);
    while (strlen(personagem->nome) > 10)
    {
        printf("\nO nome do personagem so pode ter ate 10 caracteres.\n");
        printf("Digite o nome do seu personagem: ");

        scanf("%s", personagem->nome);
    }

    printf("%d\n", personagem->classe);
    escolherClasse(personagem);

    while (personagem->classe != 1 && personagem->classe != 2 && personagem->classe != 3)
    {
        printf("Digite uma opcao valida!!");
        escolherClasse(personagem);
    }
    /*
    * guerreiro / espada // machado
    * caçador / punhal // arco
    * mago / fogo // gelo
    */
    switch (personagem->classe)
    {
    case 1:
        personagem_principal_criarGuerreiro(personagem);

        printf("Parabens, voce escolheu Guerreiro!\n");

        printf("Escolha sua arma:\n[1] - Espada\n[2] - Machado\n");
        puts("Opcao: ");
        scanf("%d", &arma);
        clearBuffer();

        switch (arma)
        {
        case 1:
            printf("Parabens, voce escolheu a espada\n");
            personagem->arma = 1;
            break;

        case 2:
            printf("Parabens, voce escolheu o machado\n");
            personagem->arma = 2;
            break;
        default:
            TratamentoDeErro();
            break;
        }
        break;
    case 2:
        personagem_principal_criarCacador(personagem);

        printf("Parabens, voce escolheu Cacador\n");

        printf("Escolha sua arma:\n[1] - Punhal\n[2] - Arco\n");
        scanf("%d", &arma);
        puts("Opcao: ");
        clearBuffer();

        switch (arma)
        {
        case 1:
            printf("Parabens, voce escolheu o punhal\n");
            personagem->arma = 3;
            break;

        case 2:
            printf("Parabens, voce escolheu o arco\n");
            personagem->arma = 4;
            break;

        default:
            TratamentoDeErro();
            break;
        }

        break;
    case 3:
        personagem_principal_criarMago(personagem);

        printf("Parabéns, voce escolheu Mago\n");

        printf("Escolha sua arma:\n[1] - Fogo\n[2] - Gelo\n");
        scanf("%d", &arma);
        puts("Opcao: ");
        clearBuffer();

        switch (arma)
        {
        case 1:
            printf("Parabens, voce escolheu o fogo\n");
            personagem->arma = 5;
            break;

        case 2:
            printf("Parabens, voce escolheu o gelo\n");
            personagem->arma = 6;
            break;

        default:
            TratamentoDeErro();
            break;
        }

        break;
    }
}