void inicializa(no** raiz) {
	*raiz = NULL;
}

short vazio(no** raiz) {
	if(*raiz == NULL) return 1;
	return 0;
}

void insere(no** raiz, int novoValor) {
	no* novoNo;

	if(vazio(raiz)) {
		novoNo = (no*) malloc (sizeof(no));
		if(novoNo == NULL) {
			printf("\nErro! Não há memória alocada...");
			exit(1);
		}
		novoNo->valor = novoValor;
		novoNo->pai = NULL;
		novoNo->esquerda = NULL;
		novoNo->direita = NULL;
		*raiz = novoNo;
	}	

	else {
		if (novoValor < (*raiz)->valor)
			insere((&(*raiz)->esquerda), novoValor);

		else if(novoValor > (*raiz)->valor)
			insere((&(*raiz)->direita), novoValor);
	}
}

void imprime(no** raiz) {
	no* aux;
	aux = *raiz;
    
	if(aux->pai == NULL) {
		printf("%d", aux->valor);
		while(aux->esquerda != NULL) {
			printf("\r\t");
			printf("\n%p", aux->esquerda);
            		aux = aux->esquerda;
        	}
    	}
}