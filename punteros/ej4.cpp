//
// Created by Matias on 09-Aug-26.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 1. Inicializamos la semilla para generar números aleatorios
    srand(time(0));

    // 2. Declaramos un arreglo de 15 elementos
    int numeros[15];

    // 3. Rellenamos el arreglo con valores entre 1 y 100
    for (int i = 0; i < 15; i++)
    {
        numeros[i] = rand() % 1000 + 1;
    }

    // 4. Declaramos un puntero y lo hacemos apuntar
    //    al primer elemento del arreglo
    int *p = numeros;

    // 5. Recorremos el arreglo utilizando el puntero
    for (int i = 0; i < 15; i++)
    {
        // *p obtiene el valor del elemento actual
        // p contiene su dirección de memoria
        cout << "Valor: " << *p
             << "\tDireccion: " << p << endl;

        // Avanzamos al siguiente elemento
        p++;
    }

    return 0;
}