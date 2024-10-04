#include "isb.h"
#include "arquivo.h"
#include "gauss.h"

void mainISB() {
    int dim;

    // Código para perguntar se vai ler o arquivo ou digitar na mão
    printf("Você deseja:\n");
    printf("1. Inserir a matriz manualmente\n");
    printf("2. Ler a matriz de um arquivo\n");
    printf("Digite sua opção: ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1) {
        // Código para digitar a matriz manualmente
        limparConsole();
        printf(NEGRITO "Digite a dimensão da matriz.\n" SEM_ESTILO);
        scanf("%d", &dim);
        double matriz[dim][dim];
        
        lerMatriz(dim, dim, matriz);
        calcularISB(dim, matriz);
    } else if (opcao == 2) {
        // Código para ler a matriz de um arquivo
        char nomeArquivo[100];
        printf("Digite o nome do arquivo (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivo);

        int linhas, colunas;

        leDimensoes(&linhas, &colunas, nomeArquivo);
        dim = linhas;
        double matriz[dim][dim];
        leMatriz(dim, dim, matriz, nomeArquivo);
        calcularISB(dim, matriz);
        
    } else {
        printf(VERMELHO NEGRITO "Opção inválida!\n" SEM_ESTILO);
        return;
    }

    
}

void calcularISB(int dim, double matriz[dim][dim]){
    limparConsole();
    double matrizOriginal[dim][dim];
    copiarMatrizOriginal(dim, dim, matrizOriginal, matriz);
    // Calcular determinante
    double det = determinante(dim, matriz);
    int opcao;
    // Calcular posto
    int posto = calcularPosto(dim, dim, matriz);

    printf(NEGRITO "Posto: %d   Determinante: %lf\n" SEM_ESTILO, posto, det);

    // Verificação de injetividade (determinante != 0)
    if (det != 0) {
        printf("A matriz representa uma transformação injetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação injetiva.\n");
    }

    // Verificação de sobretividade (posto == número de variáveis)
    if (posto == dim) {
        printf("A matriz representa uma transformação sobrejetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação sobrejetiva.\n");
    }

    // Verificação de bijetividade (determinante != 0 e posto == número de variáveis)
    if (det != 0 && posto == dim) {
        printf("A matriz representa uma transformação bijetiva.\n");
    } else {
        printf("A matriz NÃO representa uma transformação bijetiva.\n");
    }

    // Perguntar se deseja salvar a matriz
    printf("Você deseja salvar a matriz em um arquivo? (1 = Sim, 0 = Não): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        char nomeArquivoSalvar[100];
        printf("Digite o nome do arquivo para salvar (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivoSalvar);

        salvaMatriz(dim, dim, matrizOriginal, nomeArquivoSalvar);
    }

    // Para voltar ao menu ou usar novamente
    int temporario = 5;
    while (temporario != 1 && temporario != 0) {
        printf("\n(Pressione 1 para utilizar a funcionalidade novamente ou 0 para retornar ao menu.)\n");
        scanf("%d", &temporario);
        if (temporario == 1) {
            mainISB();
        } else if (temporario == 0) {
            return;
        } else {
            printf(VERMELHO NEGRITO "Opção inválida!\n\n" SEM_ESTILO);
        }
    }
}
// Le a matriz inserida
void lerMatriz(int linha, int coluna, double matriz[linha][coluna]) {
    limparConsole();
    printf(NEGRITO "Digite os elementos da matriz (%dx%d):\n" SEM_ESTILO, linha, coluna);
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
        // Caso base: determinante de uma matriz 1x1
        return matriz[0][0];  
    }

    if (n == 2) {
        // Caso base: determinante de uma matriz 2x2
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];  
    }

    double submatriz[n-1][n-1];

    for (int x = 0; x < n; x++) {
        // Índice para linhas da submatriz
        int subi = 0; 
        for (int i = 1; i < n; i++) {
            // Índice para colunas da submatriz
            int subj = 0;  
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

