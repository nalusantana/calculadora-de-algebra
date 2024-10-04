#include "diagonal.h"
#include "texto.h"
#include "auto.h"
#include "arquivo.h"

void mainDiagonal() {
    limparConsole();
    double matriz[2][2];
    int opcao;

    // Perguntar se vai ler o arquivo ou digitar na mão
    printf("Você deseja:\n");
    printf("1. Inserir a matriz manualmente\n");
    printf("2. Ler a matriz de um arquivo\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    if (opcao == 2) {
        // Código para ler o arquivo
        char nomeArquivo[100];
        printf("Digite o nome do arquivo (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivo);
        
        // Ler a matriz do arquivo
        leMatriz(2, 2, matriz, nomeArquivo); 
    } else if (opcao == 1) {
        // Código para inserir manualmente
        printf("Digite os elementos da matriz 2x2 (linhas):\n");
        for (int i = 0; i < 2; i++) {
            printf("Digite os elementos da linha %d:\n", i + 1);
            for (int j = 0; j < 2; j++) {
                scanf("%lf", &matriz[i][j]);
            }
        }
    } else {
        printf(VERMELHO "Opção inválida!\n" SEM_ESTILO);
        return;
    }

    diagonalizarMatriz(matriz);

    // Perguntar se deseja salvar a matriz original em um arquivo
    printf("Você deseja salvar a matriz original em um arquivo? (1 = Sim, 0 = Não): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        char nomeArquivoSalvar[100];
        printf("Digite o nome do arquivo para salvar (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivoSalvar);
        
        // Salvar a matriz original no arquivo
        salvaMatriz(2, 2, matriz, nomeArquivoSalvar); // Assumindo que a função salvaMatriz já existe
    }

    repetir();
}

void diagonalizarMatriz(double matriz[2][2]) {
    double autovalores[2];
    double autovetores[2][2];

    // Função de cálculo de autovalores feita em outra biblioteca
    calcularAutovalores2(matriz, autovalores);

    double lambda1 = autovalores[0], lambda2 = autovalores[1];

    limparConsole();
    printf(NEGRITO "\nAutovalores:\n" );
    printf("\tλ1 = %.2lf\n", lambda1);
    printf("\tλ2 = %.2lf\n" SEM_ESTILO, lambda2);
    
    // Autovetores não tem função, foi feito na mão direto no print e guarda na matriz de autovetor
    printf(NEGRITO "\nAutovetores:\n" SEM_ESTILO);
    if (matriz[0][1] != 0) {
        printf("\tAutovetor associado a"NEGRITO" λ1: [1, %.2lf]\n" SEM_ESTILO, (lambda1 - matriz[0][0]) / matriz[0][1]);
        printf("\tAutovetor associado a"NEGRITO" λ2: [1, %.2lf]\n" SEM_ESTILO, (lambda2 - matriz[0][0]) / matriz[0][1]);
        autovetores[0][0] = 1;
        autovetores[0][1] = (lambda1 - matriz[0][0]) / matriz[0][1];
        autovetores[1][0] = 1;
        autovetores[1][1] = (lambda2 - matriz[0][0]) / matriz[0][1];
    } else {
        printf("\tAutovetor associado a" NEGRITO" λ1: [1, 0]\n" SEM_ESTILO);
        printf("\tAutovetor associado a" NEGRITO" λ2: [1, 0]\n" SEM_ESTILO);
        autovetores[0][0] = 1;
        autovetores[0][1] = 0;
        autovetores[1][0] = 1;
        autovetores[1][1] = 0;
    }
    
    // Criar a matriz diagonal
    double matrizDiagonal[2][2] = {
        {autovalores[0], 0},
        {0, autovalores[1]}
    };

    // Mostrar a matriz diagonal
    printf("\nMatriz Diagonal:\n");
    printMatriz2(matrizDiagonal);

    // Mostrar a matriz de mudança de base
    printf("\nMatriz de Mudança de Base (autovetores):\n");
    printMatriz2(autovetores);
}

// Função de voltar para o menu ou usar de novo
void repetir() {
    int opcao;
    do {
        printf(NEGRITO "\nVocê deseja repetir o método ou voltar ao menu principal? (Sim = 1 e Não = 0)" SEM_ESTILO);
        scanf("%d", &opcao);

        if (opcao == 0) return;
        if (opcao != 1) {
            limparConsole();
            printf(VERMELHO NEGRITO "Opção inválida!\n" SEM_ESTILO);
        }

    } while (opcao != 1 && opcao != 0);
    if (opcao == 1) mainDiagonal();
}
