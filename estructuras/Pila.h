/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

#ifndef PILA_H     
#define PILA_H    
#include "estructura.h"
#include <iostream>



template <class T> class Pila{
  nodo<T> *cab;
  public: 
    Pila(){
      cab= new nodo<T>;
      cab->dato=NULL;
      cab->sig=NULL;
      }
      void Push(T p);
      T Pop();
      bool PilaVacia();
      ~Pila();
};

template <class T> void Pila<T>::Push(T p){
     nodo<T> *t = new nodo<T>;
     t->dato=p; 
     t->sig=cab->sig;
     cab->sig= t;
}

template <class T> T Pila<T>::Pop(){
     T x;
     nodo<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
}

template <class T> bool Pila<T>::PilaVacia(){
      return cab->sig== NULL;
      }

template <class T> Pila<T>::~Pila(){
     nodo<T> *t=cab;
     while (t!=NULL){
          cab=t;
          t=t->sig;
          delete cab;
     }
}

#endif