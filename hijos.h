/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef HIJO_H
#define HIJO_H
// librerias necesarias
#include "edad.h"
#include <iostream>

using namespace std;
// declaracion de la clase
class Hijo {
  string nombre, apellido, fNacimiento;
  int edad;

public:
  Hijo();
  Hijo(string nombre, string fNacimiento, long id_padre);
  string getNombre();
  string getApellido();
  string getFechaNacimiento();
  long getIdPadre();
  int getEdad();
  long id_padre;

  void setApellido(string apellido);
};

// Implementación de los métodos

Hijo::Hijo() {
  nombre = "";
  fNacimiento = "";
  edad = 0;
}

Hijo::Hijo(string nombre, string fNacimiento, long id_padre) {
  this->nombre = nombre;
  this->fNacimiento = fNacimiento;
  this->id_padre=id_padre;
  Edad e;
  this->edad = e.calcularEdad(fNacimiento);
}

void Hijo::setApellido(std::string apellido) { this->apellido = apellido; }

string Hijo::getNombre() { return nombre; }

string Hijo::getApellido() { return apellido; }

string Hijo::getFechaNacimiento()  { return fNacimiento; }

int Hijo::getEdad()  { return edad; }

long Hijo:: getIdPadre(){ return id_padre; }
#endif