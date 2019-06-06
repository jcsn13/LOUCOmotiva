#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct visitantes{
	char *idade; // idade do visitante
	char *nota; // Nota que o visitante da ao museu
	char *data; //Data de visita
};

struct pilha{
	struct visitantes *visitante;
	struct pilha *prox_visitante;
};

FILE *pont_arq;

struct pilha *pilha;// inicialização da lista

struct pilha * empilhar(struct pilha *pilha_visitantes, struct visitantes *v);
void desempilhar_e_salvar();
void imprimir_pilha();
void cadastrar_visitante();
void incluir_visitante();
void consulta_tudo();