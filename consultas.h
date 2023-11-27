

#ifndef PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H
#define PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H

#include "multilistaEmpleado.h"
#include "arbolRJ.h"
#include "ordenamiento/mergesort.h"
#include "sucursal.h"
#include <string>


class Consultas{

    MultiListaEmpleado multi;

public:
    int tamActual = 0;
    Consultas(){
    }

    ArbolRojiNegro<Cab, string> arbolCabeceras();
    void consulta1();
    Pos<string *, string> * consulta2(string);
    Pos<string *, string> *  consulta3(string);
    Pos<Sucursal, int> * consulta4(int, Lista<Sucursal>);
    Pos<string *, string> * consulta5(Lista<Sucursal>);
    Pos<Empleado, string> * consulta6(string, string);
    void setMulti(MultiListaEmpleado multiL);
};

ArbolRojiNegro<Cab, string> Consultas::arbolCabeceras(){
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
        posI.clave = Aux->getPaisNacimiento()+"-"+Aux->getCiudadNacimiento();//la clave sera la cuidad y pais de nacimiento, este sera el criterio de organizacion
        resultado[i] = posI;//se añade esa informacion al arreglo
        Aux = Aux->sigNumHijos;//se continua con el siguiente empleado en la categoria
    }

    MergeSort<string *, string> mergeSort;
    mergeSort.sort(resultado, cabecera.numRegistros);//se organiza por el criterio puesto (la clave)
    tamActual = cabecera.numRegistros;

    return resultado;//se retorna el array organizado
}

//Nombre y apellidos de las personas que viven en una ciudad dada, clasificandolos por ciudad
// de nacimiento y actividad laboral

Pos<string *, string> *  Consultas::consulta3(string ciudad) {

    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Cab cabecera = arbolRJ.buscar(ciudad+"RE")->info;//Se busca la cabecera que se necesita para la busqueda
    string *info;
    Pos<string *, string> *resultado = new Pos<string *, string>[cabecera.numRegistros];//se crea un arreglo con un arreglo de strings y un string
    Pos<string *, string> posI;//se crea un auxiliar para ir anadiendo al array de resultado.

    Empleado *Aux = cabecera.cabEmpleado;//aux se iguala al primer empleado de la cabecera

    for(int i=0; i<cabecera.numRegistros; i++){
        info = new string [2];
        info[0] = Aux->getNombre();
        info[1] = Aux->getApellido();//se anade en un arreglo la info solicitada

        posI.info = info;//se guarda el arreglo en el campo de la info asociada
        posI.clave = Aux->getCiudadNacimiento()+"-"+Aux->getActividadLaboral();//la clave sera la cuidadNa y la actividad laboral, este sera el criterio de organizacion
        resultado[i] = posI;//se añade esa informacion al arreglo
        Aux = Aux->sigCiudadRe;//se continua con el siguiente empleado en la categoria
    }

    MergeSort<string *, string> mergeSort;
    mergeSort.sort(resultado, cabecera.numRegistros);//se organiza por el criterio puesto (la clave)
    tamActual = cabecera.numRegistros;

    return resultado;//se retorna el array organizado

}

//Numero de sucursales en las que trabaja un numero de personas superior a un numero dado,
// mostrando la cantidad de personas en cada sucursal junto con el nombre del gerente, el nombre de la sucursal
//y el barrio en el que se encuentra ubicada dicha sucursal
Pos<Sucursal, int> * Consultas::consulta4(int numEmpleados, Lista<Sucursal> sucursales) {
    Sucursal Aux;
    int j =0, numRegistros;
    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Pos<Sucursal, int> *resultado = new Pos<Sucursal, int>[sucursales.get_tam()];//se crea un arreglo con un sucursales y un int
    for(int i=1; i<=sucursales.get_tam(); i++){
        Aux = sucursales.get_info(i);
        numRegistros = arbolRJ.buscar(Aux.getNombre()+"SU")->info.numRegistros;//se buscan las cabeceras de sucursales

        if(numRegistros>=numEmpleados){//si cumplen con el numero de empleados se guardan en el array resultado
            resultado[j].info = Aux;
            resultado[j].clave = numRegistros;
            j++;
        }
    }


    MergeSort<Sucursal, int> mergeSort;
    mergeSort.sort(resultado, j);//se organiza por el numero de empleados
    tamActual = j;

    return resultado;//se retorna el array organizado
}

// Obtener el numero de hombres y el numero de mujeres que trabajan en las diferentes
// sucursales, clasificando la informacion por pais y por ciudad, mostrando el nombre de la
// sucursal y el gerente

Pos<string *, string> * Consultas::consulta5(Lista<Sucursal> sucursales) {
    int i, j, numH, numM;
    numH = numM = 0;
    Sucursal Aux;
    Empleado *AuxE;
    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Cab cabecera;
    string *info;
    Pos<string *, string> *resultado = new Pos<string *, string>[sucursales.get_tam()];//se crea un arreglo con un arreglo de strings y un string
    Pos<string *, string> posI;//se crea un auxiliar para ir anadiendo al array de resultado.

    for(i = 0; i < sucursales.get_tam(); i++){
        Aux = sucursales.get_info(i+1); // se busca la cabecera de la lista sucursales en la posicion i
        cabecera = arbolRJ.buscar(Aux.getNombre()+"SU")->info; // Se busca la cabecera en el arbol
        AuxE = cabecera.cabEmpleado;
        for (j = 0; j< cabecera.numRegistros; j++) { //Se verifica si es hombre o mujer.
            if(AuxE->getSexo() == 'F'){
                numM++;
            } else {
                numH++;
            }
        }
        info = new string[4];
        info[0] = to_string(numH) + " Hombres";
        info[1] = to_string(numM) + " Mujeres";
        info[2] = Aux.getNombre();
        info[3] = Aux.getNomGerente();

        resultado[i].info = info;
        resultado[i].clave = AuxE->getPaisNacimiento()+"-"+AuxE->getCiudadNacimiento();
    }

    MergeSort<string *, string> mergeSort;
    mergeSort.sort(resultado, sucursales.get_tam());//se organiza por el numero de empleados
    tamActual = sucursales.get_tam();

    return resultado;//se retorna el array organizado
}



//Dado un rango de edad y una actividad laboral mostrar la lista de trabajadores de esas edad,
// clasificados por barrio y sucursal a la que pertenecen
Pos<Empleado, string> *Consultas::consulta6(string rangoEdad, string Act) {
    int j=0;
    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Cab cabecera = arbolRJ.buscar(rangoEdad)->info;//Se busca la cabecera que se necesita para la busqueda


    Pos<Empleado, string> *resultado = new Pos<Empleado, string>[cabecera.numRegistros];//se crea un arreglo con un arreglo de Empleados y un string

    Empleado *Aux = cabecera.cabEmpleado;//aux se iguala al primer empleado de la cabecera

    for(int i=0; i<cabecera.numRegistros; i++){
        if(Aux->getActividadLaboral() == Act){
            resultado[j].info = *Aux;//se guarda el empleado en la info asociada
            resultado[j].clave = Aux->getNombreSucursal()+"-"+Aux->getBarrio();//la clave sera la sucursal y el barrio, este sera el criterio de organizacion
            j++;
        }
        Aux = Aux->sigEdad;//se continua con el siguiente empleado en la categoria
    }

    MergeSort<Empleado, string> mergeSort;
    mergeSort.sort(resultado, j);//se organiza por el criterio puesto (la clave)

    tamActual = j;
    return resultado;//se retorna el array organizado
}


void Consultas::setMulti(MultiListaEmpleado multiL) {
    multi = multiL;
}


#endif //PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H
