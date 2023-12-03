

#ifndef PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H
#define PROYECTO_FINAL_CIENCIAS_I_CONSULTAS_H

#include "estructuras/multilistaEmpleado.h"
#include "estructuras/arbolRJ.h"
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
    Pos<Empleado, string> *consulta1(string);
    Pos<string *, string> * consulta2(string);
    Pos<string *, string> *  consulta3(string);
    Pos<Sucursal, int> * consulta4(int, Lista<Sucursal>);
    Pos<string, string> * consulta5(Lista<Sucursal>);
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

//Numero total de personas que trabajan en una sucursal dada,
// clasificandolos, por rangos de edades de los hijos de la siguiete forma: sin hijos, de 0-5,
//6-10, 11-18, mayor de 18.
Pos<Empleado, string> *Consultas::consulta1(string nomSucu) {
    Lista<Hijo> hijos;
    int edad, k = 0, hijosTotales =0;
    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.


    Cab cabecera = arbolRJ.buscar(nomSucu+"SU")->info;//Se busca la cabecera que se necesita para la busqueda

    Empleado *auxE = cabecera.cabEmpleado;//aux se iguala al primer empleado de la cabecera

    for(int i=0; i<cabecera.numRegistros; i++){
        hijosTotales += auxE->getHijos().get_tam();

        if(auxE->getHijos().get_tam() == 0){
            hijosTotales++;
        }
        auxE= auxE->sigNomSucursal;
    }

    Pos<Empleado, string> *resultado = new Pos<Empleado, string>[hijosTotales];//se crea un arreglo con un arreglo de Empleados y un string

    auxE = cabecera.cabEmpleado;
    for(int i=0; i<cabecera.numRegistros; i++){
        hijos = auxE->getHijos();

        if(hijos.get_tam() == 0){
            resultado[k].info = *auxE;
            resultado[k].clave = "sin hijos";
            k++;

        }else{

            for(int j=0; j<hijos.get_tam(); j++){
                edad = hijos.get_info(j+1).getEdad();

                if(edad>=0 && edad<=5){
                    resultado[k].info = *auxE;
                    resultado[k].clave = "0-5";
                    k++;
                }else if(edad>=6 && edad<=10){
                    resultado[k].info = *auxE;
                    resultado[k].clave = "6-10";
                    k++;
                }else if(edad>=11 && edad<=18){
                    resultado[k].info = *auxE;
                    resultado[k].clave = "11-18";
                    k++;
                }else{
                    resultado[k].info = *auxE;
                    resultado[k].clave = "mas de 18";
                    k++;
                }
            }
        }

        auxE = auxE->sigNomSucursal;
    }

    MergeSort<Empleado, string> mergeSort;
    mergeSort.sort(resultado, hijosTotales);//se organiza por el criterio puesto (la clave)
    tamActual = hijosTotales;

    return resultado;

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

Pos<string, string> * Consultas::consulta5(Lista<Sucursal> sucursales) {
    int i, j, numH, numM;
    string general, claveAnterior;
    general = "";
    numH = numM = 0;
    Sucursal Aux;
    Empleado *AuxE;
    ArbolRojiNegro<Cab, string> arbolRJ;
    arbolRJ = arbolCabeceras();//se organizan las cabeceras en un arbol rojiNegro.

    Cab cabecera;
    string *info;
    Pos<string, string> *resultado = new Pos<string, string>[sucursales.get_tam()];//se crea un arreglo con un arreglo de strings y un string
    Pos<Empleado, string> *sucuAux;
    Pos<string *, string> posI;//se crea un auxiliar para ir anadiendo al array de resultado.

    for(i = 0; i < sucursales.get_tam(); i++){
        Aux = sucursales.get_info(i+1); // se busca la cabecera de la lista sucursales en la posicion i
        cabecera = arbolRJ.buscar(Aux.getNombre()+"SU")->info; // Se busca la cabecera en el arbol
        if(cabecera.nomLista != ""){
            AuxE = cabecera.cabEmpleado;

            sucuAux = new Pos<Empleado, string>[cabecera.numRegistros];
            for (j = 0; j< cabecera.numRegistros; j++) {

                sucuAux[j].clave = AuxE->getPaisNacimiento()+"-"+AuxE->getCiudadNacimiento();
                sucuAux[j].info = *AuxE;
                AuxE = AuxE->sigNomSucursal;
            }

            MergeSort<Empleado, string> mergeAux;
            mergeAux.sort(sucuAux, cabecera.numRegistros);//se organiza por ciudad y pais

            claveAnterior = sucuAux[0].clave;

            general = "";
            for (j = 0; j< cabecera.numRegistros; j++){
                if(claveAnterior != sucuAux[j].clave){
                    general += claveAnterior+": Mujeres="+ to_string(numM)+", Hombres="+ to_string(numH)+"\n";
                    claveAnterior = sucuAux[j].clave;
                    numH = numM = 0;
                }

                if(sucuAux[j].info.getSexo() == 'F'){
                    numM++;
                }else{
                    numH++;
                }

                if(j==cabecera.numRegistros-1){
                    general += claveAnterior+": Mujeres="+ to_string(numM)+", Hombres="+ to_string(numH)+"\n";
                    claveAnterior = sucuAux[j].clave;
                    numH = numM = 0;
                }
            }

            general += "\nNom sucursal: "+Aux.getNombre()+", Gerente: "+Aux.getNomGerente()+"\n";
            resultado[i].info = general;
            resultado[i].clave = "";
        }else{
            resultado[i].info = "no hay empleados";
            resultado[i].clave = "";
        }
    }
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
