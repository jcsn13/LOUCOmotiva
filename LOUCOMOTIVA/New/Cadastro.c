#include <stdio.h>
#include <stdlib.h>
#include "DAO.h"

int main(int argc, char *argv[])
{
	struct pilha *p = NULL;
	struct visitantes cadastro_v;

	cadastro_v.nota = malloc(2*sizeof(char));
    cadastro_v.idade = malloc(2*sizeof(char));
    cadastro_v.data = malloc(10*sizeof(char));
	cadastro_v.data = "24/08/2018";
	cadastro_v.idade = "55";
	cadastro_v.nota = "5";
	
	struct visitantes cadastro_v2;
	cadastro_v2.nota = malloc(2*sizeof(char));
    cadastro_v2.idade = malloc(2*sizeof(char));
    cadastro_v2.data = malloc(10*sizeof(char));
	cadastro_v2.data = "24/10/2018";
	cadastro_v2.idade = "39";
	cadastro_v2.nota = "3";

	struct visitantes cadastro_v3;
	cadastro_v3.nota = malloc(2 * sizeof(char));
	cadastro_v3.idade = malloc(2 * sizeof(char));
	cadastro_v3.data = malloc(10 * sizeof(char));
	cadastro_v3.data = "12/10/2018";
	cadastro_v3.idade = "80";
	cadastro_v3.nota = "3";

	p = empilhar(p,&cadastro_v);
	p = empilhar(p, &cadastro_v2);
	p = empilhar(p, &cadastro_v3);
	imprimir(p);
	imprimir2(p);
	return 0;
}	



