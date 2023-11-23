/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
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

  bool encontrarCabecera(string nomCabecera) {
    int i = 1;
    Cab actual = nomCabeceras.get_info(i);

    while (actual.nomLista != nomCabecera) {
      actual = nomCabeceras.get_info(++i);
      if (i == nomCabeceras.get_tam()) {
        return false;
      }
    }
    return true;
    // La ciudad de residencia no existe en la lista de cabeceras
  }

  void crearCabecera(string nomCabecera) {
    if (!encontrarCabecera(nomCabecera)) {
      Cab cabNueva;
      cabNueva.nomLista = nomCabecera;
      cabNueva.cabEmpleado = NULL;
      nomCabeceras.insertar_inicio(cabNueva);
    }
  }

public:
  MultiListaEmpleado() { llenarCab(); }

  void llenarCab() {

    string cabFijas[16] = {"masculino",   "femenino",
                           "Artes",       "Ciencias sociales",
                           "Ingenierias", "Areas de la salud",
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
    Empleado *em = multiEmpleados.get_info_ap(1);
    organizarNomSucursal(em);
    organizarSexo(em);
    organizarCuidadNa(em);
    organizarPaisNa(em);
    organizarCuidadRe(em);
    organizarBarrio(em);
    organizarAct(em);
    //organizarEdad(em);
    organizarNumHijos(em);
  }

  void organizarNomSucursal(Empleado *empleado) {
    Cab cabAux;
    string sucursal = empleado->getNombreSucursal();
    int i = 1;

    crearCabecera(sucursal);

    while (nomCabeceras.get_info(i).nomLista != sucursal) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigNomSucursal = aux;
      aux->antNomSucursal = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }
  void organizarNumHijos(Empleado *empleado) {
    Cab cabAux;
    string cabNom;
    int i = 1;
    int numHijos = empleado->getHijos().get_tam();
    switch (numHijos) {
    case 0:
      cabNom = "sin hijos";
      break;
    case 1 ... 2:
      cabNom = "1-2";
      break;
    case 3 ... 4:
      cabNom = "3-4";
      break;
    default:
      cabNom = "mas de 4";
      break;
    }

    while (nomCabeceras.get_info(i).nomLista != cabNom) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigNumHijos = aux;
      aux->antNumHijos = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void organizarCuidadRe(Empleado *empleado) {
    Cab cabAux;
    string ciudad = empleado->getCiudadResidencia();
    ciudad = ciudad + "RE";
    int i = 1;

    crearCabecera(ciudad);

    while (nomCabeceras.get_info(i).nomLista != ciudad) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigCuidadRe = aux;
      aux->antCuidadRe = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void organizarPaisNa(Empleado *empleado) {
    Cab cabAux;
    string pais = empleado->getPaisNacimiento();
    int i = 1;

    crearCabecera(pais);

    while (nomCabeceras.get_info(i).nomLista != pais) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigPaisNa = aux;
      aux->antPaisNa = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }
  void organizarCuidadNa(Empleado *empleado) {
    Cab cabAux;
    string ciudad = empleado->getCiudadNacimiento();
    ciudad = ciudad + "NA";
    int i = 1;

    crearCabecera(ciudad);

    while (nomCabeceras.get_info(i).nomLista != ciudad) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigCiudadNa = aux;
      aux->antCiudadNa = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void organizarSexo(Empleado *empleado) {
    Cab cabAux;
    string sexo;
    int i = 1;

    if (empleado->getSexo() == 'F') {
      sexo = "femenino";
    } else {
      sexo = "masculino";
    }

    while (nomCabeceras.get_info(i).nomLista != sexo) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigSexo = aux;
      aux->antSexo = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void organizarBarrio(Empleado *empleado) {
    Cab cabAux;
    string barrio = empleado->getBarrio();
    int i = 1;

    crearCabecera(barrio);

    while (nomCabeceras.get_info(i).nomLista != barrio) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigBarrio = aux;
      aux->antBarrio = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void organizarAct(Empleado *empleado) {
    Cab cabAux;
    string act = empleado->getActividadLaboral();
    int i = 1;

    while (nomCabeceras.get_info(i).nomLista != act) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigAct = aux;
      aux->antAct = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }
  void organizarEdad(Empleado *empleado) {
    Cab cabAux;
    string cabNom;
    int i = 1;
    int edad = empleado->getEdad();

    switch (edad) {
    case 18 ... 24:
      cabNom = "18 a 24";
      break;
    case 25 ... 35:
      cabNom = "25 a 35";
      break;
    case 36 ... 45:
      cabNom = "36 a 45";
      break;
    case 46 ... 60:
      cabNom = "46 a 60";
      break;
    default:
      cabNom = "mas de 60";
      break;
    }

    while (nomCabeceras.get_info(i).nomLista != cabNom) {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL) {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    } else {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigEdad = aux;
      aux->antEdad = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  //Empleado eliminar(long id) {}

}; // AQUIIIIIIIII

#endif
