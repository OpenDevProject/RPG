cmake_minimum_required(VERSION 3.21.2)

project(RPG)

set(SRCS criacao_personagem/criacao_personagem.c
        dado/dado.c
        exit/exit.c
        estado/estado.c
        inimigo/inimigo.c
        fase1/fase1.c
        sistema_batalha/batalha.c
        introducao/introducao.c
        menu_principal/menu_principal.c
        personagem_principal/habilidade.c
        personagem_principal/item.c
        personagem_principal/personagem_principal.c
        utils/utils.c
        main.c)

add_executable(${PROJECT_NAME} ${SRCS})