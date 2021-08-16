RPG*: \
	personagem_principal/personagem_principal.o \
	personagem_principal/item.o \
	main.o \
	dado/dado.o \
    utils/utils.o \
	criacao_personagem/criacao_personagem.o \
	exit/exit.o \
	introducao/introducao.o \
	menu_principal/menu_principal.o \
	fase1/fase1.o 
	gcc -o RPG \
		personagem_principal/personagem_principal.o \
		personagem_principal/item.o \
		main.o \
		dado/dado.o \
		utils/utils.o \
		criacao_personagem/criacao_personagem.o \
		exit/exit.o \
		introducao/introducao.o \
		menu_principal/menu_principal.o \
		fase1/fase1.o 