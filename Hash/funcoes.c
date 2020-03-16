int randomNum() {
    int num;
    num = 1 + (rand() % 500);
    return num;
}

/* Gera um código que indica a posição na tabela em que a chave será
   armazenada */
int funcaoHash(int num) {
    int hash;
    hash = (33 * num) % TAM;
    return hash;
}

void inicializaTable(table tab) {
    int i = 0;
    for(; i < TAM; i++)
        tab[i] = NULL;
}

no* criaNo(int chave, int hash) {
    no* node;
    if((node = (no*) malloc(sizeof(no))) == NULL) {
        printf("\nErro de alocação de memória...\n");
        return NULL;
    }
    node->info = chave;
    node->hashCode = hash;
    node->ocorrencia = 1;
    node->prox = NULL;
    return node;
}

int insereHashTable(table tab, int chave) {
    /* Flag que anuncia se houve colisão ou não */
    int flag = 0;
    int hash;
    no* newNode;
    no* aux;
    
    /* Gera código com a posição da chave na tabela hash */
    hash = funcaoHash(chave);
    aux = tab[hash];
    newNode = criaNo(chave, hash);
    
    while(aux != NULL) {
        if(aux->info == chave) {
            aux->ocorrencia++;
            return flag;
        }
        aux = aux->prox;
        flag++;
    }
    
    if(aux == NULL) {
        aux = newNode;
        aux->prox = tab[hash];
        tab[hash] = aux;
        //printf("\nInfo: %d", aux->info);
        //printf("\nCódigo hash: %d", aux->hashCode);
	return flag;
    }
}

void removeHashTable(table tab, int chave) {
    no* aux;
    no* anterior;
    int hash;
    
    if((aux = busca(tab, chave)) == NULL)
        return NULL;
    
    hash = funcaoHash(chave);
    anterior = tab[hash];
    aux = tab[hash];
    
    if(aux->info == chave) {
        tab[hash] = aux->prox;
        printf("\nA chave %d foi removida com sucesso!", chave);
        free(aux);
        return;
    }
    else {
        aux = aux->prox;
        while(aux != NULL) {
            if(aux->info == chave) {
                anterior->prox = aux->prox;
                printf("\nA chave %d foi removida com sucesso!", chave);
                free(aux);
                return;
            }
            anterior = aux;
            aux = aux->prox;
        }
    }
}

no* busca(table tab, int chave) {
    no* aux;
    int hash;
    
    hash = funcaoHash(chave);
    aux = tab[hash];
    
    while(aux != NULL) {
        if(aux->info == chave) {
            return aux;
        }
        aux = aux->prox;
    }
    printf("\nA chave %d não pertence à tabela...", chave);
    return NULL;
}

void imprimeHashTable(table tab) {
    int i = 0;
    no* aux;
    
    printf("\nPOSIÇÃO\tELEMENTOS");
    while(i < TAM) {
        aux = tab[i];
        if(aux != NULL) {
            printf("\n(%d)\t[%d]", aux->hashCode, aux->info);
            while(aux->prox != NULL) {
                printf("->[%d]", aux->prox->info);
                aux = aux->prox;
            }
        }
        i++;
    }
}

float porcentagem(table tab) {
    int i = 0;
    float porcent, cont;
    cont = 0;
    
    while(i < TAM) {
        if(tab[i] != NULL)
            cont++;
        i++;
    }
    porcent = (cont * 100) / TAM;
    return porcent;
}

void criaArquivo(FILE* arq, char* nomeArquivo) {
    if((arq = fopen(nomeArquivo, "w"))  == NULL)
        perror("\nErro de abertura de arquivo...");
    
    fclose(arq);
}

void escreveArquivo(FILE* arq, int chave) {
    arq = fopen("elementos", "a");
    fprintf(arq, "%d\n", chave);
    fflush(arq);
    fclose(arq);
}

int preencheTable(FILE* arq, table tab) {
    int chave;
    int colisao = 0;
    
    arq = fopen("elementos", "r");
    rewind(arq);
    while(!feof(arq)) {
    	fscanf(arq, "%d", &chave);
        colisao += insereHashTable(tab, chave);
    }
    return colisao;
}

void imprimeArquivoTable(FILE* arq, table tab) {
    int i = 0;
    no* aux;
    
    arq = fopen("table", "w");
    rewind(arq);
    
    fprintf(arq, "\nPOSIÇÃO\tELEMENTOS");
    while(i < TAM) {
        aux = tab[i];
        if(aux != NULL) {
            fprintf(arq, "\n(%3d)\t[%3d]", aux->hashCode, aux->info);
            while(aux->prox != NULL) {
                fprintf(arq, "->[%3d]", aux->prox->info);
                aux = aux->prox;
            }
        }
        i++;
    }
    fclose(arq);
}