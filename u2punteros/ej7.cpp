//
// Created by Matias on 10-Aug-26.
//
#include <iostream>
using namespace std;

// Copia la cadena origen en destino utilizando punteros
void copia(char *origen, char *destino)
{
    // Recorremos la cadena hasta encontrar '\0'
    while (*origen != '\0')
    {
        // Copiamos el carácter actual
        *destino = *origen;

        // Avanzamos ambos punteros
        origen++;
        destino++;
    }

    // Agregamos el final de la cadena
    *destino = '\0';
}

int main()
{
    // 1. Declaramos las cadenas
    char origen[51];
    char destino[51];

    // 2. Ingresamos la cadena original
    cout << "Ingrese una cadena: ";
    cin.getline(origen, 51);

    // 3. Copiamos origen en destino
    copia(origen, destino);

    // 4. Mostramos la cadena copiada
    cout << "Cadena original: " << origen << endl;
    cout << "Cadena copiada:  " << destino << endl;

    return 0;
}