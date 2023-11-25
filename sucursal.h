/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <iostream>
using namespace std;

class Sucursal{

private:
    string nombre, direccion, barrio, nomGerente;
public:
    Sucursal(){
        nombre = "";
        direccion = "";
        barrio = "";
        nomGerente = "";
    }

    Sucursal(string nombre, string direccion, string barrio, string nomGerente) : nombre(nombre), direccion(direccion), barrio(barrio), nomGerente(nomGerente){

    }

    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    string getBarrio() const {
        return barrio;
    }
    string getNomGerente() const {
        return nomGerente;
    }
};

#endif
