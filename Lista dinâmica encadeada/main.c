#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "declaracoes.c"
#include "funcoes.c"

int main() {
    lista L;
    int elemento;
    int i = 0;
    
    srand((unsigned) time(NULL));
    elemento = randomNum();
    
    inicializaLista(&L);
    insereInicio(&L, 66);
    for(; i < 6; i++) {
        elemento = randomNum();
        insereOrdenado(&L, elemento);
    }
    printf("\n\nIMPRESSÃO:");
    imprime(&L);
    return 0;
}