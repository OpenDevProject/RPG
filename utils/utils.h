#ifndef UTILS_H
#define UTILS_H

#ifdef __linux__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

#define MAX_STRING_SIZE 256
#define SLEEP sleep(3.75);

void clearBuffer();
void TratamentoDeErro();
void RemoverNovaLinhaDaString(char string[]);
void cringe();

#endif