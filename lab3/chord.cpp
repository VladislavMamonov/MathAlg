#include "lab3.hpp"


void chord_process(equation obj)
{
  if (check_data(obj) == 1) {
    cout << "Wrong interval" << endl;
    return;
  }

  double eps = 1000;
  double c;

  int iteration = 0;

  while (abs(eps) > 0.01)
  {
    double Fa = obj.x1 * pow(obj.a, obj.x1Degree) + obj.x2 * pow(obj.a, obj.x2Degree) + obj.Const;
    double Fb = obj.x1 * pow(obj.b, obj.x1Degree) + obj.x2 * pow(obj.b, obj.x2Degree) + obj.Const;

    c = obj.a - Fa / (Fb - Fa) * (obj.b - obj.a);

    double Fc = obj.x1 * pow(c, obj.x1Degree) + obj.x2 * pow(c, obj.x2Degree) + obj.Const;

    double a_c = Fa * Fc;
    double c_b = Fc * Fb;

    if (a_c < 0) obj.b = c;
    else if (c_b < 0) obj.a = c;

    eps = Fc;

    iteration++;
    cout << "c = " << c << endl;
  }

  cout << endl << "Answer: " << c << endl;
  cout << "Iteration count: " << iteration << endl;
}
