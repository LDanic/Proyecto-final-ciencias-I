/*
  JUAN DIEGO ACOSTA MOLINA 20211020044
  LAURA DANIELA CUBILLOS ESCOBAR 20211020045
  SANTIAGO SANCHEZ MOYA 20211020032

*/
#ifndef EDAD_H
#define EDAD_H

#include <ctime>
#include <string>
using namespace std;

class Edad {
public:
  Edad() {}

  void convertirFecha(string &fechaString, int &year, int &month, int &day) {
    // Buscar las posiciones de los guiones
    size_t pos1 = fechaString.find('-');
    size_t pos2 = fechaString.rfind('-');

    // Convertir las subcadenas a enteros
    if (pos1 != std::string::npos && pos2 != std::string::npos &&
        pos1 != pos2) {
      year = std::stoi(fechaString.substr(0, pos1));
      day = std::stoi(fechaString.substr(pos1 + 1, pos2 - pos1 - 1));
      month = std::stoi(fechaString.substr(pos2 + 1));
    } else {
      return;
    }
  }

  int calcularEdad(string fNacimiento) {
    // Obtener la fecha y hora actual
    time_t now = time(0);
    tm *localTime = localtime(&now);

    // Extraer el año, mes y día de la estructura tm
    int yearActual = localTime->tm_year + 1900; // Se suma 1900 al año
    int monthActual = localTime->tm_mon + 1;    // Los meses empiezan desde 0
    int dayActual = localTime->tm_mday;

    // Variables para almacenar día, mes y año
    int yearNacimiento = 0, monthNacimiento = 0, dayNacimiento = 0;

    convertirFecha(fNacimiento, yearNacimiento, monthNacimiento, dayNacimiento);

    if (!esFechaValida(dayNacimiento, monthNacimiento, yearNacimiento))
      return -1;

    // Verificar si el cumpleaños ya ha ocurrido este año
    bool cumpleaniosOcurrido =
        (monthNacimiento < monthActual) ||
        (monthNacimiento == monthActual && dayNacimiento <= dayActual);

    // Calcular la edad
    int edad = yearActual - yearNacimiento - (cumpleaniosOcurrido ? 0 : 1);
    return edad;
  }

  bool esBisiesto(int year) {
    // Un año es bisiesto si es divisible por 4,
    // excepto los años que son divisibles por 100 pero no por 400
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
  }

  bool esFechaValida(int dia, int mes, int year) {
    if (mes < 1 || mes > 12) {
      return false; // Mes no válido
    }

    if (dia < 1) {
      return false; // Día no válido
    }

    switch (mes) {
    // Meses con 31 días
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return (dia <= 31);

    // Meses con 30 días
    case 4:
    case 6:
    case 9:
    case 11:
      return (dia <= 30);

    // Febrero
    case 2:
      // Verificar si es un año bisiesto
      if (esBisiesto(year)) {
        return (dia <= 29);
      } else {
        return (dia <= 28);
      }

    default:
      return false; // Mes no válido
    }
  }
};
#endif