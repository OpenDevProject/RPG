#include "fase1.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Fase1(personagem_principal *personagem){ 
    puts("[rei] Você é o mercenário contratado? ");
        sleep( 1 );
    puts("[jogador] Sim, estou aqui pela missão de execução do Dragão Aither.");
        sleep ( 1.5);
    puts("[rei] Já matou algum monstro? ");
        sleep ( 1 );
    puts("[jogador] Alguns pequenos");
        sleep ( 1 );
    puts("[rei] E você está confiante em completar essa missão?");
        sleep ( 1.5 );
    puts("[jogador] Para tudo há uma primeira vez, me esforçarei para trazer uma escama de Aither para você.");
        sleep ( 2 );
    puts("[rei] Você deve começar matando os três Wyverns guardiões para se provar competente o suficiente.");
        sleep ( 2.5 );
    puts("[rei] Não enviaremos jovens inexperientes para sua morte!");
        sleep ( 2);
    puts("[rei] Leve essa espada e algumas poções para sua aventura na Floresta Mydra, na qual você executará o primeiro Wyvern, Radamanthys.");
        sleep ( 2.5 );
    puts("(Após receber a espada e as poções você parte para a Floresta Mydra para enfrentar Radamanthys.)");
        sleep ( 1 );
    puts("(No caminho para a floresta Mydra você encontra uma placa descrevendo os perigosos monstros.)");
        sleep ( 1 );
    puts("--------------------- Goblins -------------------");
    puts("--------------------- Slime ---------------------");
    puts("--------------------- Orcs ----------------------");
    puts("--------------------- Bruxa ---------------------");
    puts("--------------------- Elfo ----------------------");
    puts("--------------------- Grifo ---------------------");
    puts("-------------- Radamanthys, Wyvern --------------");
        sleep ( 1 );
    puts("[jogador] Então essa é a Floresta Mydra!");
        sleep( 1 );
    puts("(O ventro sopra e nosso herói percebe o quão profunda e escura é a floresta.) ");
        sleep ( 1.5);
    puts("(Eis que surge um [adversário] )");
        sleep ( 1 );
    puts("[adversário]");
        sleep ( 1 );

}

// void Reaçãodoreiaosaberqueelecaçadragões (){ 
// puts(⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿);
// puts(⣿⠟⠫⢻⣿⣿⣿⣿⢟⣩⡍⣙⠛⢛⣿⣿⣿⠛⠛⠛⠛⠻⣿⣿⣿⣿⣿⡿⢿⣿);
// puts(⣿⠤⠄⠄⠙⢿⣿⣿⣿⡿⠿⠛⠛⢛⣧⣿⠇⠄⠂⠄⠄⠄⠘⣿⣿⣿⣿⠁⠄⢻);
// puts(⣿⣿⣿⣿⣶⣄⣾⣿⢟⣼⠒⢲⡔⣺⣿⣧⠄⠄⣠⠤⢤⡀⠄⠟⠉⣠⣤⣤⣤⣾);
// puts(⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣀⣬⣵⣿⣿⣿⣶⡤⠙⠄⠘⠃⠄⣴⣾⣿⣿⣿⣿⣿);
// puts(⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢻⠿⢿⣿⣿⠿⠋⠁⠄⠂⠉⠒⢘⣿⣿⣿⣿⣿⣿⣿);
// puts(⣿⣿⣿⣿⣿⣿⣿⣿⡿⣡⣷⣶⣤⣤⣀⡀⠄⠄⠄⠄⠄⠄⠄⣾⣿⣿⣿⣿⣿⣿);
// puts(⣿⣿⣿⣿⣿⣿⣿⡿⣸⣿⣿⣿⣿⣿⣿⣿⣷⣦⣰⠄⠄⠄⠄⢾⠿⢿⣿⣿⣿⣿);
// puts(⣿⡿⠋⣡⣾⣿⣿⣿⡟⠉⠉⠈⠉⠉⠉⠉⠉⠄⠄⠄⠑⠄⠄⠐⡇⠄⠈⠙⠛⠋);
// puts(⠋⠄⣾⣿⣿⣿⣿⡿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢠⡇⠄⠄⠄⠄⠄);
// puts(⠄⢸⣿⣿⣿⣿⣿⣯⠄⢠⡀⠄⠄⠄⠄⠄⠄⠄⠄⣀⠄⠄⠄⠄⠁⠄⠄⠄⠄⠄);
// puts(⠁⢸⣿⣿⣿⣿⣿⣯⣧⣬⣿⣤⣐⣂⣄⣀⣠⡴⠖⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄);
// puts(⠈⠈⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣽⣉⡉⠉⠈⠁⠄⠁⠄⠄⠄⠄⡂⠄⠄⠄⠄⠄);
// puts(⠄⠄⠙⣿⣿⠿⣿⣿⣿⣿⣷⡤⠈⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠠⠔⠄⠄⠄⠄⠄);
// puts(⠄⠄⠄⡈⢿⣷⣿⣿⢿⣿⣿⣷⡦⢤⡀⠄⠄⠄⠄⠄⠄⢐⣠⡿⠁⠄⠄⠄⠄⠄);
// }