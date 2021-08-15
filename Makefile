RPG*: main.o dado/dado.o personagem_principal/personagem_principal.o utils/utils.o \
	criacao_personagem/criacao_personagem.o exit/exit.o introducao/introducao.o \
	menu_principal/menu_principal.o fase1/fase1.o
	gcc -o RPG main.o dado/dado.o personagem_principal/personagem_principal.o utils/utils.o \
		criacao_personagem/criacao_personagem.o exit/exit.o introducao/introducao.o \
		menu_principal/menu_principal.o fase1/fase1.o