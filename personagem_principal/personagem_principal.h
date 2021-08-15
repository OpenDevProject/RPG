#ifndef PERSONAGEM_PRINCIPAL_H
#define PERSONAGEM_PRINCIPAL_H

#define MAX_STRING_NAME 10

/**
 * @brief Struct que indentifica o personagem principal
 * 
 */
typedef struct personagem_principal
{
    char nome[MAX_STRING_NAME];
    int classe;
    int atk;
    int matk;
    int vida;
    int def;
    int mana;
} personagem_principal;

void personagem_principal_criarGuerreiro(personagem_principal *personagem);
void personagem_principal_criarCacador(personagem_principal *personagem);
void personagem_principal_criarMago(personagem_principal *personagem);

#endif