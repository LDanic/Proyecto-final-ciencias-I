/*
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032
*/

#include <iostream>
#include "Lista.h"
#include "multilistaEmpleado.h"
#include "empleados.h"

using namespace std;



int main() {
  MultiListaEmpleado multi;
  Empleado emp("Daniela", "", "CC", 1000, 'F',
   "lol", "pepe", "bogota", "Colombia",
   "Bogota", "pepe", "ksdhkshd", 316, 464,
   16, "artes", "pepe sierra");

  multi.insertar(emp);
  return 0;

}