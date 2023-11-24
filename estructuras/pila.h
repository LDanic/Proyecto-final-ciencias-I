/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

#ifndef PILA_H     
#define PILA_H    
#include "estructura.h"
#include <iostream>



template <class T> class pila{
  nodo<T> *cab;
  public: 
    pila(){
      cab= new nodo<T>;
      cab->dato=NULL;
      cab->sig=NULL;
      }
      void Push(T p);
      T Pop();
      bool PilaVacia();
      ~pila();
};

template <class T> void pila<T>::Push(T p){
     nodo<T> *t = new nodo<T>;
     t->dato=p; 
     t->sig=cab->sig;
     cab->sig= t;
}

template <class T> T pila<T>::Pop(){
     T x;
     nodo<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
}

template <class T> bool pila<T>::PilaVacia(){
      return cab->sig== NULL;
      }

template <class T> pila<T>::~pila(){
     nodo<T> *t=cab;
     while (t!=NULL){
          cab=t;
          t=t->sig;
          delete cab;
     }
}

#endif