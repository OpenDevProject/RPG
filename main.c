#include "personagem_principal/personagem_principal.h"
#include "menu_principal/menu_principal.h"

personagem_principal personagem;

int main(void)
{
  MenuPrincipal(&personagem);//Aqui se inicia o jogo

  return 0;
}