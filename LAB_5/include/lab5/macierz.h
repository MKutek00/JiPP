#include "../../libs/libs.h"

using namespace std;

#ifndef Matrix_H
#define Matrix_H
class Macierz {

public:
  int wiersze, kolumny;
  double** myMatrix;

  Macierz(int vRows, int vColumns);

  Macierz(int vRows = 1);

  Macierz(string filename, string path);

  int getRows();

  int getColumns();

  void set(int n, int m, double val);

  double get(int n, int m);

  void print();

  friend ostream& operator << (ostream& print, Macierz& vMatrix);

  Macierz operator -(const Macierz& m2);

  Macierz operator *(Macierz& m2);

  Macierz operator + (Macierz& m2);

  bool operator == (Macierz& m2);

  double* operator [] (int n);
  
  void store(string filename, string path);
};
#endif