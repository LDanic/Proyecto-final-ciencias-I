/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef EMPLEADOS_H
#define EMPLEADOS_H
// librerias necesarias
#include "estructuras/Lista.h"
#include "hijos.h"

using namespace std;
// declaracion de la clase
class Empleado {

private:
    string nombre, apellido, tipoId, correo, fNa, ciudadNa, paisNa, ciudadRe,
            direccion, barrio, actividadLaboral, nomSucursal;
    long numId;
    char sexo;
    int cel, fijo, edad;
    Lista<Hijo> hijos;

public:
    Empleado *sigSexo, *sigCiudadNa, *sigPaisNa, *sigCiudadRe, *sigBarrio,
            *sigAct, *sigEdad, *sigNumHijos, *sigNomSucursal, *antSexo, *antCiudadNa,
            *antPaisNa, *antCiudadRe, *antBarrio, *antAct, *antEdad, *antNumHijos,
            *antNomSucursal;
    // constructor por defecto
    Empleado() {

        nombre = " ";
        apellido = " ";
        tipoId = " ";
        correo = " ";
        fNa = " ";
        ciudadNa = " ";
        paisNa = " ";
        ciudadRe = " ";
        direccion = " ";
        barrio = " ";
        actividadLaboral = " ";
        nomSucursal = " ";
        numId = 0;
        sexo = 'F';
        cel = 0, fijo = 0, edad = 0;
        sigSexo = NULL;
        sigCiudadNa = NULL;
        sigPaisNa = NULL;
        sigCiudadRe = NULL;
        sigBarrio = NULL;
        sigAct = NULL;
        sigEdad = NULL;
        sigNumHijos = NULL;
        sigNomSucursal = NULL;
        antSexo = NULL;
        antCiudadNa = NULL;
        antPaisNa = NULL;
        antCiudadRe = NULL;
        antBarrio = NULL;
        antAct = NULL;
        antEdad = NULL;
        antNumHijos = NULL;
        antNomSucursal = NULL;
    }

    Empleado(string nombre, string apellido, string tipoId, string correo,
             string fNa, string ciudadNa, string paisNa, string ciudadRe,
             string direccion, string barrio, string actividadLaboral,
             string nomSucursal, long numId, char sexo, int cel, int fijo)
            : nombre(nombre), apellido(apellido), tipoId(tipoId), correo(correo),
              fNa(fNa), ciudadNa(ciudadNa), paisNa(paisNa), ciudadRe(ciudadRe),
              direccion(direccion), barrio(barrio),
              actividadLaboral(actividadLaboral), nomSucursal(nomSucursal),
              numId(numId), sexo(sexo), cel(cel),
              fijo(fijo), // edad se inicializa después
              sigSexo(NULL), sigCiudadNa(NULL), sigPaisNa(NULL), sigCiudadRe(NULL),
              sigBarrio(NULL), sigAct(NULL), sigEdad(NULL), sigNumHijos(NULL),
              sigNomSucursal(NULL), antSexo(NULL), antCiudadNa(NULL), antPaisNa(NULL),
              antCiudadRe(NULL), antBarrio(NULL), antAct(NULL), antEdad(NULL),
              antNumHijos(NULL), antNomSucursal(NULL) {
        // calcula la edad
        Edad calEdad;
        this->edad = calEdad.calcularEdad(fNa);
    }
    // agrega a los hijos
    void agregarHijo(Hijo hijo) {
        hijo.setApellido(this->apellido);
        hijos.insertar_inicio(hijo);
    }

    // Getters
    string getNombre() { return nombre; }

    string getApellido() { return apellido; }

    string getTipoId() { return tipoId; }

    long getNumId() { return numId; }

    char getSexo() { return sexo; }

    string getCorreo() { return correo; }

    string getFechaNacimiento() { return fNa; }

    string getCiudadNacimiento() { return ciudadNa; }

    string getPaisNacimiento() { return paisNa; }

    string getCiudadResidencia() { return ciudadRe; }

    string getDireccion() { return direccion; }

    string getBarrio() { return barrio; }

    int getCelular() { return cel; }

    int getTelefonoFijo() { return fijo; }

    int getEdad() { return edad; }

    string getActividadLaboral() { return actividadLaboral; }

    string getNombreSucursal() { return nomSucursal; }
    // Setters
    void setNombre(const std::string &nuevoNombre) { nombre = nuevoNombre; }

    void setApellido(const string &nuevoApellido) {
        apellido = nuevoApellido;
    }

    void setTipoID(const string &nuevoTipoID) { tipoId = nuevoTipoID; }

    void setCorreo(const string &nuevoCorreo) { correo = nuevoCorreo; }

    void setFechaNacimiento(const string &nuevaFechaNacimiento) {
        fNa = nuevaFechaNacimiento;
    }

    void setCiudadNacimiento(const string &nuevaCiudadNacimiento) {
        ciudadNa = nuevaCiudadNacimiento;
    }

    void setPaisNacimiento(const string &nuevoPaisNacimiento) {
        paisNa = nuevoPaisNacimiento;
    }

    void setCiudadResidencia(const string &nuevaCiudadResidencia) {
        ciudadRe = nuevaCiudadResidencia;
    }

    void setDireccion(const string &nuevaDireccion) {
        direccion = nuevaDireccion;
    }

    void setBarrio(const string &nuevoBarrio) { barrio = nuevoBarrio; }

    void setActividadLaboral(const string &nuevaActividadLaboral) {
        actividadLaboral = nuevaActividadLaboral;
    }

    void setNombreSucursal(const std::string &nuevoNombreSucursal) {
        nomSucursal = nuevoNombreSucursal;
    }

    void setNumeroID(long nuevoNumeroID) { numId = nuevoNumeroID; }

    void setSexo(char nuevoSexo) { sexo = nuevoSexo; }

    void setTelefonoCelular(int nuevoTelefonoCelular) {
        cel = nuevoTelefonoCelular;
    }

    void setTelefonoFijo(int nuevoTelefonoFijo) { fijo = nuevoTelefonoFijo; }

    Lista<Hijo> getHijos() { return hijos; }
};

#endif
