#include <stdio.h>
#include "declaracoes.c"
#include "funcoes.c"

int main() {
    lista L;
    int item, pos;
    boolean flag;
    	
	srand((unsigned) time(NULL));
    inicializaLista(&L);
    L = FLVazia(&L);
    if(vazia) printf("\nA lista está vazia.");
    else printf("\nA lista não está vazia.");
    	
	item = randomNum();
    flag = insere(&L, &item, &flag);
    if(flag) printf("\nElemento inserido com sucesso.");
    else printf("\nInserção falhou.");
    
    flag = insere(&L, &item, &flag);
    if(flag) printf("\nElemento inserido com sucesso.");
    else printf("\nInserção falhou.");
    
    pos = randomNum();
    flag = retira(&L, &item, pos, &flag);
    if(flag) printf("\nElemento removido com sucesso.");
    else printf("\nRemoção falhou.");
    
    imprime(&L);
    return 0;
}
