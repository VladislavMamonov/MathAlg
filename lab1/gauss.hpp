#pragma once
#include <iostream>
#include <limits>
//#include <math.h>

using namespace std;


struct matrix
{
  double x1, x2, x3, Xrezult;
  double y1, y2, y3, Yrezult;
  double z1, z2, z3, Zrezult;
};

matrix data_input(matrix matrix);
void process(matrix matrix);

int IsSteppedView(matrix matrix);   //Проверка на ступенчатый вид
matrix str_swap(matrix matrix, int dest);   //свап 1 и N строки
void print_matrix(matrix matrix);
void equation_solve(matrix matrix);     //решение СЛАУ
