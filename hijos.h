/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#include "edad.h"
#include <iostream>
using namespace std;

class Hijo {
  string nombre, fNacimiento;
  int edad;

  public:
  Hijo(){
    nombre = "";
    fNacimiento = "";
    edad = 0;
  }
  Hijo(string nombre, string fNacimiento)
      : nombre(nombre), fNacimiento(fNacimiento) {

        Edad calEdad;
        edad = calEdad.calcularEdad(fNacimiento);
  }

};