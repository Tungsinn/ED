#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>

#define TAM 199

int main() {
    FILE* arquivo;
    FILE* tableFile;
    table tabela;
    no* elemento;
    int chave;
    int colisao;
    int i = 0;
    
    srand((unsigned) time(NULL));
    inicializaTable(tabela);
    
    criaArquivo(arquivo, "elementos");
    criaArquivo(tableFile, "table");
    
    for(; i < 400; i++) {
        chave = randomNum();
        escreveArquivo(arquivo, chave);
    }
    
    colisao = preencheTable(arquivo, tabela);
    imprimeHashTable(tabela);
    imprimeArquivoTable(tableFile, tabela);
    printf("\n\nNúmero de colisões: %d", colisao);
    printf("\nTaxa de preenchimento: %f\n", porcentagem(tabela));
	
	return 0;
}