#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void recebeDadosPokemons(Pokemon** poke){
    FILE* arq;
    arq = abreArquivo("pokedex.csv", "r");
    *poke = (Pokemon*) realloc(*poke, 721*sizeof(Pokemon));
    if(*poke == NULL){
        perror("Erro ao realocar a estrutura de dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i < 721 ; i++){
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
    }
  
    fclose(arq);
    return;
}

typedef enum{
    INSERIR = 1,
    LISTAR,
    PESQUISAR,
    ALTERAR,
    EXCLUIR,
    SAIR
}Selecao;

void inserirTodosPokemons(Pokemon* dados, Pokemon** pokedex, int* tam){
    *pokedex = (Pokemon*) realloc(*pokedex, 721*sizeof(Pokemon));
    if(*pokedex == NULL){
        perror("Erro ao realocar o tamanho da pokedex: ");
        exit(EXIT_FAILURE);
    }
    *tam = 721;
    for(int i = 0 ; i < *tam ; i++){
        (*pokedex)[i] = dados[i];
    }
    printf("Todos pokemons foram inseridos na pokedex com sucesso.\n");
    return;
}

typedef enum{
    TODOS = 1,
    GERACAO,
    TIPO
}Tipos;

void listarTodos(Pokemon* pokedex, int tam){
    for(int i = 0 ; i < tam ; i++){
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
    }
    return;
}

void listarGeracao(Pokemon* pokedex, int tam){
    int geracao;
    do{
        printf("Digite a geração: ");
        scanf("%i", &geracao);
        if(geracao < 1 || geracao > 6) printf("Digite uma geracao valida\n");
    }while(geracao < 1 || geracao > 6);

    for(int i = 0 ; i < tam ; i++){
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
        }
    }
    return;
}

bool checaTipo(char* tipo){
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
}

void listarTipo(Pokemon* pokedex, int tam){
    bool checa = false;
    char tipo[11];
    do{
        printf("Digite o tipo a ser exibido: ");
        setbuf(stdin, NULL);
        fgets(tipo, 11, stdin);
        tipo[strcspn(tipo, "\n")] = '\0';
        checa = checaTipo(tipo);
        if(!checa) printf("Digite um tipo válido\n");
    }while(!checa);
    
    for(int i = 0 ; i < tam ; i++){
        if(!strcmp(tipo, pokedex[i].tipo1) || !strcmp(tipo, pokedex[i].tipo2)){
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
        }
    }
    return;
}

void listarPokedex(Pokemon* pokedex, int tam){
    int selecao;
    do{
        printf("Deseja visualizar quais pokemons? \n");
        printf("1) - Todos\n");
        printf("2) - Por geração\n");
        printf("3) - Por tipo\n");
        scanf("%i", &selecao);
        if(selecao < 1 || selecao > 3 ) printf("Digite uma opção válida\n");
    }while(selecao < 1 || selecao > 3);
    switch(selecao){
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
        }

    return;    
}

void pesquisarPokemon(Pokemon* pokedex, int tam){
    char procura[12];
    printf("Digite o nome do pokemon a ser pesquisado: ");
    setbuf(stdin, NULL);
    fgets(procura, 12, stdin);
    procura[strcspn(procura, "\n")] = '\0';
    Pokemon encontrado;
    bool achou = false;
    
    for(int i = 0 ; i < tam ; i++){
        if(!strcmp(procura, pokedex[i].nome)){
            encontrado =  pokedex[i];
            achou = true;
            break;
        }
    }

    if(achou){
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
    }
    else{
        printf("Pokemon não encontrado.\n");
    }
    return;
}   

typedef enum{
        NOME = 1,
        COR,
        ALTURA,
        PESO
    }Alteracoes;

void alteraNome(Pokemon** pokedex, int indice){
    char nome[12];
    printf("Digite o novo nome: ");
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    strcpy((*pokedex)[indice].nome, nome);
    printf("Nome alterado.\n");
    return;
}

void alteraCor(Pokemon** pokedex, int indice){
    char cor[12];
    printf("Digite a nova cor: ");
    setbuf(stdin, NULL);
    fgets(cor, 12, stdin);
    cor[strcspn(cor, "\n")] = '\0';
    strcpy((*pokedex)[indice].cor, cor);
    printf("Cor alterada.\n");
    return;
}

void alteraAltura(Pokemon** pokedex, int indice){
    float altura;
    printf("Digite a nova altura: ");
    scanf("%f", &altura);
    (*pokedex)[indice].altura = altura;
    printf("Altura alterada.\n");
    return;
}

void alteraPeso(Pokemon** pokedex, int indice){
    float peso;
    printf("Digite o novo peso: ");
    scanf("%f", &peso);
    (*pokedex)[indice].peso = peso;
    printf("Peso alterado.\n");
    return;
}

void alterarPokemon(Pokemon** pokedex, int tam){
    char altera[12];
    printf("Digite o nome do pokemon a ser alterado: ");
    setbuf(stdin, NULL);
    fgets(altera, 12, stdin);
    altera[strcspn(altera, "\n")] = '\0';
    bool achou = false;
    int indice;
    for(int i = 0 ; i < tam ; i++){
        if(!strcmp(altera, (*pokedex)[i].nome)){
            indice = i;
            achou = true;
            break;
        }
    }

    if(achou){
        int alteracoes;
            do{
                printf("Possiveis alterações: \n");
                printf("1) - Nome\n");
                printf("2) - Cor\n");
                printf("3) - Altura\n");
                printf("4) - Peso\n");
                scanf("%i", &alteracoes);
                if(alteracoes < 1 || alteracoes > 4) printf("Digite uma alteração válida.\n");
            }while(alteracoes < 1 || alteracoes > 4);
            switch(alteracoes){
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
            }
    }
    else{
        printf("Pokemon não encontrado.\n");
    }
    return;
}

typedef union{
    char nome[12];
    int numero;
}Escolha;

void excluirPokemon(Pokemon** pokedex, int* tam){
    int opcao, indice;
    bool encontrou = false;
    do{
        printf("Deseja excluir um pokemon pelo nome ou número? \n");
        printf("1) - Nome\n");
        printf("2) - Número\n");
        scanf("%i", &opcao);
        if(opcao < 1 || opcao > 2) printf("Opção invalida.");
    }while(opcao < 1 || opcao > 2);
    Escolha escolha;
    if(opcao == 1){
        printf("Digite o nome do pokemon: ");
        setbuf(stdin, NULL);
        fgets(escolha.nome, 12, stdin);
        escolha.nome[strcspn(escolha.nome, "\n")] = '\0';
        for(int i = 0 ; i < *tam ; i++){
            if(!strcmp(escolha.nome, (*pokedex)[i].nome)){
                indice = i;
                encontrou = true;
                break;
            }
        }
    }
    else{
        printf("Digite o número do pokemon: ");
        scanf("%i", &escolha.numero);
        for(int i = 0 ; i < *tam ; i++){
            if(escolha.numero == (*pokedex)[i].numero){
                indice = i;
                encontrou = true;
                break;
            }
        }
    }
    
    if(encontrou){
        (*tam)--;
        for(int i = indice ; i < *tam ; i++){
            (*pokedex)[i] = (*pokedex)[i+1];
        }
        printf("Pokemon excluido.\n");
        *pokedex = (Pokemon*) realloc(*pokedex, (*tam)*sizeof(Pokemon));
        if(*pokedex == NULL){
            perror("Erro ao realocar a pokedex: ");
            exit(EXIT_FAILURE);
        }
    }
    else{
        printf("Pokemon não encontrado.\n");
    }
    return;
}

void menuPokedex(Pokemon* dados, Pokemon** pokedex, int* tam){
    int selecao;
    do{
        do{
            printf("1) - Inserir pokemons.\n");
            printf("2) - Listar pokemons.\n");
            printf("3) - Pesquisar pokemon.\n");
            printf("4) - Alterar pokemon.\n");
            printf("5) - Excluir pokemon.\n");
            printf("6) - Sair do menu.\n");
            scanf("%i", &selecao);
            if(selecao < 1 || selecao > 6) printf("Escolha uma opção válida.\n");
        }while(selecao < 1 || selecao > 6);

        switch(selecao){
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
        }
    }while(selecao != SAIR);
    return;
}

Pokemon* retornaEstruturaPokemon(){
    Pokemon* dados;
    dados = (Pokemon*) malloc(sizeof(Pokemon));
    if(dados == NULL){
        perror("Erro ao alocar as estruturas de dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }
    return dados;
}

typedef struct{
    int numero;
    int quantidade;
}Colecao;

void ordenaColecao(Colecao* colecao, int tamCol){
    Colecao troca;
    bool check = true;
    while(check){
        check = false;
        for(int i = 0 ; i < tamCol - 1 ; i++){
            if(colecao[i].numero > colecao[i+1].numero){
                troca = colecao[i];
                colecao[i] = colecao[i+1];
                colecao[i+1] = troca;
                check = true;
            }
        }
    }
    return;
}

void inserirPokemonColecao(Colecao** colecao, Pokemon* pokedex, int* tamCol, int tamPoke){
    char nome[12];
    bool checa = false, repetido = false;
    int numero;
    printf("Digite o nome do pokemon capturado para inserir: ");
    setbuf(stdin, NULL);
    fgets(nome, 12, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    for(int i = 0 ; i < tamPoke ; i++){
        if(!strcmp(nome, pokedex[i].nome)){
            numero = pokedex[i].numero;
            checa = true;
            break;
        }
    }
    if(checa){
        for(int i = 0 ; i < *tamCol ; i++){
            if(numero == (*colecao)[i].numero){
                ((*colecao)[i].quantidade)++;
                repetido = true;
            }
        }
        if(!repetido){     
            (*tamCol)++;
            *colecao = (Colecao*) realloc(*colecao, (*tamCol)*sizeof(Colecao));
            if(*colecao == NULL){
                perror("Erro ao realocar a estrutura da coleção: ");
                exit(EXIT_FAILURE);
            }
            (*colecao)[*tamCol].numero = numero;
            (*colecao)[*tamCol].quantidade = 1;
        }
    }
    else{
        printf("Pokemon não existe.\n");
    }
    ordenaColecao(*colecao, *tamCol);
    return;
}

void listarTodosColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    for(int i = 0 ; i < tamCol ; i++){
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
    }
    return;
}

void listarGeracaoColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    int geracao, cont = 0;
    do{
        printf("Digite a geração: ");
        scanf("%i", &geracao);
        if(geracao < 1 || geracao > 6) printf("Digite uma geracao valida\n");
    }while(geracao < 1 || geracao > 6);

    for(int i = 0 ; i < tamCol ; i++){
        if(geracao == pokedex[(colecao[i].numero)-1].geracao){
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
        }
    }
    if(!cont) printf("Não há pokemons dessa geração.\n");
    return;
}

void listarTipoColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    bool checa = false;
    char tipo[11];
    int cont = 0;
    do{
        printf("Digite o tipo a ser exibido: ");
        setbuf(stdin, NULL);
        fgets(tipo, 11, stdin);
        tipo[strcspn(tipo, "\n")] = '\0';
        checa = checaTipo(tipo);
        if(!checa) printf("Digite um tipo válido\n");
    }while(!checa);
    
    for(int i = 0 ; i < tamCol ; i++){
        if(!strcmp(tipo, pokedex[(colecao[i].numero)-1].tipo1) || !strcmp(tipo, pokedex[(colecao[i].numero)-1].tipo2)){
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
        }
    }
    if(!cont) printf("Não há pokemons deste tipo.\n");
    return;
}

void listarColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    int selecao;
    do{
        printf("Deseja visualizar quais pokemons? \n");
        printf("1) - Todos\n");
        printf("2) - Por geração\n");
        printf("3) - Por tipo\n");
        scanf("%i", &selecao);
        if(selecao < 1 || selecao > 3 ) printf("Digite uma opção válida\n");
    }while(selecao < 1 || selecao > 3);
    switch(selecao){
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
        }

    return;    
}

void pesquisarPokemonColecao(Colecao* colecao, Pokemon* pokedex, int tamCol){
    char procura[12];
    printf("Digite o nome do pokemon a ser pesquisado: ");
    setbuf(stdin, NULL);
    fgets(procura, 12, stdin);
    procura[strcspn(procura, "\n")] = '\0';
    Pokemon encontrado;
    bool achou = false;
    
    for(int i = 0 ; i < tamCol ; i++){
        if(!strcmp(procura, pokedex[(colecao[i].numero)-1].nome)){
            encontrado =  pokedex[(colecao[i].numero)-1];
            achou = true;
            break;
        }
    }

    if(achou){
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
    }
    else{
        printf("Pokemon não encontrado.\n");
    }
    return;
}   

void alterarPokemonColecao(Colecao* colecao, Pokemon** pokedex, int tamCol){
    char opcao;
    printf("Atenção, as alterações feitas afetaram todos pokemons do mesmo tipo.");
    printf("Deseja continuar? S/N");
    opcao = getchar();
    if(opcao == 'N'){
        return;
    }

    char altera[12];
    printf("Digite o nome do pokemon a ser alterado: ");
    setbuf(stdin, NULL);
    fgets(altera, 12, stdin);
    altera[strcspn(altera, "\n")] = '\0';
    bool achou = false;
    int indice;
    for(int i = 0 ; i < tamCol ; i++){
        if(!strcmp(altera, (*pokedex)[(colecao[i].numero)-1].nome)){
            indice = (*pokedex)[(colecao[i].numero)-1].numero;
            achou = true;
            break;
        }
    }

    if(achou){
        int alteracoes;
            do{
                printf("Possiveis alterações: \n");
                printf("1) - Nome\n");
                printf("2) - Cor\n");
                printf("3) - Altura\n");
                printf("4) - Peso\n");
                scanf("%i", &alteracoes);
                if(alteracoes < 1 || alteracoes > 4) printf("Digite uma alteração válida.\n");
            }while(alteracoes < 1 || alteracoes > 4);
            switch(alteracoes){
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
            }
    }
    else{
        printf("Pokemon não encontrado na colecao.\n");
    }
    return;
}

void excluirPokemonColecao(Colecao** colecao, Pokemon* pokedex, int* tamCol){
    int opcao, indice;
    bool encontrou = false;
    do{
        printf("Deseja excluir um pokemon pelo nome ou número? \n");
        printf("1) - Nome\n");
        printf("2) - Número\n");
        scanf("%i", &opcao);
        if(opcao < 1 || opcao > 2) printf("Opção invalida.");
    }while(opcao < 1 || opcao > 2);
    Escolha escolha;
    if(opcao == 1){
        printf("Digite o nome do pokemon: ");
        setbuf(stdin, NULL);
        fgets(escolha.nome, 12, stdin);
        escolha.nome[strcspn(escolha.nome, "\n")] = '\0';
        for(int i = 0 ; i < *tamCol ; i++){
            if(!strcmp(escolha.nome, pokedex[((*colecao)[i].numero)-1].nome)){
                indice = i;
                encontrou = true;
                break;
            }
        }
    }
    else{
        printf("Digite o número do pokemon: ");
        scanf("%i", &escolha.numero);
        for(int i = 0 ; i < *tamCol ; i++){
            if(escolha.numero == pokedex[((*colecao)[i].numero)-1].numero){
                indice = i;
                encontrou = true;
                break;
            }
        }
    }
    
    if(encontrou){
        (*tamCol)--;
        for(int i = indice ; i < *tamCol ; i++){
            (*colecao)[i] = (*colecao)[i+1];
        }
        printf("Pokemon excluido.\n");
        *colecao = (Colecao*) realloc(*colecao, (*tamCol)*sizeof(Pokemon));
        if(*colecao == NULL){
            perror("Erro ao realocar a colecao: ");
            exit(EXIT_FAILURE);
        }
    }
    else{
        printf("Pokemon não encontrado na coleção.\n");
    }
    return;
}

void menuColecao(Colecao** colecao, Pokemon** pokedex, int* tamCol, int tamPoke){
    int selecao;
    do{
        do{
            printf("1) - Inserir pokemon capturado.\n");
            printf("2) - Listar pokemons capturados.\n");
            printf("3) - Pesquisar pokemon.\n");
            printf("4) - Alterar pokemon.\n");
            printf("5) - Excluir pokemon.\n");
            printf("6) - Sair do menu.\n");
            scanf("%i", &selecao);
            if(selecao < 1 || selecao > 6) printf("Escolha uma opção válida.\n");
        }while(selecao < 1 || selecao > 6);

        switch(selecao){
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
        }
    }while(selecao != SAIR);
    return;
}

Colecao* retornaEstruturaColecao(){
    Colecao* dados;
    dados = (Colecao*) malloc(sizeof(Colecao));
    if(dados == NULL){
        perror("Erro ao alocar a estrutura de coleção dos pokemons: ");
        exit(EXIT_FAILURE);
    }
    dados[0].numero = 25;
    dados[0].quantidade = 1;
    return dados;
}

void carregaSave(Pokemon** dados, Pokemon** pokedex, int* tam){
    FILE* arquivo;
    arquivo = abreArquivo("saveState.bin", "rb");
    *dados = (Pokemon*) realloc(*dados, 721*sizeof(Pokemon));
    if(*dados == NULL){
        perror("Erro ao realocar os dados dos pokemons: ");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i < 721 ; i++){
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
    }
    fclose(arquivo);
    arquivo = abreArquivo("pokedexState.bin", "rb");
    fread(tam, sizeof(int), 1, arquivo);

    *pokedex = (Pokemon*) realloc(*pokedex, (*tam)*sizeof(Pokemon));
    if(*pokedex == NULL){
        perror("Erro ao realocar a estrutura de pokemons: ");
        exit(EXIT_FAILURE);
    }

    for(int i = 0 ; i < *tam ; i++){
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
    }
    fclose(arquivo);
    return;

}

void salvaJogo(Pokemon* dados, Pokemon* pokedex, int tam){
    FILE* arquivo;
    arquivo = abreArquivo("saveState.bin", "wb");
    for(int i = 0 ; i < 721 ; i++){
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
    }
    fclose(arquivo);
    arquivo = abreArquivo("pokedexState.bin", "wb");
    fwrite(&tam, sizeof(int), 1, arquivo);
    for(int i = 0 ; i < tam ; i++){
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
    }
    fclose(arquivo);
    return;
}

int main(void){

    Pokemon* dadosPokemons;
    dadosPokemons = retornaEstruturaPokemon();
    Pokemon* pokedex;
    pokedex = retornaEstruturaPokemon();
    int tamCol = 1, tamPoke;

    FILE* arquivo;
    arquivo = fopen("saveState.bin", "rb");
    if(arquivo == NULL){
        printf("Bem vindo ao pokemon da Shopee\n");
        recebeDadosPokemons(&dadosPokemons);
    }
    else{
        printf("Carregando dados da Shopee\n");
        carregaSave(&dadosPokemons, &pokedex, &tamPoke);
        fclose(arquivo);
    }

    Colecao* colecao;
    colecao = retornaEstruturaColecao();

    char opcao;

    printf("Digite P para acessar o menu da pokedex\n");
    printf("Digite C para acessar o menu de coleção\n");
    opcao = getchar();
    if(opcao == 'P'){
        menuPokedex(dadosPokemons, &pokedex, &tamPoke);
    }
    else if(opcao == 'C'){
        menuColecao(&colecao, &pokedex, &tamCol, tamPoke);
    }

    salvaJogo(dadosPokemons, pokedex, tamPoke);
    free(dadosPokemons);
    free(pokedex);

    return 0;
}
