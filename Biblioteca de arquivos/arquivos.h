#ifndef ARQUIVOS_H
#define ARQUIVOS_H

FILE* abreArquivo(char* nome, char* modoAbertura);
void carregaSave(Pokemon** dados, Pokemon** pokedex, int* tam);
void salvaJogo(Pokemon* dados, Pokemon* pokedex, int tam);

#endif