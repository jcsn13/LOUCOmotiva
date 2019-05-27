#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Visitantes{
	char *idade; // idade do visitante
	char *nota; // Nota que o visitante da ao museu
	char *data; //Data de visita
};

FILE *pont_arq;

void cadastrar_visitante();
void incluir_visitante();
void consulta_tudo();