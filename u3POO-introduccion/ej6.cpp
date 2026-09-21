//
// Created by Matias on 30-Aug-26.
//
/*
 * Crear una clase llamada Persona que permita representar una persona.
La clase deberá tener los siguientes atributos:
Nombre
Año de nacimiento
DNI
Sexo (H para hombre, M para mujer)
Peso
Altura
Definir los siguientes constructores:
Un constructor por defecto, que inicialice todos los atributos con valores predeterminados. El año de nacimiento deberá establecerse en un valor por defecto.
Un constructor que reciba como parámetros el nombre, el año de nacimiento y el sexo. El resto de los atributos deberá inicializarse con sus valores por defecto.
Un constructor que reciba todos los atributos como parámetros.
Definir los siguientes métodos:
cargar(): permite ingresar los datos de la persona, excepto el año de nacimiento.
mostrar(): muestra todos los datos de la persona.
calcularIMC(): calcula el índice de masa corporal mediante la fórmula:
IMC = peso / (altura × altura)
calcularEdad(anioActual): recibe como parámetro el año actual y calcula la edad de la persona.
Edad = año actual − año de nacimiento
esMayorDeEdad(anioActual): recibe como parámetro el año actual e indica si la persona tiene 18 años o más.
Realizar un programa principal que haga uso de la clase.


 */#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    int anioNacimiento;
    int dni;
    char sexo;
    float peso;
    float altura;

public:
    // Constructor por defecto.
    Persona() {
        nombre = "";
        anioNacimiento = 2000;
        dni = 0;
        sexo = 'H';
        peso = 0;
        altura = 0;
    }

    // Constructor con nombre, año de nacimiento y sexo.
    Persona(string nombre, int anioNacimiento, char sexo) {
        this->nombre = nombre;
        this->anioNacimiento = anioNacimiento;
        this->sexo = sexo;

        dni = 0;
        peso = 0;
        altura = 0;
    }

    // Constructor con todos los atributos.
    Persona(string nombre, int anioNacimiento, int dni,
            char sexo, float peso, float altura) {

        this->nombre = nombre;
        this->anioNacimiento = anioNacimiento;
        this->dni = dni;
        this->sexo = sexo;
        this->peso = peso;
        this->altura = altura;
    }

    // Permite cargar los datos, excepto el año de nacimiento.
    void cargar() {
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "DNI: ";
        cin >> dni;

        cout << "Sexo (H/M): ";
        cin >> sexo;

        cout << "Peso (kg): ";
        cin >> peso;

        cout << "Altura (m): ";
        cin >> altura;
    }

    // Muestra los datos de la persona.
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Anio de nacimiento: " << anioNacimiento << endl;
        cout << "DNI: " << dni << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Altura: " << altura << " m" << endl;
    }

    // Calcula el índice de masa corporal.
    float calcularIMC() {
        if (altura <= 0) {
            return 0;
        }

        return peso / (altura * altura);
    }

    // Calcula la edad a partir del año actual.
    int calcularEdad(int anioActual) {
        return anioActual - anioNacimiento;
    }

    // Indica si la persona es mayor de edad.
    bool esMayorDeEdad(int anioActual) {
        return calcularEdad(anioActual) >= 18;
    }
};

int main() {

    int anioActual = 2026;

    // Persona creada utilizando el constructor por defecto.
    Persona persona1;

    // Persona creada con nombre, año de nacimiento y sexo.
    Persona persona2("Juan Perez", 2000, 'H');

    // Persona creada utilizando todos los atributos.
    Persona persona3(
            "Maria Gomez",
            1995,
            30123456,
            'M',
            60,
            1.65
    );

    cout << "========== PERSONA 1 ==========" << endl;
    persona1.mostrar();

    cout << "Edad: "
         << persona1.calcularEdad(anioActual)
         << " años" << endl;

    if (persona1.esMayorDeEdad(anioActual)) {
        cout << "Es mayor de edad." << endl;
    }
    else {
        cout << "Es menor de edad." << endl;
    }


    cout << endl;
    cout << "========== PERSONA 2 ==========" << endl;
    persona2.mostrar();

    cout << "Edad: "
         << persona2.calcularEdad(anioActual)
         << " años" << endl;

    if (persona2.esMayorDeEdad(anioActual)) {
        cout << "Es mayor de edad." << endl;
    }
    else {
        cout << "Es menor de edad." << endl;
    }


    cout << endl;
    cout << "========== PERSONA 3 ==========" << endl;
    persona3.mostrar();

    cout << "Edad: "
         << persona3.calcularEdad(anioActual)
         << " anios" << endl;

    cout << "IMC: "
         << persona3.calcularIMC() << endl;

    if (persona3.esMayorDeEdad(anioActual)) {
        cout << "Es mayor de edad." << endl;
    }
    else {
        cout << "Es menor de edad." << endl;
    }

    return 0;
}