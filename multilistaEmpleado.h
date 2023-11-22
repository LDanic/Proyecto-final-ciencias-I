#ifndef MULTILISTAEMPLEADO_H
#define MULTILISTAEMPLEADO_H

#include "Lista.h"
#include "empleados.h"
#include <iostream>

using namespace std;

struct Cab {
  Empleado *cabEmpleado;
  string nomLista;
};

class MultiListaEmpleado {

private:
  Lista<Empleado> multiEmpleados;
  Lista<Cab> nomCabeceras;

public:
  MultiListaEmpleado() { llenarCab(); }

  void llenarCab() {

    string cabFijas[16] = {"masculino",   "femenino",
                           "Artes",       "ciencias sociales",
                           "Ingenierias", "areas de la salud",
                           "otros",       "sin hijos",
                           "1-2",         "3-4",
                           "mas de 4",    "18 a 24",
                           "25 a 35",     "36 a 45",
                           "46 a 60",     "mas de 60"};

    for (int i = 0; i < 16; i++) {
      Cab cabecera;
      cabecera.nomLista = cabFijas[i];
      cabecera.cabEmpleado = NULL;
      nomCabeceras.insertar_final(cabecera);
    }
  }

  void insertar(Empleado empleado) {
    multiEmpleados.insertar_inicio(empleado);
    /*organizarSexo(empleado);
    organizarCuidadNa(empleado);
    organizarPaisNa(empleado);*/
    organizarCuidadRe(empleado);
    /*organizarBarrio(empleado);
    organizarAct(empleado);
    organizarEdad(empleado);
    organizarNumHijos(empleado);
    organizarNomSucursal(empleado);*/
  }

  // numHijos, numSucursal
  /*void organizarNomSucursal(Empleado empleado) {
    string nomSucursal = empleado.getNombreSucursal();
    int i = 1;

    while (nomCabeceras.get_info(i).nomLista != nomSucursal) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      Empleado *p = nomCabeceras.get_info(i).cabEmpleado;
      p;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigNomSucursal = aux;
      nomCabeceras.get_info(i).cabEmpleado = empleado;
    }
  }
  void organizarNumHijos(Empleado empleado) {
    string cab;
    int i = 1;
    int numHijos = empleado.getHijos().get_tam();
    switch (numHijos) {
    case 0:
      cab = "sin hijos";
      break;
    case 1 ... 2:
      cab = "1-2";
      break;
    case 3 ... 4:
      cab = "3-4";
      break;
    default:
      cab = "mas de 4";
      break;
    }

    while (nomCabeceras.get_info(i).nomLista != cab) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      Empleado *p = new Empleado(empleado);
      nomCabeceras.get_info(i).cabEmpleado = p;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigNumHijos = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }*/

  void organizarCuidadRe(Empleado &empleado) {
    Cab cabAux;
    string ciudad = empleado.getCiudadResidencia();
    int i = 1;

    while (nomCabeceras.get_info(i).nomLista != ciudad) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = &empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigCuidadRe = aux;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = &empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  /*void organizarPaisNa(Empleado empleado) {
    string pais = empleado.getPaisNacimiento();
    int i = 1;

    while (nomCabeceras.get_info(i).nomLista != pais) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigPaisNa = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }
  void organizarCuidadNa(Empleado empleado) {
    string cuidad = empleado.getCiudadNacimiento();
    int i = 1;

    while (nomCabeceras.get_info(i).nomLista != cuidad) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigCiudadNa = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }

  void organizarSexo(Empleado empleado) {
    string cab;
    int i = 1;

    if (empleado.getSexo() == 'F') {
      cab = "femenino";
    } else {
      cab = "masculino";
    }

    while (nomCabeceras.get_info(i).nomLista != cab) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigSexo = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }

  void organizarBarrio(Empleado empleado) {
    string cab;
    int i = 1;

    cab = empleado.getBarrio();

    while (nomCabeceras.get_info(i).nomLista != cab) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigBarrio = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }

  void organizarAct(Empleado empleado) {
    string cab;
    int i = 1;

    cab = empleado.getActividadLaboral();

    while (nomCabeceras.get_info(i).nomLista != cab) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigAct = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }
  void organizarEdad(Empleado empleado) {
    string cab;
    int i = 1;
    int edad = empleado.getEdad();
    switch (edad) {
    case 18 ... 24:
      cab = "18 a 24";
      break;
    case 25 ... 35:
      cab = "25 a 35";
      break;
    case 36 ... 45:
      cab = "36 a 45";
      break;
    case 46 ... 60:
      cab = "46 a 60";
      break;
    default:
      cab = "mas de 60";
      break;
    }

    while (nomCabeceras.get_info(i).nomLista != cab) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == nullptr) {
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado.sigEdad = aux;
      nomCabeceras.get_info(i).cabEmpleado = &empleado;
    }
  }*/

}; // AQUIIIIIIIII

#endif
