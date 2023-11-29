#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokedex.h"
#include "colecao.h"
#include "arquivos.h"
#include "mochila.h"

/**
 * Vai rodar todas as funções, e fazer  com que o jogo funcione.
*/
int main(void)
{
    Pokemon* dadosPokemons;
    dadosPokemons = retornaEstruturaPokemon();
    Pokemon* pokedex;
    pokedex = retornaEstruturaPokemon();
    Mochila* mochila =(Mochila*) malloc(6 * sizeof(Mochila));
    int tamCol = 1, tamPoke;

    FILE* arquivo;
    arquivo = fopen("saveState.bin", "rb");
    if(arquivo == NULL)
    {
        printf("Bem vindo ao pokemon da Shopee\n");
        recebeDadosPokemons(&dadosPokemons);
    }//if

    else
    {
        printf("Carregando dados da Shopee\n");
        carregaSave(&dadosPokemons, &pokedex, &tamPoke);
        fclose(arquivo);
    }//else

    Colecao* colecao;
    colecao = retornaEstruturaColecao();

    char opcao;

    printf("Digite P para acessar o menu da pokedex\n");
    printf("Digite C para acessar o menu de coleção\n");
    opcao = getchar();
    if(opcao == 'P')
    {
        menuPokedex(dadosPokemons, &pokedex, &tamPoke);
    }//if

    else if(opcao == 'C')
    {
        menuColecao(&colecao, &pokedex, &tamCol, tamPoke);
    }//else

    armazenarMochila(mochila, dadosPokemons);

    salvaJogo(dadosPokemons, pokedex, tamPoke);
    free(dadosPokemons);
    free(pokedex);
    free(mochila);

    return 0;

}