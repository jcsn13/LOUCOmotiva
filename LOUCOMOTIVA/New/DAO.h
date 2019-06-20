struct visitantes{
	char *idade;
	char *nota; 
	char *data;
};

struct pilha{
	struct visitantes *visitante;
	struct pilha *prox_visitante;
};

FILE *pont_arq;

struct pilha *pilha;

struct pilha * empilhar(struct pilha *pilha_visitantes, struct visitantes *v);
void desempilhar_e_salvar();
void imprimir_pilha();
void cadastrar_visitante();
void incluir_visitante();
void consulta_tudo();
void destruir_pilha(struct pilha *pilha_visitantes);