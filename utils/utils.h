#ifndef UTILS_H
#define UTILS_H

#ifdef __linux__
#define CLEAR "clear"
#elif _WIN32
#define CLEAR "cls"
#endif

void clearBuffer();
void TratamentoDeErro();
void RemoverNovaLinhaDaString(char string[]);

#endif