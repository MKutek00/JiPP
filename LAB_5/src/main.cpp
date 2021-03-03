#include "../include/lab5/macierz.h"
#include "../libs/libs.h"

using namespace std;

int main() {
  srand(time(NULL));

  Macierz m2(4, 5);

  for (int i = 0; i < m2.getRows(); i++) {
    for (int j = 0; j < m2.getColumns(); j++) {
      m2.set(i, j, rand() % 10);
    }
  }

  cout << endl << "m2.set(1, 1, 5)" << endl;
  m2.set(1, 1, 5);
  cout << m2.get(1, 1);

  Macierz m3(4, 5);

  for (int i = 0; i < m3.getRows(); i++) {
    for (int j = 0; j < m3.getColumns(); j++) {
      m3.set(i, j, rand() % 10);
    }
  }

  Macierz m4(5, 6);

  for (int i = 0; i < m4.getRows(); i++) {
    for (int j = 0; j < m4.getColumns(); j++) {
      m4.set(i, j, rand() % 10);
    }
  }

  Macierz m5(5);

  for (int i = 0; i < m5.getRows(); i++) {
    for (int j = 0; j < m5.getColumns(); j++) {
      m5.set(i, j, rand() % 10);
    }
  }

  cout << endl << "Operator <<: " << endl;
  cout << endl << "Macierz m2: " << endl;
  cout << m2;
  cout << endl << "Macierz m3: " << endl;
  cout << m3;
  cout << endl << "Macierz m4: " << endl;
  cout << m4;
  cout << endl << "Macierz m5: " << endl;
  cout << m5;

  cout << endl << "Operator + (m2 + m3):" << endl;
  Macierz matrixToAdd(4, 5);
  matrixToAdd = m2 + m3;
  cout << matrixToAdd;

  cout << endl << "Operator - (m3 - m2): " << endl;
  Macierz matrixToSubstract(4, 5);
  matrixToSubstract = m3 - m2;
  cout << matrixToSubstract;

  cout << endl << "Operator * (m3 * m4): " << endl;
  Macierz matrixToMultiply(6, 4);
  matrixToMultiply = m3 * m4;
  cout << matrixToMultiply;

  cout << endl << "Operator ==: " << endl;
  if (m2 == m2) {
    cout << "m2 == m2" << endl;
  }
  else {
    cout << "m2 != m2" << endl;
  }
  if (m3 == m2) {
    cout << "m3 == m2" << endl;
  }
  else {
    cout << "m3 != m2" << endl;
  }

  cout << endl << "Operator [] dla 1 wiersza macierzy m4: " << endl;
  int n = m4.kolumny;
  double* arr = m4[1];

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

}