/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

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