/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef OBJETOSTOARCHIVOS_H
#define OBJETOSTOARCHIVOS_H
//importar archivos y librerias necesarias
#include "../empleados.h"
#include "../hijos.h"
#include "../sucursal.h"
#include "Archivos.h"
#include "../estructuras/cola.h"
#include <string>
#include <sstream>

class GuardarArchivos{

private:
  Archivo archivoEmp;
  Archivo archivoHijos;
  Archivo archivoSucu;
public:
  GuardarArchivos(){
    archivoEmp.setRuta("Empleados");
    archivoHijos.setRuta("Hijos");
    archivoSucu.setRuta("Sucursales");

  }


  void guardarEmpleado(Empleado);
  void guardarHijo(Hijo);
  void guardarSucursal(Sucursal sucu);
  string sucurToString(Sucursal);
  Cola<Empleado> leerEmpleado();
  Cola<Hijo> leerHijo();
  Lista<Sucursal> leerSucur();
};

void GuardarArchivos:: guardarEmpleado(Empleado emp){
  string empleado = emp.getNombre() + "," + emp.getApellido() + "," + emp.getTipoId() + "," + emp.getCorreo() + "," + emp.getFechaNacimiento() + "," + emp.getCiudadNacimiento() + "," + emp.getPaisNacimiento()+ "," + emp.getCiudadResidencia() + "," + emp.getDireccion() + "," + emp.getBarrio() + "," + emp.getActividadLaboral() + "," + emp.getNombreSucursal() + "," + to_string(emp.getNumId()) + "," + emp.getSexo() + "," + to_string(emp.getCelular()) + "," + to_string(emp.getTelefonoFijo()) + "," + to_string(emp.getEdad());

  for(int i = 1; i <= emp.getHijos().get_tam(); i++){
    guardarHijo(emp.getHijos().get_info(i));
  }
  
  archivoEmp.anadir(empleado);
}

void GuardarArchivos:: guardarHijo(Hijo hijo){

  string hijos = hijo.getNombre() + "," + hijo.getFechaNacimiento() + "," + to_string(hijo.getIdPadre());

  archivoHijos.anadir(hijos);
}

void GuardarArchivos:: guardarSucursal(Sucursal sucu){
  string sucursal = sucu.getNombre() + "," + sucu.getDireccion() + "," + sucu.getBarrio() + "," + sucu.getNomGerente();

  archivoSucu.anadir(sucursal);
}

Cola<Empleado> GuardarArchivos::leerEmpleado(){
  Cola<Empleado> empleados;
  
  string linea, nombre, apellido, tipoId, correo,fNa, ciudadNa, paisNa, ciudadRe, direccion, barrio, actividadLaboral,nomSucursal, aux;
  long numId;
  char sexo;
  int cel, fijo;

  linea = archivoEmp.leerLinea();

  stringstream ss(linea);
  string emp;

    while (getline(ss, emp, '/')) {
      stringstream ssAux(emp);
      getline(ssAux, nombre, ',');
      getline(ssAux, apellido, ',');
      getline(ssAux, tipoId, ',');
      getline(ssAux, correo, ',');
      getline(ssAux, fNa, ',');
      getline(ssAux, ciudadNa, ',');
      getline(ssAux, paisNa, ',');
      getline(ssAux, ciudadRe, ',');
      getline(ssAux, direccion, ',');
      getline(ssAux, barrio, ',');
      getline(ssAux, actividadLaboral, ',');
      getline(ssAux, nomSucursal, ',');
      getline(ssAux, aux, ',');
      numId = stol(aux);
      getline(ssAux, aux, ',');
      sexo = aux[0];
      getline(ssAux, aux, ',');
      cel = stol(aux);
      getline(ssAux, aux, ',');
      fijo = stol(aux);

      Empleado em(nombre, apellido, tipoId, correo,fNa, ciudadNa, paisNa, ciudadRe, direccion, barrio, actividadLaboral, nomSucursal, numId, sexo, cel, fijo);

      empleados.InsCola(em);    
    }

  return empleados;
}

Cola<Hijo> GuardarArchivos::leerHijo(){
  Cola<Hijo> hijos;

  string nombre, fNacimiento, linea, aux; 
    long id_padre;

  linea = archivoHijos.leerLinea();

  stringstream ss(linea);
  string hijo;

    while (getline(ss, hijo, '/')) {
      stringstream ssAux(hijo);
      getline(ssAux, nombre, ',');
      getline(ssAux, fNacimiento, ',');
      getline(ssAux, aux, ',');
      id_padre = stol(aux);
      


      Hijo hijo(nombre, fNacimiento, id_padre);

      hijos.InsCola(hijo);    
    }

  return hijos;
}


Lista<Sucursal> GuardarArchivos::leerSucur(){
  Lista<Sucursal> sucursales;

  string nombre, direccion, barrio, nomGerente, linea;

  linea = archivoSucu.leerLinea();

  stringstream ss(linea);
  string sucu;

    while (getline(ss, sucu, '/')) {
      stringstream ssAux(sucu);
      getline(ssAux, nombre, ',');
      getline(ssAux, direccion, ',');
      getline(ssAux, barrio, ',');
      getline(ssAux, nomGerente, ',');


      Sucursal sucu(nombre, direccion, barrio, nomGerente);

      sucursales.insertar_final(sucu);    
    }

  return sucursales;
}


#endif