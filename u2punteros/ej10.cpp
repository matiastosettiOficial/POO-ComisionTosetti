//
// Created by Matias on 10-Aug-26.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 1. Inicializamos la semilla para generar números aleatorios
    srand(time(0));

    // 2. Solicitamos la cantidad de elementos
    int n;

    cout << "Ingrese la cantidad de valores: ";
    cin >> n;

    // 3. Reservamos memoria dinámicamente
    int *vector = new int[n];

    // 4. Generamos valores aleatorios entre 0 y 100
    for (int i = 0; i < n; i++)
    {
        *(vector + i) = rand() % 101;
    }

    // 5. Mostramos el arreglo original
    cout << "\nArreglo original:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << *(vector + i) << " ";
    }

    cout << endl;

    // 6. Ordenamos de mayor a menor
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(vector + i) < *(vector + j))
            {
                int aux = *(vector + i);
                *(vector + i) = *(vector + j);
                *(vector + j) = aux;
            }
        }
    }

    // 7. Mostramos el arreglo ordenado
    cout << "\nArreglo ordenado de mayor a menor:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << *(vector + i) << " ";
    }

    cout << endl;

    // 8. Liberamos la memoria reservada
    delete[] vector;

    return 0;
}