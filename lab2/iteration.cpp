#include "lab2.hpp"


matrix test_data1(matrix matrix)
{
  matrix.x1 = 4;
  matrix.y1 = 4;
  matrix.z1 = 4;
  matrix.FirstRezult = 4;

  matrix.x2 = 4;
  matrix.y2 = 4;
  matrix.z2 = 4;
  matrix.SecondRezult = 4;

  matrix.x3 = 4;
  matrix.y3 = 4;
  matrix.z3 = 4;
  matrix.ThirdRezult = 4;

  return matrix;
}


matrix test_data2(matrix matrix)
{
  matrix.x1 = 5;
  matrix.y1 = 1;
  matrix.z1 = 2;
  matrix.FirstRezult = 3;

  matrix.x2 = 1;
  matrix.y2 = 4;
  matrix.z2 = 1;
  matrix.SecondRezult = 6;

  matrix.x3 = 2;
  matrix.y3 = -1;
  matrix.z3 = -10;
  matrix.ThirdRezult = -21;

  return matrix;
}


matrix test_data3(matrix matrix)
{
  matrix.x1 = 4;
  matrix.y1 = 1;
  matrix.z1 = -1;
  matrix.FirstRezult = 0;

  matrix.x2 = 1;
  matrix.y2 = -5;
  matrix.z2 = 1;
  matrix.SecondRezult = 1;

  matrix.x3 = 1;
  matrix.y3 = -1;
  matrix.z3 = 4;
  matrix.ThirdRezult = 0;

  return matrix;
}


matrix test_data4(matrix matrix)
{
  matrix.x1 = 4;
  matrix.y1 = 1;
  matrix.z1 = -2;
  matrix.FirstRezult = 8;

  matrix.x2 = 1;
  matrix.y2 = -5;
  matrix.z2 = 1;
  matrix.SecondRezult = -10;

  matrix.x3 = 3;
  matrix.y3 = 1;
  matrix.z3 = -5;
  matrix.ThirdRezult = 10;

  return matrix;
}


matrix data_input(matrix matrix)
{
  bool data_validation = false;

  while (data_validation == false)
  {
    cout << "x1 value: ";
    cin >> matrix.x1;

    cout << "y1 value: ";
    cin >> matrix.y1;

    cout << "z1 value: ";
    cin >> matrix.z1;

    cout << "First equation result: ";
    cin >> matrix.FirstRezult;

    cout << "x2 value: ";
    cin >> matrix.x2;

    cout << "y2 value: ";
    cin >> matrix.y2;

    cout << "z2 value: ";
    cin >> matrix.z2;

    cout << "Second equation result: ";
    cin >> matrix.SecondRezult;

    cout << "x3 value: ";
    cin >> matrix.x3;

    cout << "y3 value: ";
    cin >> matrix.y3;

    cout << "z3 value: ";
    cin >> matrix.z3;

    cout << "Third equation result: ";
    cin >> matrix.ThirdRezult;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      system("clear");
      cout << endl << "Just numbers!" << endl << endl;
    }
    else {
      data_validation = true;
    }
  }
  return matrix;
}


void print_matrix(matrix matrix)
{
  cout << matrix.x1 << "\t" << matrix.y1 << "\t" << matrix.z1 << "\t" << matrix.FirstRezult << endl;
  cout << matrix.x2 << "\t" << matrix.y2 << "\t" << matrix.z2 << "\t" << matrix.SecondRezult << endl;
  cout << matrix.x3 << "\t" << matrix.y3 << "\t" << matrix.z3 << "\t" << matrix.ThirdRezult << endl;
  cout << endl << endl << endl;
}


int check_data(matrix matrix)
{
  if (matrix.x1 == 0 || matrix.y2 == 0 || matrix.z3 == 0) {
    return 1;
  }

  return 0;
}


void process(matrix matrix)
{
  if (check_data(matrix) == 1) {
    cout << endl << "Impossible to solve matrix." << endl;
    return;
  }

  double PreviousX;
  double PreviousY;
  double PreviousZ;

  double x = matrix.FirstRezult / matrix.x1;
  double y = matrix.SecondRezult / matrix.y2;
  double z = matrix.ThirdRezult / matrix.z3;

  cout << "x: " << x << "\t";
  cout << "y: " << y << "\t";
  cout << "z: " << z << endl;

  bool IsCompleted = false;
  int iteration_counter = 1;

  while (IsCompleted != true)
  {
    x = round(x * 100) / 100;
    y = round(y * 100) / 100;
    z = round(z * 100) / 100;

    cout << "x: " << x << "\t";
    cout << "y: " << y << "\t";
    cout << "z: " << z << endl;

    if (PreviousX == x && PreviousY == y && PreviousZ == z) IsCompleted = true;
    if (iteration_counter > 100) IsCompleted = true;

    PreviousX = x;
    PreviousY = y;
    PreviousZ = z;

    x = (matrix.y1 * PreviousY - matrix.z1 * PreviousZ + matrix.FirstRezult) / matrix.x1;
    y = (matrix.x2 * PreviousX - matrix.z2 * PreviousZ + matrix.SecondRezult) / matrix.y2;
    z = (matrix.x3 * PreviousX - matrix.y3 * PreviousY + matrix.ThirdRezult) / matrix.z3;

    iteration_counter++;
  }

  cout << "Answer: " << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "z = " << z << endl;

  cout << "Iteration count: " << iteration_counter << endl;
}
