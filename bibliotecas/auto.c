#include "auto.h"
#include "texto.h"



void mainAuto(){
    limparConsole();
    int dim;
    do{
        printf("Escolha a dimensão da matriz (2 ou 3) ou 0 para retornar ao menu: \n");
        scanf("%d", &dim);

        if(dim == 0) return;
        if(dim != 2 && dim != 3) {
            limparConsole();
            printf(VERMELHO NEGRITO "Dimensão deve ser 2 ou 3!\n" SEM_ESTILO);
        }
    } while(dim != 2 && dim != 3);

    limparConsole();

    if(dim == 2) autovaloresAutovetores2();
    else if(dim == 3) autovaloresAutovetores3();
}

void autovaloresAutovetores2() {
    double matriz[2][2];

    printf(NEGRITO "Digite os elementos da matriz 2x2, linha por linha:\n" SEM_ESTILO);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    limparConsole();

    printMatriz2(matriz);
    calcularAutovalores2(matriz);
    
    retornarOuRefazer();
}

void autovaloresAutovetores3() {
    double matriz[3][3];

    printf(NEGRITO "Digite os elementos da matriz 3x3, linha por linha:\n" SEM_ESTILO);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    limparConsole();

    printMatriz3(matriz);
    calcularAutovalores3(matriz);
    
    retornarOuRefazer();
}

void calcularAutovalores2(double matriz[2][2]) {
    // Cálculo do traço e determinante
    double a = matriz[0][0], b = matriz[0][1], c = matriz[1][0], d = matriz[1][1];
    double traco = a + d;
    double determinante = (a * d) - (b * c);

    double discriminante = traco * traco - 4 * determinante;

    if (discriminante < 0) {
        printf(VERMELHO "A matriz não tem autovalores reais.\n" SEM_ESTILO);
        return;
    }

    double lambda1 = (traco + sqrt(discriminante)) / 2;
    double lambda2 = (traco - sqrt(discriminante)) / 2;

    printf(NEGRITO "\nAutovalores:\n" );
    printf("\tλ1 = %.2lf\n", lambda1);
    printf("\tλ2 = %.2lf\n" SEM_ESTILO, lambda2);

    // Cálculo dos autovetores
    printf(NEGRITO "\nAutovetores:\n" SEM_ESTILO);
    if (b != 0) {
        printf("\tAutovetor associado a"NEGRITO" λ1: [1, %.2lf]\n" SEM_ESTILO, (lambda1 - a) / b);
        printf("\tAutovetor associado a"NEGRITO" λ2: [1, %.2lf]\n" SEM_ESTILO, (lambda2 - a) / b);
    } else {
        printf("\tAutovetor associado a" NEGRITO" λ1: [1, 0]\n" SEM_ESTILO);
        printf("\tAutovetor associado a" NEGRITO" λ2: [1, 0]\n" SEM_ESTILO);
    }
}

void calcularAutovalores3(double matriz[3][3]) {
    printf("Cálculo de autovalores para matrizes 3x3 ainda não implementado.\n");
}

void retornarOuRefazer(){
    int opcao;
    do{
        printf(NEGRITO "\nVocê deseja repetir o método ou voltar ao menu principal? (Sim = 1 e Não = 0)" SEM_ESTILO);
        scanf("%d", &opcao);

        if(opcao == 0) return;
        if(opcao != 1){
            limparConsole();
            printf(VERMELHO NEGRITO"Opção inválida!\n" SEM_ESTILO);
        }

    } while(opcao != 1 && opcao != 0);
    if(opcao == 1) mainAuto();
}


void printMatriz3(double matriz[3][3]) {
    limparConsole();
    printf(NEGRITO "Matriz inserida: \n" SEM_ESTILO);
    sleep(0.8);
    printf("┌ ");
    for(int i = 0; i < 3; i++) {
        printf("         "); // 9 espaços (8 do número + 1 do espaço)
    }
    printf("   ┐\n"); // 2 espaços extras pelo "| "

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 0) printf("| ");
            // if(j == 3 - 1) printf("    |");
            printf("%8.4lf ", matriz[i][j]);
        }
        printf("   |\n");
    }

    // "Rodapé" da matriz
    printf("└ ");
    for(int i = 0; i < 3; i++) {
        printf("         "); // 9 espaços (8 do número + 1 do espaço)
    }
    printf("   ┘\n"); // 2 espaços extras pelo "| "
    
    sleep(0.8);
}

void printMatriz2(double matriz[2][2]) {
    limparConsole();
    printf(NEGRITO "Matriz inserida: \n" SEM_ESTILO);
    sleep(0.8);
    printf("┌ ");
    for(int i = 0; i < 2; i++) {
        printf("         "); // 9 espaços (8 do número + 1 do espaço)
    }
    printf("   ┐\n"); // 2 espaços extras pelo "| "

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0) printf("| ");
            // if(j == 2 - 1) printf("    |");
            printf("%8.4lf ", matriz[i][j]);
        }
        printf("   |\n");
    }

    // "Rodapé" da matriz
    printf("└ ");
    for(int i = 0; i < 2; i++) {
        printf("         "); // 9 espaços (8 do número + 1 do espaço)
    }
    printf("   ┘\n"); // 2 espaços extras pelo "| "
    
    sleep(0.8);
}