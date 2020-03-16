//======================== Funções ===========================

//Constrói um nó vazio no inicio da pilha
void inicializa(pilha** stack) {
	(*stack)->inicio = NULL;
	(*stack)->tamanho = 0;
}

//Verifica se há algum elemento na pilha
short vazio(pilha** stack) {
    if((*stack)->tamanho == 0) return 1;
    return 0;
}

//Empilhar novo elemento na pilha
void push(pilha** stack, char* dados) {
	no* novoNo;
	novoNo = (no*) malloc(sizeof(no));
	if(novoNo == NULL) {
		printf("Erro! Não há memória alocada.");
		exit(1);
	}

	novoNo->info = dados;
	novoNo->prox = (*stack)->inicio;
	(*stack)->inicio = novoNo;
	(*stack)->tamanho++;
}

//Desempilha e retorna o elemento
no* pop(pilha** stack) {
	no* aux;
	aux = (*stack)->inicio;

	if(vazio(stack))
		printf("Pilha vazia!");
	else {
		(*stack)->inicio = (*stack)->inicio->prox;
		(*stack)->tamanho--;
		return aux;
	}
	return NULL;
}

void imprime(pilha** stack) {
    no* aux;
    aux = (*stack)->inicio;

    if(!vazio(stack))
        while(aux != NULL) {
            printf("\n%s", aux->info);
            aux = aux->prox;
        }
    else
        printf("\nPilha vazia...");
}

no* busca(pilha** stack, char* dados) {
    no* aux;
    aux = (*stack)->inicio;

    if(!vazio(stack)) {
        while(aux != NULL) {
            if(!strcmp(aux->info, dados)) {
                printf("");
                return aux;
            }
            aux = aux->prox;
        }
    }
    else {
        printf("\nPilha vazia...");
        return NULL;
    }
    printf("\nElemento não encontrado...");
    return NULL;
}