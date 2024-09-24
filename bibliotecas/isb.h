#ifndef ISB_H
#define ISB_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <unistd.h>
#include "texto.h"
#include "gauss.h"


#define MAXIMO_EQUACOES 26
#define MAXIMO_VARIAVEIS 26

void mainISB();
void lerMatriz(int linha, int coluna, double matriz[linha][coluna]);
double determinante(int n, double matriz[n][n]);
int calcularPosto(int linha, int coluna, double matriz[linha][coluna]);

#endif