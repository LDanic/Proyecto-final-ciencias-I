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
  Empleado emp("Pedro", "C", "cc", "correo",
   "?", "Bogota", "Colombia", "Bogota",
   "cra 7 cl 40", "Restrepo","ciencia",
   "pepe sierra", 10656, 'F', 61165, 16165,
    0);

   Empleado emp1("Laura", "C", "cc", "correo",
     "?", "Bogota", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","ciencia",
     "pepe sierra", 10656, 'F', 61165, 16165,
      0);

  multi.insertar(emp);
  multi.insertar(emp1);

  cout<<"hola mundo"<<endl;
  return 0;

}