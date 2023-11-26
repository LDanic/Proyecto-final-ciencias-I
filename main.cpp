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
#include "ordenamiento/mergesort.h"
#include "consultas.h"

using namespace std;

// colocar esta funcion en otro lado ?
void editarEmp(Empleado *emp, MultiListaEmpleado multi) {
    Empleado aux = *emp;
    int opcion = 0;
    bool opcionValida = true;

    do {
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

        switch (opcion) {
            case 1: {
                cout << "Ingrese el nuevo nombre: ";
                string nuevoNombre;
                cin >> nuevoNombre;
                aux.setNombre(nuevoNombre);
                break;
            }
            case 2: {
                cout << "Ingrese el nuevo apellido: ";
                string nuevoApellido;
                cin >> nuevoApellido;
                aux.setApellido(nuevoApellido);
                break;
            }
            case 3: {
                cout << "Ingrese el nuevo tipo de ID: ";
                string nuevoTipoID;
                cin >> nuevoTipoID;
                aux.setTipoID(nuevoTipoID);
                break;
            }
            case 4: {
                cout << "Ingrese el nuevo correo: ";
                string nuevoCorreo;
                cin >> nuevoCorreo;
                aux.setCorreo(nuevoCorreo);
                break;
            }
            case 5: {
                cout << "Ingrese la nueva fecha de nacimiento: ";
                string nuevaFechaNacimiento;
                cin >> nuevaFechaNacimiento;
                aux.setFechaNacimiento(nuevaFechaNacimiento);
                break;
            }
            case 6: {
                cout << "Ingrese la nueva ciudad de nacimiento: ";
                string nuevaCiudadNacimiento;
                cin >> nuevaCiudadNacimiento;
                aux.setCiudadNacimiento(nuevaCiudadNacimiento);
                break;
            }
            case 7: {
                cout << "Ingrese el nuevo país de nacimiento: ";
                string nuevoPaisNacimiento;
                cin >> nuevoPaisNacimiento;
                aux.setPaisNacimiento(nuevoPaisNacimiento);
                break;
            }
            case 8: {
                cout << "Ingrese la nueva ciudad de residencia: ";
                string nuevaCiudadResidencia;
                cin >> nuevaCiudadResidencia;
                aux.setCiudadResidencia(nuevaCiudadResidencia);
                break;
            }
            case 9: {
                cout << "Ingrese la nueva dirección: ";
                string nuevaDireccion;
                cin >> nuevaDireccion;
                aux.setDireccion(nuevaDireccion);
                break;
            }
            case 10: {
                cout << "Ingrese el nuevo barrio: ";
                string nuevoBarrio;
                cin >> nuevoBarrio;
                aux.setBarrio(nuevoBarrio);
                break;
            }
            case 11: {
                cout << "Ingrese la nueva actividad laboral: ";
                string nuevaActividadLaboral;
                cin >> nuevaActividadLaboral;
                aux.setActividadLaboral(nuevaActividadLaboral);
                break;
            }
            case 12: {
                cout << "Ingrese el nuevo nombre de sucursal: ";
                string nuevoNombreSucursal;
                cin >> nuevoNombreSucursal;
                aux.setNombreSucursal(nuevoNombreSucursal);
                break;
            }
            case 13: {
                cout << "Ingrese el nuevo sexo: ";
                char nuevoSexo;
                cin >> nuevoSexo;
                aux.setSexo(nuevoSexo);
                break;
            }
            case 14: {
                cout << "Ingrese el nuevo teléfono celular: ";
                int nuevoTelefonoCelular;
                cin >> nuevoTelefonoCelular;
                aux.setTelefonoCelular(nuevoTelefonoCelular);
                break;
            }
            case 15: {
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
                bool opcionValida = false;
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcionValida == false);
    multi.actualizarEmp(aux);
}

int main() {
    MultiListaEmpleado multi;
    Empleado emp("Pedro", "C", "cc", "correo", "2000-12-02", "Bogota", "Colombia",
                 "Bogota", "cra 7 cl 40", "Restrepo", "Artes", "pepe sierra",
                 10657, 'F', 61165, 16165);
    Hijo hijo("Alejandro", "2020-20-09", 10657);
    emp.agregarHijo(hijo);
    Hijo hijo1("Alejandro", "2020-20-09", 10657);
    emp.agregarHijo(hijo1);
    Hijo hijo2("Alejandro", "2020-20-09", 10657);
    emp.agregarHijo(hijo2);

    Empleado emp2("Santia", "C", "cc", "correo", "2000-12-02", "Medellin",
                  "Colombia", "Bogota", "cra 7 cl 40", "Restrepo", "Artes",
                  "chicala", 10656, 'F', 61165, 16165);

    Empleado emp1("Laura", "C", "cc", "correo", "2002-25-05", "Bogota",
                  "Colombia", "Bogota", "cra 7 cl 40", "Restrepo", "Artes",
                  "pepe sierra", 10658, 'F', 61165, 16165);

    multi.insertar(emp);

    multi.insertar(emp2);
    multi.insertar(emp1);



    /*Sucursal su1("pepe sierra", "???", "???", "PEPE");
    gestionSucursales gS;
    gS.anadirSucursal(su1);

    gestionPersistencia cM;
    cM.guardarMulti(multi);*/
    //cM.guardarSucursales(gS.sucursales);


    //multi = cM.construirMulti();



    /*editarEmp(multi.buscarPorID(10658), multi);
    cout<<multi.buscarPorID(10658)->getNombre()<<endl;*/

    Consultas consultas;
    consultas.setMulti(multi);
    Pos<string *, string> *resul=consultas.consulta2("sin hijos");
    int tam = sizeof(resul) / 4;

    for(int i=0; i<tam; i++){
        cout<<resul[i].clave<<"-";
        cout<<resul[i].info[0]+"-";
        cout<<resul[i].info[1]<<endl;
    }

    cout << "hola mundo" << endl;

    return 0;
}