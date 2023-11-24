/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#include <fstream>
#include <iostream>

using namespace std;

class Archivo {
private:
  string nombreArchivo, rutaArchivo;

public:
  Archivo() {}

  void anadir(string);
  string leerLinea();
  void setRuta(string nombre);
};

void Archivo::setRuta(string nombre) {
  nombreArchivo = nombre + ".txt";
  rutaArchivo = "Memoria Secundaria/" + nombreArchivo;
}
void Archivo::anadir(string linea) {
  ofstream archivoE(rutaArchivo, ios::app);
  archivoE << linea << endl;
  archivoE.close();
}

string Archivo::leerLinea() {
  ifstream archivoL(rutaArchivo);
  string linea;
  string resultado = "";
  while (getline(archivoL, linea)) {
    resultado += linea + "/";
  }
  archivoL.close();
  return resultado;
}
