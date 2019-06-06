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

struct pilha * empilhar(struct pilha *p, struct visitantes *v);
void imprimir();
void imprimir2();
void cadastrar_visitante();
void incluir_visitante();
void consulta_tudo();