#include "personagem_principal.h"

#include <stdio.h>
#include <string.h>

static int seItemForVazio(item itemParaVerificar)
{
    return itemParaVerificar.quant == -1 && (strcmp(itemParaVerificar.nome, "VAZIO") == 0);
}

int item_encontrarVazioNoInventario(item inventario[])
{
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
        if (seItemForVazio(inventario[i]))
            return i;

    return -1;
}

static int itemTiverOMesmoNome(item itemAtual, item itemAProcurar)
{
    return strcmp(itemAtual.nome, itemAProcurar.nome) == 0;
}

int item_encontrarItemNoInventario(item inventario[], item itemAProcurar)
{
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
        if (itemTiverOMesmoNome(inventario[i], itemAProcurar))
            return i;
}

static void usarKitDeArmaduraDoInventario(item *itemAtual, item inventario[], personagem_principal *personagem)
{
    itemAtual->quant = itemAtual->quant - 1;
    personagem_recuperarDef(personagem, 20);
    if (itemAtual->quant <= 0)
        item_RemoverItemDoInventario(*itemAtual, inventario);
}

static int itemEKitDeArmadura(item itemParaUsar)
{
    return strcmp(itemParaUsar.nome, "Kit de Armadura") == 0;
}

static int itemAtualEOMesmo(item itemParaUsar, item itemAtual)
{
    return strcmp(itemAtual.nome, itemParaUsar.nome) == 0;
}

static int itemAtualEONecessitadoEKitDeArmadura(item itemParaUsar, item itemAtual)
{
    return itemAtualEOMesmo(itemParaUsar, itemAtual) && itemEKitDeArmadura(itemParaUsar);
}

static void usarPocaoDoInventario(item *itemAtual, item inventario[], personagem_principal *personagem)
{
    itemAtual->quant = itemAtual->quant - 1;
    personagem_recuperarVida(20, personagem);
    if (itemAtual->quant <= 0)
        item_RemoverItemDoInventario(*itemAtual, inventario);
}

static int itemEPocaoDeVida(item itemParaUsar)
{
    return strcmp(itemParaUsar.nome, "Pocao de vida") == 0;
}

static int itemAtualEONecessitadoEPocaoDeVida(item itemParaUsar, item itemAtual)
{
    return itemAtualEOMesmo(itemParaUsar, itemAtual) && itemEPocaoDeVida(itemParaUsar);
}

static void realizarAcaoDoItem(item itemParaUsar, item *itemAtual, item inventario[], personagem_principal *personagem)
{
    if (itemAtualEONecessitadoEPocaoDeVida(itemParaUsar, *itemAtual))
        usarPocaoDoInventario(itemAtual, inventario, personagem);
    if (itemAtualEONecessitadoEKitDeArmadura(itemParaUsar, *itemAtual))
        usarKitDeArmaduraDoInventario(itemAtual, inventario, personagem);
}

void item_UsarItemDoInventario(item itemParaUsar, personagem_principal *personagem, item inventario[])
{
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
        realizarAcaoDoItem(itemParaUsar, &inventario[i], inventario, personagem);
}

void item_AdicionarItemAoInventario(item itemParaAdicionar, item inventario[])
{
    inventario[item_encontrarVazioNoInventario(inventario)] = itemParaAdicionar;
}

static void removerItem(item inventario[], int index)
{
    item itemVazio = ITEM_VAZIO;
    inventario[index] = itemVazio;
}

void item_RemoverItemDoInventario(item itemParaRemover, item inventario[])
{
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
        if (itemAtualEOMesmo(itemParaRemover, inventario[i]))
            removerItem(inventario, i);
}

void item_CriarArrayItem(item inventario[])
{
    item vazio = ITEM_VAZIO;

    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
        inventario[i] = vazio;
}