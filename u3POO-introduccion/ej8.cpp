#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
    int legajo;
    string nombre;
    float sueldoBasico;
    int horasExtras;
    float valorHoraExtra;

public:
    // Constructor por defecto
    Empleado() {
        legajo = 0;
        nombre = "";
        sueldoBasico = 0;
        horasExtras = 0;
        valorHoraExtra = 0;
    }

    // Constructor con legajo, nombre y sueldo básico
    Empleado(int l, string n, float s) {
        legajo = l;
        nombre = n;
        sueldoBasico = s;
        horasExtras = 0;
        valorHoraExtra = 0;
    }

    // Constructor con todos los atributos
    Empleado(int l, string n, float s, int h, float v) {
        legajo = l;
        nombre = n;
        sueldoBasico = s;
        horasExtras = h;
        valorHoraExtra = v;
    }

    void cargar() {
        cout << "Nombre: ";
        cin >> nombre;

        do {
            cout << "Sueldo basico: ";
            cin >> sueldoBasico;

            if (sueldoBasico <= 0) {
                cout << "El sueldo debe ser mayor que 0." << endl;
            }
        } while (sueldoBasico <= 0);

        do {
            cout << "Cantidad de horas extras: ";
            cin >> horasExtras;

            if (horasExtras < 0) {
                cout << "La cantidad no puede ser negativa." << endl;
            }
        } while (horasExtras < 0);

        do {
            cout << "Valor de la hora extra: ";
            cin >> valorHoraExtra;

            if (valorHoraExtra < 0) {
                cout << "El valor no puede ser negativo." << endl;
            }
        } while (valorHoraExtra < 0);
    }

    void mostrar() {
        cout << "Legajo: " << legajo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Sueldo basico: $" << sueldoBasico << endl;
        cout << "Horas extras: " << horasExtras << endl;
        cout << "Valor hora extra: $" << valorHoraExtra << endl;
        cout << "Sueldo total: $" << calcularSueldo() << endl;
    }

    void agregarHorasExtras(int cantidad) {
        if (cantidad > 0) {
            horasExtras += cantidad;
        }
        else {
            cout << "La cantidad debe ser mayor que 0." << endl;
        }
    }

    void modificarSueldo(float nuevoSueldo) {
        if (nuevoSueldo > 0) {
            sueldoBasico = nuevoSueldo;
        }
        else {
            cout << "El sueldo debe ser mayor que 0." << endl;
        }
    }

    float calcularPagoHorasExtras() {
        return horasExtras * valorHoraExtra;
    }

    float calcularSueldo() {
        return sueldoBasico + calcularPagoHorasExtras();
    }

    // Compara el sueldo de este empleado con otro empleado
    bool esMayorSueldo(Empleado otroEmpleado) {
        return calcularSueldo() > otroEmpleado.calcularSueldo();
    }
};

int main() {

    // Se utilizan distintos constructores
    Empleado empleado1;
    Empleado empleado2(101, "Juan", 500000);
    Empleado empleado3(102, "Pedro", 600000, 10, 8000);

    cout << "EMPLEADO 1" << endl;
    empleado1.cargar();
    cout << endl;

    cout << "EMPLEADO 2" << endl;
    empleado2.mostrar();
    cout << endl;

    cout << "EMPLEADO 3" << endl;
    empleado3.mostrar();
    cout << endl;

    // Agregamos horas extras al empleado 2
    cout << "Agregando 15 horas extras al empleado 2..." << endl;
    empleado2.agregarHorasExtras(15);

    // Modificamos el sueldo del empleado 1
    cout << "Modificando sueldo del empleado 1..." << endl;
    empleado1.modificarSueldo(550000);

    cout << endl;
    cout << "DATOS ACTUALIZADOS" << endl;

    cout << "\nEmpleado 1:" << endl;
    empleado1.mostrar();

    cout << "\nEmpleado 2:" << endl;
    empleado2.mostrar();

    cout << "\nEmpleado 3:" << endl;
    empleado3.mostrar();

    cout << endl;
    cout << "COMPARACION DE SUELDOS" << endl;

    if (empleado1.esMayorSueldo(empleado2)) {
        cout << "El empleado 1 tiene mayor sueldo que el empleado 2." << endl;
    }
    else {
        cout << "El empleado 2 tiene mayor o igual sueldo que el empleado 1." << endl;
    }

    // Determinamos cuál de los tres empleados tiene mayor sueldo
    Empleado mayor = empleado1;

    if (empleado2.esMayorSueldo(mayor)) {
        mayor = empleado2;
    }

    if (empleado3.esMayorSueldo(mayor)) {
        mayor = empleado3;
    }

    cout << endl;
    cout << "EMPLEADO CON MAYOR SUELDO" << endl;
    mayor.mostrar();

    return 0;
}