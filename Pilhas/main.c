#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int main() {
    pilha* stack;
    char string[15];
    no* elem;
    
    if((stack = (pilha*) malloc(sizeof(pilha))) == NULL) {
        printf("\nErro de alocação de memória...");
        exit(1);
    }
    
    inicializa(&stack);
    push(&stack, "Hector");
    push(&stack, "Mia");
    push(&stack, "Felipe");

    printf("\n\nNúmero de palavras na pilha: %d", stack->tamanho);
    elem = busca(&stack, "Mia");

    return 0;
}