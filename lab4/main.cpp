#include "interpolation.hpp"

double x = 1;


points test_data(points obj)
{
  obj.k = 1;
  obj.m = 0;

  obj.tPoint = 2;

  // obj.x[0] = 1;
  // obj.x[1] = 3;
  //
  // obj.tPoint = 0.5;


  // obj.x[0] = -2;
  // obj.x[1] = 0;
  // obj.x[2] = 2;
  //
  // obj.tPoint = 0.5;

  if (obj.k == sin(x)) {
    for (int i = 0; i < TOTAL_POINTS; i++)
      obj.Fx[i] = x * sin(obj.x[i]) + obj.m;
    return obj;
  }

  if (obj.k == cos(x)) {
    for (int i = 0; i < TOTAL_POINTS; i++)
      obj.Fx[i] = x * cos(obj.x[i]) + obj.m;
    return obj;
  }

  if (obj.k == tan(x)) {
    for (int i = 0; i < TOTAL_POINTS; i++)
      obj.Fx[i] = x * tan(obj.x[i]) + obj.m;
    return obj;
  }

  if (obj.k == log(x)) {
    for (int i = 0; i < TOTAL_POINTS; i++) {
      if (obj.x[i] <= 0) {
        cout << "incorrect points (log(x), x <= 0)" << endl;
        exit(1);
      }
      obj.Fx[i] = x * log(obj.x[i]) + obj.m;
    }
    return obj;
  }

  for (int i = 0; i < TOTAL_POINTS; i++)
    obj.Fx[i] = pow(obj.tPoint, 3) + 1;

  return obj;
}


int main()
{
  points obj = test_data(obj);
  lagrange_interpolation(obj);

  return 0;
}
