#include "interpolation.hpp"


int input_check(points obj)
{
  double h = obj.x[1] - obj.x[0];

  for (int i = 1; i < TOTAL_POINTS; i++) {
    if (obj.x[i] - obj.x[i - 1] != h)
      return 1;
  }
  return 0;
}


void lagrange_interpolation(points obj)
{
  double Lx;
  double l[TOTAL_POINTS];
  double x = obj.tPoint;

  for (int i = 0; i < TOTAL_POINTS; i++)
  {
    double l_part[TOTAL_POINTS];

    for (int j = 0; j < TOTAL_POINTS; j++) {
      if (j == i) { l_part[j] = 1; continue; }
      if (obj.x[i] - obj.x[j] == 0) {
        cout << "incorrect points" << endl;
        return;
      }
      l_part[j] = (x - obj.x[j]) / (obj.x[i] - obj.x[j]);
    }

    l[i] = 1;

    for (int k = 0; k < TOTAL_POINTS; k++) {
      l[i] *= l_part[k];
    }
  }

  for (int i = 0; i < TOTAL_POINTS; i++) {
    Lx += l[i] * obj.Fx[i];
  }

  cout << "Answer: " << Lx << endl;
}


void newton_interpolation(points obj)
{
  if (input_check(obj) == 1) {
    cout << "nodes are not equally spaced" << endl;
    return;
  }

  double Lx;
  int total_l = 0;
  int l_checkpoint[TOTAL_POINTS - 1];

  for (int i = 1, j = 0; i < TOTAL_POINTS; i++, j++) {
    total_l += TOTAL_POINTS - i;
    l_checkpoint[j] = total_l;
  }

  double l[total_l];
  double x = obj.tPoint;

  int i;

  for (i = 0; i < l_checkpoint[0]; i++) {
    if (obj.x[i + 1] - obj.x[i] == 0) {
      cout << "incorrect points" << endl;
      return;
    }
    l[i] = (obj.Fx[i + 1] - obj.Fx[i]) / (obj.x[i + 1] - obj.x[i]);
  }

  for (int j = i, k = 0, t = 2, p = 1; j < total_l; j++, k++) {
    if (obj.x[k + t] - obj.x[k]) {
      cout << "incorrect points" << endl;
      return;
    }
    if (j == l_checkpoint[p]) t++, p++, k = 0;
    l[j] = (l[k + 1] - l[k]) / (obj.x[k + t] - obj.x[k]);
  }

  Lx = obj.Fx[0];
  double Lx_temp;
  double Lx_part[TOTAL_POINTS - 1];
  for (int i = 0; i < TOTAL_POINTS - 1; i++) Lx_part[i] = 1;

  for (int i = 0; i < TOTAL_POINTS - 1; i++)
  {
    Lx_temp = 1;
    for (int j = 0; j <= i; j++) {
      Lx_part[j] = x - obj.x[j];
    }
    if (i == 0) {
      for (int i = 0; i < TOTAL_POINTS - 1; i++)
        Lx_temp *= Lx_part[i];
      Lx += l[i] * Lx_temp;
      continue;
    }
    for (int i = 0; i < TOTAL_POINTS - 1; i++)
      Lx_temp *= Lx_part[i];
    Lx += l[l_checkpoint[i - 1]] * Lx_temp;
  }
  cout << "Answer: " << Lx << endl;
}
