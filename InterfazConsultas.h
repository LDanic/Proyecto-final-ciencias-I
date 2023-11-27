//
// Created by vadan on 26/11/2023.
//

#ifndef PROYECTO_FINAL_CIENCIAS_I_INTERFAZCONSULTAS_H
#define PROYECTO_FINAL_CIENCIAS_I_INTERFAZCONSULTAS_H

#include "consultas.h"

class InterfazConsultas{
    Consultas consultas;

    InterfazConsultas(){

    }

    /*Consultas consultas;
    consultas.setMulti(multi);
    Pos<Sucursal, int> *resul=consultas.consulta4(2, gS.sucursales);


    for(int i=0; i<consultas.tamActual; i++){
        cout<<resul[i].clave<<"-";
        cout<<resul[i].info[0]
        cout<<resul[i].info.getNombre()<<endl;
    }*/

    void consulta1();
    void consulta2(string);
    void consulta4(int, Lista<Sucursal>);
    void consulta6(string, string);
};

void InterfazConsultas::consulta2(string numHijos) {
    Pos<string *, string> * resul = consultas.consulta2(numHijos);
    string anteriorClave = resul[0].clave;

    for(int i=0; i<consultas.tamActual; i++){
        if(anteriorClave != resul[i].clave) {
            cout << resul[i].clave<<endl;
        }
        cout <<"Nombre: "+resul[i].info[0]<<endl;
        cout <<"Apellido: "+resul[i].info[1]<<endl;
    }
}

void InterfazConsultas::consulta4(int numEmpleados, Lista<Sucursal> sucursales) {
    Pos<Sucursal, int> *resul=consultas.consulta4(numEmpleados, sucursales);
    int anteriorClave = resul[0].clave;
    Sucursal sucuAux;

    for(int i=0; i<consultas.tamActual; i++){
        if(anteriorClave != resul[i].clave){
            cout<<"Num empleados: "+resul[i].clave<<endl;
        }
        sucuAux = resul[i].info;
        cout<<"Nom sucursal: "+sucuAux.getNombre()<<endl;
        cout<<"Nom gerente: "+sucuAux.getNomGerente()<<endl;
        cout<<"Barrio: "+sucuAux.getBarrio()<<endl;
    }
}

void InterfazConsultas::consulta6(string rangoEdad, string Act) {
    Pos<Empleado, string> *resul=consultas.consulta6(rangoEdad, Act);
    string anteriorClave = resul[0].clave;
    Empleado empAux;

    for(int i=0; i<consultas.tamActual; i++){
        if(anteriorClave != resul[i].clave){
            cout<<resul[i].clave<<endl;
        }
        empAux = resul[i].info;
        cout<<"Nombre: "+empAux.getNombre()<<endl;
        cout<<"Apellido"+empAux.getApellido()<<endl;
        cout<<"Edad: "+empAux.getEdad()<<endl;
        cout<<"Actividad laboral: "+empAux.getActividadLaboral()<<endl;
    }
}


#endif //PROYECTO_FINAL_CIENCIAS_I_INTERFAZCONSULTAS_H
