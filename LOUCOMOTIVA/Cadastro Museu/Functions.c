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

    char *dados;

    dados = malloc(sizeof(v));

    strcat(dados, v.idade);
    strcat(dados, ";");
    strcat(dados, v.nota);
    strcat(dados, ";");
    strcat(dados, v.data);
    strcat(dados, ";");
    strcat(dados, "\n");

    pont_arq = fopen("banco.txt", "a");

    fprintf(pont_arq, "%s", dados);
    fclose(pont_arq);

    printf("Visitante Salvo\n");

    free(dados);
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
        int mes = local -> tm_mon + 1;
        int ano = local -> tm_year + 1900;
        char dia_h[3], ano_h[5], mes_h[3]; // variaveis auxiliares para armazenar a data como string
        //Aqui usa recursos da lib <time.h> para definir a data atual

        nota = malloc(sizeof(char));
        idade = malloc(2 * sizeof(char));
        data = malloc(16 * sizeof(char));

        printf("***Bem vindo ao feedback do Museu do Trem***\n");
        printf("Qual a sua idade?\n");
        scanf("%s", idade);
        printf("Qual a nota para sua experiência no museu do trem?\n");
        scanf("%s", nota);

        //converte as variaveis dia,mes e ano que sao do tipo int em string e sao salvas respectivamente em dia_h,mes_h e ano_h
        sprintf(dia_h, "%i", dia);
        sprintf(ano_h, "%i", ano);
        sprintf(mes_h, "%i", mes);

        //concatena dia_h,mes_h e ano_h para ficar no formato dd/mm/aaaa
        strcat(data, dia_h);
        strcat(data, "/");
        strcat(data, mes_h);
        strcat(data, "/");
        strcat(data, ano_h);

        cadastro_v.nota = malloc(sizeof(nota));
        cadastro_v.idade = malloc(sizeof(idade));
        cadastro_v.data = malloc(sizeof(data));

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