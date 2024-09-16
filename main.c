#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <unistd.h>

// definindo estilos de texto
#define NEGRITO  "\e[1m"
#define APAGADO  "\e[2m"
#define SEM_ESTILO   "\e[m"
#define VERMELHO  "\x1B[31m"

// constantes globais
#define MAXIMO_VARIAVEIS 26
#define MAXIMO_EQUACOES 26
#define VARIAVEIS "xyzwvutsrqponmlkjihgfedcba"

// funções
void eliminacaoGauss();
void limparConsole();
void calcularEliminacaoGauss(int linha, int coluna, double matriz[linha][coluna]);
void imprimirMatrizComoEquacao(int linha, int coluna, double matriz[linha][coluna], int maxI, int maxJ);
int checarSePossivel(int quandidadeEquacoes, int quantidadeVariaveis);
void preencherMatriz(int linha, int coluna, double matriz[linha][coluna]);
void inicializarMatriz(int linha, int coluna, double matriz[linha][coluna]);
void imprimirMatriz(int linha, int coluna, double matriz[linha][coluna]);

int main(){
    limparConsole();
    while(1){
    int opcao;
        printf(NEGRITO "Digite a opção desejada.\n");
        printf(NEGRITO "\t1 - "  "Resolução de Sistemas Lineares. (Eliminação de Gauss)\n" SEM_ESTILO);
        printf(APAGADO "\t2 - "  "Verificação de Injetividade, Sobretividade e Bijetividade. (PARA FAZER)\n" SEM_ESTILO);
        printf(APAGADO "\t3 - "  "Determinação de bases. (PARA FAZER)\n" SEM_ESTILO);
        printf(APAGADO "\t4 - "  "Cálculo de autovalores e autovetores. (PARA FAZER)\n" SEM_ESTILO);
        printf(APAGADO "\t5 - "  "Diagonalização. (PARA FAZER)\n" SEM_ESTILO);

        printf(NEGRITO "\t0 - "  "Sair\n" SEM_ESTILO);

        scanf("%d", &opcao);
        limparConsole();

        switch(opcao){
            case 1:
                eliminacaoGauss();
                break;
            case 0:
                return 0;
            default:
                printf(VERMELHO NEGRITO "%d - Opção inválida e/ou não implementada.\n" SEM_ESTILO, opcao);
        }
    }

    return 0;
}
//funcao para limpar o texto do terminal
void limparConsole(){
    printf("\033[H\033[J");
    fflush(stdout);
}

void eliminacaoGauss(){
    int quantidadeEquacoes, quantidadeVariaveis;
    
    limparConsole();
    printf(NEGRITO "Digite o número de equações e variáveis (Max: %d, %d respectivamente).\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
    scanf("%d %d", &quantidadeEquacoes, &quantidadeVariaveis);

    // garante que o usuário digite um valor valido
    while(quantidadeEquacoes > MAXIMO_EQUACOES || quantidadeVariaveis > MAXIMO_VARIAVEIS){
        limparConsole();
        printf(VERMELHO NEGRITO "O número de equações e variáveis devem ser menores que %d e %d respectivamente.\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
        printf(NEGRITO "Digite o número de equações e variáveis (Max: %d, %d respectivamente).\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
        scanf("%d %d", &quantidadeEquacoes, &quantidadeVariaveis);
    }

    int opcao = checarSePossivel(quantidadeEquacoes, quantidadeVariaveis);

    if(opcao == 1){
        eliminacaoGauss();
        limparConsole();
        return;
    }else if(opcao == 0){
        limparConsole();
        return;
    }

    int linhas = quantidadeEquacoes, colunas = quantidadeVariaveis + 1;

    double matriz[linhas][colunas];

    inicializarMatriz(linhas, colunas, matriz);

    preencherMatriz(linhas, colunas, matriz);

    imprimirMatriz(linhas, colunas, matriz);

    calcularEliminacaoGauss(linhas, colunas, matriz);

    // printar resultado

    // opcao para salvar resultado

    return;
}
//funcao que checa se o sistema é possivel de resolver com a quantidade de variaveis e equacoes compativeis
int checarSePossivel(int quantidadeEquacoes, int quantidadeVariaveis){
    limparConsole();
    int opcao = -1;
    if(quantidadeEquacoes > quantidadeVariaveis){
        printf(NEGRITO "Sistema de equações superdeterminado. Não é possível resolver com este algoritmo.\n" SEM_ESTILO);
        printf("Pressione 1 para inserir novos valores ou 0 para retornar ao menu principal.\n");
        scanf("%d", &opcao);
    }else if (quantidadeEquacoes < quantidadeVariaveis){
        printf(NEGRITO "Sistema de equações indeterminado. Não é possível encontrar um resultado.\n" SEM_ESTILO);
        printf("Pressione 1 para inserir novos valores ou 0 para retornar ao menu principal.\n");
        scanf("%d", &opcao);
    }
    return opcao;
}
//converte o sistema em matriz
void preencherMatriz(int linha, int coluna, double matriz[linha][coluna]){
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            limparConsole();
            if(j == coluna - 1){
                sleep(0.8);
                printf(NEGRITO "Digite o valor do resultado da equacao %d (indicado por parenteses):\n" SEM_ESTILO, i+1);
            }else{
                sleep(0.8);
                printf(NEGRITO "Digite o valor do coeficiente na equacao %d, variavel %c (indicado por parenteses):\n" SEM_ESTILO, i+1, VARIAVEIS[j]);
            }
            imprimirMatrizComoEquacao(linha, coluna, matriz, i, j);
            printf("\n");
            scanf("%lf", &matriz[i][j]);
        }
    }
    imprimirMatrizComoEquacao(linha, coluna, matriz, -1, -1);
}

void calcularEliminacaoGauss(int linha, int coluna, double matriz[linha][coluna]) {
    // criar matriz triangular superior
    // fazer o escalonamento
    // substituicao para resultados
}

void imprimirMatrizComoEquacao(int linha, int coluna, double matriz[linha][coluna], int maxI, int maxJ) {
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {      // se for o simbolo indicando onde esta sendo inserido
            char* simbolo = "       _";        // 7" " para alinhamento

            if(i <= maxI && j <= maxJ){      // se for o simbolo indicando um valor nao inserido
                simbolo = "     (_)";        // 5" " para alinhamento
            }

            if(j == 0){
                if(i == 0) printf("┌ %d - ", i+1);
                else if(i == linha - 1) printf("└ %d - ", i+1);
                else printf("├ %d - ", i+1);
            }
            

            if(matriz[i][j] == HUGE_VAL){   // checa se o valor nao foi inserido ainda
                if(j == coluna - 1){           // se for a colunauna de resultados
                    printf("= %s\n", simbolo);
                }else{                      // se for a colunauna de coeficientes
                    printf("%s%c ", simbolo, VARIAVEIS[j]);
                }
            } else {
                if(j == coluna - 1){           // se for a colunauna de resultados
                    printf("= %8.2lf\n", matriz[i][coluna-1]);
                }else{                      // se for a colunauna de coeficientes
                    printf("%8.2lf%c ", matriz[i][j], VARIAVEIS[j]);
                }
            }
        }
    }
}

void imprimirMatriz(int linha, int coluna, double matriz[linha][coluna]) {

    // "Cabecalho" da matriz
    limparConsole();
    sleep(0.8);
    printf("A matriz gerada com os coeficientes é:\n");
    printf("┌ ");
    for(int i = 0; i < coluna; i++) {
        printf("         ");        // 9 espacos (8 do numero + 1 do espaco)
    }
    printf("   ┐\n");               // 2 espacos extras pelo "| "

    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            if(j == 0 || j == coluna - 1) printf("| ");
            printf("%8.2lf ", matriz[i][j]);
        }
        printf(" |\n");
    }

    // "Rodape" da matriz
    printf("└ ");
    for(int i = 0; i < coluna; i++) {
        printf("         ");        // 9 espacos (8 do numero + 1 do espaco)
    }
    printf("   ┘\n");               // 2 espacos extras pelo "| "
    
}

void inicializarMatriz(int linha, int coluna, double matriz[linha][coluna]){
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            matriz[i][j] = HUGE_VAL;    // valor extremamente alto para indicar que nao foi preenchido
        }
    }
}
