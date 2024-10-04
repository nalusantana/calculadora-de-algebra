#include "gauss.h"
#include "arquivo.h"
// aqui e a funcao principal que puxa as outras
void eliminacaoGauss() {
    int quantidadeEquacoes, quantidadeVariaveis, sn, opcao;
    int linhas, colunas;
    limparConsole();

    // Perguntar se vai ler o arquivo ou digitar na mão
    printf("Você deseja:\n");
    printf("1. Inserir a matriz manualmente\n");
    printf("2. Ler a matriz de um arquivo\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    // Lógica para ler do arquivo
    if (opcao == 2) {
        // Código para ler o arquivo
        char nomeArquivo[100];
        printf("Digite o nome do arquivo (incluindo a extensão .txt): ");
        scanf("%s", nomeArquivo);
        
        leDimensoes(&quantidadeEquacoes, &quantidadeVariaveis, nomeArquivo);
        linhas = quantidadeEquacoes;
        colunas = quantidadeVariaveis;
        quantidadeVariaveis -= 1;

        int possivel = checarSePossivel(quantidadeEquacoes, quantidadeVariaveis);

        if (possivel == 1) {
            eliminacaoGauss();
            limparConsole();
            return;
        } else if (possivel == 0) {
            limparConsole();
            return;
        }

        double matriz[linhas][colunas];
        double matrizOriginal[linhas][colunas];
        
        leMatriz(linhas, colunas, matriz, nomeArquivo);

        copiarMatrizOriginal(linhas, colunas, matrizOriginal, matriz);

        calcularEliminacaoGauss(linhas, colunas, matriz);

        imprimirMatriz(linhas, colunas, matriz);

        printf(NEGRITO "Esta é sua forma seguindo Gauss-Jordan!\n" SEM_ESTILO);
        if (verificarInconsistencia(linhas, colunas, matriz)) {
            printf(NEGRITO VERMELHO "Sistema sem solução!" SEM_ESTILO);
        } else {
            printVariaveis(linhas, colunas, matriz);
        }
        // Perguntar se deseja salvar a matriz original em um arquivo
        printf("Você deseja salvar a matriz original em um arquivo? (1 = Sim, 0 = Não): ");
        scanf("%d", &sn);
        if (sn == 1) {
            char nomeArquivoSalvar[100];
            printf("Digite o nome do arquivo para salvar (incluindo a extensão .txt): ");
            scanf("%s", nomeArquivoSalvar);
            
            // Salvar a matriz original no arquivo
            salvaMatriz(linhas, colunas, matrizOriginal, nomeArquivoSalvar); 
        }
        int temporario;
        while (temporario != 1 && temporario != 0) {
            printf("\n(Pressione 1 para utilizar a funcionalidade novamente ou 0 para retornar ao menu.)\n");
            scanf("%d", &temporario);
            if (temporario == 1) {
                eliminacaoGauss();
            } else if (temporario == 0) {
                return;
            } else {
                printf(VERMELHO NEGRITO "Opção inválida!\n\n" SEM_ESTILO);
            }
        }
    } else if (opcao == 1) {
        // Lógica para digitar na mão
        printf(NEGRITO "Digite o número de equações e variáveis (Max: %d, %d respectivamente).\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
        scanf("%d %d", &quantidadeEquacoes, &quantidadeVariaveis);

        // garante que o usuário digite um valor válido
        while (quantidadeEquacoes > MAXIMO_EQUACOES || quantidadeVariaveis > MAXIMO_VARIAVEIS) {
            limparConsole();
            printf(VERMELHO NEGRITO "O número de equações e variáveis devem ser menores que %d e %d respectivamente.\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
            printf(NEGRITO "Digite o número de equações e variáveis (Max: %d, %d respectivamente).\n" SEM_ESTILO, MAXIMO_EQUACOES, MAXIMO_VARIAVEIS);
            scanf("%d %d", &quantidadeEquacoes, &quantidadeVariaveis);
        }

        int possivel = checarSePossivel(quantidadeEquacoes, quantidadeVariaveis);

        if (possivel == 1) {
            eliminacaoGauss();
            limparConsole();
            return;
        } else if (possivel == 0) {
            limparConsole();
            return;
        }

        linhas = quantidadeEquacoes;
        colunas = quantidadeVariaveis + 1;

        double matriz[linhas][colunas];
        double matrizOriginal[linhas][colunas];

        inicializarMatriz(linhas, colunas, matriz);

        preencherMatriz(linhas, colunas, matriz);

        copiarMatrizOriginal(linhas, colunas, matrizOriginal, matriz);

        while (sn != 2) {
        printf("Deseja inserir os valores novamente?\n(Pressione 1 para inserir novos valores ou 2 para ir para a próxima etapa.)\n");
        scanf("%d", &sn);
        if (sn == 1) {
            inicializarMatriz(linhas, colunas, matriz);
            preencherMatriz(linhas, colunas, matriz);
            copiarMatrizOriginal(linhas, colunas, matrizOriginal, matriz);
            printf("A matriz gerada com os coeficientes é:\n");
            imprimirMatriz(linhas, colunas, matriz);
        }
        if (sn == 2) {
            calcularEliminacaoGauss(linhas, colunas, matriz);
            imprimirMatriz(linhas, colunas, matriz);
            printf(NEGRITO "Esta é sua forma seguindo Gauss-Jordan!\n" SEM_ESTILO);
            if (verificarInconsistencia(linhas, colunas, matriz)) {
                printf(NEGRITO VERMELHO "Sistema sem solução!" SEM_ESTILO);
            } else {
                printVariaveis(linhas, colunas, matriz);
            }
            // Perguntar se deseja salvar a matriz original em um arquivo
            printf("Você deseja salvar a matriz original em um arquivo? (1 = Sim, 0 = Não): ");
            scanf("%d", &sn);
            if (sn == 1) {
                char nomeArquivoSalvar[100];
                printf("Digite o nome do arquivo para salvar (incluindo a extensão .txt): ");
                scanf("%s", nomeArquivoSalvar);
                
                // Salvar a matriz original no arquivo
                salvaMatriz(linhas, colunas, matrizOriginal, nomeArquivoSalvar); 
            }
            int temporario;
            while (temporario != 1 && temporario != 0) {
                printf("\n(Pressione 1 para utilizar a funcionalidade novamente ou 0 para retornar ao menu.)\n");
                scanf("%d", &temporario);
                if (temporario == 1) {
                    eliminacaoGauss();
                } else if (temporario == 0) {
                    return;
                } else {
                    printf(VERMELHO NEGRITO "Opção inválida!\n\n" SEM_ESTILO);
                }
            }
        }
        if (sn != 1 && sn != 2) {
            limparConsole();
            printf(VERMELHO NEGRITO "Opção inválida!\n\n" SEM_ESTILO);
        }
        }
    } else {
        printf(VERMELHO "Opção inválida!\n" SEM_ESTILO);
        return;
    }


    

    

    return;
}

// função que checa se o sistema é possível de resolver com a quantidade de variáveis e equações compatíveis
int checarSePossivel(int quantidadeEquacoes, int quantidadeVariaveis) {
    limparConsole();
    int opcao = -1;
    if (quantidadeEquacoes > quantidadeVariaveis) {
        printf(NEGRITO "Sistema de equações superdeterminado. Não é possível resolver com este algoritmo.\n" SEM_ESTILO);
        printf("Pressione 1 para inserir novos valores ou 0 para retornar ao menu principal.\n");
        scanf("%d", &opcao);
    } else if (quantidadeEquacoes < quantidadeVariaveis) {
        printf(NEGRITO "Sistema de equações indeterminado. Não é possível encontrar um resultado.\n" SEM_ESTILO);
        printf("Pressione 1 para inserir novos valores ou 0 para retornar ao menu principal.\n");
        scanf("%d", &opcao);
    }
    return opcao;
}

// verifica se o sistema foi realmente resolvido, se tiver uma linha com todos os elementos sendo 0, e um sistema inconsistente
int verificarInconsistencia(int linha, int coluna, double matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        int todos_zeros = 1;
        for (int j = 0; j < linha; j++) {
            if (matriz[i][j] != 0) {
                todos_zeros = 0; 
                break;
            }
        }
        // se todos os coeficientes forem zero, mas o termo constante for diferente de zero
        if (todos_zeros && matriz[i][linha] != 0) {
            return 1;  // sistema inconsistente
        }
    }
    return 0;  // sistema pode ter solução
}

// print final do resultado
void printVariaveis(int linha, int coluna, double matriz[linha][coluna]) {
    printf("Soluções para as variáveis:\n");
    for (int i = 0; i < linha; i++) {
        printf("%c = %.2f\n", VARIAVEIS[i], matriz[i][linha]); 
    }
}

// converte o sistema em matriz
void preencherMatriz(int linha, int coluna, double matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            limparConsole();
            if (j == coluna - 1) {
                sleep(0.8);
                printf(NEGRITO "Digite o valor do resultado da equação %d (indicado por parênteses):\n" SEM_ESTILO, i + 1);
            } else {
                sleep(0.8);
                printf(NEGRITO "Digite o valor do coeficiente na equação %d, variável %c (indicado por parênteses):\n" SEM_ESTILO, i + 1, VARIAVEIS[j]);
            }
            imprimirMatrizComoEquacao(linha, coluna, matriz, i, j);
            printf("\n");
            scanf("%lf", &matriz[i][j]);
        }
    }
    imprimirMatrizComoEquacao(linha, coluna, matriz, -1, -1);
}

// aqui apenas aplica o teorema, zera os valores abaixo da diagonal principal, define a diagonal principal com todos os valores igual a 1 e zera os valores acima da diagonal principal
void calcularEliminacaoGauss(int linha, int coluna, double matriz[linha][coluna]) {
    limparConsole();
    for (int i = 0; i < linha; i++) {
        if (matriz[i][i] == 0) {
            for (int k = i + 1; k < linha; k++) {
                if (matriz[k][i] != 0) {
                    for (int j = 0; j < coluna; j++) {
                        float temp = matriz[i][j];
                        matriz[i][j] = matriz[k][j];
                        matriz[k][j] = temp;
                    }
                    break;
                }
            }
        }
        float pivo = matriz[i][i];
        if (pivo != 0) {
            for (int j = 0; j < coluna; j++) {
                matriz[i][j] /= pivo;
            }
        }
        for (int k = i + 1; k < linha; k++) {
            float fator = matriz[k][i];
            for (int j = 0; j < coluna; j++) {
                matriz[k][j] -= fator * matriz[i][j];
            }
        }
        for (int k = i - 1; k >= 0; k--) {
            float fator = matriz[k][i];
            for (int j = 0; j < coluna; j++) {
                matriz[k][j] -= fator * matriz[i][j];
            }
        }
    }

    return;
}

// apenas para formatar como sistema de equação para ficar mais agradável ao usuário
void imprimirMatrizComoEquacao(int linha, int coluna, double matriz[linha][coluna], int maxI, int maxJ) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {      // se for o símbolo indicando onde está sendo inserido
            char* simbolo = "       _";        // 7" " para alinhamento

            if (i <= maxI && j <= maxJ) {      // se for o símbolo indicando um valor não inserido
                simbolo = "     (_)";        // 5" " para alinhamento
            }

            if (j == 0) {
                if (i == 0) printf("┌ %d - ", i + 1);
                else if (i == linha - 1) printf("└ %d - ", i + 1);
                else printf("├ %d - ", i + 1);
            }

            if (matriz[i][j] == HUGE_VAL) {   // checa se o valor não foi inserido ainda
                if (j == coluna - 1) {           // se for a coluna de resultados
                    printf("= %s\n", simbolo);
                } else {                      // se for a coluna de coeficientes
                    printf("%s%c ", simbolo, VARIAVEIS[j]);
                }
            } else {
                if (j == coluna - 1) {           // se for a coluna de resultados
                    printf("= %8.2lf\n", matriz[i][coluna - 1]);
                } else {                      // se for a coluna de coeficientes
                    printf("%8.2lf%c ", matriz[i][j], VARIAVEIS[j]);
                }
            }
        }
    }
}

// essa só mostra como ficou a matriz com os inputs do usuário, de forma mais agradável
void imprimirMatriz(int linha, int coluna, double matriz[linha][coluna]) {

    // "cabeçalho" da matriz
    limparConsole();
    sleep(0.8);
    printf("┌ ");
    for (int i = 0; i < coluna; i++) {
        printf("         ");        // 9 espaços (8 do número + 1 do espaço)
    }
    printf("   ┐\n");               // 2 espaços extras pelo "| "

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (j == 0 || j == coluna - 1) printf("| ");
            printf("%8.2lf ", matriz[i][j]);
        }
        printf(" |\n");
    }

    // "rodapé" da matriz
    printf("└ ");
    for (int i = 0; i < coluna; i++) {
        printf("         ");        // 9 espaços (8 do número + 1 do espaço)
    }
    printf("   ┘\n");               // 2 espaços extras pelo "| "
    
    sleep(0.8);
}

// coloca valor extremamente alto para indicar que não foi preenchido
void inicializarMatriz(int linha, int coluna, double matriz[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            matriz[i][j] = HUGE_VAL;    
        }
    }
}

void copiarMatrizOriginal(int linhas, int colunas, double copia[linhas][colunas], double original[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            copia[i][j] = original[i][j];
        }
    }
}