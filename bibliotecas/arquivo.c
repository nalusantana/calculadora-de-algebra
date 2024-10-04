#include "arquivo.h"


//funcao que salva a matriz em arquivo
void salvaMatriz(int linhas, int colunas, double matriz[linhas][colunas], const char* nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar a matriz.\n");
        return;
    }
    
    //printa o conteudo para dentro do arquivo
    fprintf(arquivo, "%d %d\n", linhas, colunas); //salva o tamanho da matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fprintf(arquivo, "%8.4lf ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Matriz salva com sucesso em %s\n", nomeArquivo);
}

//le a matriz salva
void leMatriz(int linhas, int colunas, double matriz[linhas][colunas], const char* nomeArquivo) {
    limparConsole();
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para ler a matriz.\n");
        return;
    }

    fscanf(arquivo, "%d %d", &linhas, &colunas); //le o tamanho da matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(arquivo, "%lf", &matriz[i][j]);
        }
    }
    fclose(arquivo);
    printf("Matriz lida com sucesso de %s\n", nomeArquivo);
}

// Função para ler as dimensões da matriz no arquivo
void leDimensoes(int* linhas, int* colunas, const char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para ler a matriz.\n");
        return;
    }
    fscanf(arquivo, "%d %d", linhas, colunas); // lê as dimensões da matriz
    fclose(arquivo);
}