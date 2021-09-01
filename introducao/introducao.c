#include "introducao.h"
#include "../utils/utils.h"
#include "../personagem_principal/personagem_principal.h"
#include <stdio.h>
#include <unistd.h>

static void requisitarNomeNovamente(personagem_principal *personagem)
{
    printf("\nO nome do personagem so pode ter ate 10 caracteres.\n");
    printf(" [???] Meu nome eh: ");

    scanf("%s", personagem->nome);
    system(CLEAR);
}

static int nomeDoPersonagemMaiorQueDez(personagem_principal *personagem)
{
    return strlen(personagem->nome) > 10;
}

static void requisitarNomeDoPersonagem(personagem_principal *personagem)
{
    printf(" [???] Meu nome eh: ");
    scanf("%s", personagem->nome);
    printf("\n");
    while (nomeDoPersonagemMaiorQueDez(personagem))
        requisitarNomeNovamente(personagem);
}

void Introducao(personagem_principal *personagem)
{
    puts(" [Comerciante] Ei! Ei!");
    printf("\n");
    SLEEP;
    puts(" [Comerciante] Voce esta ai? Ouvi falar que voce eh mercenario.");
    printf("\n");
    SLEEP;
    puts(" [???] O que voce quer?");
    printf("\n");
    SLEEP;
    puts(" [Comerciante] Tenho um servico para voce.");
    printf("\n");
    SLEEP;
    puts(" [???] Quanto voce vai me pagar?");
    printf("\n");
    SLEEP;
    puts(" [Comerciante] Uma quantia consideravel, pagarei assim que terminar a missão");
    printf("\n");
    SLEEP;
    puts(" [???] Passe-me as instrucoes.");
    printf("\n");
    SLEEP;
    puts(" [Comerciante] Precisamos que voce elimine uma tribo de goblins na parte exterior da floresta Mydra");
    printf("\n");
    SLEEP;
    puts(" [Comerciante] Eles estao saqueando as carruagens de mercadorias");
    printf("\n");
    SLEEP;
    puts(" [Comerciante] Qual e o seu nome? ");
    requisitarNomeDoPersonagem(personagem);
    SLEEP;
    printf("\n [Comerciante] Eh um prazer conhece-lo, %s, conto com voce para completar minha missao. ", personagem->nome);
    printf("\n\n");
    SLEEP;
    puts(" [Comerciante]  Leve com voce essas pocoes, desejo-lhe sorte");
    printf("\n");
    SLEEP;
    printf(" [ %s ] Breve voltarei.\n", personagem->nome);
    puts("(Voce monta em seu cavalo e parte para a parte exterior da floresta Mydra)");
    printf("\n");
    SLEEP;
    system(CLEAR);
}
