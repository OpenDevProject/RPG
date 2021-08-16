// Habilitar acentuação no programa
#include <locale.h>

#include "personagem_principal/personagem_principal.h"
#include "menu_principal/menu_principal.h"

personagem_principal personagem;

int main(void)
{
    // Habilita a acentuação usando o português como lingua
    setlocale(LC_ALL, "Portuguese");

    // Inicializa o inventario
    item_CriarArrayItem(personagem.inventario);

    MenuPrincipal(&personagem);

    return 0;
}