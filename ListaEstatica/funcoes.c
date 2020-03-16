int randomNum() {
	int num;
	num = rand() % 10;
	return num;
}

void inicializaLista(lista* L) {
	int i = 0;
	L->disp = 0;
    L->prim = -1;
    
    for( ; i < MAX - 1 ; i++)
       	L->elementos[i].prox = i + 1;
    
    L->elementos[i].prox = -1;
}

lista FLVazia(lista* L) {
    int i = 0;
    while(i < MAX) {
       	L->elementos[i].elem = -1;
       	i++;
   	}
    return *L;
}

boolean vazia(lista* L) {
    if(L->prim == -1) return TRUE;
    return FALSE;
}

boolean retira(lista* L, int* item, int pos, boolean* flag) {
    int p;
   	p = L->prim;
    
   	if(vazia(L) || pos >= MAX) 
       	*flag = FALSE;
	if(L->elementos[pos].elem == -1)
       	*flag = FALSE;
   	else {
       	*item = L->elementos[pos].elem;
		L->elementos[pos].elem = -1;
       	while(L->elementos[p].prox != pos) p++;
       	L->elementos[p].prox = L->elementos[p].prox;
       	L->disp = pos;
       	L->numElem--;
       	*flag = TRUE;
   	}
   	return *flag;
}

boolean insere(lista* L, int* item, boolean* flag) {
    int pos;
    int i = 0;
    pos = L->disp;
    
    if(L->numElem == MAX)
       	*flag = FALSE;
    else if(vazia(L)) {
       	L->prim = pos;
       	L->elementos[pos].elem = *item;
       	L->disp = L->elementos[pos].prox;
       	L->numElem++;
       	*flag = TRUE;
    }
    else {
       	L->elementos[pos].elem = *item;
       	L->numElem++;
       	while(L->elementos[i].elem != -1) i++;
       	L->disp = i;
       	L->elementos[pos].prox = i;
    }
    return *flag;
}

void imprime(lista* L) {
	int p;
	p = L->prim;
    
    while(L->elementos[p].prox != L->disp) {
    	printf("\nElemento: %d\tPosição: %d", L->elementos[p].elem, p);
       	p = L->elementos[p].prox;
   	}
   	printf("\nElemento: %d\tPosição: %d", L->elementos[p].elem, p);
}