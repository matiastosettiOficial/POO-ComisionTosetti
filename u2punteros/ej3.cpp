//
// Created by Matias on 09-Aug-26.
//
#include <iostream>
using namespace std;

int main()
{
    // 1. Declaramos el arreglo
    int numeros[5] = {10, 20, 30, 40, 50};

    // 2. Declaramos dos punteros a entero
    int *pInicio;
    int *pFin;

    // 3. pInicio apunta al primer elemento
    pInicio = &numeros[0];

    // 4. pFin apunta al último elemento
    pFin = &numeros[4];

    // 5. Mostramos las direcciones para observarlas
    cout << "Direccion del primer elemento: " << pInicio << endl;
    cout << "Direccion del ultimo elemento: " << pFin << endl;

    // 6. Restamos los punteros
    //    El resultado indica cuántos elementos los separan
    cout << "Diferencia entre punteros: " << pFin - pInicio << endl;
/* Nota:
 * La aritmética de punteros tiene en cuenta automáticamente el
 * tamaño del tipo apuntado. No estamos calculando directamente
 * una diferencia de bytes, sino la cantidad de elementos que
 * separan ambos punteros.
 * */
    return 0;
}