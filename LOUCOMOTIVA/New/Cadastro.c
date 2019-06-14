#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DAO.h"

void sleep();

int main(int argc, char *argv[])
{	
	// o servidor manda no maximo 5 cadastros por vez que chama o codigo
	
	int cont = 1;

	while(cont < argc){

		if(cont < 4){
			struct visitantes cadastro_1;

			cadastro_1.data = argv[cont];
			cadastro_1.nota = argv[cont+1];
			cadastro_1.idade = argv[cont+2];

			if (cadastro_1.data != NULL || cadastro_1.nota != NULL || cadastro_1.idade != NULL)
				pilha = empilhar(pilha, &cadastro_1);

		}else if(cont < 7){
			struct visitantes cadastro_2;

			cadastro_2.data = argv[cont];
			cadastro_2.idade = argv[cont+1];
			cadastro_2.nota = argv[cont+2];

			if (cadastro_2.data != NULL || cadastro_2.nota != NULL || cadastro_2.idade != NULL)
				pilha = empilhar(pilha,&cadastro_2);
		}else if (cont < 10){
			struct visitantes cadastro_3;

			cadastro_3.data = argv[cont];
			cadastro_3.idade = argv[cont+1];
			cadastro_3.nota = argv[cont+2];

			if (cadastro_3.data != NULL || cadastro_3.nota != NULL || cadastro_3.idade != NULL)
				pilha = empilhar(pilha, &cadastro_3);
		}else if (cont < 13){
			struct visitantes cadastro_4;

			cadastro_4.data = argv[cont];
			cadastro_4.idade = argv[cont+1];
			cadastro_4.nota = argv[cont+2];

			if (cadastro_4.data != NULL || cadastro_4.nota != NULL || cadastro_4.idade != NULL)
				pilha = empilhar(pilha, &cadastro_4);
		}
		else if (cont < 16){
			struct visitantes cadastro_5;

			cadastro_5.data = argv[cont];
			cadastro_5.idade = argv[cont+1];
			cadastro_5.nota = argv[cont+2];

			if (cadastro_5.data != NULL || cadastro_5.nota != NULL || cadastro_5.idade != NULL)
				pilha = empilhar(pilha, &cadastro_5);
		}

		cont = cont + 3;

	}

	desempilhar_e_salvar(pilha);
	imprimir_pilha(pilha);

	sleep(120);
	return 0;
}


