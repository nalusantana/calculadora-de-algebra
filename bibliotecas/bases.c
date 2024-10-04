#include "bases.h"
#include "texto.h"
#include "arquivo.h"  // Incluindo o cabeçalho para manipulação de arquivos

// professor de algebra pediu somente dimensao 2 e 3
void mainBases() {
    limparConsole();
    int dim, opcao;
    double matriz2[2][2], matriz3[3][3];

    // Perguntar se vai ler o arquivo ou digitar na mão
    printf("Você deseja:\n");
    printf("1. Inserir os vetores manualmente\n");
    printf("2. Ler os vetores de um arquivo\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    if (opcao == 2) {
        // Código para ler o arquivo
        char nomeArquivo[100];
        printf("Digite o nome do arquivo (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivo);

        // Ler a dimensão do arquivo
        int linhas, colunas;
        leDimensoes(&linhas, &colunas, nomeArquivo);
        dim = linhas;

        if (linhas == 2 && colunas == 2) {
            leMatriz(linhas, colunas, matriz2, nomeArquivo);
            printVetores2(matriz2);
            verificarBases2(matriz2);
        } else if (linhas == 3 && colunas == 3) {
            leMatriz(linhas, colunas, matriz3, nomeArquivo);
            printVetores3(matriz3);
            verificarBases3(matriz3);
        } else {
            printf(VERMELHO "O arquivo não contém uma matriz válida (2x2 ou 3x3).\n" SEM_ESTILO);
        }
    } else if (opcao == 1) {
        // Código para inserir manualmente
        do {
            printf("Escolha a dimensão do espaço vetorial (2 ou 3) ou 0 para retornar ao menu: \n");
            scanf("%d", &dim);

            if (dim == 0) return;
            if (dim != 2 && dim != 3) {
                limparConsole();
                printf(VERMELHO NEGRITO "Dimensão deve ser 2 ou 3!\n" SEM_ESTILO);
            }
        } while (dim != 2 && dim != 3);
        limparConsole();

        if (dim == 2) {
            bases2(matriz2);
        } else if (dim == 3) {
            bases3(matriz3);
        }
    }

    // Perguntar se deseja salvar a matriz
    printf("Você deseja salvar os vetores em um arquivo? (1 = Sim, 0 = Não): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        char nomeArquivoSalvar[100];
        printf("Digite o nome do arquivo para salvar (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivoSalvar);

        if (dim == 2) {
            salvaMatriz(2, 2, matriz2, nomeArquivoSalvar);
        } else if (dim == 3) {
            salvaMatriz(3, 3, matriz3, nomeArquivoSalvar);
        }
    }
    perguntarOpcao();
}

// Função que lê os vetores e confere se são bases na dimensão 2
void bases2(double matriz[2][2]) {
    printf(NEGRITO "Digite os elementos dos vetores de R2, um vetor por vez (linhas):\n" SEM_ESTILO);
    for (int i = 0; i < 2; i++) {
        printf("Digite os elementos do vetor %d:\n", i + 1);
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    // Calcula o determinante
    double det = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

    printVetores2(matriz);

    if (det != 0) {
        printf(NEGRITO "Os vetores formam uma base em R2.\n" SEM_ESTILO);
    } else {
        printf(NEGRITO "Os vetores não formam uma base em R2.\n" SEM_ESTILO);
    }

}

// Função que lê os vetores e confere se são bases na dimensão 3
void bases3(double matriz[3][3]) {
    printf(NEGRITO "Digite os elementos dos vetores de R3, um vetor por vez (linhas):\n" SEM_ESTILO);
    for (int i = 0; i < 3; i++) {
        printf("Digite os elementos do vetor %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    // Calcula o determinante
    double det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
              - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
              + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    printVetores3(matriz);

    if (det != 0) {
        printf(NEGRITO "Os vetores formam uma base em R3.\n" SEM_ESTILO);
    } else {
        printf(NEGRITO "Os vetores não formam uma base em R3.\n" SEM_ESTILO);
    }

}

// Função para verificar se os vetores formam uma base em R2
void verificarBases2(double matriz[2][2]) {
    // Calcula o determinante
    double det = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

    if (det != 0) {
        printf(NEGRITO "Os vetores formam uma base em R2.\n" SEM_ESTILO);
    } else {
        printf(NEGRITO "Os vetores não formam uma base em R2.\n" SEM_ESTILO);
    }
}

void verificarBases3(double matriz[3][3]) {
    // Calcula o determinante
    double det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
              - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
              + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    if (det != 0) {
        printf(NEGRITO "Os vetores formam uma base em R3.\n" SEM_ESTILO);
    } else {
        printf(NEGRITO "Os vetores não formam uma base em R3.\n" SEM_ESTILO);
    }

    perguntarOpcao();
}

// Função de voltar ao menu ou usar a funcionalidade novamente
void perguntarOpcao() {
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
    if (opcao == 1) mainBases();
}

// Print dos vetores inseridos um abaixo do outro para dimensão 2
void printVetores2(double matriz[2][2]) {
    printf(NEGRITO "Vetores inseridos (R2):\n" SEM_ESTILO);
    for (int i = 0; i < 2; i++) {
        printf("[ ");
        for (int j = 0; j < 2; j++) {
            printf("%6.2lf ", matriz[i][j]);  // exibe cada valor com 2 casas decimais
        }
        printf("]\n");  // fecha a linha de cada vetor
    }
}

// Print dos vetores inseridos um abaixo do outro para dimensão 3
void printVetores3(double matriz[3][3]) {
    printf(NEGRITO "Vetores inseridos (R3):\n" SEM_ESTILO);
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%6.2lf ", matriz[i][j]);
        }
        printf("]\n");
    }
}
