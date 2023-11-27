/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

#include "empleados.h"
#include "estructuras/Lista.h"
#include "estructuras/multilistaEmpleado.h"
#include "manejo_archivos/ObjetosToArchivos.h"
#include "gestionPersistencia.h"
#include "gestionSucursales.h"
#include "VistaConsola.h"
#include "consultas.h"
using namespace std;
class Controlador
{
public:
    MultiListaEmpleado mul;
    gestionPersistencia gP;
    gestionSucursales gs;
    Lista<Sucursal> sucursales;
    Vista vista;
    Consultas consultar;
    void ingresarEmpleado();
    void ingresarSucursal();
    void mostrarMenuP();
    void realizarConsultas();
    void eliminarEmpleado();
    void editarInformacionEmpleado();
    void Consulta1();
    void Consulta2();
    void Consulta3();
    void Consulta4();
    void Consulta5();
    void Consulta6();
    void ejecutar()
    {
        mul = gP.construirMulti();
        sucursales = gP.construirSucursales();
        mostrarMenuP();
    }
    void finalizar()
    {
        gP.guardarMulti(mul);
        // gP.guardarSucursales(sucursales);
    }
};

void Controlador::ingresarEmpleado()
{
    Empleado em = vista.mostrarSubMenuInsercion();
    if (mul.buscarPorID(em.getNumId()) == NULL)
    {
        mul.insertar(em);
    }
    mostrarMenuP();
}

void Controlador::ingresarSucursal()
{
    Sucursal suc = vista.mostrarSubMenuInsercionS();
    sucursales.insertar_final(suc);
    mostrarMenuP();
}

void Controlador::mostrarMenuP()
{
    int opcionSeleccionada = vista.mostrarMenu();

    switch (opcionSeleccionada)
    {
    case 1:
        ingresarEmpleado();
        break;
    case 2:
        ingresarSucursal();
        break;
    case 3:
        eliminarEmpleado();
        break;
    case 4:
        editarInformacionEmpleado();
        break;
    case 5:
        realizarConsultas();
        break;
    case 6:
        finalizar();
        break;
    default:
        mostrarMenuP();
        break;
    }
}
void Controlador::realizarConsultas()
{
    int opcion = vista.mostrarMenuConsultas();

    switch (opcion)
    {
    case 1:
        Consulta1();
        break;
    case 2:
        Consulta2();
        break;
    case 3:
        Consulta3();
        break;
    case 4:
        Consulta4();
        break;
    case 5:
        Consulta5();
        break;

    case 6:
        Consulta6();
        break;
    }

    mostrarMenuP();
}
void Controlador::eliminarEmpleado()
{
    int id = vista.buscarempleado();

    mul.eliminar(mul.buscarAnt(id));

    mostrarMenuP();
}
void Controlador::editarInformacionEmpleado()
{
    int id = vista.buscarempleado();
    Empleado *em1 = mul.buscarPorID(id);
    Empleado em = vista.editarEmp(em1);
    mul.actualizarEmp(em);
    mostrarMenuP();
}

void Controlador::Consulta1()
{
    consultar.setMulti(mul);
}

void Controlador::Consulta2()
{
    consultar.setMulti(mul);
    int seleccion = vista.solicitarConsulta2();

    string rangoH;

    switch (seleccion)
    {
    case 1:
        rangoH = "sin hijos";
        break;
    case 2:
        rangoH = "1-2";
        break;
    case 3:
        rangoH = "3-4";
        break;
    case 4:
        rangoH = "mas de 4";
        break;
    }

    Pos<string *, string> *resultado = consultar.consulta2(rangoH);

     vista.retornarConsulta2(resultado,consultar.tamActual);
}
void Controlador::Consulta3()
{
    consultar.setMulti(mul);
}
void Controlador::Consulta4()
{
    consultar.setMulti(mul);
    int seleccion = vista.solicitarConsulta4();
    Pos<Sucursal, int> *resultado = consultar.consulta4(seleccion,sucursales);
    vista.retornarConsulta4(resultado, consultar.tamActual);

}
void Controlador::Consulta5()
{
    consultar.setMulti(mul);
}
void Controlador::Consulta6()
{
    string rangoE;
    string Act;
    consultar.setMulti(mul);
    int seleccion = vista.solicitarConsulta6_1();
    switch (seleccion)
    {
        case 1:
            rangoE = "18 a 24";
            break;
        case 2:
            rangoE = "25 a 35";
            break;
        case 3:
            rangoE = "36 a 45";
            break;
        case 4:
            rangoE = "45 a 60";
            break;
        case 5:
            rangoE = "mas de 60";
            break;
    }
    int actividad= vista.solicitarConsulta6_2();
    switch (actividad)
    {
        case 1:
            Act = "Artes";
            break;
        case 2:
            Act = "Ciencias sociales";
            break;
        case 3:
            Act = "Ingenierias";
            break;
        case 4:
            Act = "Areas de la salud";
            break;
        case 5:
            Act = "otros";
            break;
    }
    Pos<Empleado, string> *resultado= consultar.consulta6(rangoE,Act);
    vista.retornarConsulta6(resultado, consultar.tamActual);

}
