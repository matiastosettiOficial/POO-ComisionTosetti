//
// Created by Matias on 30-Aug-26.
//
/*
 * Realizar una clase que permita representar una fecha.

Definir los datos de miembros de la clase.
Definir si fuera necesario funciones de carga y muestra de datos miembros.
Definir un constructor que inicializa la fecha a una fecha pasada por parámetro.
Definir un constructor que inicializa la fecha en 01/01/1900.
Realizar un programa principal que haga uso de la clase instanciando al menos dos objetos de la clase.

 */
#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructor que recibe una fecha por parámetro.
    Fecha(int d, int m, int a) {
        dia = d;
        mes = m;
        anio = a;
    }
    // Constructor que establece la fecha 01/01/1900.
    Fecha() {
        dia = 1;
        mes = 1;
        anio = 1900;
    }
    void setAnio(int a);
    // Muestra la fecha en formato día/mes/año.
    void mostrar();
};


void Fecha::mostrar(){

       cout << dia << "/" << mes << "/" << anio << endl;

}

/*Programa de Prueba*/
int main() {
    // Se crea un objeto utilizando el constructor con parámetros.
    Fecha fecha1(31, 8, 2026);

    // Se crea un objeto utilizando el constructor por defecto.
    Fecha fecha2(1, 9, 2026);

    cout << "Fecha 1: ";
    fecha1.mostrar();
    fecha1.setAnio(2027);

    cout << "Fecha 2: ";
    fecha2.mostrar();

    return 0;
}