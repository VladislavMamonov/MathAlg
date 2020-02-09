#include "gauss.hpp"


matrix data_input(matrix matrix)
{
  cout << "x1 value: ";
  cin >> matrix.x1;

  cout << "x2 value: ";
  cin >> matrix.x2;

  cout << "x3 value: ";
  cin >> matrix.x3;

  cout << "First equation result: ";
  cin >> matrix.Xrezult;

  cout << "y1 value: ";
  cin >> matrix.y1;

  cout << "y2 value: ";
  cin >> matrix.y2;

  cout << "y3 value: ";
  cin >> matrix.y3;

  cout << "Second equation result: ";
  cin >> matrix.Yrezult;

  cout << "z1 value: ";
  cin >> matrix.z1;

  cout << "z2 value: ";
  cin >> matrix.z2;

  cout << "z3 value: ";
  cin >> matrix.z3;

  cout << "Third equation result: ";
  cin >> matrix.Zrezult;

  return matrix;
}


int IsSteppedView(matrix matrix)
{
  if (matrix.x1 == 1 && matrix.y2 == 1 && matrix.z3 == 1
     && matrix.y1 == 0 && matrix.z1 == 0 && matrix.z2 == 0)
    return 1;
  else
    return 0;
}


matrix str_swap(matrix matrix, int dest)
{
  double dest1_temp, dest2_temp, dest3_temp, DestRezult_temp;

  if (dest == 2) {
    dest1_temp = matrix.y1, dest2_temp = matrix.y2, dest3_temp = matrix.y3, DestRezult_temp = matrix.Yrezult;
    matrix.y1 = matrix.x1, matrix.y2 = matrix.x2, matrix.y3 = matrix.x3, matrix.Yrezult = matrix.Xrezult;
    matrix.x1 = dest1_temp, matrix.x2 = dest2_temp, matrix.x3 = dest3_temp, matrix.Xrezult = DestRezult_temp;
  }

  if (dest == 3) {
    dest1_temp = matrix.z1, dest2_temp = matrix.z2, dest3_temp = matrix.z3, DestRezult_temp = matrix.Zrezult;
    matrix.z1 = matrix.x1, matrix.z2 = matrix.x2, matrix.z3 = matrix.x3, matrix.Zrezult = matrix.Xrezult;
    matrix.x1 = dest1_temp, matrix.x2 = dest2_temp, matrix.x3 = dest3_temp, matrix.Xrezult = DestRezult_temp;
  }

  return matrix;
}


void print_matrix(matrix matrix)
{
  cout << matrix.x1 << "\t" << matrix.x2 << "\t" << matrix.x3 << "\t" << matrix.Xrezult << endl;
  cout << matrix.y1 << "\t" << matrix.y2 << "\t" << matrix.y3 << "\t" << matrix.Yrezult << endl;
  cout << matrix.z1 << "\t" << matrix.z2 << "\t" << matrix.z3 << "\t" << matrix.Zrezult << endl;
  cout << endl << endl << endl;
}


void equation_solve(matrix matrix)
{
  double z = matrix.Zrezult / matrix.z3;
  double y = matrix.Yrezult - matrix.y3 * z;

  double xDivider = matrix.x2 * y + matrix.x3 * z;
  double x = matrix.Xrezult - xDivider;

  cout << "Answer: " << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
}


void process(matrix matrix)
{
  cout << endl << "-----------------" << endl;
  cout << "Source matrix: " << endl;
  print_matrix(matrix);

  bool solutions = true;
  int search_iteration = 0;
  int search_limit = 30;

  while (IsSteppedView(matrix) != 1)
  {
    if (matrix.x1 != 1) {     //Получаем единицу в x1

      if (matrix.y1 == 1)
        matrix = str_swap(matrix, 2);

      if (matrix.z1 == 1)
        matrix = str_swap(matrix, 3);

      if (matrix.x1 != 0 && matrix.x1 != 1 && matrix.y1 != 1 && matrix.z1 != 1) {
        double divider = matrix.x1;     //делим x1 на самого себя чтобы получить единицу
        matrix.x1 /= divider;
        matrix.x2 /= divider;
        matrix.x3 /= divider;
        matrix.Xrezult /= divider;
      }
      print_matrix(matrix);
    }

    if (matrix.y1 != 0) {     //Получаем ноль в y1

      if (matrix.y1 > 0) {                //Отнимаем от второй строки первую строку умноженную на y1
        double multiplier = matrix.y1;
        matrix.y1 -= (matrix.x1 * multiplier);
        matrix.y2 -= (matrix.x2 * multiplier);
        matrix.y3 -= (matrix.x3 * multiplier);
        matrix.Yrezult -= (matrix.Xrezult * multiplier);
      }

      if (matrix.y1 < 0) {
        double multiplier = -matrix.y1;
        matrix.y1 += (matrix.x1 * multiplier);
        matrix.y2 += (matrix.x2 * multiplier);
        matrix.y3 += (matrix.x3 * multiplier);
        matrix.Yrezult -= (matrix.Xrezult * multiplier);
      }
      print_matrix(matrix);
    }

    if (matrix.z1 != 0) {     //Получаем ноль в z1

      if (matrix.z1 > 0) {
        double multiplier = matrix.z1;
        matrix.z1 -= (matrix.x1 * multiplier);
        matrix.z2 -= (matrix.x2 * multiplier);
        matrix.z3 -= (matrix.x3 * multiplier);
        matrix.Zrezult -= (matrix.Xrezult * multiplier);
      }

      if (matrix.z1 < 0) {
        double multiplier = -matrix.z1;
        matrix.z1 += (matrix.x1 * multiplier);
        matrix.z2 += (matrix.x2 * multiplier);
        matrix.z3 += (matrix.x3 * multiplier);
        matrix.Zrezult -= (matrix.Xrezult * multiplier);
      }
      print_matrix(matrix);
    }

    if (matrix.y2 != 1) {     //Получаем единицу в y2
      if (matrix.y2 != 0) {
        double divider = matrix.y2;
        matrix.y1 /= divider;
        matrix.y2 /= divider;
        matrix.y3 /= divider;
        matrix.Yrezult /= divider;
      }
      print_matrix(matrix);
    }

    if (matrix.z3 != 1) {     //Получаем единицу в z3
      if (matrix.z3 != 0) {
        double divider = matrix.z3;
        matrix.z1 /= divider;
        matrix.z2 /= divider;
        matrix.z3 /= divider;
        matrix.Zrezult /= divider;
      }
      print_matrix(matrix);
    }

    if (matrix.z2 != 0) {     //Получаем ноль в z2

      if (matrix.z2 > 0) {
        double multiplier = matrix.z2;
        matrix.z1 -= (matrix.y1 * multiplier);
        matrix.z2 -= (matrix.y2 * multiplier);
        matrix.z3 -= (matrix.y3 * multiplier);
        matrix.Zrezult -= (matrix.Yrezult * multiplier);
      }

      if (matrix.z2 < 0) {
        double multiplier = -matrix.z2;
        matrix.z1 += (matrix.y1 * multiplier);
        matrix.z2 += (matrix.y2 * multiplier);
        matrix.z3 += (matrix.y3 * multiplier);
        matrix.Zrezult -= (matrix.Yrezult * multiplier);
      }
      print_matrix(matrix);
    }

    if (matrix.z1 == 0 && matrix.z2 == 0 && matrix.z3 == 0) {
      cout << "Impossible to solve matrix" << endl;
      solutions = false;
      break;
    }
    search_iteration++;

    if (search_iteration == search_limit) {
      cout << "Impossible to solve matrix" << endl;
      solutions = false;
      break;
    }
  }
  if (solutions == true ) equation_solve(matrix);
}
