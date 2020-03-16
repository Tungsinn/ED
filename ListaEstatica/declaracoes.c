#define TAM 10

int randomNum();
void inicializaLista(lista* L);
lista FLVazia(lista* L);
boolean vazia(lista* L);
boolean retira(lista* L, int* item, int pos, boolean* flag);
boolean insere(lista* L, int* item, boolean* flag);
void imprime(lista* L);

typedef enum {FALSE, TRUE} boolean;
typedef struct Registro {
	int elem;
	int prox;
} reg;

typedef struct Lista {
	reg elementos[MAX];
	int numElem;
	int prim;
	int disp;
} lista;