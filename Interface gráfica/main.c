#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
Para gerenciar a Pokedex, defina uma estrutura Pokémon contendo: XXX. Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.
*/

typedef struct{
    int numero;
    char nome[10];
    char tipo1[9], tipo2[9];
    int total;
    int hp, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade;
    int geracao;
    bool lendario;
    char cor[8];
    float altura, peso;
    int taxaCaptura;
    bool brilhante;
}Pokemon;

FILE* abreArquivo(char* nome, char* modoAbertura){
    FILE* arq;
    arq = fopen(nome, modoAbertura);
    if(arq == NULL){

        perror("Erro ao abrir o arquivo: ");
        exit(EXIT_FAILURE);
    }
    return arq;
}

void recebeDadosPokemons(Pokemon* poke){
    FILE* arq;
    arq = abreArquivo("pokedex.csv", "r");
    poke = (Pokemon*) realloc(poke, 721*sizeof(Pokemon));
    if(poke == NULL){
        perror("Erro ao realocar a estrutura de dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i < 721 ; i++){
        fscanf(arq, "%i, %s ,%s ,%s ,%i,%i,%i,%i,%i,%i,%i,%i,%i,%s , %f , %f ,%i,%i", 
            &poke[i].numero,
            poke[i].nome,
            poke[i].tipo1,
            poke[i].tipo2,
            &poke[i].total,
            &poke[i].hp, 
            &poke[i].ataque, 
            &poke[i].defesa, 
            &poke[i].ataqueEspecial, 
            &poke[i].defesaEspecial, 
            &poke[i].velocidade,
            &poke[i].geracao,
            &poke[i].lendario,
            poke[i].cor,
            &poke[i].altura,
            &poke[i].peso,
            &poke[i].taxaCaptura,
            &poke[i].brilhante);
    }
/*
    for(int i = 0 ; i < 721 ; i++){
        printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
        poke[i].numero,
            poke[i].nome,
            poke[i].tipo1,
            poke[i].tipo2,
            poke[i].total,
            poke[i].hp, 
            poke[i].ataque, 
            poke[i].defesa, 
            poke[i].ataqueEspecial, 
            poke[i].defesaEspecial, 
            poke[i].velocidade,
            poke[i].geracao,
            poke[i].lendario,
            poke[i].cor,
            poke[i].altura,
            poke[i].peso,
            poke[i].taxaCaptura,
            poke[i].brilhante);
    }
*/ 
  
    fclose(arq);
    return;
}

typedef enum{
    INSERIRTODOS = 1,
    INSERIRGERACAO,
    INSERIRTIPO,
    INSERIRESPECIFICO
}Selecao;

void inserirTodosPokemons(Pokemon* dados, Pokemon* pokedex){
    pokedex = (Pokemon*) realloc(dados, 721*sizeof(Pokemon));
    if(pokedex == NULL){
        perror("Erro ao realocar o tamanho da pokedex: ");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i < 721 ; i++){
        pokedex[i] = dados[i];
    }
    return;
}

int contaPokemons(Pokemon* dados, int geracao, char* tipo){
    int contador;
    if(tipo == NULL){
        for(int i = 0 ; i < 721 ; i++){
            if(dados[i].geracao == geracao){
                contador++;
            }
        }
    }
    else{
        for(int i = 0 ; i < 721 ; i++){
            if(strcmp(dados[i].tipo1, tipo) == 0 || strcmp(dados[i].tipo2, tipo) == 0){
                contador++;
            }
        }
    }
    return contador;
}

void inserirGeracaoPokemons(Pokemon* dados, Pokemon* pokedex){
    int ger;
    do{
        printf("Digite qual a geração de pokemons que deseja inserir: ");
        scanf("%i", &ger);
        if(ger < 1 || ger > 6) printf("Digite uma geração válida (1~6)\n");
    }while(ger < 1 || ger > 6);
    int tam = contaPokemons(dados, ger, NULL);
    pokedex = (Pokemon*) realloc(dados, tam*sizeof(Pokemon));
    if(pokedex == NULL){
        perror("Erro ao realocar o tamanho da pokedex: ");
        exit(EXIT_FAILURE);
    }
    // INSERTION SORT
    return;
}

void inserirTipoPokemons(Pokemon* dados, Pokemon* pokedex){
    char tipo[10];
    printf("Digite qual tipo de pokemons que deseja inserir: ");
    setbuf(stdin, NULL);
    fgets(tipo, 8, stdin);
    tipo[strcspn(tipo, "\n")] = '\0';
    int tam = contaPokemons(dados, NULL, tipo);
    pokedex = (Pokemon*) realloc(pokedex, tam*sizeof(Pokemon));
    if(pokedex == NULL){
        perror("Erro ao realocar a pokedex: ");
        exit(EXIT_FAILURE);
    }
    // INSERTION SORT
    return;
}

void inserirPokemon(){
    int selecao;
    do{
        printf("1) - Inserir todos pokemons.\n");
        printf("2) - Inserir pokemons de uma geração.\n");
        printf("3) - Inserir pokemons de um tipo.\n");
        printf("4) - Inserir um pokemon específico.\n");
        scanf("%i", &selecao);
        if(selecao < 1 || selecao > 4) printf("Escolha uma opção válida.\n");
    }while(selecao < 1 || selecao > 4);

    switch(selecao){
        case INSERIRTODOS:

        case INSERIRGERACAO:

        case INSERIRTIPO:

        case INSERIRESPECIFICO:

    }
}

/*
Defina uma estrutura Coleção que deve armazenar a relação dos Pokémons já
capturados, para isso armazene apenas o número(códigos). Essa relação deve
aumentar e diminuir dinamicamente. Você deve prever o caso de Pokémons duplicados.
O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os pokémons
já capturados.
*/

typedef struct{
    
}Pokedex;

typedef struct{
    
}Colecao;

/*
Defina uma estrutura Mochila que deve armazenar a relação de até 6 Pokémons já
capturados e que poderão ser utilizados em batalha, para isso armazene apenas o
número(códigos).
*/

typedef struct{

}Mochila;

Pokemon* retornaEstrutura(){
    Pokemon* dados;
    dados = (Pokemon*) malloc(sizeof(Pokemon));
    if(dados == NULL){
        perror("Erro ao alocar as estruturas de dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }
    return dados;
}

int main(void){

    Pokemon* dadosPokemons;
    dadosPokemons = retornaEstrutura();

    char opcao;

    printf("Sua pokedex está vazia, digite A para inserir pokemons.");
    opcao = getchar();
    if(opcao == 'A'){
        inserirPokemon();
    }

    recebeDadosPokemons(dadosPokemons);
    
    //printf("Tamanho da pokedex: %li", sizeof(pokemons));

    return 0;
}