#include "../include/lab5/macierz.h"
using namespace std;


Macierz::Macierz(int vRows, int vColumns) {    /*  Konstruktor 1 : przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami*/
  wiersze = vRows;
  kolumny = vColumns;
  myMatrix = new double* [wiersze] {};
  for (int i = 0; i < wiersze; i++)
    myMatrix[i] = new double[kolumny] {};
}

Macierz::Macierz(int vRows) {                  /* Kontruktor 2 : przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami  */
  wiersze = vRows;
  kolumny = vRows;
  myMatrix = new double* [wiersze] {};
  for (int i = 0; i < wiersze; i++)
    myMatrix[i] = new double[kolumny] {};
}

Macierz::Macierz(string filename, string path) {  /*  Kontruktor 3 : jako argument przyjmujący ścieżkę do pliku o podanym wcześniej formacie i na jego podstawie tworzący */
  ifstream file;                                   /*                                             nową macierz na podstawie przekazanego pliku                             */
  file.open(path + filename, ios::out);
  if (file.good() == false) {
    cout << endl << "File error" << endl;
    return;
  }
  else {
    file >> kolumny;
    file >> wiersze;
    myMatrix = new double* [kolumny];
    for (int i = 0; i < wiersze; i++) {
      myMatrix[i] = new double[kolumny];
      for (int j = 0; j < kolumny; j++) {
        file >> myMatrix[i][j];
      }
    }
  }
  file.close();
}

int Macierz::getRows() {
  return wiersze;
}

int Macierz::getColumns() {
  return kolumny;
}

void Macierz::set(int n, int m, double val) {
  if (n < 0 || n > wiersze - 1)
    throw "Niepoprawny numer wiersza";
  if (m < 0 || m > kolumny - 1)
    throw "Niepoprawny numer kolumny";
  myMatrix[n][m] = val;
}

double Macierz::get(int n, int m) {
  if (n < 0 || n > wiersze - 1)
    throw "Niepoprawny numer wiersza";
  if (m < 0 || m > kolumny - 1)
    throw "Niepoprawny numer kolumny";
  return myMatrix[n][m];
}

void Macierz::print() {
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      cout << get(i, j) << " ";
    }
    cout << endl;
  }
}

void Macierz::store(string filename, string path) {
  fstream file;
  file.open(path + filename, ios::out);
  if (file.good() == false) {
    throw "Blad przy otwieraniu pliku";
  }
  else {
    file << kolumny << " " << wiersze << "\n";
    for (int j = 0; j < wiersze; j++) {
      for (int i = 0; i < kolumny; i++) {
        file << myMatrix[j][i] << " ";
      }
      file << "\n";
    }
  }
  file.close();
}

ostream& operator << (ostream& print, Macierz& vMatrix) {
  for (int i = 0; i < vMatrix.wiersze; i++) {
    for (int j = 0; j < vMatrix.kolumny; j++) {
      print << vMatrix.get(i, j) << " ";
    }
    cout << endl;
  }
  return print;
}

Macierz Macierz::operator - (const Macierz& m2) {
  Macierz matrixToSubstract(m2.wiersze, m2.kolumny);
  if (m2.wiersze != wiersze)
    throw "Niepoprawna liczba wierszy";
  if (m2.kolumny != kolumny)
    throw "Niepoprawna liczba kolumn";
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      matrixToSubstract.set(i, j, (myMatrix[i][j] - m2.myMatrix[i][j]));
    }
  }
  return matrixToSubstract;
}

Macierz Macierz::operator * (Macierz& m2) {
  double temp;
  Macierz matrixToMultiply(wiersze, m2.kolumny);

  if (m2.wiersze != kolumny)
    throw "Niepoprawna liczba wierszy";
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < m2.kolumny; j++) {
      temp = 0;
      for (int k = 0; k < kolumny; k++) {
        temp += (myMatrix[i][k]) * (m2.myMatrix[k][j]);
      }
      matrixToMultiply.set(i, j, temp);
    }
  }
  return matrixToMultiply;
}


Macierz Macierz::operator + (Macierz& m2) {
  Macierz matrixToAdd(wiersze, kolumny);
  if (m2.wiersze != wiersze)
    throw "Bledna liczba wierszy.";
  if (m2.kolumny != kolumny)
    throw "Bledna liczba kolumn.";
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      matrixToAdd.myMatrix[i][j] = m2.myMatrix[i][j] + myMatrix[i][j];
    }
  }
  return matrixToAdd;
}

bool Macierz::operator == (Macierz& m2) {
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      if (myMatrix[i][j] != m2.myMatrix[i][j]) {
        return false;
      }
    }
  }
  return true;
}

double* Macierz::operator [] (int n) {
  if (n > wiersze) {
    cout << "Error" << endl;
    exit(0);
  }
  else {
    return myMatrix[n];
  }
}