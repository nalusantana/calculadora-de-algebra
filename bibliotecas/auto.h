#ifndef AUTO_H
#define AUTO_H

//include de bibliotecas necessarias e a texto.h criada
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <unistd.h>
#include "texto.h"


void mainAuto();
void autovaloresAutovetores2();
void autovaloresAutovetores3();
void calcularAutovalores2(double matriz[2][2], double* autovalores);
void calcularAutovalores3(double matriz[3][3]);
void retornarOuRefazer();
void printMatriz2(double matriz[2][2]);
void printMatriz3(double matriz[3][3]);

#endif 