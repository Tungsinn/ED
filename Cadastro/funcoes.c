void limpaBuffer() {
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int menu() {
    int opcao;
    
    printf("\n========== Menu ==========");
    printf("\n1 - Cadastrar candidato");
    printf("\n2 - Pesquisar candidato");
    printf("\n3 - Descadastrar candidato");
    printf("\n4 - Alterar dados do candidato");
    printf("\n5 - SAIR");
    printf("\n\n===> ");
    scanf("%d", &opcao);
    limpaBuffer();
    return opcao;
}

void insereCandidato(lista* listaCandidatos) {
    char opcao;
    char rgC[14];
    char nomeC[49];
    char telefoneC[13];
    char enderecoC[59];
    int i;
    int continua = 1;
    i = listaCandidatos->numCandidatos;
    
    while((i < 200) && continua) {
        printf("\nNome do candidato: ");
        scanf("%s", nomeC);
        strcpy(listaCandidatos->vetor[i].nome, nomeC);
        
        printf("RG: ");
        scanf("%s", rgC);
        strcpy(listaCandidatos->vetor[i].rg, rgC);
        
        printf("Telefone: ");
        scanf("%s", telefoneC);
        strcpy(listaCandidatos->vetor[i].telefone, telefoneC);
        
        printf("Endereço: ");
        scanf("%s", enderecoC);
        strcpy(listaCandidatos->vetor[i].endereco, enderecoC);
        listaCandidatos->numCandidatos++;
        limpaBuffer();
        i++;
        
        printf("\nDeseja cadastrar mais candidatos? [S/N]: ");
        scanf("%c", &opcao);
        if((opcao == 'N') || (opcao == 'n')) continua = 0;
        limpaBuffer();
    }
}

int pesquisaCandidato(lista* listaCandidatos) {
    int i = 0;
    int failed = -1;
    candidato c;
    char rgC[13];
    
    printf("\nDigite o RG: ");
    scanf("%s", rgC);
        while((i < listaCandidatos->numCandidatos) && (failed == -1)) {
            if(strcmp(listaCandidatos->vetor[i].rg, rgC) == 0) {
                failed = 0;
                c = listaCandidatos->vetor[i];
                printf("\nNome: %s", c.nome);
                printf("\nRG: %s", c.rg);
                printf("\nTelefone: %s", c.telefone);
                printf("\nEndereço: %s", c.endereco);
                printf("\n");
                limpaBuffer();
                return i;
            }
            i++;
        }
        limpaBuffer();
        return failed;
}

void controlaPesquisa(lista* listaCandidatos) {
    int aux;
    int continua = 1;
    char caractere;
    
    while(continua) {
        aux = pesquisaCandidato(listaCandidatos);
        if(aux == -1)
            printf("\nCandidato não encontrado...");

        printf("\nDeseja pesquisar mais candidatos? [S/N]: ");
        scanf("%c", &caractere);
        if((caractere == 'N') || (caractere == 'n')) 
            continua = 0;
    }
}

void removeCandidato(lista* listaCandidatos) {
    int posicao;
    char caractere;
    int continua = 1;
    
    while(continua) {
        posicao = pesquisaCandidato(listaCandidatos);
        if(posicao != -1) {
            while(posicao < listaCandidatos->numCandidatos) {
                listaCandidatos->vetor[posicao] = listaCandidatos->vetor[posicao + 1];
                listaCandidatos->numCandidatos--;
                posicao++;
            }
            printf("\nCandidato descadastrado com sucesso...");
            printf("\nNúmero de candidatos cadastrados: %d", listaCandidatos->numCandidatos);
        }
        printf("\nDeseja descadastrar mais candidatos? [S/N]: ");
        scanf("%c", &caractere);
        limpaBuffer();
        if((caractere == 'N') || (caractere == 'n')) 
            return;
    }
}

void alteraCadastro(lista* listaCandidatos) {
    int posicao;
    char caractere;
    int continua = 1;
    int continua2 = 1;
    int item;
    char rgC[14];
    char nomeC[49];
    char telefoneC[13];
    char enderecoC[59];
    
    while(continua) {
        posicao = pesquisaCandidato(listaCandidatos);
        if(posicao != -1) {
            while(continua2) {
                printf("\n\nSelecione o item que deseja alterar: ");
                printf("\n1 - Nome");
                printf("\n2 - RG");
                printf("\n3 - Telefone");
                printf("\n4 - Endereço");
                printf("\n5 - VOLTAR\n");
                printf("\n===> ");
                scanf("%d", &item);
                
                switch(item) {
                    case 1:
                        printf("\nNome atual: %s", listaCandidatos->vetor[posicao].nome);
                        printf("\nNovo nome: ");
                        scanf("%s", nomeC);
                        strcpy(listaCandidatos->vetor[posicao].nome, nomeC);
                        printf("Cadastro alterado com sucesso...");
                        break;
                    case 2:
                        printf("\nRG atual: %s", listaCandidatos->vetor[posicao].rg);
                        printf("\nNovo RG: ");
                        scanf("%s", rgC);
                        strcpy(listaCandidatos->vetor[posicao].rg, rgC);
                        printf("Cadastro alterado com sucesso...");
                        break;
                    case 3:
                        printf("\nTelefone atual: %s", listaCandidatos->vetor[posicao].telefone);
                        printf("\nNovo telefone: ");
                        scanf("%s", telefoneC);
                        strcpy(listaCandidatos->vetor[posicao].telefone, telefoneC);
                        printf("Cadastro alterado com sucesso...");
                        break;
                    case 4:
                        printf("\nEndereço atual: %s", listaCandidatos->vetor[posicao].endereco);
                        printf("\nNovo endereço: ");
                        scanf("%s", enderecoC);
                        strcpy(listaCandidatos->vetor[posicao].endereco, enderecoC);
                        printf("Cadastro alterado com sucesso...");
                        break;
                    case 5:
                        continua2 = 0;
                        break;
                }
            }
        }
        limpaBuffer();
        printf("\n\nDeseja alterar mais cadastros? [S/N]: ");
        scanf("%c", &caractere);
        if((caractere == 'N') || (caractere == 'n')) continua = 0;
    }
}