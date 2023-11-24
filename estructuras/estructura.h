//Santiago Sanchez Moya 20211020032
//Laura Daniela Cubillos Escobar 20211020045

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include <iostream>
using namespace std;

struct NODO { 
  int cod;
  string nombre;
  NODO *izq, *der;
};

template <class T> struct nodo {
  T dato;
  nodo<T> *sig;
};

struct LHijos{
    int cabListaH, cod, sigHermano;
    string nom;
};

#endif