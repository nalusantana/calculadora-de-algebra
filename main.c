#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <unistd.h>
#include "bibliotecas/gauss.h"
#include "bibliotecas/texto.h"
#include "bibliotecas/isb.h"


int main(){
    limparConsole();
    while(1){
        int opcao;
        printf(NEGRITO "Digite a opção desejada.\n");
        printf(NEGRITO "\t1 - "  "Resolução de Sistemas Lineares. (Eliminação de Gauss)\n" SEM_ESTILO);
        printf(NEGRITO "\t2 - "  "Verificação de Injetividade, Sobretividade e Bijetividade.\n" SEM_ESTILO);
        printf(APAGADO "\t3 - "  "Determinação de bases. (PARA FAZER)\n" SEM_ESTILO);
        printf(APAGADO "\t4 - "  "Cálculo de autovalores e autovetores. (PARA FAZER)\n" SEM_ESTILO);
        printf(APAGADO "\t5 - "  "Diagonalização. (PARA FAZER)\n" SEM_ESTILO);

        printf(NEGRITO "\t0 - "  "Sair\n" SEM_ESTILO);

        scanf("%d", &opcao);
        limparConsole();

        switch(opcao){
            case 1:
                eliminacaoGauss();
                limparConsole();
                break;
            case 2:
                mainISB();
                limparConsole();
                break;
            case 0:
                return 0;
            default:
                printf(VERMELHO NEGRITO "%d - Opção inválida e/ou não implementada.\n" SEM_ESTILO, opcao);
        }
    }

    return 0;
}
