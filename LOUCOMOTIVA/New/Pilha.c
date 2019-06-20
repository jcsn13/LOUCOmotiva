#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DAO.h"

struct pilha * empilhar(struct pilha *pilha_visitantes,struct visitantes *v)
{
	        struct pilha *novo_visitante;

	        if(pilha_visitantes == NULL){

                    pilha_visitantes = (struct pilha *)malloc(sizeof(struct pilha));

            if(pilha_visitantes == NULL){

                    printf("Erro de alocação de memória(pilha_visitantes)\n");

                    exit(1);

            }

            pilha_visitantes->visitante = v;
		    pilha_visitantes->prox_visitante = NULL;
        
            return pilha_visitantes;
        
        }else{

		        struct pilha *auxiliar;

                auxiliar = (struct pilha *)malloc(sizeof(struct pilha));

                if (auxiliar == NULL){

                        printf("Erro de alocação de memória(auxiliar)\n");
             
                        exit(1);

                }   

            auxiliar->visitante = v;
            auxiliar->prox_visitante = pilha_visitantes;

            return auxiliar;

    }
}

void imprimir_pilha(struct pilha *pilha_visitantes)
{
        if (pilha_visitantes == NULL){
        
                printf("A Pilha vazia!\n");

        }else{

                struct pilha *percorre_pilha;

                percorre_pilha = pilha_visitantes;

                printf("-------------------------\n");

        while (percorre_pilha != NULL){

                printf("Idade: %s \n", percorre_pilha->visitante->idade);

                printf("Data: %s \n", percorre_pilha->visitante->nota);

                printf("Nota: %s \n", percorre_pilha->visitante->data);
            
                printf("-------------------------\n");

                percorre_pilha = percorre_pilha->prox_visitante;

        }

                free(percorre_pilha);
    }   
}

void desempilhar_e_salvar(struct pilha *pilha_visitantes)
{
        if (pilha_visitantes == NULL){

                printf("A Pilha vazia!\n");

        }else{

                struct pilha *percorre_pilha;

                if (percorre_pilha == NULL){

                        printf("Erro de alocação de memória(auxiliar)\n");

                        exit(1);

        }

        percorre_pilha = pilha_visitantes;

        printf("-------------------------\n");

        while (percorre_pilha != NULL){
            
                struct visitantes *user = percorre_pilha->visitante;

                incluir_visitante(*user);
            
                percorre_pilha = percorre_pilha->prox_visitante;
        }

        free(percorre_pilha);
    }   
}
