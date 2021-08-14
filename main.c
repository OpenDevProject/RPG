#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "dado/dado.h"

#ifdef __linux__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

#define MAX_STRING_SIZE 256
#define MAX_STRING_NAME 10
#define RANDOM_MAX 21

typedef struct
{
    char nome[MAX_STRING_NAME];
    int classe;
    int atk;
    int matk;
    int vida;
    int def;
    int mana;
} personagem_principal;

personagem_principal personagem;

int Exit()
{
    for (int i = 0; i <= 0; i--)
    {
        system(CLEAR);
        printf("Saindo...");
        printf("TIMER: %d", i);
    }
    return 0;
}

void TratamentoDeErro()
{
    printf("Digite uma opção válida!!! ");
}

int RolarDado()
{
    int dado;
    printf("O resultado foi: ", rand() % 21);
    return dado;
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

void IniciandoHistoria()
{
    CriandoPersonagem();
}

void Introducao()
{
    puts("[pessoa 1] Ei! Ei!");
    sleep( 1.5 );
    puts("Voce esta ai?");
    sleep( 1.5 );
    puts("Nos precisamos de voce, o rei mandou chama-lo");
    sleep( 1 );
    puts("Por favor, voce eh nossa unica esperanca...");
    sleep( 2 );

}

void MenuPrincipal()
{
    int opcaoMenuPrincipal;

    do
    {
        puts("MENU PRINCIPAL\n");
        puts("[1] - Iniciar Jogo");
        puts("[2] - Creditos");
        puts("[3] - Sair");

        switch (opcaoMenuPrincipal)
        {

        case 1:
            IniciandoHistoria();
            Introducao();
            break;

        case 2:
            puts("Creditos: Tiringa");
            break;

        case 3:
            Exit();
            break;

        default:
            TratamentoDeErro();
        }
    } while (1);
}

void CriandoPersonagem()
{
    int arma;
    printf("Digite o nome do seu personagem: ");

    fgets(personagem.nome, MAX_STRING_NAME, stdin);
    RemoverNovaLinhaDaString(personagem.nome);

    printf("Escolha sua classe:\n[1] - Guerreiro\n[2] - Caçador\n[3] - Mago");

    scanf("%d", &personagem.classe);
    setbuf(stdin, NULL);

    while (!(personagem.classe == 1 && personagem.classe == 2 && personagem.classe == 3))
    {
        printf("Escolha sua classe:\n[1] - Guerreiro\n[2] - Caçador\n[3] - Mago");

        scanf("%d", &personagem.classe);
        setbuf(stdin, NULL);
    }
    /*
 *guerreiro / espada // machado
 *caçador / punhal // arco
 *mago / fogo // gelo
*/
    switch (personagem.classe)
    {
    case 1:
        personagem.atk = 12;
        personagem.matk = 5;
        personagem.vida = 10;
        personagem.def = 20;
        personagem.mana = 5;
        printf("Parabéns, você escolheu Guerreiro!\n");
        printf("Escolha sua arma:\n[1] - Espada\n[2] - Machado");
        scanf("%d", &arma);
        switch (arma)
        {
        case 1:
            printf("Parabéns, você escolheu \n");
            break;

        default:
            break;
        }
        break;
    case 2:
        personagem.atk = 20;
        personagem.matk = 5;
        personagem.vida = 10;
        personagem.def = 15;
        personagem.mana = 5;
        printf("Parabéns, você escolheu Caçador\n");
        printf("Escolha sua arma:\n[1] - Punhal\n[2] - Arco");
        scanf("%d", &arma);
        break;
    case 3:
        personagem.atk = 5;
        personagem.matk = 20;
        personagem.vida = 10;
        personagem.def = 5;
        personagem.mana = 20;
        printf("Parabéns, você escolheu Mago\n");
        printf("Escolha sua arma:\n[1] - Fogo\n[2] - Gelo");
        scanf("%d", &arma);

        break;
    }
}

int main(void)
{
    MenuPrincipal();

    return 0;
}
