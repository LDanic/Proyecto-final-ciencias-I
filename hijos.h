/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef HIJO_H
#define HIJO_H

#include "edad.h"
#include <iostream>

using namespace std;

class Hijo {
  std::string nombre, apellido, fNacimiento;
  int edad;

public:
  Hijo();
  Hijo(std::string nombre, std::string fNacimiento);

  void setApellido(std::string apellido);
};


// Implementación de los métodos

Hijo::Hijo() {
  nombre = "";
  fNacimiento = "";
  edad = 0;
}

Hijo::Hijo(std::string nombre, std::string fNacimiento) {
  this->nombre = nombre;
  this->fNacimiento = fNacimiento;
  Edad e;
  this->edad = e.calcularEdad(fNacimiento);
}

void Hijo::setApellido(std::string apellido) {
  this->apellido = apellido;
}
#endif