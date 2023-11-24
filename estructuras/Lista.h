/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class T> struct Nodo {
  T info;
  Nodo<T> *sig;
};

template <class T> class Lista {

public:
  Nodo<T> *cab;
  Nodo<T> *fin;
  int tam;

  Lista() {
    cab = new Nodo<T>;
    fin = NULL;
    cab->sig = fin;
    tam = 0;
  }

  bool lista_vacia() { return cab->sig == NULL; }

  void insertar_final(T dato);
  void insertar_inicio(T dato);
  void insertar_pos(T dato, int pos);
  bool eliminar(int pos);
  void editarInfo(int pos, T info);
  int get_tam();
  void set_tam(int t) { this->tam = t; };
  T get_info(int pos);
  T *get_info_ap(int pos);
  Nodo<T> *get_nodo_ap(int pos);
};

template <class T> void Lista<T>::insertar_final(T dato) {
  Nodo<T> *Aux;      // Se declaran dos apuntadores hacia un nodo
  Aux = new Nodo<T>; // Se inicializa un nuevo apuntador
  Aux->info = dato;  // se inserta la info dada en el nuevo apuntador
  Aux->sig =
      NULL; // como el nodo va a quedar en el final, este no tiene siguiente

  if (lista_vacia()) {
    fin = Aux;
    cab->sig = fin;
  } else {
    fin->sig = Aux;
    fin = Aux;
  }
  tam++; // se aumenta el tamano de la lista
}

template <class T> void Lista<T>::insertar_inicio(T dato) {
  Nodo<T> *Aux;   // Se declara un apuntador hacia un nodo
  Aux = cab->sig; // se guarda la direccion de memoria del primer nodo en el
                  // auxiliar para no perderla
  cab->sig =
      new Nodo<T>; // la cabeza de la lista ahora apuntara hacia un nuevo nodo
  cab->sig->info =
      dato; // el cual tendra como info el dato pasado como parametro
  cab->sig->sig =
      Aux; // y el nodo siguiente sera el que era la anterior cabeza de la lista

  tam++; // se aumenta el tamaño de la lista
}

template <class T> void Lista<T>::insertar_pos(T dato, int pos) {
  if (pos <= get_tam()) {
    Nodo<T> *Aux, *Aux1;
    Aux1 = cab;
    Aux = new Nodo<T>;
    Aux->info = dato;
    Aux->sig = NULL;

    for (int i = 0; i < pos - 1; i++) {
      Aux1 = Aux1->sig;
    }
    Aux->sig = Aux1->sig;
    Aux1->sig = Aux;

    tam++;
  }
}

template <class T> bool Lista<T>::eliminar(int pos) {
  Nodo<T> *Aux, *Aux1; // Se declaran dos apuntadores hacia un nodo
  Aux = cab;

  if (pos <= get_tam()) {

    for (int i = 1; i <= pos - 1; i++) {
      Aux = Aux->sig;
    }
    Aux1 = Aux->sig;
    Aux->sig = Aux1->sig;
    delete Aux1;
    return true;
  }
  return false;
}

template <class T> void Lista<T>::editarInfo(int pos, T info) {
  Nodo<T> *Aux;
  Aux = cab;
  if (pos <= get_tam()) {

    for (int i = 1; i <= pos; i++) {
      Aux = Aux->sig;
    }
    Aux->info = info;
  }
}

template <class T> int Lista<T>::get_tam() { return tam; }

template <class T> T Lista<T>::get_info(int pos) {
  T res;
  Nodo<T> *Aux;
  Aux = cab;

  if (pos <= get_tam()) {

    for (int i = 1; i <= pos; i++) {
      Aux = Aux->sig;
    }
    return Aux->info;
  }
  return res;
}

template <class T> T *Lista<T>::get_info_ap(int pos) {
  T *res = NULL;
  Nodo<T> *Aux;
  Aux = cab;

  if (pos <= get_tam()) {

    for (int i = 1; i <= pos; i++) {
      Aux = Aux->sig;
    }
    return &Aux->info;
  }
  return res;
}

template <class T> Nodo<T> *Lista<T>::get_nodo_ap(int pos) {
  Nodo<T> *res = NULL;
  Nodo<T> *Aux;
  Aux = cab;

  if (pos <= get_tam()) {

    for (int i = 1; i <= pos; i++) {
      Aux = Aux->sig;
    }
    return Aux;
  }
  return res;
}

#endif