#include <iostream>
using namespace std;

class Matriz2D_1 {
private:
  int** _matriz;
  int _nf, _nc;
public:
  Matriz2D_1() {
    _matriz = new int*[0];
    _nf = 0;
    _nc = 0;
  }
  Matriz2D_1(int nf, int nc) {
    _matriz = new int*[nf];
    for ( int i = 0; i < nf; i++ )
      _matriz[i] = new int[nc];
    _nf = nf;
    _nc = nc;
  }
  int getFilas() const {
    return _nf;
  }
  int getColumnas() const {
    return _nc;
  }
  int getCelda ( int i, int j ) const {
    return _matriz[i][j];
  }
  void liberar() {
    for ( int i = 0; i < _nf; i++ )
      delete[] _matriz[i];
    delete[] _matriz;
  }
  void write() const {
    for ( int i = 0; i < _nf; i++ ) {
      for ( int j = 0; j < _nc; j++ )
        cout << _matriz[i][j] << " ";
      cout << endl;
    }
  }
  Matriz2D_1 copia() const {
    Matriz2D_1 nueva_matriz(_nf,_nc);
    nueva_matriz._matriz = _matriz;
    return nueva_matriz;
  }
  Matriz2D_1 submatriz( int a_i, int a_j, int b_i, int b_j ) {
    Matriz2D_1 submatriz(b_i-a_i, b_j-a_j);
    for ( int i = a_i; i < b_i; i++ )
      for ( int j = a_j; j < b_j; j++ )
        submatriz._matriz[i-a_i][j-b_j] = _matriz[i][j];
  }
  void eliminarFila( int fila ) {
    Matriz2D_1 nueva_matriz(_nf-1,_nc);
    for ( int i = 0; i < _nf; i++ )
      for ( int j = 0; j < _nc; j++ )
        if ( i != fila )
          if ( i < fila )
            nueva_matriz._matriz[i][j] = _matriz[i][j];
          else
            nueva_matriz._matriz[i-1][j] = _matriz[i][j];
    _matriz = nueva_matriz._matriz;
    _nf--;
  }
  void eliminarColumna( int columna ) {
    Matriz2D_1 nueva_matriz(_nf,_nc-1);
    for ( int i = 0; i < _nf; i++ )
      for ( int j = 0; j < _nc; j++ )
        if ( j != columna )
          if ( j < columna )
            nueva_matriz._matriz[i][j] = _matriz[i][j];
          else
            nueva_matriz._matriz[i][j-1] = _matriz[i][j];
    _matriz = nueva_matriz._matriz;
    _nc--;
  }
};

class Matriz2D_2 {
private:
  int* _matriz;
  int _nf, _nc;
  void modifCelda( int i, int j, int num ) {
    _matriz[i*_nc+j] = num;
  }
public:
  Matriz2D_1() {
    _matriz = new int[0];
    _nf = 0;
    _nc = 0;
  }
  Matriz2D_1(int nf, int nc) {
    _matriz = new int[nf*nc];
    _nf = nf;
    _nc = nc;
  }
  int getFilas() const {
    return _nf;
  }
  int getColumnas() const {
    return _nc;
  }
  int getCelda ( int i, int j ) const {
    return _matriz[i*_nc+j];
  }
  void liberar() {
    delete[] _matriz;
    _nf = 0;
    _nc = 0;
  }
  void write() const {
    for ( int i = 0; i < _nf; i++ ) {
      for ( int j = 0; j < _nc; j++ )
        cout << getCelda(i,j) << " ";
      cout << endl;
    }
  }
  Matriz2D_1 copia() const {
    Matriz2D_1 nueva_matriz(_nf,_nc);
    nueva_matriz._matriz = _matriz;
    return nueva_matriz;
  }
  Matriz2D_1 submatriz( int a_i, int a_j, int b_i, int b_j ) {
    Matriz2D_1 submatriz(b_i-a_i, b_j-a_j);
    for ( int i = a_i; i < b_i; i++ )
      for ( int j = a_j; j < b_j; j++ )
        submatriz.modifCelda(i-a_i,j-b_j, getCelda(i,j));
  }
  void eliminarFila( int fila ) {
    Matriz2D_1 nueva_matriz(_nf-1,_nc);
    for ( int i = 0; i < _nf; i++ )
      for ( int j = 0; j < _nc; j++ )
        if ( i != fila )
          if ( i < fila )
            nueva_matriz.modifCelda(i,j,getCelda(i,j));
          else
            nueva_matriz.modifCelda(i-1,j,getCelda(i,j));
    _matriz = nueva_matriz._matriz;
    _nf--;
  }
  void eliminarColumna( int columna ) {
    Matriz2D_1 nueva_matriz(_nf,_nc-1);
    for ( int i = 0; i < _nf; i++ )
      for ( int j = 0; j < _nc; j++ )
        if ( j != columna )
          if ( j < columna )
            nueva_matriz.modifCelda(i,j,getCelda(i,j));
          else
            nueva_matriz.modifCelda(i,j-1,getCelda(i,j));
    _matriz = nueva_matriz._matriz;
    _nc--;
  }
};
