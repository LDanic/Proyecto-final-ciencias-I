//
// Created by vadan on 26/11/2023.
//

#ifndef PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H
#define PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H

#include "multilistaEmpleado.h"
#include "arbolRJ.h"
#include "ordenamiento/mergesort.h"

class Consultas{

    MultiListaEmpleado multi;

public:
    Consultas(){
    }

    ArbolRojiNegro<Cab, string> arbolCabeceras();
    void consulta1();
    Pos<Empleado, string> * consulta2(string);
    void consulta3();
    void consulta4();
    void consulta5();
    void consulta6();
    void setMulti(MultiListaEmpleado multiL);
};

ArbolRojiNegro<Cab, string> Consultas::arbolCabeceras() {
    ArbolRojiNegro<Cab, string> arbolRJ;
    int i;
    Cab info;
    string llave;

    for(i=1; i<=multi.nomCabeceras.get_tam(); i++){
        info =multi.nomCabeceras.get_info(i);
        llave = multi.nomCabeceras.get_info(i).nomLista;
        arbolRJ.insertarNodo(llave, info);
    }

    return arbolRJ;
}

//Listado de los nombres y apellidos de aquellos que tienen un numero de hijos dado (en rangos),
// clasificandolos por ciudad y pais en que viven.
Pos<Empleado, string> * Consultas::consulta2(string numHijos) {

    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Cab cabecera = arbolRJ.buscar(numHijos)->info;//Se busca la cabecera que se necesita para la busqueda
    Pos<Empleado, string> *resultado = new Pos<Empleado, string>[cabecera.numRegistros];//se crea un arreglo con empleados y un atring
    Pos<Empleado, string> posI;//se crea un auxiliar para ir anadiendo al array de resultado.

    Empleado *Aux = cabecera.cabEmpleado;//aux se iguala al primer empleado de la cabecera

    for(int i=0; i<cabecera.numRegistros; i++){
        posI.info = *Aux;//la informacion asociada sera el empleado
        posI.clave = posI.info.getPaisNacimiento()+"-"+posI.info.getCiudadNacimiento();//la clase sera la cuidad y pais de nacimiento, este sera el criterio de organizacion
        resultado[i] = posI;//se añade esa informacion al arreglo
        Aux = Aux->sigNumHijos;//se continua con el siguiente empleado en la categoria
    }

    MergeSort<Empleado, string> mergeSort;
    mergeSort.sort(resultado, cabecera.numRegistros);//se organiza por el criterio puesto (la clave)

    return resultado;//se retorna el array organizado
}


void Consultas::setMulti(MultiListaEmpleado multiL) {
    multi = multiL;
}
#endif //PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H
