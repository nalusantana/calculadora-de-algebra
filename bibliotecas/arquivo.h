//biblioteca de arquivo

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <unistd.h>
#include <string.h>
#include "texto.h"
void salvaMatriz(int linhas, int colunas, double matriz[linhas][colunas], const char* nomeArquivo);
void leMatriz(int linhas, int colunas, double matriz[linhas][colunas], const char* nomeArquivo);
void leDimensoes(int* linhas, int* colunas, const char* nomeArquivo);

#endif 