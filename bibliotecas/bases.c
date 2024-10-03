#include "bases.h"
#include "texto.h"


void mainBases(){
    limparConsole();
    int dim;
    do{
        printf("Escolha a dimensão do espaço vetorial (2 ou 3) ou 0 para retornar ao menu: \n");
        scanf("%d", &dim);

        if(dim == 0) return;
        if(dim != 2 && dim != 3) {
            limparConsole();
            printf(VERMELHO NEGRITO "Dimensão deve ser 2 ou 3!\n" SEM_ESTILO);
        }
    }while(dim != 2 && dim != 3);
    limparConsole();


    if(dim == 2) bases2();
    else if(dim == 3) bases3();
}

void bases2() {
    float matriz[2][2];

    printf(NEGRITO "Digite os elementos dos vetores 2D, um vetor por vez (linhas):\n" SEM_ESTILO);
    for (int i = 0; i < 2; i++) {
        printf("Digite os elementos do vetor %d:\n", i + 1);
        for (int j = 0; j < 2; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    float det = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

    printVetores2(matriz);

    if (det != 0) {
        printf( NEGRITO "Os vetores formam uma base em R2.\n" SEM_ESTILO);
    } else {
        printf( NEGRITO "Os vetores não formam uma base em R2.\n" SEM_ESTILO);
    }

    perguntarOpcao();
}

void bases3() {
    float matriz[3][3];

    printf(NEGRITO "Digite os elementos dos vetores 3D, um vetor por vez (linhas):\n" SEM_ESTILO);
    for (int i = 0; i < 3; i++) {
        printf("Digite os elementos do vetor %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    float det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
              - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
              + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    printVetores3(matriz);

    if (det != 0) {
        printf( NEGRITO "Os vetores formam uma base em R3.\n" SEM_ESTILO);
    } else {
        printf( NEGRITO "Os vetores não formam uma base em R3.\n" SEM_ESTILO);
    }

    perguntarOpcao();
}

void perguntarOpcao(){
    int opcao;
    do{
        printf(NEGRITO "Voce deseja repetir o metodo (1) ou voltar ao menu principal (0)?" SEM_ESTILO);
        scanf("%d", &opcao);

        if(opcao == 0) return;
        if(opcao != 1){
            limparConsole();
            printf(VERMELHO NEGRITO"Opção inválida!\n" SEM_ESTILO);
        }

    }while(opcao != 1 && opcao != 0);
    if(opcao == 1) mainBases();
}

void printVetores2(float matriz[2][2]) {
    printf(NEGRITO "Vetores inseridos (R2):\n" SEM_ESTILO);
    for (int i = 0; i < 2; i++) {
        printf("[ ");
        for (int j = 0; j < 2; j++) {
            printf("%6.2f ", matriz[i][j]);  // Exibe cada valor com 2 casas decimais
        }
        printf("]\n");  // Fecha a linha de cada vetor
    }
}

void printVetores3(float matriz[3][3]) {
    printf(NEGRITO "Vetores inseridos (R3):\n" SEM_ESTILO);
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%6.2f ", matriz[i][j]);  
        }
        printf("]\n");  
    }
}