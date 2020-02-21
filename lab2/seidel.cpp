#include "lab2.hpp"


matrix seidel_conversion(matrix matrix)
{
  struct matrix transposed;
  struct matrix matrix_temp = matrix;

  transposed.x1 = matrix_temp.x1;
  transposed.y1 = matrix_temp.x2;
  transposed.z1 = matrix_temp.x3;
  transposed.x2 = matrix_temp.y1;
  transposed.y2 = matrix_temp.y2;
  transposed.z2 = matrix_temp.y3;
  transposed.x3 = matrix_temp.z1;
  transposed.y3 = matrix_temp.z2;
  transposed.z3 = matrix_temp.z3;

  matrix.x1 = matrix_temp.x1 * transposed.x1 + matrix_temp.y1 * transposed.x2 + matrix_temp.z1 * transposed.x3;
  matrix.y1 = matrix_temp.x1 * transposed.y1 + matrix_temp.y1 * transposed.y2 + matrix_temp.z1 * transposed.y3;
  matrix.z1 = matrix_temp.x1 * transposed.z1 + matrix_temp.y1 * transposed.z2 + matrix_temp.z1 * transposed.z3;

  matrix.x2 = matrix_temp.x2 * transposed.x1 + matrix_temp.y2 * transposed.x2 + matrix_temp.z2 * transposed.x3;
  matrix.y2 = matrix_temp.x2 * transposed.y1 + matrix_temp.y2 * transposed.y2 + matrix_temp.z2 * transposed.y3;
  matrix.z2 = matrix_temp.x2 * transposed.z1 + matrix_temp.y2 * transposed.z2 + matrix_temp.z2 * transposed.z3;

  matrix.x3 = matrix_temp.x3 * transposed.x1 + matrix_temp.y3 * transposed.x2 + matrix_temp.z3 * transposed.x3;
  matrix.y3 = matrix_temp.x3 * transposed.y1 + matrix_temp.y3 * transposed.y2 + matrix_temp.z3 * transposed.y3;
  matrix.z3 = matrix_temp.x3 * transposed.z1 + matrix_temp.y3 * transposed.z2 + matrix_temp.z3 * transposed.z3;


  matrix.FirstRezult = transposed.x1 * matrix_temp.FirstRezult + transposed.y1 * matrix_temp.SecondRezult
  + transposed.z1 * matrix_temp.ThirdRezult;

  matrix.SecondRezult = transposed.x2 * matrix_temp.FirstRezult + transposed.y2 * matrix_temp.SecondRezult
  + transposed.z2 * matrix_temp.ThirdRezult;

  matrix.ThirdRezult = transposed.x3 * matrix_temp.FirstRezult + transposed.y3 * matrix_temp.SecondRezult
  + transposed.z3 * matrix_temp.ThirdRezult;

  //print_matrix(matrix);

  return matrix;
}
