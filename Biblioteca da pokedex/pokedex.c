#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokedex.h"
#include "arquivos.h"

/**
 * Recebe os dados dos pokemons
*/
void recebeDadosPokemons(Pokemon** poke)
{
    FILE* arq;
    arq = abreArquivo("pokedex.csv", "r");
    *poke = (Pokemon*) realloc(*poke, 721*sizeof(Pokemon));
    if(*poke == NULL)
    {
        perror("Erro ao realocar a estrutura de dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }//if

    for(int i = 0 ; i < 721 ; i++)
    {
        fscanf(arq, "%i, %s ,%s ,%s ,%i,%i,%i,%i,%i,%i,%i,%i,%i,%s , %f , %f ,%i,%i", 
            &(*poke)[i].numero,
            (*poke)[i].nome,
            (*poke)[i].tipo1,
            (*poke)[i].tipo2,
            &(*poke)[i].total,
            &(*poke)[i].hp, 
            &(*poke)[i].ataque, 
            &(*poke)[i].defesa, 
            &(*poke)[i].ataqueEspecial, 
            &(*poke)[i].defesaEspecial, 
            &(*poke)[i].velocidade,
            &(*poke)[i].geracao,
            &(*poke)[i].lendario,
            (*poke)[i].cor,
            &(*poke)[i].altura,
            &(*poke)[i].peso,
            &(*poke)[i].taxaCaptura,
            &(*poke)[i].brilhante);
    }//for
  
    fclose(arq);

    return;

}// Receber os dados dos Pokemons

/**
 * Inseri todos os pokemons, se não tiver espaço aparecera uma mensagem de erro ao realocar o tamanho da pokedex
 * se não, aparecera uma mensagem de sucesso
*/
void inserirTodosPokemons(Pokemon* dados, Pokemon** pokedex, int* tam)
{
    *pokedex = (Pokemon*) realloc(*pokedex, 721*sizeof(Pokemon));

    if(*pokedex == NULL)
    {
        perror("Erro ao realocar o tamanho da pokedex: ");
        exit(EXIT_FAILURE);
    }//if

    *tam = 721;

    for(int i = 0 ; i < *tam ; i++)
    {
        (*pokedex)[i] = dados[i];
    }//for

    printf("Todos pokemons foram inseridos na pokedex com sucesso.\n");
   
    return;

}//Inserir todos os pokemons

/**
 * Essa função sera acionada quando o usuário selecionar a função no listarpokedex ou listarcolecao
 * quando selecionado, vai exibir todos os pokemons da pokedex
*/
void listarTodos(Pokemon* pokedex, int tam)
{
    for(int i = 0 ; i < tam ; i++)
    {
        printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            pokedex[i].numero,
            pokedex[i].nome,
            pokedex[i].tipo1,
            pokedex[i].tipo2,
            pokedex[i].total,
            pokedex[i].hp, 
            pokedex[i].ataque, 
            pokedex[i].defesa, 
            pokedex[i].ataqueEspecial, 
            pokedex[i].defesaEspecial, 
            pokedex[i].velocidade,
            pokedex[i].geracao,
            pokedex[i].lendario,
            pokedex[i].cor,
            pokedex[i].altura,
            pokedex[i].peso,
            pokedex[i].taxaCaptura,
            pokedex[i].brilhante);
    }//for

    return;

}//listar todos

/**
 * Essa função sera acionada quando o usuário selecionar a função no listarpokedex ou listarcolecao
 * quando selecionado, o usuário vai colocar a coleção e o programa vai verificar se tem pokemons daquela geração
 * se não tiver, vai aparecer uma mensagem falando que não tem pokemons daquela geração
 */
void listarGeracao(Pokemon* pokedex, int tam)
{
    int geracao;
    do
    {
        printf("Digite a geração: ");
        scanf("%i", &geracao);
        if(geracao < 1 || geracao > 6) printf("Digite uma geracao valida\n");
    }while(geracao < 1 || geracao > 6);
    //do

    for(int i = 0 ; i < tam ; i++)
    {
        if(geracao == pokedex[i].geracao){
            printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            pokedex[i].numero,
            pokedex[i].nome,
            pokedex[i].tipo1,
            pokedex[i].tipo2,
            pokedex[i].total,
            pokedex[i].hp, 
            pokedex[i].ataque, 
            pokedex[i].defesa, 
            pokedex[i].ataqueEspecial, 
            pokedex[i].defesaEspecial, 
            pokedex[i].velocidade,
            pokedex[i].geracao,
            pokedex[i].lendario,
            pokedex[i].cor,
            pokedex[i].altura,
            pokedex[i].peso,
            pokedex[i].taxaCaptura,
            pokedex[i].brilhante);
        }//if

    }//for

    return;

}//Listar geração

/**
 * Essa função está relacionada a listarTipo
 * vai verificar com os tipos de pokemons listados abaixo;
*/
bool checaTipo(char* tipo)
{
    if(!strcmp(tipo, "Planta")) return true;
    else if(!strcmp(tipo, "Venenoso")) return true;
    else if(!strcmp(tipo, "Fogo")) return true;
    else if(!strcmp(tipo, "Voador")) return true;
    else if(!strcmp(tipo, "Água")) return true;
    else if(!strcmp(tipo, "Inseto")) return true;
    else if(!strcmp(tipo, "Normal")) return true;
    else if(!strcmp(tipo, "Elétrico")) return true;
    else if(!strcmp(tipo, "Terra")) return true;
    else if(!strcmp(tipo, "Fantasma")) return true;
    else if(!strcmp(tipo, "Pedra")) return true;
    else if(!strcmp(tipo, "Psíquico")) return true;
    else if(!strcmp(tipo, "Sombrio")) return true;
    else if(!strcmp(tipo, "Gelo")) return true;
    else if(!strcmp(tipo, "Aço")) return true;
    else if(!strcmp(tipo, "Dragão")) return true;
    else if(!strcmp(tipo, "Lutador")) return true;
    else if(!strcmp(tipo, "Fada")) return true;
    else return false;  

}//checar o tipo 

/**
 * Essa função sera acionada quando o usuário selecionar a função no listarpokedex ou listarcolecao
 * quando selecionado, o usuário vai colocar o tipo e o programa vai verificar se tem pokemons daquele tipo
 * se não tiver, vai aparecer uma mensagem falando que não tem pokemons daquele tipo
 */
void listarTipo(Pokemon* pokedex, int tam)
{
    bool checa = false;
    char tipo[11];
    do
    {
        printf("Digite o tipo a ser exibido: ");
        setbuf(stdin, NULL);
        fgets(tipo, 11, stdin);
        tipo[strcspn(tipo, "\n")] = '\0';
        checa = checaTipo(tipo);
        if(!checa) printf("Digite um tipo válido\n");
    }while(!checa); //do
    
    for(int i = 0 ; i < tam ; i++)
    {
        if(!strcmp(tipo, pokedex[i].tipo1) || !strcmp(tipo, pokedex[i].tipo2))
        {
            printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            pokedex[i].numero,
            pokedex[i].nome,
            pokedex[i].tipo1,
            pokedex[i].tipo2,
            pokedex[i].total,
            pokedex[i].hp, 
            pokedex[i].ataque, 
            pokedex[i].defesa, 
            pokedex[i].ataqueEspecial, 
            pokedex[i].defesaEspecial, 
            pokedex[i].velocidade,
            pokedex[i].geracao,
            pokedex[i].lendario,
            pokedex[i].cor,
            pokedex[i].altura,
            pokedex[i].peso,
            pokedex[i].taxaCaptura,
            pokedex[i].brilhante);
        }//if
    }//for

    return;

}//Listar o tipo

/**
 * Essa função sera acionada quando o usuário selecionar a funcção no menupokedex
 * quando selecionado, o usuário podera escolher entre listar  - todos, por geração ou por tipo
 * quando selecionado será encaminhado para a função correspondente ao que o usuário escolheu
 */
void listarPokedex(Pokemon* pokedex, int tam)
{
    int selecao;
    do
    {
        printf("Deseja visualizar quais pokemons? \n");
        printf("1) - Todos\n");
        printf("2) - Por geração\n");
        printf("3) - Por tipo\n");
        scanf("%i", &selecao);
        if(selecao < 1 || selecao > 3 ) printf("Digite uma opção válida\n");
    }while(selecao < 1 || selecao > 3); //do

    switch(selecao)
    {
            case TODOS:
                listarTodos(pokedex, tam);
            break;
            case GERACAO:
                listarGeracao(pokedex, tam);
            break;
            case TIPO:
                listarTipo(pokedex, tam);
            break;
            default:
                printf("Não sei nem como entrou nesse erro.");
            break;  
        }//switch

    return;   

}//listar pokedex

/**
 * Essa função sera acionada quando o usuário selecionar a funcção no menupokedex
 * quando selecionado, o usuário podera pesquisar o pokemon pelo nome, se encontrar mostra tudo sobre o pokemon
 */
void pesquisarPokemon(Pokemon* pokedex, int tam)
{
    char procura[12];
    printf("Digite o nome do pokemon a ser pesquisado: ");
    setbuf(stdin, NULL);
    fgets(procura, 12, stdin);
    procura[strcspn(procura, "\n")] = '\0';
    Pokemon encontrado;
    bool achou = false;
    
    for(int i = 0 ; i < tam ; i++)
    {
        if(!strcmp(procura, pokedex[i].nome))
        {
            encontrado =  pokedex[i];
            achou = true;
            break;
        }//if

    }//for

    if(achou)
    {
        printf("Pokemon encontrado: ");
        printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            encontrado.numero,
            encontrado.nome,
            encontrado.tipo1,
            encontrado.tipo2,
            encontrado.total,
            encontrado.hp, 
            encontrado.ataque, 
            encontrado.defesa, 
            encontrado.ataqueEspecial, 
            encontrado.defesaEspecial, 
            encontrado.velocidade,
            encontrado.geracao,
            encontrado.lendario,
            encontrado.cor,
            encontrado.altura,
            encontrado.peso,
            encontrado.taxaCaptura,
            encontrado.brilhante);
    }//if

    else
    {
        printf("Pokemon não encontrado.\n");
    }//else

    return;
}//Pesquisar pokedéx

/**
 * Essa função sera acionada quando o usuário selecionar a função no alterarpokemon ou alterarpokemoncolecao
 * quando selecionado, o usuário podera alterar o nome do pokemon
*/
void alteraNome(Pokemon** pokedex, int indice)
{
    char nome[12];
    printf("Digite o novo nome: ");
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    strcpy((*pokedex)[indice].nome, nome);
    printf("Nome alterado.\n");
    return;

}//alterar nome

/**
 * Essa função sera acionada quando o usuário selecionar a função no alterarpokemon ou alterarpokemoncolecao
 * quando selecionado, o usuário podera alterar a cor do pokemon
*/
void alteraCor(Pokemon** pokedex, int indice)
{
    char cor[12];
    printf("Digite a nova cor: ");
    setbuf(stdin, NULL);
    fgets(cor, 12, stdin);
    cor[strcspn(cor, "\n")] = '\0';
    strcpy((*pokedex)[indice].cor, cor);
    printf("Cor alterada.\n");
    return;

}//altera cor

/**
 * Essa função sera acionada quando o usuário selecionar a função no alterarpokemon ou alterarpokemoncolecao
 * quando selecionado, o usuário podera alterar a altura do pokemon
*/
void alteraAltura(Pokemon** pokedex, int indice)
{
    float altura;
    printf("Digite a nova altura: ");
    scanf("%f", &altura);
    (*pokedex)[indice].altura = altura;
    printf("Altura alterada.\n");
    return;
}//altera altura

/**
 * Essa função sera acionada quando o usuário selecionar a função no alterarpokemon ou alterarpokemoncolecao
 * quando selecionado, o usuário podera alterar o peso do pokemon
*/
void alteraPeso(Pokemon** pokedex, int indice)
{
    float peso;
    printf("Digite o novo peso: ");
    scanf("%f", &peso);
    (*pokedex)[indice].peso = peso;
    printf("Peso alterado.\n");
    return;

}//altera peso

/**
 * Essa função sera acionada quando o usuário selecionar a funcção no menupokedex
 * quando selecionado, o usuário podera escolher entre alterar  - nome, cor, altura ou peso
 * quando selecionado será encaminhado para a função correspondente ao que o usuário escolheu
 */
void alterarPokemon(Pokemon** pokedex, int tam)
{
    char altera[12];
    printf("Digite o nome do pokemon a ser alterado: ");
    setbuf(stdin, NULL);
    fgets(altera, 12, stdin);
    altera[strcspn(altera, "\n")] = '\0';
    bool achou = false;
    int indice;
    for(int i = 0 ; i < tam ; i++)
    {
        if(!strcmp(altera, (*pokedex)[i].nome))
        {
            indice = i;
            achou = true;
            break;
        }//if
    }//for

    if(achou)
    {
        int alteracoes;
            do
            {
                printf("Possiveis alterações: \n");
                printf("1) - Nome\n");
                printf("2) - Cor\n");
                printf("3) - Altura\n");
                printf("4) - Peso\n");
                scanf("%i", &alteracoes);
                if(alteracoes < 1 || alteracoes > 4) printf("Digite uma alteração válida.\n");
            }while(alteracoes < 1 || alteracoes > 4); //do

            switch(alteracoes)
            {
                case NOME:
                    alteraNome(pokedex, indice);
                break;
                case COR:
                    alteraCor(pokedex, indice);
                break;
                case ALTURA:
                    alteraPeso(pokedex, indice);
                break;
                case PESO:
                    alteraPeso(pokedex, indice);
                break;
                default:
                    printf("Ué\n");
                break;
            }//switch
    }//if

    else
    {
        printf("Pokemon não encontrado.\n");
    }//else

    return;
}//alterar pokemon

/**
 * Essa função sera acionada quando o usuário selecionar a funcção no menupokedex
 * quando selecionado, o usuário podera escolher entre excluir o pokemon pelo nome ou numero.
*/
void excluirPokemon(Pokemon** pokedex, int* tam)
{
    int opcao, indice;
    bool encontrou = false;
    do
    {
        printf("Deseja excluir um pokemon pelo nome ou número? \n");
        printf("1) - Nome\n");
        printf("2) - Número\n");
        scanf("%i", &opcao);
        if(opcao < 1 || opcao > 2) printf("Opção invalida.");
    }while(opcao < 1 || opcao > 2);

    Escolha escolha;
    if(opcao == 1)
    {
        printf("Digite o nome do pokemon: ");
        setbuf(stdin, NULL);
        fgets(escolha.nome, 12, stdin);
        escolha.nome[strcspn(escolha.nome, "\n")] = '\0';
        for(int i = 0 ; i < *tam ; i++)
        {
            if(!strcmp(escolha.nome, (*pokedex)[i].nome))
            {
                indice = i;
                encontrou = true;
                break;
            }//if

        }//for
    }//if

    else
    {
        printf("Digite o número do pokemon: ");
        scanf("%i", &escolha.numero);
        for(int i = 0 ; i < *tam ; i++)
        {
            if(escolha.numero == (*pokedex)[i].numero)
            {
                indice = i;
                encontrou = true;
                break;
            }//if
        }//for
    }//else
    
    if(encontrou)
    {
        (*tam)--;
        for(int i = indice ; i < *tam ; i++)
        {
            (*pokedex)[i] = (*pokedex)[i+1];
        }//for

        printf("Pokemon excluido.\n");
        *pokedex = (Pokemon*) realloc(*pokedex, (*tam)*sizeof(Pokemon));
        if(*pokedex == NULL)
        {
            perror("Erro ao realocar a pokedex: ");
            exit(EXIT_FAILURE);
        }//if

    }//if

    else
    {
        printf("Pokemon não encontrado.\n");
    }//else

    return;

}//excluir pokemon

/**
 * Função do menu da pokedex
 * se o usuário acessar essa função ele pode escolehr entre, inserir, listar, pesquisar, alterar, excluir ou sair do menu
 * quando o usuário escolher um, vai ser direcionado diretamente para a função  escolhido
*/
void menuPokedex(Pokemon* dados, Pokemon** pokedex, int* tam)
{
    int selecao;
    do
    {
        do
        {
            printf("1) - Inserir pokemons.\n");
            printf("2) - Listar pokemons.\n");
            printf("3) - Pesquisar pokemon.\n");
            printf("4) - Alterar pokemon.\n");
            printf("5) - Excluir pokemon.\n");
            printf("6) - Sair do menu.\n");
            scanf("%i", &selecao);
            if(selecao < 1 || selecao > 6) printf("Escolha uma opção válida.\n");
        }while(selecao < 1 || selecao > 6);

        switch(selecao)
        {
            case INSERIR:
                inserirTodosPokemons(dados, pokedex, tam);
            break;
            case LISTAR:
                listarPokedex(*pokedex, *tam);
            break;
            case PESQUISAR:
                pesquisarPokemon(*pokedex, *tam);
            break;
            case ALTERAR:
                alterarPokemon(pokedex, *tam);
            break;
            case EXCLUIR:
                excluirPokemon(pokedex, tam);
            break;
            case SAIR:
                break;
        } //switch
    }while(selecao != SAIR);

    return;
}//Menu 

/**
 * alocação dinamica para os dados do pokemon
*/
Pokemon* retornaEstruturaPokemon()
{
    Pokemon* dados;
    dados = (Pokemon*) malloc(sizeof(Pokemon));
    if(dados == NULL)
    {
        perror("Erro ao alocar as estruturas de dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }//if

    return dados;

}// retorna estrutura pokemon