/*
JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef MULTILISTAEMPLEADO_H
#define MULTILISTAEMPLEADO_H

#include "Lista.h"
#include "empleados.h"
#include <iostream>

using namespace std;

struct Cab
{
  Empleado *cabEmpleado;
  string nomLista;
};

class MultiListaEmpleado
{

private:
  Lista<Empleado> multiEmpleados;
  Lista<Cab> nomCabeceras;

  bool encontrarCabecera(string nomCabecera)
  {
    int i = 1;
    Cab actual = nomCabeceras.get_info(i);

    while (actual.nomLista != nomCabecera)
    {
      actual = nomCabeceras.get_info(++i);
      if (i == nomCabeceras.get_tam())
      {
        return false;
      }
    }
    return true;
    // La ciudad de residencia no existe en la lista de cabeceras
  }

  void crearCabecera(string nomCabecera)
  {
    if (!encontrarCabecera(nomCabecera))
    {
      Cab cabNueva;
      cabNueva.nomLista = nomCabecera;
      cabNueva.cabEmpleado = NULL;
      nomCabeceras.insertar_inicio(cabNueva);
    }
  }

public:
  MultiListaEmpleado() { llenarCab(); }

  void llenarCab()
  {

    string cabFijas[16] = {"masculino", "femenino",
                           "Artes", "Ciencias sociales",
                           "Ingenierias", "Areas de la salud",
                           "otros", "sin hijos",
                           "1-2", "3-4",
                           "mas de 4", "18 a 24",
                           "25 a 35", "36 a 45",
                           "46 a 60", "mas de 60"};

    for (int i = 0; i < 16; i++)
    {
      Cab cabecera;
      cabecera.nomLista = cabFijas[i];
      cabecera.cabEmpleado = NULL;
      nomCabeceras.insertar_final(cabecera);
    }
  }

  void insertar(Empleado empleado)
  {

    multiEmpleados.insertar_inicio(empleado);
    Empleado *em = multiEmpleados.get_info_ap(1);
    insertarCabNomSucursal(em);
    insertarCabSexo(em);
    insertarCabCiudadNa(em);
    insertarCabPaisNa(em);
    insertarCabCiudadRe(em);
    insertarCabBarrio(em);
    insertarCabAct(em);
    // insertarCabEdad(em);
    insertarCabNumHijos(em);
  }

  void insertarCabNomSucursal(Empleado *empleado)
  {
    Cab cabAux;
    string sucursal = empleado->getNombreSucursal();
    int i = 1;

    crearCabecera(sucursal);

    while (nomCabeceras.get_info(i).nomLista != sucursal)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigNomSucursal = aux;
      aux->antNomSucursal = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }
  void insertarCabNumHijos(Empleado *empleado)
  {
    Cab cabAux;
    string cabNom;
    int i = 1;
    int numHijos = empleado->getHijos().get_tam();
    switch (numHijos)
    {
    case 0:
      cabNom = "sin hijos";
      break;
    case 1 ... 2:
      cabNom = "1-2";
      break;
    case 3 ... 4:
      cabNom = "3-4";
      break;
    default:
      cabNom = "mas de 4";
      break;
    }

    while (nomCabeceras.get_info(i).nomLista != cabNom)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigNumHijos = aux;
      aux->antNumHijos = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void insertarCabCiudadRe(Empleado *empleado)
  {
    Cab cabAux;
    string ciudad = empleado->getCiudadResidencia();
    ciudad = ciudad + "RE";
    int i = 1;

    crearCabecera(ciudad);

    while (nomCabeceras.get_info(i).nomLista != ciudad)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigCiudadRe = aux;
      aux->antCiudadRe = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void insertarCabPaisNa(Empleado *empleado)
  {
    Cab cabAux;
    string pais = empleado->getPaisNacimiento();
    int i = 1;

    crearCabecera(pais);

    while (nomCabeceras.get_info(i).nomLista != pais)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigPaisNa = aux;
      aux->antPaisNa = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }
  void insertarCabCiudadNa(Empleado *empleado)
  {
    Cab cabAux;
    string ciudad = empleado->getCiudadNacimiento();
    ciudad = ciudad + "NA";
    int i = 1;

    crearCabecera(ciudad);

    while (nomCabeceras.get_info(i).nomLista != ciudad)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigCiudadNa = aux;
      aux->antCiudadNa = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void insertarCabSexo(Empleado *empleado)
  {
    Cab cabAux;
    string sexo;
    int i = 1;

    if (empleado->getSexo() == 'F')
    {
      sexo = "femenino";
    }
    else
    {
      sexo = "masculino";
    }

    while (nomCabeceras.get_info(i).nomLista != sexo)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigSexo = aux;
      aux->antSexo = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void insertarCabBarrio(Empleado *empleado)
  {
    Cab cabAux;
    string barrio = empleado->getBarrio();
    int i = 1;

    crearCabecera(barrio);

    while (nomCabeceras.get_info(i).nomLista != barrio)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigBarrio = aux;
      aux->antBarrio = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  void insertarCabAct(Empleado *empleado)
  {
    Cab cabAux;
    string act = empleado->getActividadLaboral();
    int i = 1;

    while (nomCabeceras.get_info(i).nomLista != act)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigAct = aux;
      aux->antAct = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }
  void insertarCabEdad(Empleado *empleado)
  {
    Cab cabAux;
    string cabNom;
    int i = 1;
    int edad = empleado->getEdad();

    switch (edad)
    {
    case 18 ... 24:
      cabNom = "18 a 24";
      break;
    case 25 ... 35:
      cabNom = "25 a 35";
      break;
    case 36 ... 45:
      cabNom = "36 a 45";
      break;
    case 46 ... 60:
      cabNom = "46 a 60";
      break;
    default:
      cabNom = "mas de 60";
      break;
    }

    while (nomCabeceras.get_info(i).nomLista != cabNom)
    {
      i++;
    }

    if (nomCabeceras.get_info(i).cabEmpleado == NULL)
    {
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
    else
    {

      Empleado *aux = (nomCabeceras.get_info(i).cabEmpleado);
      empleado->sigEdad = aux;
      aux->antEdad = empleado;
      cabAux.nomLista = nomCabeceras.get_info(i).nomLista;
      cabAux.cabEmpleado = empleado;
      nomCabeceras.editarInfo(i, cabAux);
    }
  }

  Nodo<Empleado> *buscarAnt(long id)
  {
    Nodo<Empleado> *aux, *auxSig;
    int i;

    aux = multiEmpleados.get_nodo_ap(1);

    if (aux->info.getNumId() == id)
    {
      return multiEmpleados.cab;
    }

    for (i = 1; i <= multiEmpleados.get_tam(); i++)
    {
      aux = multiEmpleados.get_nodo_ap(i);
      auxSig = aux->sig;
      if (auxSig->info.getNumId() == id)
      {
        return aux;
      }
    }
    return NULL;
  }

  void eliminar(Nodo<Empleado> *anterior)
  {
    // se conectan en anterior y el sig del que se va a eliminar
    Nodo<Empleado> *empEliminar = anterior->sig;
    anterior->sig = empEliminar->sig;

    Empleado *em = &empEliminar->info;
    eliminarCabNomSucursal(em);
    eliminarCabSexo(em);
    eliminarCabCiudadNa(em);
    eliminarCabPaisNa(em);
    eliminarCabCiudadRe(em);
    eliminarCabBarrio(em);
    eliminarCabAct(em);
    // eliminarCabEdad(em);
    eliminarCabNumHijos(em);

    delete empEliminar;
  }

  void eliminarCabSexo(Empleado *empEliminar)
  {
    int i = 1;
    string sexo;
    Empleado *antCab = empEliminar->antSexo;
    Empleado *sigCab = empEliminar->sigSexo;

    sigCab->antSexo = antCab;

    if (antCab == NULL)
    {

      if (empEliminar->getSexo() == 'F')
      {
        sexo = "femenino";
      }
      else
      {
        sexo = "masculino";
      }

      while (nomCabeceras.get_info(i).nomLista != sexo)
      {
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigSexo = sigCab;
    }
  }

  void eliminarCabNomSucursal(Empleado *empEliminar)
  {
    int i = 1;
    string nomSucursal;

    Empleado *antCab = empEliminar->antNomSucursal;
    Empleado *sigCab = empEliminar->sigNomSucursal;

    sigCab->antNomSucursal = antCab;

    if (antCab == NULL)
    {
      nomSucursal = empEliminar->getNombreSucursal();
      while (nomCabeceras.get_info(i).nomLista != nomSucursal)
      {
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigNomSucursal = sigCab;
    }
  }

  void eliminarCabCiudadNa(Empleado *empEliminar)
  {
    int i = 1;
    string ciudadNa;

    Empleado *antCab = empEliminar->antCiudadNa;
    Empleado *sigCab = empEliminar->sigCiudadNa;

    sigCab->antCiudadNa = antCab;

    if (antCab == NULL)
    {
      ciudadNa = empEliminar->getCiudadNacimiento();
      while (nomCabeceras.get_info(i).nomLista != ciudadNa)
      {
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigCiudadNa = sigCab;
    }
  }

  void eliminarCabCiudadRe(Empleado *empEliminar)
  {
    int i = 1;
    string ciudadRe;

    Empleado *antCab = empEliminar->antCiudadRe;
    Empleado *sigCab = empEliminar->sigCiudadRe;

    sigCab->antCiudadRe = antCab;

    if (antCab == NULL)
    {
      ciudadRe = empEliminar->getCiudadResidencia();
      while (nomCabeceras.get_info(i).nomLista != ciudadRe)
      {
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigCiudadRe = sigCab;
    }
  }

  void eliminarCabPaisNa(Empleado *empEliminar)
  {
    int i = 1;
    string paisNa;

    Empleado *antCab = empEliminar->antPaisNa;
    Empleado *sigCab = empEliminar->sigPaisNa;

    sigCab->antPaisNa = antCab;

    if (antCab == NULL)
    {
      paisNa = empEliminar->getPaisNacimiento();
      while (nomCabeceras.get_info(i).nomLista != paisNa){
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigPaisNa = sigCab;
    }
  }

    void eliminarCabBarrio(Empleado *empEliminar)
  {
    int i = 1;
    string barrio;

    Empleado *antCab = empEliminar->antBarrio;
    Empleado *sigCab = empEliminar->sigBarrio;

    sigCab->antBarrio = antCab;

    if (antCab == NULL)
    {
      barrio = empEliminar->getBarrio();
      while (nomCabeceras.get_info(i).nomLista != barrio){
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigBarrio = sigCab;
    }
  }

  void eliminarCabAct(Empleado *empEliminar)
  {
    int i = 1;
    string act;

    Empleado *antCab = empEliminar->antAct;
    Empleado *sigCab = empEliminar->sigAct;

    sigCab->antAct = antCab;

    if (antCab == NULL)
    {
      act = empEliminar->getActividadLaboral();
      while (nomCabeceras.get_info(i).nomLista != act){
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigAct = sigCab;
    }
  }

  void eliminarCabEdad(Empleado *empEliminar)
  {
    int i = 1;
    string edad;

    Empleado *antCab = empEliminar->antEdad;
    Empleado *sigCab = empEliminar->sigEdad;

    sigCab->antEdad = antCab;

    if (antCab == NULL)
    {
      edad = empEliminar->getEdad();
      while (nomCabeceras.get_info(i).nomLista != edad){
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigEdad= sigCab;
    }
  }

  void eliminarCabNumHijos(Empleado *empEliminar)
  {
    int i = 1;
    string numHijos;

    Empleado *antCab = empEliminar->antNumHijos;
    Empleado *sigCab = empEliminar->sigNumHijos;

    sigCab->antNumHijos = antCab;

    if (antCab == NULL)
    {
      numHijos = empEliminar->getHijos().get_tam();
      while (nomCabeceras.get_info(i).nomLista != numHijos){
        i++;
      }

      nomCabeceras.get_info_ap(i)->cabEmpleado = sigCab;
    }
    else
    {
      antCab->sigNumHijos = sigCab;
    }
  }

}; // AQUIIIIIIIII

#endif
