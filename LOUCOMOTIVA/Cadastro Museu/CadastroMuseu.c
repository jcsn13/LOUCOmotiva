#include <stdio.h>
#include <stdlib.h>
#include "DAO.h"

void cadastrarVisitante();

int main(int argc, char *argv[]) {
	//cadastrarVisitante();
	cadastrarVisitante();
	return 0;
}	


void cadastrarVisitante(){
	
	char op[1],cidade[20],nome[60],instagram[20];
	while(1){
		struct Visitantes cadastroV;
		memset(op, 0, 1);
		memset(cidade, 0, 100);
		memset(nome, 0, 100);
		memset(instagram, 0, 20);

		printf("***Bem vindo ao cadastro do Museu do Trem***\n");
		printf("Qual o seu nome?\n");
		scanf("%s",nome);
		printf("Onde voce mora?\n");
		scanf("%s",cidade);
		printf("Voce tem instragram?(s/n)\n");
		scanf("%s",op);
			
		if(op[0] == 'S'|| op[0] == 's'){
			printf("Qual o seu instragram?\n");
			scanf("%s",instagram);
		}
		
		cadastroV.cidade = malloc(sizeof(cidade));
		cadastroV.nome = malloc(sizeof(nome));
		cadastroV.instagram = malloc(sizeof(instagram));
		strcpy(cadastroV.nome,nome);
		strcpy(cadastroV.cidade,cidade);
		strcpy(cadastroV.instagram,instagram);
		
		incluirVisitante(cadastroV);
		free(cadastroV.nome);
		free(cadastroV.cidade);
		free(cadastroV.instagram);
	}	
	
		
}




