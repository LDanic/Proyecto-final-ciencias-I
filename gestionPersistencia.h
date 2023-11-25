/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
// incluir archivos y librerias necesarias
#include "estructuras/multilistaEmpleado.h"
#include "manejo_archivos/ObjetosToArchivos.h"

class gestionPersistencia {
    // atributos privados
private:
    Cola<Hijo> hijos;
    Cola<Empleado> empleados;
    GuardarArchivos objAr;
    // atributos publicos
public:
    gestionPersistencia() {}
    // declaracion de los metodos
    void asignarHijos();
    MultiListaEmpleado construirMulti();
    void guardarMulti(MultiListaEmpleado);
    Lista<Sucursal> construirSucursales();
    void guardarSucursales(Lista<Sucursal>);
};
// implementacion de los metodos
// metodo asignar hijos
void gestionPersistencia:: asignarHijos(){
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

MultiListaEmpleado gestionPersistencia::construirMulti() {
    hijos = objAr.leerHijo();
    empleados = objAr.leerEmpleado();

    asignarHijos();
    MultiListaEmpleado multiEmp;
    while (!empleados.ColaVacia()) {
        multiEmp.insertar(empleados.AtenderCola());
    }
    return multiEmp;
}

void gestionPersistencia::guardarMulti(MultiListaEmpleado multiEmp) {
    objAr.persistenciaNueva(1);

    for(int i=1; i<=multiEmp.multiEmpleados.get_tam(); i++){
        objAr.guardarEmpleado(multiEmp.multiEmpleados.get_info(i));
    }

    objAr.eliminarTemp();
}

Lista<Sucursal> gestionPersistencia::construirSucursales() {
    return objAr.leerSucur();
}

void gestionPersistencia::guardarSucursales(Lista<Sucursal> sucursales) {
    objAr.persistenciaNueva(3);
    for(int i=1; i<=sucursales.get_tam(); i++){
        objAr.guardarSucursal(sucursales.get_info(i++));
    }
    objAr.eliminarTemp();
}