/*
JUAN DIEGO ACOSTA MOLINA 20211020044
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
   "cra 7 cl 40", "Restrepo","Artes",
   "pepe sierra", 10656, 'F', 61165, 16165,
    0);

  Empleado emp2("Santia", "C", "cc", "correo",
     "?", "Medellin", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","Artes",
     "chicala", 10656, 'F', 61165, 16165,
      0);

   Empleado emp1("Laura", "C", "cc", "correo",
     "?", "Bogota", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","Artes",
     "pepe sierra", 10656, 'F', 61165, 16165,
      0);

  multi.insertar(emp);
  multi.insertar(emp2);
  multi.insertar(emp1);

  cout<<"hola mundo"<<endl;
  return 0;

}