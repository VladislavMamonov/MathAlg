#pragma once
#include <iostream>
#include <cmath>


using namespace std;


#define TOTAL_POINTS 3


struct points
{
  double x[TOTAL_POINTS], Fx[TOTAL_POINTS];
  double tPoint;
};


void lagrange_interpolation(points obj);
void newton_interpolation(points obj);
int input_check(points obj);
