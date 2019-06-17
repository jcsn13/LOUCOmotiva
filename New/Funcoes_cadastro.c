#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DAO.h"

void incluir_visitante(struct visitantes v)
{
    /*
	Recebe como parametro os dados do visitante:
	  -Data da visita
	  -Nota de sua visita
	  -Idade do visitante

	Apos, concatena todos os dados em uma String, separados por ";".E por final da append dessa String em um arquivo .txt com uma quebra de linha no final, e imprime uma mensagem de sucesso.
	*/

    pont_arq = fopen("banco.txt", "a");

    fprintf(pont_arq,"%s;%s;%s\n",v.idade,v.nota,v.data);

    fclose(pont_arq);

    printf("Visitante Salvo\n");
}

void consulta_tudo()
{
    // Imprime todos os dados salvo no .txt pela funçao incluir_visitante()

    pont_arq = fopen("banco.txt", "r");
    char c;

    while ((c = fgetc(pont_arq)) != EOF)
        printf("%c", c);

    fclose(pont_arq);
}

void cadastrar_visitante()
{
    /*
	Cria 3 ponteiros para coletar os dados do visitante:
		-Data da visita
		-Nota de sua visita
		-Idade do visitante
	
	Cria uma variavel do tipo struct, a qual é definida no começo do arquivo DAO.h.

	Depois de coletados os dados copia a string para cada variável da struct e chama a função incluir_visitante() passando como parametro a struct criada. Após isso libera todos os endereços de memória alocados.
	*/

    char *nota, *idade, *data;

    do
    {
        struct visitantes cadastro_v;
        struct tm * local;

        time_t t;
        t = time(NULL);
        local = localtime(&t);

        int dia = local -> tm_mday;
        int mes = local -> tm_mon+1;
        int ano = local -> tm_year+1900;
        char dia_h[3], ano_h[5], mes_h[3]; // variaveis auxiliares para armazenar a data como string
        //Aqui usa recursos da lib <time.h> para definir a data atual

        nota = (char *) malloc(sizeof(char));
        idade = (char *) malloc(2*sizeof(char));
        data = (char *) malloc(10*sizeof(char));

        if(nota == NULL || idade == NULL || data == NULL){

            printf("Erro de alocação de memória(nota,idade,data)\n");

            exit(1);
        }

        printf("***Bem vindo ao feedback do Museu do Trem***\n");
        printf("Qual o sua idade?\n");
        scanf("%s", idade);
        printf("Qual o nota para o museu do trem?\n");
        scanf("%s", nota);

        if(idade[0] != '0')
            break;

        //converte as variaveis dia,mes e ano que sao do tipo int em string e sao salvas respectivamente em diaH,mesH e anoH
        sprintf(dia_h, "%i", dia);
        sprintf(ano_h, "%i", ano);
        sprintf(mes_h, "%i", mes);

        //concatena diaH,mesH e anoH para ficar no formato dd/mm/aaaa
        strcat(data, dia_h);
        strcat(data, "/");
        strcat(data, mes_h);
        strcat(data, "/");
        strcat(data, ano_h);

        cadastro_v.nota = (char *) malloc(sizeof(nota));
        cadastro_v.idade = (char *) malloc(sizeof(idade));
        cadastro_v.data = (char *) malloc(sizeof(data));

        if (cadastro_v.nota == NULL || cadastro_v.idade == NULL || cadastro_v.data == NULL){
            
            printf("Erro de alocação de memória(cadastro_visitante)\n");

            exit(1);
        }

        //copia os valores para as variaveis da struct
        strcpy(cadastro_v.idade , idade);
        strcpy(cadastro_v.data , data);
        strcpy(cadastro_v.nota , nota);

        if (idade[0] != '0')
            incluir_visitante(cadastro_v);

        free(cadastro_v.idade);
        free(cadastro_v.data);
        free(cadastro_v.nota);
        free(nota);
        free(data);
        free(idade);

    } while (idade[0] != '0');
}