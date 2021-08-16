#include "personagem_principal/personagem_principal.h"
#include "menu_principal/menu_principal.h"

personagem_principal personagem;

int main(void)
{
    // Inicializa o inventario
    item_CriarArrayItem(personagem.inventario);

    MenuPrincipal(&personagem);

    return 0;
}