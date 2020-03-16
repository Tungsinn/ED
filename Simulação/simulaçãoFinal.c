/* Simulação de um dia de expediente de trabalho em um estabelecimento com
quatro caixas de atendimento aos clientes. O dia tem oito horas, ininterruptas.
*/

/* Os clientes chegam ao estabelecimento entre 1 e 4 minutos, com um problema
que será resolvido por um caixa específico. O novo cliente entra na fila do seu
caixa, e aguarda até ser o primeiro da fila. Cada cliente é atendido em um
intervalo de 3 à 8 minutos. */

/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#define CAIXAS 4
#define HORA 60

/*****************************************************************************/

typedef struct Clientes {
    int horario;
    int tempo;
    int codigo;
    struct Clientes* prox;
} clientes;

typedef struct Caixas {
    int clientesRecebidos;
    clientes* cliente;
} caixas;

/*****************************************************************************/

short caixaVazio(caixas** caixa, int cod);
clientes* novoCliente(caixas** caixa);
void entraFila(caixas** caixa, clientes** novo, int hora);
void saiFila(caixas** caixa, int cod, int hora);

/*****************************************************************************/

short caixaVazio(caixas** caixa, int cod) {
    if((*caixa + cod)->cliente == 0) return 1;
    else return 0;
}

clientes* novoCliente(caixas** caixa) {
    int i = 0;
    clientes* novo;
    int cod, zeit;
    
    if((novo = (clientes*) malloc(sizeof(clientes))) == NULL) {
        printf("\nErro de alocação de memória...\n");
        return 0;
    }
    cod = rand() % 4;
    zeit = 3 + (rand() % 5);
    novo->codigo = cod;
    novo->tempo = zeit;
    novo->prox = (void*) 0;

    return novo;
}

void entraFila(caixas** caixa, clientes** novo, int hora) {
    clientes* aux;
    int i;
    i = (*novo)->codigo;
    
    if(caixaVazio(caixa, i)) {
        (*caixa + i)->cliente = *novo;
        (*caixa + i)->cliente->horario = hora;
        (*caixa + i)->clientesRecebidos++;
    }
    else {
        aux = (*caixa + i)->cliente;
        while(aux->prox != NULL)
            aux = aux->prox;
            
        aux->prox = *novo;
        (*caixa + i)->clientesRecebidos++;
    }
}

void saiFila(caixas** caixa, int cod, int hora) {
    clientes* aux;
    
    if(caixaVazio(caixa, cod) == 1)
        return;
    else {
        aux = (*caixa + cod)->cliente;
        (*caixa + cod)->cliente = aux->prox;
        free(aux);
        
        if(caixaVazio(caixa, cod) == 0)
            (*caixa + cod)->cliente->horario = hora;
    }
}

/*****************************************************************************/

int main() {
    int dia = 8 * HORA;
    int minutos = 0;
    int i = 0;
    int frequencia = 0;
    int tempoAtendimento;
    int code;
    caixas* caixa;
    clientes* novo;
    
    srand((unsigned) time(NULL));
    
    if((caixa = (caixas*) calloc(4, sizeof(caixas))) == NULL) {
        printf("\nErro de alocação de memória...\n");
        return 0;
    }
    
    while(minutos <= dia) {
        if(frequencia == 0) {
            novo = novoCliente(&caixa);
            code = novo->codigo;
            entraFila(&caixa, &novo, minutos);
            frequencia = 1 + (rand() % 3);
        }
        
        for(; i < 4; i++) {
            tempoAtendimento = 0;
            if(caixaVazio(&caixa, i) == 0) {
                tempoAtendimento = (caixa + i)->cliente->tempo;
                if(tempoAtendimento == 0) 
                    saiFila(&caixa, i, minutos);
                if(caixaVazio(&caixa, i) == 0)
                    (caixa + i)->cliente->tempo = 
			(caixa + i)->cliente->tempo - 1;
            }
        }
        
        i = 0;
        frequencia--;
        minutos++;
        printf("\nMinuto: %d", minutos);
    }
    
    printf("\n\nClientes atendidos em cada caixa: ");
    for(; i < 4; i++)
	printf("\nCaixa[%d]: %d", i, (caixa + i)->clientesRecebidos);


    return 0;
}