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
            printf(VERMELHO NEGRITO "A dimensão deve ser 2 ou 3!\n" SEM_ESTILO);
        }
    } while(dim != 2 && dim != 3);

    limparConsole();

    if(dim == 2) autovaloresAutovetores2();
    else if(dim == 3) autovaloresAutovetores3();
}

//funcao que calcula autovetores dimensao 2
void autovaloresAutovetores2() {
    double matriz[2][2];

    printf(NEGRITO "Digite os vetores que formam a matriz 2x2, linha por linha:\n" SEM_ESTILO);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    limparConsole();

    printf(NEGRITO "Matriz inserida: \n" SEM_ESTILO);
    //print unico para matriz 2x2 sem bugar as laterais que desenhei
    printMatriz2(matriz);

    double autovalores[2];

    //calculo dos autovalores na dimensao 2 > valores sao guardados dentro do vetor "autovalores"
    calcularAutovalores2(matriz, autovalores);

    double lambda1 = autovalores[0], lambda2 = autovalores[1];

    printf(NEGRITO "\nAutovalores:\n" );
    printf("\tλ1 = %.2lf\n", lambda1);
    printf("\tλ2 = %.2lf\n" SEM_ESTILO, lambda2);

    //calculo dos autovetores
    printf(NEGRITO "\nAutovetores:\n" SEM_ESTILO);
    if (matriz[0][1] != 0) {
        printf("\tAutovetor associado a"NEGRITO" λ1: [1, %.2lf]\n" SEM_ESTILO, (lambda1 - matriz[0][0]) / matriz[0][1]);
        printf("\tAutovetor associado a"NEGRITO" λ2: [1, %.2lf]\n" SEM_ESTILO, (lambda2 - matriz[0][0]) / matriz[0][1]);
    } else {
        printf("\tAutovetor associado a" NEGRITO" λ1: [1, 0]\n" SEM_ESTILO);
        printf("\tAutovetor associado a" NEGRITO" λ2: [1, 0]\n" SEM_ESTILO);
    }
    
    retornarOuRefazer();
}

//funcao que calcula autovetores dimensao 3
void autovaloresAutovetores3() {
    double matriz[3][3];

    printf(NEGRITO "Digite os elementos da matriz 3x3, linha por linha:\n" SEM_ESTILO);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    limparConsole();

    printf(NEGRITO "Matriz inserida: \n" SEM_ESTILO);
    //print matriz 3x3
    printMatriz3(matriz);
    //calculo dos autovalores na dimensao 3 > valores sao guardados dentro do vetor "autovalores"
    calcularAutovalores3(matriz);
    
    retornarOuRefazer();
}

void calcularAutovalores2(double matriz[2][2], double autovalores[2]) {
    //calculo do traco e determinante
    double a = matriz[0][0], b = matriz[0][1], c = matriz[1][0], d = matriz[1][1];
    double traco = a + d;
    double determinante = (a * d) - (b * c);

    double discriminante = traco * traco - 4 * determinante;

    if (discriminante < 0) {
        printf(VERMELHO "A matriz não tem autovalores reais.\n" SEM_ESTILO);
        return;
    }

    autovalores[0] = (traco + sqrt(discriminante)) / 2;
    autovalores[1] = (traco - sqrt(discriminante)) / 2;
    
}

//infelizmente nao esta funcionando, decidi focar em manipulacao de arquivos
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

//funciona mas precisa da anterior, e o print padrao que estamos usando no codigo todo sempre que usamos matrizes
void printMatriz3(double matriz[3][3]) {
    limparConsole();
    sleep(0.8);
    printf("┌ ");
    for(int i = 0; i < 3; i++) {
        printf("         "); 
    }
    printf("   ┐\n"); 

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 0) printf("| ");
            printf("%8.4lf ", matriz[i][j]);
        }
        printf("   |\n");
    }

    printf("└ ");
    for(int i = 0; i < 3; i++) {
        printf("         ");
    }
    printf("   ┘\n");
    
    sleep(0.8);
}

//print padrao da matriz quadrada dimensao 2
void printMatriz2(double matriz[2][2]) {
    sleep(0.8);
    printf("┌ ");
    for(int i = 0; i < 2; i++) {
        printf("         "); 
    }
    printf("   ┐\n"); 
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0) printf("| ");
            printf("%8.4lf ", matriz[i][j]);
        }
        printf("   |\n");
    }

    printf("└ ");
    for(int i = 0; i < 2; i++) {
        printf("         ");
    }
    printf("   ┘\n");
    
    sleep(0.8);
}