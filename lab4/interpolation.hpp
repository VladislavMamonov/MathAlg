#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

#define TOTAL_POINTS 1


struct points
{
  double x[TOTAL_POINTS], Fx[TOTAL_POINTS];
  double tPoint;
  double k, m;
};


void lagrange_interpolation(points obj);
void newton_interpolation(points obj);
int input_check(points obj);
