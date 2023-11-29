#ifndef POKEDEX_H
#define POKEDEX_H

typedef struct{
    int   numero;
    char  nome[10];
    char  tipo1[9], tipo2[9];
    int   total;
    int   hp, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade;
    int   geracao;
    bool  lendario;
    char  cor[8];
    float altura, peso;
    int   taxaCaptura;
    bool  brilhante;
}Pokemon;

typedef enum
{
    INSERIR = 1,
    LISTAR,
    PESQUISAR,
    ALTERAR,
    EXCLUIR,
    SAIR

}Selecao;

typedef enum
{
    TODOS = 1,
    GERACAO,
    TIPO
}Tipos;

typedef enum
{
        NOME = 1,
        COR,
        ALTURA,
        PESO

}Alteracoes;

typedef union
{
    char nome[12];
    int  numero;
}Escolha;

void recebeDadosPokemons(Pokemon** poke);
void inserirTodosPokemons(Pokemon* dados, Pokemon** pokedex, int* tam);
void listarTodos(Pokemon* pokedex, int tam);
void listarGeracao(Pokemon* pokedex, int tam);
bool checaTipo(char* tipo);
void listarTipo(Pokemon* pokedex, int tam);
void listarPokedex(Pokemon* pokedex, int tam);
void pesquisarPokemon(Pokemon* pokedex, int tam);
void alteraNome(Pokemon** pokedex, int indice);
void alteraCor(Pokemon** pokedex, int indice);
void alteraAltura(Pokemon** pokedex, int indice);
void alteraPeso(Pokemon** pokedex, int indice);
void alterarPokemon(Pokemon** pokedex, int tam);
void excluirPokemon(Pokemon** pokedex, int* tam);
void menuPokedex(Pokemon* dados, Pokemon** pokedex, int* tam);
Pokemon* retornaEstruturaPokemon();

#endif