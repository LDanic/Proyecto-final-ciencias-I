#include "estructuras/multilistaEmpleado.h"
#include "sucursal.h"

class gestionSucursales {

private:
    MultiListaEmpleado multiEmp;

public:
    Lista<Sucursal> sucursales;
    gestionSucursales(){

    }

    int eliminarSucursal(Sucursal);
    void anadirSucursal(Sucursal);
};

int gestionSucursales::eliminarSucursal(Sucursal sucursal) {
    int i = 1;

    while (multiEmp.nomCabeceras.get_info(i).nomLista != sucursal.getNombre()) {
        i++;
    }

    if (i > multiEmp.nomCabeceras.get_tam()) {
        return -1; // cuando la sucursal no existe.

    } else if (multiEmp.nomCabeceras.get_info(i).cabEmpleado != NULL) {
        return -2; //-2 es cuando la sucursal tiene empleados, entonces no se puede
        //eliminar.
    } else {
        multiEmp.nomCabeceras.eliminar(i);

        i = 1;

        while (sucursales.get_info(i).getNombre() != sucursal.getNombre()) {
            i++;
        }

        sucursales.eliminar(i);

        return 0; // cuando si se puedo eliminar la sucursal,
    }
}

void gestionSucursales::anadirSucursal(Sucursal sucursal) {
    sucursales.insertar_final(sucursal);
}
