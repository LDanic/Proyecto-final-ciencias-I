/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#include <iostream>
#include "ControladorPrincipal.h"
using namespace std;

/*#include "empleados.h"
#include "estructuras/Lista.h"
#include "estructuras/multilistaEmpleado.h"
#include "manejo_archivos/ObjetosToArchivos.h"
#include "gestionPersistencia.h"
#include "gestionSucursales.h"
#include "ordenamiento/mergesort.h"
#include "consultas.h"



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
    Empleado emp("Pedro", "Rodriguez", "CC", "pedro@ccom.com", "1996-05-06", "Madrid", "Espana",
                 "Madrid", "gran via 26", "Prado", "Artes", "Gran Via",
                 12345678, 'M', 30060090, 4785623);
    Hijo hijo("Hugo", "2012-20-09", 12345678);
    emp.agregarHijo(hijo);
    Hijo hijo1("Paco", "2008-20-09", 12345678);
    emp.agregarHijo(hijo1);
    Hijo hijo2("Luis", "2006-20-09", 12345678);
    emp.agregarHijo(hijo2);

    Empleado emp1("Ana", "Ramirez", "CE", "Ana@ccom.com", "1997-29-06", "Madrid",
                  "Espana", "Cali", "Cl 5 #36-25", "Lido", "Ciencias sociales",
                  "Lido", 98765432, 'F', 310357698, 2658974);
    Hijo hijo3("Maria", "2015-20-09", 98765432);
    emp1.agregarHijo(hijo3);


    Empleado emp2("Maria", "Moliner", "TI", "maria@ccom.com", "1995-15-11", "Barcelona",
                  "Espana", "Barcelona", "paseomaritimo 15", "Villa Olimpica", "Ingenierias",
                  "Villa Olimpica", 1010106332, 'F', 315318314, 7789965);

    Empleado emp3("Luis", "Lopez", "CC", "luis@ccom.com", "1990-04-07", "Bogota", "Colombia",
                 "Bogota", "cra 5 #72-00", "Rosales", "Areas de la salud", "Rosales",
                 56824973, 'M', 320648957, 3698741);
    Hijo hijo4("Ana", "2023-20-09", 56824973);
    emp3.agregarHijo(hijo4);
    Hijo hijo5("Juan", "2018-20-09", 56824973);
    emp3.agregarHijo(hijo5);


    Empleado emp4("Juan", "Perez", "CC", "juan@ccom.com", "1994-22-03", "Bogota", "Colombia",
                 "Bogota", "Cra 6 #60-32", "La Salle", "otros", "Rosales",
                 32165487, 'M', 301932660, 7895623);
    Hijo hijo6("Sara", "2012-20-09", 32165487);
    emp4.agregarHijo(hijo6);
    Hijo hijo7("Manuel", "2008-20-09", 32165487);
    emp4.agregarHijo(hijo7);



    Empleado emp5("Margarita", "Lopez", "CE", "marga@ccom.com", "1993-09-01", "Bogota", "Colombia",
                 "Barcelona", "Rambla 42", "Marina Village", "Ciencias sociales", "Villa Olimpica",
                 76543256, 'F', 310698235, 5826749);

    Hijo hijo8("Jorge", "2016-20-09", 76543256);
    emp5.agregarHijo(hijo8);


    Empleado emp6("Sara", "Connor", "TI", "sara@ccom.com", "1998-05-05", "Cali", "Colombia",
                 "Cali", "cra 39 # 3-02", "San Fernando", "Ingenierias", "Lido",
                 1210123623, 'F', 315833145, 9657897);


    multi.insertar(emp);
    multi.insertar(emp1);
    multi.insertar(emp2);
    multi.insertar(emp3);
    multi.insertar(emp4);
    multi.insertar(emp5);
    multi.insertar(emp6);





    Sucursal su1("Gran Via", "Gran Via 120", "Prado", "Alan Turing");
    Sucursal su2("Lido", "cL 4 #38d-23", "Lido", "Tomas Alba");
    Sucursal su3("Villa Olimpica", "RondaLitoral48", "Villa Olimpica", "Mark Twain");
    Sucursal su4("Rosales", "Cl 4 #69-22", "Rosales", "Pablo Neruda");
    gestionSucursales gS;
    gS.anadirSucursal(su1);
    gS.anadirSucursal(su2);
    gS.anadirSucursal(su3);
    gS.anadirSucursal(su4);

    gestionPersistencia cM;
    cM.guardarMulti(multi);
    cM.guardarSucursales(gS.sucursales);
*/

    //multi = cM.construirMulti();



    /*editarEmp(multi.buscarPorID(10658), multi);
    cout<<multi.buscarPorID(10658)->getNombre()<<endl;*/
/*
 return 0;
}
*/


int main() {
Controlador c;
cout << "Hola" << endl;
c.ejecutar();
cout << "Hola" << endl;

return 0;


}
