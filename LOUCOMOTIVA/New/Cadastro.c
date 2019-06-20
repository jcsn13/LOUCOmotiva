#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DAO.h"

void sleep();

int main(int argc, char *argv[])
{	
	/*
	o servidor manda no maximo 5 cadastros por vez que chama o codigo
	*/
	cadastro(argc,argv);
	sleep(120);
	return 0;
}


