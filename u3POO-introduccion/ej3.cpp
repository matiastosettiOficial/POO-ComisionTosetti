//
// Created by Matias on 30-Aug-26.
//
/*
 * Realizar una clase que permita representar un punto en coordenadas cartesianas.

Definir los datos miembros de la clase.
Definir si fuera necesario funciones de carga y muestra de los datos miembro.
Definir un constructor que inicializa el punto en el origen de coordenadas.
Definir la/las función/es miembro para obtener la conversión en coordenadas polares.
Realizar un programa principal que haga uso de la clase instanciando al menos un objeto de la clase.

 */

#include <iostream>
#include <cmath>
using namespace std;

class coordenadaCartesiana {
private:
    float x;
    float y;

public:
    // El constructor inicializa el punto en el origen.
    coordenadaCartesiana() {
        x = 0;
        y = 0;
    }

    // Permite cargar las coordenadas del punto.
    void cargar(float a, float y) {
        x = a;
        this->y = y;
    }

    // Muestra las coordenadas cartesianas.
    void mostrar() {
        cout << "Coordenadas cartesianas: (" << x << ", " << y << ")" << endl;
    }

    // Calcula y muestra las coordenadas polares.
    void mostrarPolares() {
        float radio = sqrt(x * x + y * y);
        float angulo = atan2(y, x) * 180 / M_PI;

        cout << "Coordenadas polares:" << endl;
        cout << "Radio: " << radio << endl;
        cout << "Angulo: " << angulo << " grados" << endl;
    }
};

int main() {
    coordenadaCartesiana cartesiana1;

    // Cargamos un punto ubicado en (3, 4).
    cartesiana1.cargar(3, 4);

    cartesiana1.mostrar();

    // Convertimos las coordenadas cartesianas a polares.
    cartesiana1.mostrarPolares();

    return 0;
}