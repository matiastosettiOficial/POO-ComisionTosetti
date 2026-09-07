//
// Created by Matias on 30-Aug-26.
//
/*
 * Realizar una clase que permita representar un cronómetro. Dicho cronómetro consta de horas, minutos y segundos. Las horas no tienen límite en valor mientras que los minutos y segundos llegan al máximo hasta 59.

Definir los datos miembros de la clase.
Definir si fuera necesario funciones de carga y muestra de los datos miembro.
Definir un constructor que inicializa a cero el cronómetro.
Definir un método Reset que permita llevar a cero el cronómetro.
Realizar un programa principal que haga uso de la clase instanciando al menos un objeto de la clase.

 */
#include <iostream>
using namespace std;

class Cronometro {
private:
    int horas;
    int minutos;
    int segundos;

public:
    // El constructor inicializa el cronómetro en cero.
    Cronometro() {
        horas = 0;
        minutos = 0;
        segundos = 0;
    }

    // Permite cargar los valores del cronómetro.
    void cargar(int h, int m, int s) {
        horas = h;
        minutos = m;
        segundos = s;
    }

    // Muestra el estado actual del cronómetro.
    void mostrar() {
        cout << horas << ":" << minutos << ":" << segundos << endl;
    }

    // Restablece el cronómetro a cero.
    void Reset() {
        horas = 0;
        minutos = 0;
        segundos = 0;
    }
};

int main() {
    Cronometro cronometro1;

    cout << "Cronometro inicial: ";
    cronometro1.mostrar();

    // Cargamos una hora, 25 minutos y 40 segundos.
    cronometro1.cargar(2, 25, 40);

    cout << "Cronometro despues de cargar: ";
    cronometro1.mostrar();

    // Volvemos el cronómetro a cero.
    cronometro1.Reset();

    cout << "Cronometro despues de Reset: ";
    cronometro1.mostrar();

    return 0;
}

/*
#include <iostream>
#include <chrono>

using namespace std;

class Cronometro {
private:
    int horas;
    int minutos;
    int segundos;

    // Guarda los instantes de inicio y finalización.
    chrono::steady_clock::time_point inicio;
    chrono::steady_clock::time_point fin;

public:
    // El constructor inicializa el cronómetro en cero.
    Cronometro() {
        horas = 0;
        minutos = 0;
        segundos = 0;
    }

    // Carga manualmente los valores del cronómetro.
    void cargar(int h, int m, int s) {
        horas = h;
        minutos = m;
        segundos = s;
    }

    // Muestra el tiempo almacenado en el cronómetro.
    void mostrar() {
        cout << horas << ":" << minutos << ":" << segundos << endl;
    }

    // Lleva el cronómetro a cero.
    void Reset() {
        horas = 0;
        minutos = 0;
        segundos = 0;
    }

    // Guarda el momento en que comienza el cronómetro.
    void iniciar() {
        inicio = chrono::steady_clock::now();
    }

    // Guarda el momento final y calcula el tiempo transcurrido.
    void finalizar() {
        fin = chrono::steady_clock::now();

        auto tiempoTranscurrido =
                chrono::duration_cast<chrono::seconds>(fin - inicio);

        int totalSegundos = tiempoTranscurrido.count();

        horas = totalSegundos / 3600;
        totalSegundos %= 3600;

        minutos = totalSegundos / 60;
        segundos = totalSegundos % 60;
    }
};

int main() {
    Cronometro cronometro;

    cout << "Iniciando cronometro..." << endl;
    cronometro.iniciar();

    cout << "Presione ENTER para finalizar..." << endl;
    cin.get();

    cronometro.finalizar();

    cout << "Tiempo transcurrido: ";
    cronometro.mostrar();

    return 0;
}*/