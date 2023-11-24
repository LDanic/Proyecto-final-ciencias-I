/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
//incluir archivos y librerias necesarias
#include "manejo_archivos/ObjetosToArchivos.h"
#include "estructuras/multilistaEmpleado.h"

class ConstruirMultilista{
// atributos privados
  private:
    Cola<Hijo> hijos;
    Cola<Empleado> empleados;
//atributos publicos
  public:
    ConstruirMultilista(Cola<Hijo> hijos, Cola<Empleado> empleados){
      this->hijos = hijos;
      this->empleados = empleados;
    }
//declaracion de los metodos
    void asignarHijos();
    MultiListaEmpleado construirMulti();
};
//implementacion de los metodos
//metodo asignar hijos
void ConstruirMultilista:: asignarHijos(){
  Cola<Empleado> colaNueva;
  Empleado em;
  Hijo hijo = hijos.AtenderCola();
  //atiende la cola
// iterar en las colas y donde encuentra un match entre padre e hijos, agregar ese hijo al padre
  while(!hijos.ColaVacia()){

    em = empleados.AtenderCola();
    
    while(hijo.getIdPadre() == em.getNumId() ){
      em.agregarHijo(hijo);
      if(!hijos.ColaVacia()){
        hijo = hijos.AtenderCola();
      }else{
        break;
      }
    }
    colaNueva.InsCola(em);
  }

  while(!empleados.ColaVacia()){
    colaNueva.InsCola(empleados.AtenderCola());
  }
  empleados = colaNueva;
}

MultiListaEmpleado ConstruirMultilista::construirMulti(){
  asignarHijos();
  MultiListaEmpleado multiEmp;
  while(!empleados.ColaVacia()){
    multiEmp.insertar(empleados.AtenderCola());
  }
  return multiEmp;
}