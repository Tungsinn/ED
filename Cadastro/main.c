#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "declaracoes.c"
#include "funcoes.c"

int main() {
    lista listaCandidatos;
    listaCandidatos.numCandidatos = 0;
    int opcao;
    int continua = 1;
    
    while(continua) {
        opcao = menu();
        switch(opcao) {
            case 1:
                printf("\n========== Cadastro ==========");
                insereCandidato(&listaCandidatos);
                break;
            case 2:
                printf("\n========== Pesquisa ==========");
                controlaPesquisa(&listaCandidatos);
                break;
            case 3:
                printf("\n========== Descadastro ==========");
                removeCandidato(&listaCandidatos);
                break;
            case 4:
                printf("\n========== Alteração ==========");
                alteraCadastro(&listaCandidatos);
                break;
            case 5:
                continua = 0;
                printf("\nSaindo...\n\n");
                break;
        }
    }
    return 0;
}