#include "criacao_personagem.h"
#include "../utils/utils.h"

#include <stdio.h>

/**
 * @brief Pede para o usuário escolher uma classe
 * 
 * @param personagem O endereço do personagem a ser alterado a classe
 */
void escolherClasse(personagem_principal *personagem)
{
    printf("Escolha sua classe:\n[1] - Guerreiro\n[2] - Caçador\n[3] - Mago\n");

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

    fgets(personagem->nome, MAX_STRING_NAME, stdin);
    RemoverNovaLinhaDaString(personagem->nome);

    escolherClasse(personagem);

    while (personagem->classe != 1 && personagem->classe != 2 && personagem->classe != 3)
    {
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

        printf("Escolha sua arma:\n[1] - Espada\n[2] - Machado");
        scanf("%d", &arma);
        clearBuffer();

        switch (arma)
        {
        case 1:
            printf("Parabens, voce escolheu a espada\n");
            break;

        case 2:
            printf("Parabens, voce escolheu o machado\n");
            break;

        default:
            break;
        }
        break;
    case 2:
        personagem_principal_criarCacador(personagem);

        printf("Parabens, voce escolheu Cacador\n");

        printf("Escolha sua arma:\n[1] - Punhal\n[2] - Arco");
        scanf("%d", &arma);
        clearBuffer();

        break;
    case 3:
        personagem_principal_criarMago(personagem);

        printf("Parabéns, voce escolheu Mago\n");

        printf("Escolha sua arma:\n[1] - Fogo\n[2] - Gelo");
        scanf("%d", &arma);
        clearBuffer();

        break;
    }
}