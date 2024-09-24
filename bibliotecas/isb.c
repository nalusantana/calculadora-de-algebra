#include "isb.h"



void mainISB(){
    // LER MATRIZ
    int quantidadeEquacoes, quantidadeVariaveis;
    
    limparConsole();
    printf(NEGRITO "Digite o número de equações e variáveis (Max: %d, %d respectivamente).\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
    scanf("%d %d", &quantidadeEquacoes, &quantidadeVariaveis);
    
    int linha = quantidadeEquacoes, coluna = quantidadeVariaveis;
    double matriz[linha][coluna];

    lerMatriz(linha, coluna, matriz);
    limparConsole();
    // VERIFICAR DETERMINANTE
    double det = determinante(coluna, matriz);  // Mudei para usar a quantidade de variáveis

    // VERIFICAR POSTO
    
    int posto = calcularPosto(linha, coluna, matriz);

    printf(NEGRITO "Posto: %d   Determinante: %lf\n" SEM_ESTILO, posto, det);

    // VERIFICAÇÕES DE SOBRE, INJ E BIJ
    if (det != 0 && linha == coluna) {
        printf("A matriz representa uma transformação injetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação injetiva.\n");
    }

    // Verificação de Sobretividade (posto == número de variáveis)
    if (posto == coluna) {
        printf("A matriz representa uma transformação sobrejetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação sobrejetiva.\n");
    }

    // Verificação de Bijetividade (determinante != 0 e posto == número de variáveis)
    if (det != 0 && posto == coluna) {
        printf("A matriz representa uma transformação bijetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação bijetiva.\n");
    }
    int temporario;
    while(temporario != 1 && temporario != 0){
        printf("\n(Pressione 1 para utilizar a funcionalidade novamente ou 0 para retornar ao menu.)\n");
        scanf("%d", &temporario);
        if(temporario == 1){
            mainISB();
        }
        else if(temporario == 0){
            return;
        }else{
            printf(VERMELHO NEGRITO "Opção inválida!\n\n" SEM_ESTILO);
        }
    }
}

void lerMatriz(int linha, int coluna, double matriz[linha][coluna]) {
    limparConsole();
    printf(NEGRITO "Digite os elementos da matriz de coeficiente (%dx%d):\n" SEM_ESTILO, linha, coluna);
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
}

// Função auxiliar para calcular o determinante de uma matriz quadrada usando expansão de Laplace
double determinante(int n, double matriz[n][n]) {
    double det = 0;

    if (n == 1) {
        return matriz[0][0];  // Caso base: determinante de uma matriz 1x1
    }

    if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];  // Caso base: determinante de uma matriz 2x2
    }

    double submatriz[n-1][n-1];

    for (int x = 0; x < n; x++) {
        int subi = 0;  // Índice para linhas da submatriz
        for (int i = 1; i < n; i++) {
            int subj = 0;  // Índice para colunas da submatriz
            for (int j = 0; j < n; j++) {
                if (j == x) {
                    continue;
                }
                submatriz[subi][subj] = matriz[i][j];
                subj++;
            }
            subi++;
        }
        det += pow(-1, x) * matriz[0][x] * determinante(n-1, submatriz);
    }

    return det;
}

// Função para calcular o posto da matriz usando eliminação de Gauss
int calcularPosto(int linha, int coluna, double matriz[linha][coluna]) {
    int rank = coluna;

    for (int row = 0; row < rank; row++) {
        // Se a linha não é zero, fazer eliminação
        if (matriz[row][row]) {
            for (int col = 0; col < linha; col++) {
                if (col != row) {
                    double mult = matriz[col][row] / matriz[row][row];
                    for (int i = 0; i < rank; i++) {
                        matriz[col][i] -= mult * matriz[row][i];
                    }
                }
            }
        } else {
            // Se a linha é zero, procurar uma linha não nula para trocar
            int reduce = 1;
            for (int i = row + 1; i < linha; i++) {
                if (matriz[i][row]) {
                    for (int j = 0; j < rank; j++) {
                        double temp = matriz[row][j];
                        matriz[row][j] = matriz[i][j];
                        matriz[i][j] = temp;
                    }
                    reduce = 0;
                    break;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < linha; i++) {
                    matriz[i][row] = matriz[i][rank];
                }
            }
            row--;
        }
    }

    return rank;
}