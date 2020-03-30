#pragma once
#include <iostream>
#include <limits>
#include <cmath>
#include <unistd.h>

using namespace std;


struct matrix
{
  double x1, y1, z1, FirstRezult;
  double x2, y2, z2, SecondRezult;
  double x3, y3, z3, ThirdRezult;
};

matrix data_input(matrix matrix);
int check_data(matrix matrix);
void print_matrix(matrix matrix);

matrix test_data1(matrix matrix);
matrix test_data2(matrix matrix);
matrix test_data3(matrix matrix);
matrix test_data4(matrix matrix);

void process(matrix matrix);
double rounding(double x);
