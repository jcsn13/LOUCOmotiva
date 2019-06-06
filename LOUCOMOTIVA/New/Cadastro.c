#include <stdio.h>
#include <stdlib.h>
#include "DAO.h"

int main(int argc, char *argv[])
{
	struct pilha *p = NULL;
	struct visitantes cadastro_v;

	cadastro_v.nota = (char *) malloc(2*sizeof(char));
	cadastro_v.idade = (char *) malloc(2 * sizeof(char));
	cadastro_v.data = (char *) malloc(10 * sizeof(char));
	cadastro_v.data = "24/08/2018";
	cadastro_v.idade = "55";
	cadastro_v.nota = "5";
	
	struct visitantes cadastro_v2;
	cadastro_v2.nota = (char *) malloc(2 * sizeof(char));
	cadastro_v2.idade = (char *) malloc(2 * sizeof(char));
	cadastro_v2.data = (char *) malloc(10 * sizeof(char));
	cadastro_v2.data = "24/10/2018";
	cadastro_v2.idade = "39";
	cadastro_v2.nota = "3";

	struct visitantes cadastro_v3;
	cadastro_v3.nota = (char *) malloc(2 * sizeof(char));
	cadastro_v3.idade = (char *) malloc(2 * sizeof(char));
	cadastro_v3.data = (char *) malloc(10 * sizeof(char));
	cadastro_v3.data = "12/10/2018";
	cadastro_v3.idade = "80";
	cadastro_v3.nota = "3";

	p = empilhar(p,&cadastro_v);
	p = empilhar(p, &cadastro_v2);
	p = empilhar(p, &cadastro_v3);
	desempilhar_e_salvar(p);
	imprimir_pilha(p);
	return 0;
}	



