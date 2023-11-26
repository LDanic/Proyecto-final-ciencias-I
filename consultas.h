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
    Pos<string *, string> * consulta2(string);
    void consulta3();
    Pos<Empleado, string> * consulta4(string);
    void consulta5();
    Pos<Empleado, string> * consulta6(string);
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
Pos<string *, string> * Consultas::consulta2(string numHijos) {

    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Cab cabecera = arbolRJ.buscar(numHijos)->info;//Se busca la cabecera que se necesita para la busqueda
    string *info;
    Pos<string *, string> *resultado = new Pos<string *, string>[cabecera.numRegistros];//se crea un arreglo con un arreglo de strings y un string
    Pos<string *, string> posI;//se crea un auxiliar para ir anadiendo al array de resultado.

    Empleado *Aux = cabecera.cabEmpleado;//aux se iguala al primer empleado de la cabecera

    for(int i=0; i<cabecera.numRegistros; i++){
        info = new string [2];
        info[0] = Aux->getNombre();
        info[1] = Aux->getApellido();//se anade en un arreglo la info solicitada

        posI.info = info;//se guarda el arreglo en el campo de la info asociada
        posI.clave = Aux->getPaisNacimiento()+"-"+Aux->getCiudadNacimiento();//la clase sera la cuidad y pais de nacimiento, este sera el criterio de organizacion
        resultado[i] = posI;//se añade esa informacion al arreglo
        Aux = Aux->sigNumHijos;//se continua con el siguiente empleado en la categoria
    }

    MergeSort<string *, string> mergeSort;
    mergeSort.sort(resultado, cabecera.numRegistros);//se organiza por el criterio puesto (la clave)

    return resultado;//se retorna el array organizado
}

//Numero de sucursales en las que trabaja un numero de personas superior a un numero dado,
// mostrando la cantidad de personas en cada sucursal junto con el nombre del gerente, el nombre de la sucursal
//y el barrio en el que se encuentra ubicada dicha sucursal

Pos<Empleado, string> *Consultas::consulta4(string) {
    return nullptr;
}


//Dado un rango de edad y una actividad laboral mostrar la lista de trabajadores de esas edad,
// clasificados por barrio y sucursal a la que pertenecen
Pos<Empleado, string> *Consultas::consulta6(string) {
    return nullptr;
}


void Consultas::setMulti(MultiListaEmpleado multiL) {
    multi = multiL;
}


#endif //PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H
