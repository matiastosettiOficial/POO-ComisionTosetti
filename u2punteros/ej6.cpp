//
// Created by Matias on 10-Aug-26.

#include <iostream>
using namespace std;

// Invierte la cadena utilizando dos punteros
void invertir(char *cadena)
{
    // pInicio apunta al primer carácter
    char *pInicio = cadena;

    // pFin busca el último carácter de la cadena
    char *pFin = cadena;

    while (*pFin != '\0')
    {
        pFin++;
    }

    // Retrocedemos para no apuntar al '\0'
    pFin--;

    // Intercambiamos los caracteres desde los extremos
    while (pInicio < pFin)
    {
        char aux = *pInicio;
        *pInicio = *pFin;
        *pFin = aux;

        // Acercamos ambos punteros hacia el centro
        pInicio++;
        pFin--;
    }
}

int main()
{
    // 1. Declaramos una cadena de máximo 50 caracteres
    char cadena[51];

    // 2. Ingresamos la cadena
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, 51);

    // 3. Enviamos la cadena a la función
    invertir(cadena);

    // 4. Mostramos la cadena invertida
    cout << "Cadena invertida: " << cadena << endl;

    return 0;
}

//
//#include <iostream>
//using namespace std;
//
//char* invertir(char *cadena){
//
//    char *p=cadena;
//    char *q =cadena;
//    while(*p != '\0'){
//        p++;
//    }
//    p--;
//    char aux;
//    for( int i=0; i<(p-cadena)/2; i++){
//        aux=*q;
//        *q=*p;
//        *p=aux;
//        q++;
//        p--;
//    }
//    return cadena;
//}
//
//int main () {
//    char cadena[50];
//    cout<<"Ingrese una cadena"<<endl;
//    cin.getline(cadena, 100);
//    cout << invertir(cadena) <<endl;
//
//
//}