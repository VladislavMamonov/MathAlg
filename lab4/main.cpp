#include "interpolation.hpp"


points test_data(points obj)
{
  // obj.x[0] = -1.5;
  // obj.x[1] = -0.75;
  // obj.x[2] = 0;
  // obj.x[3] = 0.75;
  // obj.x[4] = 1.5;
  //
  // obj.Fx[0] = -14.1014;
  // obj.Fx[1] = -0.931596;
  // obj.Fx[2] = 0;
  // obj.Fx[3] = 0.931596;
  // obj.Fx[4] = 14.1014;
  //
  // obj.tPoint = 0.5;


  // obj.x[0] = 1;
  // obj.x[1] = 5;
  //
  // obj.Fx[0] = 3;
  // obj.Fx[1] = 6;
  //
  // obj.tPoint = 3;


  obj.x[0] = -2;
  obj.x[1] = 0;
  obj.x[2] = 2;

  obj.Fx[0] = 10;
  obj.Fx[1] = 0;
  obj.Fx[2] = 7;

  obj.tPoint = 1.5;

  return obj;
}


int main()
{
  points obj = test_data(obj);
  newton_interpolation(obj);

  return 0;
}
