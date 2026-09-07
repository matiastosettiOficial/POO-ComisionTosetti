//
// Created by Matias on 10-Aug-26.
//
#include <iostream>
using namespace std;

int main()
{
    int filas, columnas;

    // 1. Solicitamos las dimensiones de la matriz
    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;

    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas;

    // 2. Creamos un puntero a punteros de tipo float
    float **matriz;

    // 3. Reservamos memoria para las filas
    matriz = new float*[filas];

    // 4. Para cada fila, reservamos memoria para sus columnas
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = new float[columnas];
    }

    // 5. Ingresamos los datos
    cout << "\nIngrese los datos de la matriz:" << endl;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // 6. Mostramos la matriz utilizando []
    cout << "\nContenido de la matriz:" << endl;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "\t";
        }

        cout << endl;
    }

    // 7. Liberamos la memoria de cada fila
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }

    // 8. Liberamos la memoria de las filas
    delete[] matriz;

    return 0;
}