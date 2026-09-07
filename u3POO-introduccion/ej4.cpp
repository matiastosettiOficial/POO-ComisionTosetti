//
// Created by Matias on 30-Aug-26.
//
/*
 *Crear una clase llamada Password que permita representar una contraseña.
La clase deberá tener como atributos:
longitud máxima de la contraseña.
contraseña.
Definir los siguientes constructores:
Un constructor por defecto que establezca una longitud máxima de 8 caracteres.
Un constructor parametrizado que permita establecer la longitud máxima de la contraseña.
Definir los siguientes métodos:
generarPassword(): permite al usuario ingresar una contraseña. La contraseña ingresada no podrá superar la longitud máxima establecida para el objeto. Si el usuario ingresa una contraseña de mayor longitud, deberá informarse el error y solicitar nuevamente el ingreso.
esFuerte(): determina si la contraseña es fuerte. Una contraseña será considerada fuerte si contiene:
Más de 2 letras mayúsculas.
Más de 1 letra minúscula.
Más de 2 números.
mostrar(): muestra la contraseña y su longitud.
cargarLongitud(): permite establecer la longitud máxima de la contraseña.
Realizar un programa principal que haga uso de la clase instanciando al menos un objeto de la clase.

 */
#include <iostream>
#include <string>

using namespace std;

class Password {
private:
    int longitud;
    string contrasenia;

public:
    // Constructor por defecto: longitud máxima de 8 caracteres.
    Password() {
        longitud = 8;
        contrasenia = "";
    }

    // Constructor que establece la longitud máxima.
    Password(int longitud) {
        this->longitud = longitud;
        contrasenia = "";
    }

    // Permite cambiar la longitud máxima.
    void setLongitud(int longitud) {
        this->longitud = longitud;
    }

    // El usuario ingresa la contraseña sin superar la longitud establecida.
    void generarPassword() {
        contrasenia = "";

        cout << "Ingrese una contrasenia de hasta "
             << longitud << " caracteres: ";

        char caracter;

        while (contrasenia.length() < longitud) {
            cin >> caracter;

            contrasenia += caracter;
        }

        cout << "Contraseña cargada correctamente." << endl;
    }

    // Determina si la contraseña es fuerte.
    bool esFuerte() {
        int mayusculas = 0;
        int minusculas = 0;
        int numeros = 0;

        for (int i = 0; i < contrasenia.length(); i++) {

            if (contrasenia[i] >= 'A' && contrasenia[i] <= 'Z') {
                mayusculas++;
            }
            else if (contrasenia[i] >= 'a' && contrasenia[i] <= 'z') {
                minusculas++;
            }
            else if (contrasenia[i] >= '0' && contrasenia[i] <= '9') {
                numeros++;
            }
        }

        if (mayusculas > 1 &&
               minusculas > 1 &&
               numeros > 1) {
            return true;

        }else {
            return false;
        }

        //return mayusculas > 1 && minusculas > 1 && numeros > 1;

    }

    // Muestra la contraseña y su longitud.
    void mostrar() {
        cout << "Contrasenia: " << contrasenia << endl;
        cout << "Longitud: " << contrasenia.length() << endl;
    }


};

int main() {

    // La contraseña podrá tener como máximo 8 caracteres.
    Password password1;

    password1.generarPassword();

    cout << endl;
    password1.mostrar();

    if (password1.esFuerte()) {
        cout << "La contrasenia es fuerte." << endl;
    }
    else {
        cout << "La contrasenia no es fuerte." << endl;
    }

    return 0;
}