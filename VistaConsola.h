/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/

#include <iostream>
#include "empleados.h"
#include "sucursal.h"
#include "hijos.h"
#include "ordenamiento/mergesort.h"
using namespace std;

class Vista
{
public:
    // metodos
    int mostrarMenu();
    int mostrarMenuConsultas();
    int buscarempleado();
    Empleado mostrarSubMenuInsercion();
    Sucursal mostrarSubMenuInsercionS();
    Empleado editarEmp(Empleado *emp);
    void retornarConsulta2();
    int solicitarConsulta2();
    int solicitarConsulta6_1();
    int solicitarConsulta6_2();
    void retornarConsulta4();
    void retornarConsulta6();

    int solicitarConsulta4();
};

int Vista::mostrarMenu()
{
    // mostrar opciones
    int opcion;
    cout << "Bienvenido al sistema de informacion de la empresa, que desea hacer, seleccione una opcion\n";
    cout << "1. Ingresar un empleado\n";
    cout << "2. Ingresar una sucursal\n";
    cout << "3. Eliminar un empleado\n";
    cout << "4. Editar la información de un empleado\n";
    cout << "5. Realizar consultas de información \n";
    cout << "6. Salir\n";
    cin >> opcion;
    // retornar opcion
    return opcion;
}

int Vista::mostrarMenuConsultas()
{ // mostrar opciones
    int opcion;
    cout << "seleccione una opcion para consultar";
    cout << "1.	Número total de personas que trabajan en una sucursal dada,\n clasificándolos por rangos de edades de los hijos de la siguiente forma: sin hijos, de 0-5, 6-10, 11-18, mayor de 18. \n";
    cout << "2.	Listado de los nombres y apellidos de aquellos que tienen  un número de hijos dado (en rangos)\n, clasificándolos por ciudad y país en que viven.";
    cout << "3.	Nombre y apellidos de las personas que viven en una ciudad dada,\n  clasificándolos por ciudad de nacimiento y actividad laboral. ";
    cout << "4. Número de sucursales en las que trabaja un número de personas superior a un número dado,\n mostrando la cantidad de personas de cada sucursal junto con el nombre del gerente,\n el nombre de la sucursal y el barrio en que se encuentra ubicada dicha sucursal. \n";
    cout << "5. Obtener el número de hombres y el número de mujeres que trabajan en las diferentes sucursales,\n clasificando la información por país y ciudad, mostrando el nombre de la sucursal y del gerente. \n";
    cout << "6. Dado un rango de edad y una actividad laborar mostrar la lista de trabajadores de esa edad, clasificados por barrio y sucursal a la que pertenecen.\n";
    cin >> opcion;
    return opcion;
}

int Vista::buscarempleado()
{
    int opcion;
    cout << "Ingrese el codigo del empleado a buscar/eliminar" << endl;
    cin >> opcion;

    return opcion;
}

Empleado Vista::mostrarSubMenuInsercion()
{
    string nombre, apellido, tipoId, correo,
        fNa, ciudadNa, paisNa, ciudadRe,
        direccion, barrio, actividadLaboral,
        nomSucursal;
    long numId;
    char sexo;
    int cel, fijo;

    cout << "Ingrese el nombre del empleado: ";
    cin.ignore(); // Descarta el carácter de nueva línea pendiente en el búfer
    getline(cin, nombre);

    cout << "Ingrese el apellido del empleado: ";
    getline(cin, apellido);

    cout << "Ingrese el tipo de identificación del empleado: ";
    getline(cin, tipoId);

    cout << "Ingrese el correo del empleado: ";
    getline(cin, correo);

    cout << "Ingrese la fecha de nacimiento del empleado (formato: aaaa-dd-mm): ";
    getline(cin, fNa);

    cout << "Ingrese la ciudad de nacimiento del empleado: ";
    getline(cin, ciudadNa);

    cout << "Ingrese el país de nacimiento del empleado: ";
    getline(cin, paisNa);

    cout << "Ingrese la ciudad de residencia del empleado: ";
    getline(cin, ciudadRe);

    cout << "Ingrese la dirección del empleado: ";
    getline(cin, direccion);

    cout << "Ingrese el barrio del empleado: ";
    getline(cin, barrio);

    cout << "Ingrese la actividad laboral del empleado: ";
    getline(cin, actividadLaboral);

    cout << "Ingrese el nombre de la sucursal del empleado: ";
    getline(cin, nomSucursal);

    cout << "Ingrese el número de identificación del empleado: ";
    cin >> numId;

    cout << "Ingrese el sexo del empleado (M/F): ";
    cin >> sexo;

    cout << "Ingrese el número de teléfono celular del empleado: ";
    cin >> cel;

    cout << "Ingrese el número de teléfono fijo del empleado: ";
    cin >> fijo;

    Empleado emp(nombre, apellido, tipoId, correo, fNa, ciudadNa, paisNa, ciudadRe,
                 direccion, barrio, actividadLaboral, nomSucursal, numId, sexo, cel, fijo);
    cout << "Ingrese la cantidad de hijos del empleado: ";
    int cantidadHijos;
    cin >> cantidadHijos;

    Lista<Hijo> hijos;

    for (int i = 0; i < cantidadHijos; ++i)
    {
        string nombreHijo, fNacimientoHijo;
        long idPadre;

        cout << "Ingrese el nombre del hijo " << i + 1 << ": ";
        cin >> nombreHijo;

        cout << "Ingrese la fecha de nacimiento del hijo " << i + 1 << " (formato: aaaa-dd-mm): ";
        cin >> fNacimientoHijo;

        idPadre = numId;

        Hijo nuevoHijo(nombreHijo, fNacimientoHijo, idPadre);
        emp.agregarHijo(nuevoHijo);
    }

    return emp;
};

Sucursal Vista::mostrarSubMenuInsercionS()
{
    string nombre, direccion, barrio, nomGerente;

    cout << "Ingrese el nombre de la sucursal: ";
    cin.ignore(); // Descarta el carácter de nueva línea pendiente en el búfer
    getline(cin, nombre);

    cout << "Ingrese la dirección de la sucursal: ";
    getline(cin, direccion);

    cout << "Ingrese el barrio de la sucursal: ";
    getline(cin, barrio);

    cout << "Ingrese el nombre del gerente de la sucursal: ";
    getline(cin, nomGerente);

    // Crear y devolver un objeto Sucursal con los datos ingresados
    return Sucursal(nombre, direccion, barrio, nomGerente);
};

Empleado Vista::editarEmp(Empleado *emp)
{
    Empleado aux = *emp;
    int opcion = 0;
    bool opcionValida = true;

    do
    {
        cout << "Seleccione el atributo a editar:\n"
             << "1. Nombre\n"
             << "2. Apellido\n"
             << "3. Tipo ID\n"
             << "4. Correo\n"
             << "5. Fecha de Nacimiento\n"
             << "6. Ciudad de Nacimiento\n"
             << "7. País de Nacimiento\n"
             << "8. Ciudad de Residencia\n"
             << "9. Dirección\n"
             << "10. Barrio\n"
             << "11. Actividad Laboral\n"
             << "12. Nombre de Sucursal\n"
             << "13. Sexo\n"
             << "14. Teléfono Celular\n"
             << "15. Teléfono Fijo\n"
             << "0. Salir\n";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese el nuevo nombre: ";
            string nuevoNombre;
            cin >> nuevoNombre;
            aux.setNombre(nuevoNombre);
            break;
        }
        case 2:
        {
            cout << "Ingrese el nuevo apellido: ";
            string nuevoApellido;
            cin >> nuevoApellido;
            aux.setApellido(nuevoApellido);
            break;
        }
        case 3:
        {
            cout << "Ingrese el nuevo tipo de ID: ";
            string nuevoTipoID;
            cin >> nuevoTipoID;
            aux.setTipoID(nuevoTipoID);
            break;
        }
        case 4:
        {
            cout << "Ingrese el nuevo correo: ";
            string nuevoCorreo;
            cin >> nuevoCorreo;
            aux.setCorreo(nuevoCorreo);
            break;
        }
        case 5:
        {
            cout << "Ingrese la nueva fecha de nacimiento: ";
            string nuevaFechaNacimiento;
            cin >> nuevaFechaNacimiento;
            aux.setFechaNacimiento(nuevaFechaNacimiento);
            break;
        }
        case 6:
        {
            cout << "Ingrese la nueva ciudad de nacimiento: ";
            string nuevaCiudadNacimiento;
            cin >> nuevaCiudadNacimiento;
            aux.setCiudadNacimiento(nuevaCiudadNacimiento);
            break;
        }
        case 7:
        {
            cout << "Ingrese el nuevo país de nacimiento: ";
            string nuevoPaisNacimiento;
            cin >> nuevoPaisNacimiento;
            aux.setPaisNacimiento(nuevoPaisNacimiento);
            break;
        }
        case 8:
        {
            cout << "Ingrese la nueva ciudad de residencia: ";
            string nuevaCiudadResidencia;
            cin >> nuevaCiudadResidencia;
            aux.setCiudadResidencia(nuevaCiudadResidencia);
            break;
        }
        case 9:
        {
            cout << "Ingrese la nueva dirección: ";
            string nuevaDireccion;
            cin.ignore();
            getline(cin, nuevaDireccion);
            aux.setDireccion(nuevaDireccion);
            break;
        }
        case 10:
        {
            cout << "Ingrese el nuevo barrio: ";
            string nuevoBarrio;
            cin >> nuevoBarrio;
            aux.setBarrio(nuevoBarrio);
            break;
        }
        case 11:
        {
            cout << "Ingrese la nueva actividad laboral: ";
            string nuevaActividadLaboral;
            cin >> nuevaActividadLaboral;
            aux.setActividadLaboral(nuevaActividadLaboral);
            break;
        }
        case 12:
        {
            cout << "Ingrese el nuevo nombre de sucursal: ";
            string nuevoNombreSucursal;
            cin >> nuevoNombreSucursal;
            aux.setNombreSucursal(nuevoNombreSucursal);
            break;
        }
        case 13:
        {
            cout << "Ingrese el nuevo sexo: ";
            char nuevoSexo;
            cin >> nuevoSexo;
            aux.setSexo(nuevoSexo);
            break;
        }
        case 14:
        {
            cout << "Ingrese el nuevo teléfono celular: ";
            int nuevoTelefonoCelular;
            cin >> nuevoTelefonoCelular;
            aux.setTelefonoCelular(nuevoTelefonoCelular);
            break;
        }
        case 15:
        {
            cout << "Ingrese el nuevo teléfono fijo: ";
            int nuevoTelefonoFijo;
            cin >> nuevoTelefonoFijo;
            aux.setTelefonoFijo(nuevoTelefonoFijo);
            break;
        }
        case 0:
            cout << "Edición finalizada.\n";
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            opcionValida = false;
            break;
        }
    } while (opcionValida == false);
    return aux;
}

int Vista::solicitarConsulta2()
{
    int rango;
    cout << "Introduzca el número correspondiente para elegir un rango de hijos\n";
    cout << "1. sin hijos\n";
    cout << "2. 1-2 hijos\n";
    cout << "3. 3-4 hijos\n";
    cout << "4. mas de 4 hijos\n"
         << endl;
    cin >> rango;
    return rango;
}

int Vista::solicitarConsulta4() {
    int rango;
    cout << " Ingrese un numero para obtener las sucursales que tienen más empleados que el valor de dicho numero\n";
    cin>>rango;
}

int Vista::solicitarConsulta6_2() {
    int actividad;
    cout << "Introduzca el número correspondiente para elegir una actividad\n";
    cout << "1. Artes\n";
    cout << "2. Ciencias sociales\n";
    cout << "3. Ingenierias\n";
    cout << "4. Areas de la salud\n";
    cout << "5. otros\n"<< endl;
    cin >> actividad;
    return actividad;
}

int Vista::solicitarConsulta6_1() {
    int rango;
    cout << "Introduzca el número correspondiente para elegir un intervalo de edad\n";
    cout << "1. 18-24\n";
    cout << "2. 25-35\n";
    cout << "3. 36-45\n";
    cout << "4. 45-60\n";
    cout << "5. 60+\n"<< endl;
    cin >> rango;
    return rango;
}

