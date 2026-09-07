//
// Created by Matias on 09-Aug-26.
//
#include <iostream>
#include <cctype>

using namespace std;

// Recorre la cadena mediante un puntero
// y convierte cada carácter a mayúscula.
char* convertirMayusculas(char *cadena)
{
    char *p = cadena;

    // Recorremos hasta encontrar el final de la cadena
    while (*p != '\0')
    {
        *p = toupper(*p);
        p++;
    }

    // Retornamos la dirección inicial de la cadena
    return cadena;
}

int main()
{
    // 1. Declaramos una cadena de máximo 10 caracteres
    char cadena[100];

    // 2. Ingresamos la cadena
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, 100);

    // 3. Enviamos la cadena a la función
    char *resultado = convertirMayusculas(cadena);

    // 4. Mostramos la cadena modificada
    cout << "Cadena en mayusculas: " << resultado << endl;

    return 0;
}