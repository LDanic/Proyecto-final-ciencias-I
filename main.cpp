/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

#include "estructuras/Lista.h"
#include "estructuras/multilistaEmpleado.h"
#include "empleados.h"
#include "manejo_archivos/ObjetosToArchivos.h"
#include "construirMultilista.h"

using namespace std;

int main() {
  /*MultiListaEmpleado multi;
  Empleado emp("Pedro", "C", "cc", "correo",
   "2000-12-02", "Bogota", "Colombia", "Bogota",
   "cra 7 cl 40", "Restrepo","Artes",
   "pepe sierra", 10657, 'F', 61165, 16165);
  Hijo hijo("Alejandro","2020-20-09", 10657);
  emp.agregarHijo( hijo);
  Hijo hijo1("Alejandro","2020-20-09", 10657);
  emp.agregarHijo( hijo1);
  Hijo hijo2("Alejandro","2020-20-09", 10657);
  emp.agregarHijo( hijo2);
  
  Empleado emp2("Santia", "C", "cc", "correo",
     "2000-12-02", "Medellin", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","Artes",
     "chicala", 10656, 'F', 61165, 16165);

   Empleado emp1("Laura", "C", "cc", "correo",
     "2002-25-05", "Bogota", "Colombia", "Bogota",
     "cra 7 cl 40", "Restrepo","Artes",
     "pepe sierra", 10658, 'F', 61165, 16165);

  multi.insertar(emp);
  
  multi.insertar(emp2);
  multi.insertar(emp1);

  multi.eliminar(multi.buscarAnt(10658));*/


  GuardarArchivos ga;
  /*ga.guardarEmpleado(emp);
  ga.guardarEmpleado(emp1);
  ga.guardarEmpleado(emp2);*/

  Cola<Empleado> colaE =ga.leerEmpleado();
  Cola<Hijo> colaH = ga.leerHijo();

  
  ConstruirMultilista ca(colaH, colaE);
  MultiListaEmpleado multi = ca.construirMulti();
  

  
  cout<<"hola mundo"<<endl;
  
  return 0;

}