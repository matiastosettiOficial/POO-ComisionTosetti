//
// Created by Matias on 09-Aug-26.
//
//
// Created by Matias on 09-Aug-26.
////
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    // 1. Declaramos e inicializamos dos variables
//    int numero1 = 10;
//    int numero2 = 20;
//
//    // 2. Declaramos un puntero a entero
//    int *p;
//
//    // 3. Hacemos que p apunte a numero1
//    //    & obtiene la dirección de memoria
//    p = &numero1;
//
//    cout << "PRIMERA VARIABLE" << endl;
//
//    // p contiene la dirección de numero1
//    cout << "Direccion: " << p << endl;
//
//    // *p permite acceder al contenido apuntado
//    cout << "Contenido: " << *p << endl;
//
//    cout << endl;
//
//    // 4. Ahora hacemos que p apunte a numero2
//    p = &numero2;
//
//    cout << "SEGUNDA VARIABLE" << endl;
//
//    // p contiene la dirección de numero2
//    cout << "Direccion: " << p << endl;
//
//    // *p permite acceder al contenido apuntado
//    cout << "Contenido: " << *p << endl;
//
//    return 0;
//}
#include <iostream>
using namespace std;

int main()
{
    // 1. Declaramos e inicializamos un arreglo de 5 enteros
    int numeros[5] = {10, 20, 30, 40, 50};

    // 2. Declaramos un puntero a entero
    int *p;

    // 3. Hacemos que p apunte al primer elemento del arreglo
    p = numeros;

    // 4. Recorremos el arreglo utilizando el puntero
    for (int i = 0; i < 5; i++)
    {
        // *p permite obtener el valor del elemento apuntado
        // p contiene la dirección de memoria de ese elemento
        cout << "Elemento: " << *p << endl;
        cout << "Direccion: " << p << endl;

        // Avanzamos al siguiente elemento del arreglo
        p++;

        cout << endl;
    }

    return 0;
}