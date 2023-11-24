//Santiago Sanchez Moya 20211020032
//Laura Daniela Cubillos Escobar 20211020045

#include <iostream>
#include "estructura.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;

template <class T> class Cola{
  nodo<T> *cab,*fin;
  public: 
    int tam;
    Cola(){
      tam = 0;
      cab=fin=NULL;
    }
    void InsCola(T p);
    T AtenderCola();
    T ImprimirCola(int pos);
    bool ColaVacia();

    //~cola();
 };

template <class T> void Cola<T>::InsCola(T p){
  tam++;
  nodo<T> *nuevo;
  nuevo= new nodo<T>;
  nuevo->dato= p;
  nuevo->sig= NULL;
  if (cab==NULL){
    cab=nuevo;
  }
  else {
    fin->sig = nuevo;
  }
  fin=nuevo;
}
template <class T> T Cola<T>::AtenderCola(){   
  tam--;
  T x;
  nodo<T> *aux = cab; 
  cab=aux->sig;
  x= aux->dato;
  delete aux;
  return x;
}

template <class T> T Cola<T>::ImprimirCola(int pos){
  T res;
  nodo<T> *Aux;
  Aux = cab;

  if (pos <= tam) {
    if (pos == 1) {
      return Aux->dato;
    }

    for (int i = 2; i <= pos; i++) {
      Aux = Aux->sig;
    }
    return Aux->dato;
  }
  return res;

}

template <class T> bool Cola<T>::ColaVacia(){
  return (cab==NULL);
}

/*template <class T> cola<T>::~cola(){
  nodo<T> *aux;
  while(cab!=NULL){
    aux= cab;
    cab=aux->sig;
    delete aux;
  }
  delete cab;
}*/

#endif
