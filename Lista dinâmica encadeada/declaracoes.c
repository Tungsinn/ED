typedef struct Node {
	int elem;
	struct Node* prox;
} no;

typedef struct Lista {
	no* priElem;
	no* ultElem;
} lista;

int randomNum();
void inicializaLista(lista* L);
short listaVazia(lista* L);
void insereInicio(lista* L, int x);
void insereFinal(lista* L, int x);
void inserePosicao(lista* L, int x, int pos);
void insereOrdenado(lista* L, int x);
void preencheLista(lista* L);
no* buscaElem(lista* L, int x);
void removePrimeiro(lista* L);
void removeUltimo(lista* L);
short removeNo(lista* L, int x);
short removePosicao(lista* L, int pos);
no* getPrimeiro(lista* L);
no* getUltimo(lista* L);
int tamanhoLista(lista* L);
short verificaOrdenacao(lista* L, char* ordem);
void copiaLista(lista* L, lista* L2);
void imprime(lista* L);
