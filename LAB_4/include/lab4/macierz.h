#include "../libs/libs.h"

#ifndef Macierz_H
#define Macierz_H
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

  bool operator == (Macierz& m2);

  Macierz add(Macierz m2);

  Macierz substract(Macierz m2);

  Macierz multiply(Macierz m2);

  void store(string filename, string path);
};
#endif