#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokedex.h"
#include "colecao.h"
#include "arquivos.h"
#include "mochila.h"

/**
 * Nessa função é para armazenar 6 pokemons na mochila , aqueles que já foram capturados, para usar em batalha.
 * Vai verificar se o pokemon que a pessoa escolheu está na lista dos pokemons, se sim ele registra o numero/ codigo na mochila.
*/
void armazenarMochila(Mochila* mochila, Pokemon* pokemons)
{   
    int   j = 1;
    char  nome[6][20];
    
   for(int i = 0; i < 6; i++)
   {
       do 
       {
          printf("Escolha %iº pokemon que já foi capturado: \n " , j);
          setbuf(stdin, NULL);
          fgets(nome[i], 20, stdin);
          nome[i][strcspn(nome[i], "\n")] = '\0';

          if(!strcmp(nome[i], pokemons[i].nome) == 0)
          {
             mochila[i].num_codigo = pokemons[i].numero;
          }

       }while(nome[i] != pokemons[i].nome);

       j++;

   }
    
}