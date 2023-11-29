#ifndef COLECAO_H
#define COLECAO_H

typedef struct
{
    int numero;
    int quantidade;
}Colecao;

void ordenaColecao(Colecao* colecao, int tamCol);
void inserirPokemonColecao(Colecao** colecao, Pokemon* pokedex, int* tamCol, int tamPoke);
void listarTodosColecao(Colecao* colecao, Pokemon* pokedex, int tamCol);
void listarGeracaoColecao(Colecao* colecao, Pokemon* pokedex, int tamCol);
void listarTipoColecao(Colecao* colecao, Pokemon* pokedex, int tamCol);
void listarColecao(Colecao* colecao, Pokemon* pokedex, int tamCol);
void pesquisarPokemonColecao(Colecao* colecao, Pokemon* pokedex, int tamCol);
void alterarPokemonColecao(Colecao* colecao, Pokemon** pokedex, int tamCol);
void excluirPokemonColecao(Colecao** colecao, Pokemon* pokedex, int* tamCol);
void menuColecao(Colecao** colecao, Pokemon** pokedex, int* tamCol, int tamPoke);
Colecao* retornaEstruturaColecao();

#endif