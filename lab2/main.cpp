#include "lab2.hpp"


int main()
{
  matrix matrix;

  //matrix = data_input(matrix);
  matrix = test_data2(matrix);
  //matrix = seidel_conversion(matrix);
  process(matrix);

  return 0;
}
