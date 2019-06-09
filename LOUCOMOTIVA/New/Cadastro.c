#include <stdio.h>
#include <stdlib.h>
#include "DAO.h"

void sleep();

int main(int argc, char *argv[])
{	
	pilha = NULL;//Valor da pilha é nulo,pois não há nenhum elemento nela
	
	struct visitantes cadastro1;
	cadastro1.data = "24/08/2018";
	cadastro1.idade = "55";
	cadastro1.nota = "5";
	
	struct visitantes cadastro2;
	cadastro2.data = "24/10/2018";
	cadastro2.idade = "39";
	cadastro2.nota = "3";

	struct visitantes cadastro3;
	cadastro3.data = "12/10/2018";
	cadastro3.idade = "80";
	cadastro3.nota = "3";

	pilha = empilhar(pilha,&cadastro1);
	pilha = empilhar(pilha,&cadastro2);
	pilha = empilhar(pilha,&cadastro3);
	desempilhar_e_salvar(pilha);
	imprimir_pilha(pilha);
	
	// sleep(120);
	return 0;
}	



