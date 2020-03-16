typedef struct Candidato {
    char rg[14];
    char nome[49];
    char telefone[13];
    char endereco[59];
} candidato;

typedef struct Lista {
    candidato vetor[200];
    int numCandidatos;
} lista;

void limpaBuffer();
int menu();
void insereCandidato(lista* listaCandidatos);
int pesquisaCandidato(lista* listaCandidatos);
void controlaPesquisa(lista* listaCandidatos);
void removeCandidato(lista* listaCandidatos);
void alteraCadastro(lista* listaCandidatos);
