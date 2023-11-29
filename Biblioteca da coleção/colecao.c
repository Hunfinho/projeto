#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokedex.h"
#include "colecao.h"

/**
 * Essa função verifica a coleção e coloca em ordem de acordo com o número
*/
void ordenaColecao(Colecao* colecao, int tamCol)
{
    Colecao troca;
    bool check = true;
    while(check)
    {
        check = false;
        for(int i = 0 ; i < tamCol - 1 ; i++)
        {
            if(colecao[i].numero > colecao[i+1].numero)
            {
                troca = colecao[i];
                colecao[i] = colecao[i+1];
                colecao[i+1] = troca;
                check = true;

            }//if

        }//for , verifica a coleção

    }//while pra checar

    return;

}//Ordena coleção

/**
 * Essa função será acionada quando o usuário solicitar na função menucolecao,
 * quando solicitado, verifica se o pokemon que foi capturado se o nome for igual ao de um que já tenha na pokedex, o numero desse pokemon vai ser o mesmo do que o da pokedex
*/
void inserirPokemonColecao(Colecao** colecao, Pokemon* pokedex, int* tamCol, int tamPoke)
{
    char nome[12];
    bool checa = false, repetido = false;
    int numero;
    printf("Digite o nome do pokemon capturado para inserir: ");
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    for(int i = 0 ; i < tamPoke ; i++)
    {
        if(!strcmp(nome, pokedex[i].nome))
        {
            numero = pokedex[i].numero;
            checa = true;
            break;
        }//if o  nome do pokemon capturado for igual ao que ja existe, ele vai colocar o numero como o numero da estrutura do pokemon
         //ele checa se é verdade, se for ele para
    }//for

    if(checa)
    {
        for(int i = 0 ; i < *tamCol ; i++)
        {
            if(numero == (*colecao)[i].numero)
            {
                ((*colecao)[i].quantidade)++;
                repetido = true;
            }//if pra ver se o numero é igual ao numero da estrutura coleção
       
        }//for

        if(!repetido)
        {     
            (*tamCol)++;
            *colecao = (Colecao*) realloc(*colecao, (*tamCol)*sizeof(Colecao));
            if(*colecao == NULL)
            {
                perror("Erro ao realocar a estrutura da coleção: ");
                exit(EXIT_FAILURE);
            }// arquivo

            (*colecao)[*tamCol].numero = numero;
            (*colecao)[*tamCol].quantidade = 1;
        }//se for diferente de repetido

    }//if, pra checar
    else
    {
        printf("Pokemon não existe.\n");
    }//else

    ordenaColecao(*colecao, *tamCol);

    return;

}//Inserir pokémon na coleção

/**
 * Essa função será acionada quando o usuário solicitar na função listarcolecao,
 * quando solicitado, mostram todos os pokemons da coleção que tem.
*/
void listarTodosColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    for(int i = 0 ; i < tamCol ; i++)
    {
        printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            pokedex[(colecao[i].numero)-1].numero,
            pokedex[(colecao[i].numero)-1].nome,
            pokedex[(colecao[i].numero)-1].tipo1,
            pokedex[(colecao[i].numero)-1].tipo2,
            pokedex[(colecao[i].numero)-1].total,
            pokedex[(colecao[i].numero)-1].hp, 
            pokedex[(colecao[i].numero)-1].ataque, 
            pokedex[(colecao[i].numero)-1].defesa, 
            pokedex[(colecao[i].numero)-1].ataqueEspecial, 
            pokedex[(colecao[i].numero)-1].defesaEspecial, 
            pokedex[(colecao[i].numero)-1].velocidade,
            pokedex[(colecao[i].numero)-1].geracao,
            pokedex[(colecao[i].numero)-1].lendario,
            pokedex[(colecao[i].numero)-1].cor,
            pokedex[(colecao[i].numero)-1].altura,
            pokedex[(colecao[i].numero)-1].peso,
            pokedex[(colecao[i].numero)-1].taxaCaptura,
            pokedex[(colecao[i].numero)-1].brilhante);
    }//printf

    return;

}//Listar todos da coleção

/**
 * Essa função será acionada quando o usuário solicitar na função listarcolecao,
 * quando solicitado, verifica se tem pokemon da geração que foi escolhido, se tiver mostra tudo sobre o pokemon,
 * se não tiver aparece uma mensagem falando que não tem pokemons daquela geração.
*/
void listarGeracaoColecao(Colecao* colecao, Pokemon* pokedex, int tamCol)
{
    int geracao, cont = 0;
    do
    {
        printf("Digite a geração: ");
        scanf("%i", &geracao);
        if(geracao < 1 || geracao > 6) printf("Digite uma geracao valida\n");
    
    }while(geracao < 1 || geracao > 6); //do
    //verifica a geração, e se for menor do que 1 ou maior do que 6 ele fica repetindo até colocar uma geração válida

    for(int i = 0 ; i < tamCol ; i++)
    {
        if(geracao == pokedex[(colecao[i].numero)-1].geracao)
        {
            printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            pokedex[(colecao[i].numero)-1].numero,
            pokedex[(colecao[i].numero)-1].nome,
            pokedex[(colecao[i].numero)-1].tipo1,
            pokedex[(colecao[i].numero)-1].tipo2,
            pokedex[(colecao[i].numero)-1].total,
            pokedex[(colecao[i].numero)-1].hp, 
            pokedex[(colecao[i].numero)-1].ataque, 
            pokedex[(colecao[i].numero)-1].defesa, 
            pokedex[(colecao[i].numero)-1].ataqueEspecial, 
            pokedex[(colecao[i].numero)-1].defesaEspecial, 
            pokedex[(colecao[i].numero)-1].velocidade,
            pokedex[(colecao[i].numero)-1].geracao,
            pokedex[(colecao[i].numero)-1].lendario,
            pokedex[(colecao[i].numero)-1].cor,
            pokedex[(colecao[i].numero)-1].altura,
            pokedex[(colecao[i].numero)-1].peso,
            pokedex[(colecao[i].numero)-1].taxaCaptura,
            pokedex[(colecao[i].numero)-1].brilhante);
            cont++;
        }// o - 1 é por conta que o computador salva 1 numero antes do que a geração normal

    }///for

    if(!cont) printf("Não há pokemons dessa geração.\n");
    return;

}//Listar geração da coleção

/**
 * Essa função será acionada quando o usuário solicitar na função listarcolecao,
 * quando solicitado, verifica se tem pokemon do tipo que foi escolhido, se tiver mostra tudo sobre o pokemon,
 * se não tiver aparece uma mensagem falando que não tem pokemons daqueles tipo.
*/
void listarTipoColecao(Colecao* colecao, Pokemon* pokedex, int tamCol)
{
    bool checa = false;
    char tipo[11];
    int cont = 0;
    do
    {
        printf("Digite o tipo a ser exibido: ");
        setbuf(stdin, NULL);
        fgets(tipo, 11, stdin);
        tipo[strcspn(tipo, "\n")] = '\0';
        checa = checaTipo(tipo);
        if(!checa) printf("Digite um tipo válido\n");

    }while(!checa); //do
    
    for(int i = 0 ; i < tamCol ; i++)
    {
        if(!strcmp(tipo, pokedex[(colecao[i].numero)-1].tipo1) || !strcmp(tipo, pokedex[(colecao[i].numero)-1].tipo2))
        {
            printf("%i %s %s %s %i %i %i %i %i %i %i %i %i %s %.2f %.2f %i %i\n",
            pokedex[(colecao[i].numero)-1].numero,
            pokedex[(colecao[i].numero)-1].nome,
            pokedex[(colecao[i].numero)-1].tipo1,
            pokedex[(colecao[i].numero)-1].tipo2,
            pokedex[(colecao[i].numero)-1].total,
            pokedex[(colecao[i].numero)-1].hp, 
            pokedex[(colecao[i].numero)-1].ataque, 
            pokedex[(colecao[i].numero)-1].defesa, 
            pokedex[(colecao[i].numero)-1].ataqueEspecial, 
            pokedex[(colecao[i].numero)-1].defesaEspecial, 
            pokedex[(colecao[i].numero)-1].velocidade,
            pokedex[(colecao[i].numero)-1].geracao,
            pokedex[(colecao[i].numero)-1].lendario,
            pokedex[(colecao[i].numero)-1].cor,
            pokedex[(colecao[i].numero)-1].altura,
            pokedex[(colecao[i].numero)-1].peso,
            pokedex[(colecao[i].numero)-1].taxaCaptura,
            pokedex[(colecao[i].numero)-1].brilhante);
            cont++;
        }//if

    }//for

    if(!cont) printf("Não há pokemons deste tipo.\n");

    return;

}//listar tipo coleção

/**
 * Essa função será acionada apenas quando o usuário solicitar no Menu
 * serve para o usuário verificar os pokemóns da coleção,
 * pode fazer isso escolhendo as opções - todos, por geração ou por tipo;
*/
void listarColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    int selecao;
    do
    {
        printf("Deseja visualizar quais pokemons? \n");
        printf("1) - Todos\n");
        printf("2) - Por geração\n");
        printf("3) - Por tipo\n");
        scanf("%i", &selecao);
        if(selecao < 1 || selecao > 3 ) printf("Digite uma opção válida\n");
    }while(selecao < 1 || selecao > 3);

    switch(selecao)
    {
            case TODOS:
                listarTodosColecao(colecao, pokedex, tamCol);
            break;
            case GERACAO:
                listarGeracaoColecao(colecao, pokedex, tamCol);
            break;
            case TIPO:
                listarTipoColecao(colecao, pokedex, tamCol);
            break;
            default:
                printf("Ainda não sei porque eu coloco, não vai cair aqui.");
            break;  
    }//switch

    return;    
}//Listar coleção

/**
 * Essa função funciona quando é selecionada no menu,
 * serve para pesquisar se o pokemon esta na coleção do usuário
*/
void pesquisarPokemonColecao(Colecao* colecao, Pokemon* pokedex, int tamCol)
{
    char procura[12];
    printf("Digite o nome do pokemon a ser pesquisado: ");
    setbuf(stdin, NULL);
    fgets(procura, 12, stdin);
    procura[strcspn(procura, "\n")] = '\0';
    Pokemon encontrado;
    bool achou = false;
    
    for(int i = 0 ; i < tamCol ; i++)
    {
        if(!strcmp(procura, pokedex[(colecao[i].numero)-1].nome))
        {
            encontrado =  pokedex[(colecao[i].numero)-1];
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
}//Pesquisar Pokemon da coleção

/**
 * Essa função está ligada com o Menu, caso o usuário selecione essa função ela vai
 * verificar se o usuário realmente deseja fazer a alteração, 
 * se a resposta for S, o código pede o nome do pokemon para ser alterado
 * o usuário pode alterar - Nome, Cor, altura ou peso.
*/
void alterarPokemonColecao(Colecao* colecao, Pokemon** pokedex, int tamCol){
    char opcao;
    printf("Atenção, as alterações feitas afetaram todos pokemons do mesmo tipo.");
    printf("Deseja continuar? S/N");
    opcao = getchar();
    if(opcao == 'N')
    {
        return;
    }//if

    char altera[12];
    printf("Digite o nome do pokemon a ser alterado: ");
    setbuf(stdin, NULL);
    fgets(altera, 12, stdin);
    altera[strcspn(altera, "\n")] = '\0';
    bool achou = false;
    int indice;

    for(int i = 0 ; i < tamCol ; i++)
    {
        if(!strcmp(altera, (*pokedex)[(colecao[i].numero)-1].nome))
        {
            indice = (*pokedex)[(colecao[i].numero)-1].numero;
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
        printf("Pokemon não encontrado na colecao.\n");
    }//else
    return;
}//Alterar pokemon coleção

/**
 * Essa função só aparece caso a pessoa no Menu selecione a opção de excluir um pokeemon,
 * se o usuario decidir exluir um pokemon, ele pode fazer isso colocando o nome ou numero.
*/
void excluirPokemonColecao(Colecao** colecao, Pokemon* pokedex, int* tamCol)
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
        for(int i = 0 ; i < *tamCol ; i++)
        {
            if(!strcmp(escolha.nome, pokedex[((*colecao)[i].numero)-1].nome))
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
        for(int i = 0 ; i < *tamCol ; i++)
        {
            if(escolha.numero == pokedex[((*colecao)[i].numero)-1].numero)
            {
                indice = i;
                encontrou = true;
                break;
            }//if
        }//for
    }//else
    
    if(encontrou)
    {
        (*tamCol)--;
        for(int i = indice ; i < *tamCol ; i++)
        {
            (*colecao)[i] = (*colecao)[i+1];
        }//for

        printf("Pokemon excluido.\n");
        *colecao = (Colecao*) realloc(*colecao, (*tamCol)*sizeof(Pokemon));
        if(*colecao == NULL)
        {
            perror("Erro ao realocar a colecao: ");
            exit(EXIT_FAILURE);
        }//if

    }//if

    else
    {
        printf("Pokemon não encontrado na coleção.\n");
    }
    return;
}//Excluir pokemon da coleção

/**
 * O menu verifica se o usuário quer ir para a parte de inserir, listar, pesquisar, alterar, excluir ou sair do menu.
 * se o usuario não fornecer um numero valido ele fica repetindo até colocar um numero válido.
*/
void menuColecao(Colecao** colecao, Pokemon** pokedex, int* tamCol, int tamPoke)
{
    int selecao;
    do
    {
        do
        {
            printf("1) - Inserir pokemon capturado.\n");
            printf("2) - Listar pokemons capturados.\n");
            printf("3) - Pesquisar pokemon.\n");
            printf("4) - Alterar pokemon.\n");
            printf("5) - Excluir pokemon.\n");
            printf("6) - Sair do menu.\n");
            scanf("%i", &selecao);
            if(selecao < 1 || selecao > 6) printf("Escolha uma opção válida.\n");
       
        }while(selecao < 1 || selecao > 6); //do

        switch(selecao)
        {
            case INSERIR:
                inserirPokemonColecao(colecao, *pokedex, tamCol, tamPoke);
            break;
            case LISTAR:
                listarColecao(*colecao, *pokedex, *tamCol);
            break;
            case PESQUISAR:
                pesquisarPokemonColecao(*colecao, *pokedex, *tamCol);
            break;
            case ALTERAR:
                alterarPokemonColecao(*colecao, pokedex, *tamCol);
            break;
            case EXCLUIR:
                excluirPokemonColecao(colecao, *pokedex, tamCol);
            break;
            case SAIR:
                break;
        }//switch

    }while(selecao != SAIR); //do

    return;
}//Menu coleção

/**
 * função que faz uma alocação dinâmica para a coleção
 * verifica se tem espaço, se não tiver espaço ele mostra que deu erro.
*/
Colecao* retornaEstruturaColecao()
{
    Colecao* dados;
    dados = (Colecao*) malloc(sizeof(Colecao));
    if(dados == NULL)
    {
        perror("Erro ao alocar a estrutura de coleção dos pokemons: ");
        exit(EXIT_FAILURE);
    }//if

    dados[0].numero = 25;
    dados[0].quantidade = 1;

    return dados;

}// retorna coleção