#include "lab3.hpp"


int check_data(equation obj)
{
  double Fa = obj.x1 * pow(obj.a, obj.x1Degree) + obj.x2 * pow(obj.a, obj.x2Degree) + obj.Const;
  double Fb = obj.x1 * pow(obj.b, obj.x1Degree) + obj.x2 * pow(obj.b, obj.x2Degree) + obj.Const;

  if (Fa * Fb > 0)
    return 1;

  return 0;
}


equation test_data(equation obj)
{
  obj.x1Degree = 2;
  obj.x2Degree = 1;
  obj.x1 = 1, obj.x2 = -1, obj.Const = -4;
  obj.a = 2, obj.b = 3;

  // obj.x1Degree = 2;
  // obj.x2Degree = 1;
  // obj.x1 = 5, obj.x2 = -4, obj.Const = 1;
  // obj.a = 0, obj.b = 10;

  // obj.x1Degree = 2;
  // obj.x2Degree = 1;
  // obj.x1 = 1, obj.x2 = 12, obj.Const = 8;
  // obj.a = -5, obj.b = 5;


  return obj;
}


int main()
{
  equation obj;

  obj = test_data(obj);
  bisection_process(obj);
}
