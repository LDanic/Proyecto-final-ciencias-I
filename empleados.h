/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include "Lista.h"
#include "hijos.h"
#include <iostream>

using namespace std;

class Empleado {

private:
  string nombre, apellido, tipoId, correo, fNa, cuidadNa, paisNa, cuidadRe,
      direccion, barrio, actividadLaboral, nomSucursal;
  long numId;
  char sexo;
  int cel, fijo, edad;
  Lista<Hijo> hijos;

public:
  Empleado *sigSexo, *sigCiudadNa, *sigPaisNa, *sigCuidadRe, *sigBarrio,
      *sigAct, *sigEdad, *sigNumHijos, *sigNomSucursal, *antSexo, *antCiudadNa,
      *antPaisNa, *antCuidadRe, *antBarrio, *antAct, *antEdad, *antNumHijos,
      *antNomSucursal;

  Empleado() {

    nombre = " ";
    apellido = " ";
    tipoId = " ";
    correo = " ";
    fNa = " ";
    cuidadNa = " ";
    paisNa = " ";
    cuidadRe = " ";
    direccion = " ";
    barrio = " ";
    actividadLaboral = " ";
    nomSucursal = " ";
    numId = 0;
    sexo = 'F';
    cel = 0, fijo = 0, edad = 0;
    sigSexo = NULL;
    sigCiudadNa = NULL;
    sigPaisNa = NULL;
    sigCuidadRe = NULL;
    sigBarrio = NULL;
    sigAct = NULL;
    sigEdad = NULL;
    sigNumHijos = NULL;
    sigNomSucursal = NULL;
    antSexo = NULL;
    antCiudadNa = NULL;
    antPaisNa = NULL;
    antCuidadRe = NULL;
    antBarrio = NULL;
    antAct = NULL;
    antEdad = NULL;
    antNumHijos = NULL;
    antNomSucursal = NULL;
  }
  Empleado(string nombre, string apellido, string tipoId, string correo,
           string fNa, string cuidadNa, string paisNa, string cuidadRe,
           string direccion, string barrio, string actividadLaboral,
           string nomSucursal, long numId, char sexo, int cel, int fijo,
           int edad)
      : nombre(nombre), apellido(apellido), tipoId(tipoId), correo(correo),
        fNa(fNa), cuidadNa(cuidadNa), paisNa(paisNa), cuidadRe(cuidadRe),
        direccion(direccion), barrio(barrio),
        actividadLaboral(actividadLaboral), nomSucursal(nomSucursal),
        numId(numId), sexo(sexo), cel(cel), fijo(fijo),
        edad(edad), // edad se inicializa después
        sigSexo(NULL), sigCiudadNa(NULL), sigPaisNa(NULL), sigCuidadRe(NULL),
        sigBarrio(NULL), sigAct(NULL), sigEdad(NULL), sigNumHijos(NULL),
        sigNomSucursal(NULL), antSexo(NULL), antCiudadNa(NULL), antPaisNa(NULL),
        antCuidadRe(NULL), antBarrio(NULL), antAct(NULL), antEdad(NULL),
        antNumHijos(NULL), antNomSucursal(NULL) {

    // Edad calEdad;
    // this->edad = calEdad.calcularEdad(fNa);
  }

  // void agregarHijo(Hijo hijo) { hijos.insertar_inicio(hijo); }

  // Getters
  string getNombre() { return nombre; }

  string getApellido() { return apellido; }

  string getTipoId() { return tipoId; }

  long getNumId() { return numId; }

  char getSexo() { return sexo; }

  string getCorreo() { return correo; }

  string getFechaNacimiento() { return fNa; }

  string getCiudadNacimiento() { return cuidadNa; }

  string getPaisNacimiento() { return paisNa; }

  string getCiudadResidencia() { return cuidadRe; }

  string getDireccion() { return direccion; }

  string getBarrio() { return barrio; }

  int getCelular() { return cel; }

  int getTelefonoFijo() { return fijo; }

  int getEdad() { return edad; }

  string getActividadLaboral() { return actividadLaboral; }

  string getNombreSucursal() { return nomSucursal; }

  Lista<Hijo> getHijos() { return hijos; }
};

#endif
