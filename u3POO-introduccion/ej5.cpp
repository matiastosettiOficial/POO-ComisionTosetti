//
// Created by Matias on 30-Aug-26.
//
/*
 * Obtener una clase que represente una cuenta bancaria. Para la misma se tiene como información:
Número de cuenta.
Saldo.
Tasa de interés
Definir los datos miembro de la clase.
Obtener los métodos para:
Crear una cuenta nueva (constructor) a partir de la asignación del número de cuenta y una tasa de interés. Toda nueva cuenta se crea con saldo 0.
Carga y visualización de los datos del miembro.
Realizar un depósito.
Realizar una extracción.
Acreditar intereses.
Considerar que algunas operaciones requieren comprobación antes de ser realizadas
Definir un programa principal que gestione dos cuentas distintas.

 */
#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    int numeroCuenta;
    float saldo;
    float tasaInteres;

public:
    // Una cuenta nueva comienza siempre con saldo 0.
    CuentaBancaria(int numero, float tasa) {
        numeroCuenta = numero;
        tasaInteres = tasa;
        saldo = 0;
    }

    // Permite cargar los datos de la cuenta.
    void cargar() {
        cout << "Numero de cuenta: ";
        cin >> numeroCuenta;

        cout << "Tasa de interes (%): ";
        cin >> tasaInteres;
    }

    // Muestra los datos actuales de la cuenta.
    void mostrar() {
        cout << "Numero de cuenta: " << numeroCuenta << endl;
        cout << "Saldo: $" << saldo << endl;
        cout << "Tasa de interes: " << tasaInteres << "%" << endl;
    }

    // Realiza un depósito si el monto es válido.
    void depositar(float monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito realizado correctamente." << endl;
        }
        else {
            cout << "El monto del deposito debe ser mayor a 0." << endl;
        }
    }

    // Realiza una extracción solamente si hay saldo suficiente.
    void extraer(float monto) {
        if (monto <= 0) {
            cout << "El monto de la extraccion debe ser mayor a 0." << endl;
        }
        else if (monto > saldo) {
            cout << "Saldo insuficiente." << endl;
        }
        else {
            saldo -= monto;
            cout << "Extraccion realizada correctamente." << endl;
        }
    }

    // Calcula y acredita los intereses sobre el saldo actual.
    void acreditarIntereses() {
        saldo += saldo * tasaInteres / 100;
    }
};

int main() {
    // Se crean dos cuentas con diferente número y tasa de interés.
    CuentaBancaria cuenta1(1001, 5);
    CuentaBancaria cuenta2(2002, 3);

    cout << "CUENTA 1" << endl;
    cuenta1.mostrar();

    cout << endl << "Realizando deposito de $10000..." << endl;
    cuenta1.depositar(10000);

    cout << "Realizando extraccion de $2500..." << endl;
    cuenta1.extraer(2500);

    cout << "Acreditando intereses..." << endl;
    cuenta1.acreditarIntereses();

    cout << endl << "Datos finales de la cuenta 1:" << endl;
    cuenta1.mostrar();


    cout << endl << "================================" << endl;


    cout << "CUENTA 2" << endl;
    cuenta2.mostrar();

    cout << endl << "Realizando deposito de $20000..." << endl;
    cuenta2.depositar(20000);

    cout << "Realizando extraccion de $5000..." << endl;
    cuenta2.extraer(5000);

    cout << "Acreditando intereses..." << endl;
    cuenta2.acreditarIntereses();

    cout << endl << "Datos finales de la cuenta 2:" << endl;
    cuenta2.mostrar();

    return 0;
}