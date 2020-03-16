/*****************************************************************************/

typedef struct Node {
    int info;
    int hashCode;
    int ocorrencia;
    struct Node* prox;
} no;

typedef no* table[TAM];

/*****************************************************************************/
int randomNum();
int funcaoHash(int num);
void inicializaTable(table tab);
no* criaNo(int chave, int hash);
int insereHashTable(table tab, int chave);
void removeHashTable(table tab, int chave);
no* busca(table tab, int chave);
void imprimeHashTable(table tab);
float porcentagem(table tab);
void criaArquivo(FILE* arq, char* nomeArquivo);
void escreveArquivo(FILE* arq, int chave);
int preencheTable(FILE* arq, table tab);
void imprimeArquivoTable(FILE* arq, table tab);

/*****************************************************************************/