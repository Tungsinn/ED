#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "declaracoes.c"
#include "funcoes.c"

int main() {
	no* tree;
	int value = 0;
	int value1 = 1;
	int value2 = 2;
    
	if((tree = (no*) malloc(sizeof(no))) == NULL) {
        	perror("\nErro: ");
        	exit(1);
    	}
    	else {
        	printf("\nInicializando...");
        	inicializa(&tree);
        	if(vazio(&tree))
            		printf("\nÁrvore vazia...");
        	else 
            		printf("\nÁrvore não está vazia...");
    	}		
    
	insere(&tree, value);
	insere(&tree, value1);
	insere(&tree, value2);
    
	if(vazio(&tree))
        	printf("\nÁrvore vazia...");
    	else 
        	printf("\nÁrvore não está vazia...");
    
    //printf("\n\n");
    //imprime(&tree);
    	return 0;
}
