//
// Created by Matias on 10-Aug-26.
//
#include <iostream>
using namespace std;

int main()
{
    // 1. Solicitamos la cantidad de datos
    int n;

    cout << "Ingrese la cantidad de datos: ";
    cin >> n;

    // 2. Reservamos memoria dinámicamente para los datos
    float *datos = new float[n];

    // 3. Ingresamos los valores
    cout << "\nIngrese los valores:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Dato " << i + 1 << ": ";
        cin >> datos[i];
    }

    // 4. Inicializamos máximo y mínimo con el primer dato
    float maximo = datos[0];
    float minimo = datos[0];

    float suma = 0;

    // 5. Recorremos el arreglo para calcular los resultados
    for (int i = 0; i < n; i++)
    {
        if (datos[i] > maximo)
            maximo = datos[i];

        if (datos[i] < minimo)
            minimo = datos[i];

        suma += datos[i];
    }

    // 6. Calculamos la media aritmética
    float media = suma / n;

    // 7. Mostramos los resultados
    cout << "\nResultados" << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;
    cout << "Media: " << media << endl;

    // 8. Liberamos la memoria reservada
    delete[] datos;

    return 0;
}