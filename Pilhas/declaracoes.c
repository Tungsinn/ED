//================ Definições ===================

//Elementos da pilha
typedef struct Node {
	char* info;
	struct Node* prox;
} no;

//Estrutura da pilha
typedef struct Pilha {
	no *inicio;
	int tamanho;
} pilha;

void inicializa(pilha** stack);
short vazio(pilha** stack);
void push(pilha** stack, char* dados);
no* pop(pilha** stack);
void imprime(pilha** stack);