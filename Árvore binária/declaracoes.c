typedef struct Node {
	int valor;
	struct Node* pai;
	struct Node* esquerda;
	struct Node* direita;
} no;

void inicializa(no** raiz);
short vazio(no** raiz);
void insere(no** raiz, int novoValor);
void imprime(no** raiz);