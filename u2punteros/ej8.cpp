//
// Created by Matias on 10-Aug-26.
//
#include <iostream>
using namespace std;

// Cuenta las vocales minúsculas utilizando un puntero
int contarVocales(char *cadena)
{
    int cantidad = 0;

    // Recorremos la cadena hasta encontrar '\0'
    while (*cadena != '\0')
    {
        // Comprobamos si el carácter actual es una vocal
        if (*cadena == 'a' ||
            *cadena == 'e' ||
            *cadena == 'i' ||
            *cadena == 'o' ||
            *cadena == 'u')
        {
            cantidad++;
        }

        // Avanzamos al siguiente carácter
        cadena++;
    }

    return cantidad;
}

int main()
{
    // 1. Declaramos una cadena de máximo 50 caracteres
    char cadena[51];

    // 2. Ingresamos la cadena
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, 51);

    // 3. Enviamos la cadena a la función
    int cantidad = contarVocales(cadena);

    // 4. Mostramos el resultado
    cout << "Cantidad de vocales minusculas: " << cantidad << endl;

    return 0;
}