#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DAO.h"

void incluir_visitante(struct visitantes v)
{
       /*
	*Recebe como parametro os dados do visitante:
	*-Data da visita
	*-Nota de sua visita
	*-Idade do visitante
        *
	*Apos, concatena todos os dados em uma String, separados por ";".E por final da append dessa String em um *arquivo .txt com uma quebra de linha no final, e imprime uma mensagem de sucesso.
	*/

        pont_arq = fopen("banco.txt", "a");

        fprintf(pont_arq,"%s;%s;%s\n",v.idade,v.nota,v.data);

        fclose(pont_arq);

        printf("Visitante Salvo\n");
}

void consulta_tudo()
{
        pont_arq = fopen("banco.txt", "r");
        char c;

        while ((c = fgetc(pont_arq)) != EOF)
                printf("%c", c);

        fclose(pont_arq);
}

void cadastrar_visitante()
{
       /*
	*Cria 3 ponteiros para coletar os dados do visitante:
	*   -Data da visita
	*   -Nota de sua visita
	*   -Idade do visitante
        *
	*Cria uma variavel do tipo struct, a qual é definida no começo do arquivo DAO.h.
        *
	*Depois de coletados os dados copia a string para cada variável da struct e chama a função incluir_visitante()*passando como parametro a struct criada. Após isso libera todos os endereços de memória alocados.
	*/

         char *nota, *idade, *data;

        do{
                struct visitantes cadastro_v;
                struct tm * local;

                 time_t t;
                 t = time(NULL);
                local = localtime(&t);

                int dia = local -> tm_mday;
                 int mes = local -> tm_mon+1;
                int ano = local -> tm_year+1900;
                char dia_h[3], ano_h[5], mes_h[3]; /*
                                                    *variaveis auxiliares para armazenar a data como string
                                                    */
                /* 
                 *Aqui usa recursos da lib <time.h> para definir a data atual
                 */

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

                sprintf(dia_h, "%i", dia);
                sprintf(ano_h, "%i", ano);
                sprintf(mes_h, "%i", mes);

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

void cadastro(int argc,char *argv[])
{
        /*
         * Cadastra ate 5 usuarios que sao mandados pelo servidor em python
         * pela linha de comando
         * Ex:
         * ./Teste.out "30/04/1998" "27" "05" "Aprendi Mais" "28/07/1999" 
         * "15" "03" "Nao aprendi"
         */
        int cont = 1;

        while (cont < argc)
        {

                if (cont < 5)
                {
                        struct visitantes cadastro_1;

                        cadastro_1.data = argv[cont];
                        cadastro_1.idade = argv[cont + 1];
                        cadastro_1.nota = argv[cont + 2];
                        cadastro_1.palavra = argv[cont + 3];

                        if (cadastro_1.data != NULL || cadastro_1.nota != NULL || cadastro_1.idade != NULL)
                                pilha = empilhar(pilha, &cadastro_1);
                }
                else if (cont < 8)
                {
                        struct visitantes cadastro_2;

                        cadastro_2.data = argv[cont];
                        cadastro_2.idade = argv[cont + 1];
                        cadastro_2.nota = argv[cont + 2];
                        cadastro_2.palavra = argv[cont + 3];

                        if (cadastro_2.data != NULL || cadastro_2.nota != NULL || cadastro_2.idade != NULL)
                                pilha = empilhar(pilha, &cadastro_2);
                }
                else if (cont < 11)
                {
                        struct visitantes cadastro_3;

                        cadastro_3.data = argv[cont];
                        cadastro_3.idade = argv[cont + 1];
                        cadastro_3.nota = argv[cont + 2];
                        cadastro_3.palavra = argv[cont + 3];

                        if (cadastro_3.data != NULL || cadastro_3.nota != NULL || cadastro_3.idade != NULL)
                                pilha = empilhar(pilha, &cadastro_3);
                }
                else if (cont < 14)
                {
                        struct visitantes cadastro_4;

                        cadastro_4.data = argv[cont];
                        cadastro_4.idade = argv[cont + 1];
                        cadastro_4.nota = argv[cont + 2];
                        cadastro_4.palavra = argv[cont + 3];

                        if (cadastro_4.data != NULL || cadastro_4.nota != NULL || cadastro_4.idade != NULL)
                                pilha = empilhar(pilha, &cadastro_4);
                }
                else if (cont < 17)
                {
                        struct visitantes cadastro_5;

                        cadastro_5.data = argv[cont];
                        cadastro_5.idade = argv[cont + 1];
                        cadastro_5.nota = argv[cont + 2];
                        cadastro_5.palavra = argv[cont + 3];

                        if (cadastro_5.data != NULL || cadastro_5.nota != NULL || cadastro_5.idade != NULL)
                                pilha = empilhar(pilha, &cadastro_5);
                }

                cont = cont + 4;
        }

        desempilhar_e_salvar(pilha);
        imprimir_pilha(pilha);
}