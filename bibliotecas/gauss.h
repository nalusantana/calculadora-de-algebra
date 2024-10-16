//biblioteca para aa primeira funcionalidade

#ifndef GAUSS_H
#define GAUSS_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <unistd.h>
#include "texto.h"


#define MAXIMO_EQUACOES 26
#define MAXIMO_VARIAVEIS 26



void eliminacaoGauss();
int checarSePossivel(int quantidadeEquacoes, int quantidadeVariaveis);
int verificarInconsistencia(int linha, int coluna, double matriz[linha][coluna]);
void printVariaveis(int linha, int coluna, double matriz[linha][coluna]);
void preencherMatriz(int linha, int coluna, double matriz[linha][coluna]);
void calcularEliminacaoGauss(int linha, int coluna, double matriz[linha][coluna]);
void imprimirMatrizComoEquacao(int linha, int coluna, double matriz[linha][coluna], int maxI, int maxJ);
void imprimirMatriz(int linha, int coluna, double matriz[linha][coluna]);
void inicializarMatriz(int linha, int coluna, double matriz[linha][coluna]);
void copiarMatrizOriginal(int linhas, int colunas, double copia[linhas][colunas], double original[linhas][colunas]);

#endif 