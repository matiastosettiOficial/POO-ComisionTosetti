//
// Created by Matias on 10-Aug-26.
//
#include <iostream>
using namespace std;

int main()
{
    // 1. Solicitamos la cantidad de elementos
    int n;

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    // 2. Reservamos memoria dinámicamente
    int *vector = new int[n];

    // 3. Ingresamos los datos utilizando notación vectorial
    cout << "\nIngrese los elementos:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Elemento " << i << ": ";
        cin >> vector[i];
    }

    // 4. Mostramos el contenido utilizando índices
    cout << "\nContenido usando notacion vectorial:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << vector[i] << " ";
    }

    cout << endl;

    // 5. Mostramos el contenido utilizando aritmética de punteros
    cout << "\nContenido usando aritmetica de punteros:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << *(vector + i) << " ";
    }

    cout << endl;

    // 6. Liberamos la memoria reservada
    delete[] vector;

    return 0;
}