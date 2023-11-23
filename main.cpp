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
   "2004-12-02", "Bogota", "Colombia", "Bogota",
   "cra 7 cl 40", "Restrepo","Artes",
   "pepe sierra", 10657, 'F', 61165, 16165,
    0);

  Empleado emp2("Santia", "C", "cc", "correo",
     "2000-12-02", "Medellin", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","Artes",
     "chicala", 10656, 'F', 61165, 16165,
      0);

   Empleado emp1("Laura", "C", "cc", "correo",
     "2002-25-05", "Bogota", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","Artes",
     "pepe sierra", 10658, 'F', 61165, 16165,
      0);

  multi.insertar(emp);
  multi.insertar(emp2);
  multi.insertar(emp1);

  multi.eliminar(multi.buscarAnt(10658));

  cout<<"hola mundo"<<endl;
  return 0;

}