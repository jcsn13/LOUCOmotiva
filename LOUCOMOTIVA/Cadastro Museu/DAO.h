#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Visitantes{
char *cidade;
char *instagram;
char *nome;
};

FILE *pont_arq;

void incluirVisitante(struct Visitantes v){
	
	char *dados;
	dados = (char *)malloc( sizeof(char) * 150);
	
	strcat(dados,v.nome);
	strcat(dados,";");
	strcat(dados,v.cidade);
	strcat(dados,";");
	strcat(dados,v.instagram);
	strcat(dados,"\n");
	printf(dados);
	
	pont_arq = fopen("banco.txt","a");
	fprintf(pont_arq, "%s", dados);
	fclose(pont_arq);
	printf("Visitante Salvo\n");
}

void consultaTudo(){
	 
	 pont_arq = fopen("banco.txt","r");
	char c;
	 while((c = fgetc(pont_arq)) != EOF)
			printf("%c", c);
	
	fclose(pont_arq);
}

//swig