#include "isb.h"

void 
mainISB(){
    int dim;
    
    limparConsole();
    printf(NEGRITO "Digite a dimensão da matriz.\n" SEM_ESTILO);
    scanf("%d", &dim);
    
    double matriz[dim][dim];

    lerMatriz(dim, dim, matriz);

    limparConsole();
    //calcular determinante
    double det = determinante(dim, matriz);  // Mudei para usar a quantidade de variáveis

    //calcular posto
    int posto = calcularPosto(dim, dim, matriz);

    printf(NEGRITO "Posto: %d   Determinante: %lf\n" SEM_ESTILO, posto, det);

    //verificacao de injetividade (determinante != 0)
    if (det != 0) {
        printf("A matriz representa uma transformação injetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação injetiva.\n");
    }

    // verificação de sobretividade (posto == número de variáveis)
    if (posto == dim) {
        printf("A matriz representa uma transformação sobrejetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação sobrejetiva.\n");
    }

    // verificação de bijetividade (determinante != 0 e posto == número de variáveis)
    if (det != 0 && posto == dim) {
        printf("A matriz representa uma transformação bijetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação bijetiva.\n");
    }

    //para voltar ao menu ou usar novamente
    int temporario = 5;
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

//le a matriz inserida
void lerMatriz(int linha, int coluna, double matriz[linha][coluna]) {
    limparConsole();
    printf(NEGRITO "Digite os elementos da matriz (%dx%d):\n" SEM_ESTILO, linha, coluna);
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
}

// função auxiliar para calcular o determinante de uma matriz quadrada usando expansão de Laplace
double determinante(int n, double matriz[n][n]) {
    double det = 0;

    if (n == 1) {
        // caso base: determinante de uma matriz 1x1
        return matriz[0][0];  
    }

    if (n == 2) {
        // caso base: determinante de uma matriz 2x2
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];  
    }

    double submatriz[n-1][n-1];

    for (int x = 0; x < n; x++) {
        // indice para linhas da submatriz
        int subi = 0; 
        for (int i = 1; i < n; i++) {
            // indice para colunas da submatriz
            int subj = 0;  
            for (int j = 0; j < n; j++) {                                    //aqui eu tive dificuldade, tive que pedir ajuda, mas basicamente calcula o determinante 
                if (j == x) {                                                //recursivamente, ou seja, chamando ela mesma ate chegar no caso base
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

// funcao para calcular o posto da matriz usando eliminacao de Gauss
int calcularPosto(int linha, int coluna, double matriz[linha][coluna]) {
    int rank = coluna;

    for (int row = 0; row < rank; row++) {
        //se a linha nao e zero, fazer eliminacao
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
            //se a linha e zero, procurar uma linha nao nula para trocar
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