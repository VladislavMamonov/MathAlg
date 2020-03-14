#pragma once
#include <iostream>
#include <cmath>

using namespace std;


struct equation
{
  double x1, x2, Const;
  double x1Degree, x2Degree;
  double a, b;
};


equation test_data(equation obj);
void bisection_process(equation obj);
void chord_process(equation obj);
int check_data(equation obj);
