SOURCES = personagem_principal/personagem_principal.o \
		personagem_principal/item.o \
		personagem_principal/habilidade.o \
		main.o \
		dado/dado.o \
    	utils/utils.o \
		criacao_personagem/criacao_personagem.o \
		exit/exit.o \
		introducao/introducao.o \
		menu_principal/menu_principal.o \
		fase1/fase1.o \
		inimigo/inimigo.o \
		sistema_batalha/batalha.o \
		estado/estado.o
CC = gcc
PROGRAM_NAME = RPG

RPG*: $(SOURCES)
	$(CC) -o $(PROGRAM_NAME) $(SOURCES)