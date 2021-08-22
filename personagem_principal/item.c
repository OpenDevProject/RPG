#include "personagem_principal.h"

#include <stdio.h>
#include <string.h>

/**
 * @brief Encontra primeiro vazio do inventario
 * 
 * @param inventario O array que guarda o inventario
 */
int item_encontrarVazioNoInventario(item inventario[])
{
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
    {
        if (inventario[i].quant == -1 && (strcmp(inventario[i].nome, "VAZIO") == 0))
            return i;
    }

    return -1;
}

/**
 * @brief Encontra o item no inventario
 * 
 * @param inventario O array que guarda o inventario
 */
int item_encontrarItemNoInventario(item inventario[], item itemAProcurar)
{
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
    {
        if (strcmp(inventario[i].nome, itemAProcurar.nome) == 0)
            return i;
    }
}

/**
 * @brief Usa um item do inventario
 * 
 * @param itemParaUsar A struct item que será usada
 * @param personagem O endereco do personagem a remover do inventario
 * @param inventario O array que guarda o inventario
 */
void item_UsarItemDoInventario(item itemParaUsar, personagem_principal *personagem, item inventario[])
{
    for(int i = 0; i < MAX_INVENTARIO_SIZE; i++)
    {
        if(strcmp(inventario[i].nome, itemParaUsar.nome) == 0 && strcmp(itemParaUsar.nome, "Pocao de vida") == 0)
        {   
            inventario[i].quant--;
            personagem_recuperarVida(20, personagem);
            if(inventario[i].quant <= 0)
                item_RemoverItemDoInventario(itemParaUsar, inventario);
            
            break;
        }
        if(strcmp(inventario[i].nome, itemParaUsar.nome) == 0 && strcmp(itemParaUsar.nome, "Kit de Armadura") == 0)
        {   
            inventario[i].quant--;
            personagem_recuperarDef(6, personagem);
            if(inventario[i].quant <= 0)
                item_RemoverItemDoInventario(itemParaUsar, inventario);
            break;
        }
    }
}

/**
 * @brief Adiciona um item ao inventario
 * 
 * @param itemParaAdicionar O item a ser adicionado
 * @param inventario O array que guarda o inventario
 */
void item_AdicionarItemAoInventario(item itemParaAdicionar, item inventario[])
{
    // Insere o novo item no valor vazio mais proximo
    inventario[item_encontrarVazioNoInventario(inventario)] = itemParaAdicionar;
}

/**
 * @brief Remove um item do inventario
 * 
 * @param itemParaRemover O item para ser removido
 * @param inventario O array que guarda o inventario
 */
void item_RemoverItemDoInventario(item itemParaRemover, item inventario[])
{
    // Percorre todo o inventario
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++){
        // Se o item para remover tiver o mesmo nome retira ele do inventario
        if (strcmp(inventario[i].nome, itemParaRemover.nome) == 0)
        {
            // Insere o item vazio no lugar do item atual
            item itemVazio = ITEM_VAZIO;
            inventario[i] = itemVazio;
            
            break;
        }
    }
}

/**
 * @brief Cria o inventario colocando o ultimo elemento como uma finalizacao
 * 
 * @param inventario O array que guarda o inventario
 */
void item_CriarArrayItem(item inventario[])
{
    // Define o primeiro item do inventario como o item de inicializacao
    item vazio = ITEM_VAZIO;

    // Coloca todo o inventario como vazio
    for (int i = 0; i < MAX_INVENTARIO_SIZE; i++)
        inventario[i] = vazio;
}