#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokedex.h"
#include "colecao.h"
#include "arquivos.h"

FILE* abreArquivo(char* nome, char* modoAbertura)
{
    FILE* arq;
    arq = fopen(nome, modoAbertura);
    if(arq == NULL)
    {
        perror("Erro ao abrir o arquivo: ");
        exit(EXIT_FAILURE);
    }//if

    return arq;

}//abreArquivo

void carregaSave(Pokemon** dados, Pokemon** pokedex, int* tam)
{
    FILE* arquivo;
    arquivo = abreArquivo("saveState.bin", "rb");
    *dados = (Pokemon*) realloc(*dados, 721*sizeof(Pokemon));
    if(*dados == NULL)
    {
        perror("Erro ao realocar os dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }//if

    for(int i = 0 ; i < 721 ; i++)
    {
        fread(&(*dados)[i].numero, sizeof(int), 1, arquivo);
        fread((*dados)[i].nome, sizeof(char), 10, arquivo);
        fread((*dados)[i].tipo1, sizeof(char), 9, arquivo);
        fread((*dados)[i].tipo2, sizeof(char), 9, arquivo);
        fread(&(*dados)[i].total, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].hp, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].ataque, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].defesa, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].ataqueEspecial, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].defesaEspecial, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].velocidade, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].geracao, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].lendario, sizeof(bool), 1, arquivo);
        fread((*dados)[i].cor, sizeof(char), 8, arquivo);
        fread(&(*dados)[i].altura, sizeof(float), 1, arquivo);
        fread(&(*dados)[i].peso, sizeof(float), 1, arquivo);
        fread(&(*dados)[i].taxaCaptura, sizeof(int), 1, arquivo);
        fread(&(*dados)[i].brilhante, sizeof(bool), 1, arquivo);
    }//for

    fclose(arquivo);
    arquivo = abreArquivo("pokedexState.bin", "rb");
    fread(tam, sizeof(int), 1, arquivo);

    *pokedex = (Pokemon*) realloc(*pokedex, (*tam)*sizeof(Pokemon));
    if(*pokedex == NULL)
    {
        perror("Erro ao realocar a estrutura de pokemons: ");
        exit(EXIT_FAILURE);
    }//if

    for(int i = 0 ; i < *tam ; i++)
    {
        fread(&(*pokedex)[i].numero, sizeof(int), 1, arquivo);
        fread((*pokedex)[i].nome, sizeof(char), 10, arquivo);
        fread((*pokedex)[i].tipo1, sizeof(char), 9, arquivo);
        fread((*pokedex)[i].tipo2, sizeof(char), 9, arquivo);
        fread(&(*pokedex)[i].total, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].hp, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].ataque, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].defesa, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].ataqueEspecial, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].defesaEspecial, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].velocidade, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].geracao, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].lendario, sizeof(bool), 1, arquivo);
        fread((*pokedex)[i].cor, sizeof(char), 8, arquivo);
        fread(&(*pokedex)[i].altura, sizeof(float), 1, arquivo);
        fread(&(*pokedex)[i].peso, sizeof(float), 1, arquivo);
        fread(&(*pokedex)[i].taxaCaptura, sizeof(int), 1, arquivo);
        fread(&(*pokedex)[i].brilhante, sizeof(bool), 1, arquivo);
    }//for

    fclose(arquivo);

    return;

}//carrega save

/**
 * Função na qual salva o jogo.
 * cria um arquivo para escrever;
*/
void salvaJogo(Pokemon* dados, Pokemon* pokedex, int tam)
{
    FILE* arquivo;
    arquivo = abreArquivo("saveState.bin", "wb");
    for(int i = 0 ; i < 721 ; i++)
    {
        fwrite(&dados[i].numero, sizeof(int), 1, arquivo);
        fwrite(dados[i].nome, sizeof(char), 10, arquivo);
        fwrite(dados[i].tipo1, sizeof(char), 9, arquivo);
        fwrite(dados[i].tipo2, sizeof(char), 9, arquivo);
        fwrite(&dados[i].total, sizeof(int), 1, arquivo);
        fwrite(&dados[i].hp, sizeof(int), 1, arquivo);
        fwrite(&dados[i].ataque, sizeof(int), 1, arquivo);
        fwrite(&dados[i].defesa, sizeof(int), 1, arquivo);
        fwrite(&dados[i].ataqueEspecial, sizeof(int), 1, arquivo);
        fwrite(&dados[i].defesaEspecial, sizeof(int), 1, arquivo);
        fwrite(&dados[i].velocidade, sizeof(int), 1, arquivo);
        fwrite(&dados[i].geracao, sizeof(int), 1, arquivo);
        fwrite(&dados[i].lendario, sizeof(bool), 1, arquivo);
        fwrite(dados[i].cor, sizeof(char), 8, arquivo);
        fwrite(&dados[i].altura, sizeof(float), 1, arquivo);
        fwrite(&dados[i].peso, sizeof(float), 1, arquivo);
        fwrite(&dados[i].taxaCaptura, sizeof(int), 1, arquivo);
        fwrite(&dados[i].brilhante, sizeof(bool), 1, arquivo);
    }//for
    
    fclose(arquivo);
    arquivo = abreArquivo("pokedexState.bin", "wb");
    fwrite(&tam, sizeof(int), 1, arquivo);

    for(int i = 0 ; i < tam ; i++)
    {
        fwrite(&pokedex[i].numero, sizeof(int), 1, arquivo);
        fwrite(pokedex[i].nome, sizeof(char), 10, arquivo);
        fwrite(pokedex[i].tipo1, sizeof(char), 9, arquivo);
        fwrite(pokedex[i].tipo2, sizeof(char), 9, arquivo);
        fwrite(&pokedex[i].total, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].hp, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].ataque, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].defesa, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].ataqueEspecial, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].defesaEspecial, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].velocidade, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].geracao, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].lendario, sizeof(bool), 1, arquivo);
        fwrite(pokedex[i].cor, sizeof(char), 8, arquivo);
        fwrite(&pokedex[i].altura, sizeof(float), 1, arquivo);
        fwrite(&pokedex[i].peso, sizeof(float), 1, arquivo);
        fwrite(&pokedex[i].taxaCaptura, sizeof(int), 1, arquivo);
        fwrite(&pokedex[i].brilhante, sizeof(bool), 1, arquivo);
    }//for

    fclose(arquivo);
    return;
}//salva o jogo