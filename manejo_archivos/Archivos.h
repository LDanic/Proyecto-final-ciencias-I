#include "../empleados.h"
#include <fstream>
#include <iostream>

using namespace std;

class Archivo {
  private:
    string nombreArchivo, rutaArchivo;
    char delimitador = ';';
  
  public:
    Archivo(string nombre) {
      nombreArchivo = nombre + ".csv";
      rutaArchivo = "Memoria Secundaria/" + nombreArchivo;
    }
  
    void cerrarArchivo();
    void escribir(string);
    void leer();
};

void Archivo:: escribir(string linea){ 
  fstream fout; 
  fout.open(rutaArchivo, ios::app); 

  
  
}

