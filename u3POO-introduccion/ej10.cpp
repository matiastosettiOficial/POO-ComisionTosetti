//
// Created by Matias on 20-Sep-26.
//
#include <iostream>
#include <string>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha() {
        this->dia = 0;
        this->mes = 0;
        this->anio = 0;
    }

    Fecha(int dia, int mes, int anio) {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }

    void mostrar() {//funcion interna o  método de lcase
        cout << dia << "/" << mes << "/" << anio;
    }
};

class Huesped {
private:
    string nombre;
    string dni;
    string telefono;

public:
    Huesped() {
        nombre = "";
        dni = "";
        telefono = "";
    }

    Huesped(string nombre, string dni, string telefono) {
        this->nombre = nombre;
        this->dni = dni;
        this->telefono = telefono;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Telefono: " << telefono << endl;
    }
};

class Habitacion {
private:
    int numero;
    string tipo;
    double precioPorNoche;

public:
    Habitacion() {
        this->numero = 0;
        this->tipo = "";
        this->precioPorNoche = 0;
    }

    Habitacion(int numero, string tipo, double precioPorNoche) {
        this->numero = numero;
        this->tipo = tipo;
        this->precioPorNoche = precioPorNoche;
    }

    double getPrecioPorNoche() {
        return precioPorNoche;
    }

    void mostrar() {
        cout << "Numero: " << numero << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Precio por noche: $" << precioPorNoche << endl;
    }
};

class Reserva {//clase composición
private:
    Huesped huesped;
    Habitacion habitacion;
    Fecha fechaIngreso;
    Fecha fechaEgreso;

    int noches;

public:
    // Constructor recibiendo los objetos ya construidos
    Reserva(Huesped hue,
            Habitacion hab,
            Fecha fechaIng,
            Fecha fechaEgr,
            int noches)
        : huesped(hue),
          habitacion(hab),
          fechaIngreso(fechaIng),
          fechaEgreso(fechaEgr)
    {

        this->noches = noches;
    }
//SINTAXIS ALTERNATIVA no aconsejada
    // Reserva(Huesped hue,
    //         Habitacion hab,
    //         Fecha fechaIng,
    //         Fecha fechaEgr,
    //         int noches) {
    //     this->huesped = hue;
    //     this->habitacion = hab;
    //     this->fechaIngreso = fechaIng;
    //     this->fechaEgreso = fechaEgr;
    //     this->noches = noches;
    // }

    // Constructor recibiendo los datos para construir
    // cada uno de los objetos DESDE CONSTRUCTOR DE RESERVA
    Reserva(string nombre,
            string dni,
            string telefono,
            int numero,
            string tipo,
            double precioPorNoche,
            int diaIng,
            int mesIng,
            int anioIng,
            int diaEgr,
            int mesEgr,
            int anioEgr,
            int cantNoches)
        : huesped(nombre, dni, telefono),
          habitacion(numero, tipo, precioPorNoche),
          fechaIngreso(diaIng, mesIng, anioIng),
          fechaEgreso(diaEgr, mesEgr, anioEgr){
        this->noches = cantNoches;

    }

    double calcularTotal() {
        return habitacion.getPrecioPorNoche() * noches;
    }

    void cambiarNoches(int nuevasNoches) {
        noches = nuevasNoches;
    }

    void mostrarHuesped() {
        huesped.mostrar();
    }

    void mostrarHabitacion() {
        habitacion.mostrar();
    }

    void mostrar() {
        cout << "===== RESERVA =====" << endl;

        cout << "\n--- Huesped ---" << endl;
        huesped.mostrar();

        cout << "\n--- Habitacion ---" << endl;
        habitacion.mostrar();

        cout << "\n--- Fechas ---" << endl;

        cout << "Ingreso: ";
        fechaIngreso.mostrar();

        cout << endl;

        cout << "Egreso: ";
        fechaEgreso.mostrar();

        cout << endl;

        cout << "Noches: " << noches << endl;
        cout << "Total: $" << calcularTotal() << endl;
    }
};

int main() {
    Huesped h1("Juan Perez", "30123456", "3515555555");

    Habitacion hab1(205, "Doble", 50000);

    Fecha ingreso1(20, 9, 2026);
    Fecha egreso1(25, 9, 2026);

    Reserva reserva1(
        h1,
        hab1,
        ingreso1,
        egreso1,
        5
    );

    reserva1.mostrar();

    cout << "\n========================\n" << endl;

    Huesped h2("Maria Lopez", "28987654", "3514444444");

    Habitacion hab2(310, "Suite", 85000);

    Fecha ingreso2(22, 9, 2026);
    Fecha egreso2(27, 9, 2026);

    Reserva reserva2(
        h2,
        hab2,
        ingreso2,
        egreso2,
        5
    );

    reserva2.mostrar();

    cout << "\n--- Modificando cantidad de noches ---" << endl;

    reserva2.cambiarNoches(7);

    cout << "Nuevo total: $" << reserva2.calcularTotal() << endl;


    Reserva reserva3("Matias","1011641",
        "351222222",101,"matrimonial",
        150000, 15,9,2026,29,
        9,2026,14);

    reserva3.mostrar();
    return 0;
}
