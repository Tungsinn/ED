#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declaracoes.c"
#include "funcoes.c"

int main() {
    lista L; 
    lista L2;
    int elemento;
    int i = 0;
	int verifica;
    
    srand((unsigned) time(NULL));
    elemento = randomNum();
    
    inicializaLista(&L);
    insereInicio(&L, 66);
    for(; i < 6; i++) {
        elemento = randomNum();
        insereOrdenado(&L, elemento);
    }
	if(verifica = verificaOrdenacao(&L, "crescente"))
		printf("\nA lista está em ordem crescente!");
	else printf("\nA lista não está em ordem crescente...");
	
	if(!(verifica = verificaOrdenacao(&L, "descrescente")))
	    printf("\nA lista está em ordem descrescente!");
	else printf("\nA lista não está em ordem decrescente...");
	
    printf("\n\nIMPRESSÃO:");
    imprime(&L);
	
	inicializaLista(&L2);
	copiaLista(&L, &L2);
	printf("\n\nIMPRESSÃO L2:");
	imprime(&L2);
    return 0;
}
