// Habilitar acentuação no programa
#include <locale.h>

#include "personagem_principal/personagem_principal.h"
#include "menu_principal/menu_principal.h"
#include "fase1/fase1.h"

#define MAX_STRING_SIZE 256

personagem_principal personagem;

int main(void)
{
    // Habilita a acentuação usando o português como lingua
    setlocale(LC_ALL, "Portuguese");
    MenuPrincipal(&personagem);

    return 0;
}