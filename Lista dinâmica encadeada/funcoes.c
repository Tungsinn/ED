int randomNum() {
    int num;
    num = rand() % 66;
    return num;
}

void inicializaLista(lista* L) {
	L->priElem = NULL;
	L->ultElem = NULL;
}

/* Inserção no início */
void insereInicio(lista* L, int x) {
	no* novoNo;
	
	if((novoNo = (no*) malloc(sizeof(no))) == NULL) {
		perror("\nErro de alocação de memória...");
		exit(1);
	}
	novoNo->elem = x;
	novoNo->prox = NULL;
	if(L->priElem == NULL)
		L->ultElem = novoNo;
	else
		novoNo->prox = L->priElem;
	L->priElem = novoNo;
}

void inserePosicao(lista* L, int x, int pos) {
	int cont = 0;
	no* novoNo;
	no* aux = NULL;
	no* ant;
	aux = L->priElem;
	
	if((novoNo = (no*) malloc(sizeof(no))) == NULL) {
		perror("\nErro de alocação de memória...");
		exit(1);
	}
	novoNo->elem = x;
	while(aux != NULL) {
		if(cont == pos) {
			novoNo->prox = aux;
			ant->prox = novoNo;
			return;
		}
		cont++;
		ant = aux;
		aux = aux->prox;
	}
	return;
}

void insereOrdenado(lista* L, int x) {
    no* novoNo;
    no* aux;
    no* ant = NULL;
    aux = L->priElem;
    
    if((novoNo = (no*) malloc(sizeof(no))) == NULL) {
		perror("\nErro de alocação de memória...");
		exit(1);
	}
	novoNo->elem = x;
	while(aux != NULL) {
        if(x < aux->elem) {
            if(ant == NULL) {
                novoNo->prox = aux;
                L->priElem = novoNo;
                return;
            }
            ant->prox = novoNo;
            novoNo->prox = aux;
            return;
        }
        else if(x == aux->elem) return;
	    ant = aux;
	    aux = aux->prox;
	}
	aux = novoNo;
	L->ultElem = novoNo;
	ant->prox = novoNo;
	novoNo->prox = NULL;
}

void preencheLista(lista* L) {
	int i, x;
	
	for(i = 0; i < 5; i++) {
		x = randomNum();
		insereInicio(L, x);
	}
}

void imprimeLista(lista* L) {
	no* aux;
	aux = L->priElem;
	
	while(aux != NULL) {
		printf("\nElemento = %d", aux->elem);
		aux = aux->prox;
	}
}

short listaVazia(lista* L) {
	if(L->priElem == NULL) return 1;
	return 0;
}

no* buscaElem(lista* L, int x) {
	no* aux;
	aux = L->priElem;
	
	while(aux != NULL) {
		if(aux->elem == x) return aux;
		aux = aux->prox;
	}
	return NULL;
}

void removePrimeiro(lista* L) {
	no* aux;
	aux = L->priElem;
	L->priElem = aux->prox;
	free(aux);
}

short removeNo(lista* L, int x) {
	no* ant = NULL;
	no* aux = L->priElem;
	
	while(aux != NULL && aux->elem != x) {
		ant = aux;
		aux = aux->prox;
	}
	if(aux == NULL) return 0;
	if(ant == NULL) removePrimeiro(L);
	else if(aux == L->ultElem) {
		L->ultElem = ant;
		L->ultElem->prox = NULL;
	}
	else ant->prox = aux->prox;
	free(aux);
	return 1;
}

short removePosicao(lista* L, int pos) {
	no* ant = NULL;
	no* aux = L->priElem;
	int cont = 0;
	
	while(aux != NULL) {
		if(cont == 0) {
			removePrimeiro(L);
			return 1;
		}
		if(cont == pos) {
			ant->prox = aux->prox;
			free(aux);
			return 1;
		}
		ant = aux;
		aux = aux->prox;
	}
	return 0;
}

no* getPrimeiro(lista* L) {
	return L->priElem;
}

no* getUltimo(lista* L) {
	return L->ultElem;
}

int tamanhoLista(lista* L) {
	no* aux = L->priElem;
	int tam =  0;
	
	while(aux != NULL) {
		tam++;
		aux = aux->prox;
	}
	return tam;
}

void imprime(lista* L) {
	no* aux;
	aux = L->priElem;
	
	while(aux != NULL) {
		printf("\n%d", aux->elem);
		aux = aux->prox;
	}
}