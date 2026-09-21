//
// Created by Matias on 21-Sep-26.
//
#include <iostream>
#include <string>

using namespace std;

class Procesador {
private:
    string modelo;
    int nucleos;
    double velocidad;

public:
    Procesador(string modelo, int nucleos, double velocidad) {
        this->modelo = modelo;
        this->nucleos = nucleos;
        this->velocidad = velocidad;
    }

    void mostrar() {
        cout << "Modelo: " << modelo << endl;
        cout << "Nucleos: " << nucleos << endl;
        cout << "Velocidad: " << velocidad << " GHz" << endl;
    }
};

class MemoriaRAM {
private:
    int capacidad;
    string tipo;

public:
    MemoriaRAM(int capacidad, string tipo) {
        this->capacidad = capacidad;
        this->tipo = tipo;
    }

    void mostrar() {
        cout << "Capacidad: " << capacidad << " GB" << endl;
        cout << "Tipo: " << tipo << endl;
    }

    void cambiarCapacidad(int nuevaCapacidad) {
        capacidad = nuevaCapacidad;
    }
};

class Disco {
private:
    int capacidad;
    string tipo;

public:
    Disco(int capacidad, string tipo) {
        this->capacidad = capacidad;
        this->tipo = tipo;
    }

    void mostrar() {
        cout << "Capacidad: " << capacidad << " GB" << endl;
        cout << "Tipo: " << tipo << endl;
    }
};

class Computadora {//CLASE COMPUESTA
private:
    string marca;
    string modelo;

    // Composición
    Procesador procesador;
    MemoriaRAM memoria;
    Disco disco;

public:
    Computadora(string marca, string modelo,
                Procesador procesador,
                MemoriaRAM memoria,
                Disco disco)
        : procesador(procesador),
          memoria(memoria),
          disco(disco) {

        this->marca = marca;
        this->modelo = modelo;
    }

    Computadora(string marcaCompu, string modeloCompu,string modeloProc, int nucleosProc, double velocidadProc,
    int capacidadMemoria, string tipoMemoria,int capacidadDisco, string tipoDisco):procesador(modeloProc, nucleosProc, velocidadProc),
          memoria(capacidadMemoria,tipoMemoria),
          disco(capacidadDisco,tipoDisco) {

        this->marca = marcaCompu;
        this->modelo = modeloCompu;
        }

    void mostrar() {
        cout << "===== COMPUTADORA =====" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;

        cout << "\n--- Procesador ---" << endl;
        procesador.mostrar();

        cout << "\n--- Memoria RAM ---" << endl;
        memoria.mostrar();

        cout << "\n--- Disco ---" << endl;
        disco.mostrar();
    }

    void cambiarMemoria(int nuevaCapacidad) {
        memoria.cambiarCapacidad(nuevaCapacidad);
    }

    void mostrarProcesador() {
        procesador.mostrar();
    }
};

int main() {

    Procesador p1("Intel i5", 6, 3.5);
    MemoriaRAM m1(16, "DDR4");
    Disco d1(512, "SSD");

    Computadora pc1("Lenovo", "IdeaPad", p1, m1, d1);

    Procesador p2("AMD Ryzen 7", 8, 4.2);
    MemoriaRAM m2(32, "DDR5");
    Disco d2(1000, "SSD");

    Computadora pc2("Asus", "TUF Gaming", p2, m2, d2);

    pc1.mostrar();

    cout << "\n========================\n" << endl;

    pc2.mostrar();

    cout << "\n--- Cambiando memoria de PC1 ---" << endl;
    pc1.cambiarMemoria(32);

    pc1.mostrar();

    Computadora Pc3 ("Samsung","nimbus",
        "intel i9",8,4,32,
        "DDR5",500,"SDD");

    Pc3.mostrar();
    return 0;
}