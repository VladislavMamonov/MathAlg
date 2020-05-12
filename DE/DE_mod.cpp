#include "DE_mod.hpp"


double f(double x, double y)
{
  return x * x + y * y;
}


int DE_Euler_mod()
{
  double x = 0, y = 0, h = 0.5;
  int iteration_amount = 1 / h;

  for (int i = 0; i < iteration_amount; i++) {
    double x0 = x + h / 2;
    double y0 = y + (h / 2) * f(x, y);
    double dy = h * f(x0, y0);

    y += dy;
    x += h;

    cout << "i = " << i << ": x = " << x;
    cout << "; y = " << y << endl;
  }

  cout << "\n\n" << "Result: " << "x = " << x;
  cout << "; " << "y = " << y << endl;

  return 0;
}
