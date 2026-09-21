//
// Created by Matias on 06-Sep-26.
//
#include <iostream>
#include <string>

using namespace std;

class Producto {
private:
    int codigo;
    string descripcion;
    float precio;
    int stock;

public:
    // Constructor por defecto
    Producto() {
        codigo = 0;
        descripcion = "";
        precio = 0;
        stock = 0;
    }

    // Constructor con código, descripción y precio
    Producto(int c, string d, float p) {
        codigo = c;
        descripcion = d;
        precio = p;
        stock = 0;
    }

    // Constructor con todos los atributos
    Producto(int c, string d, float p, int s) {
        codigo = c;
        descripcion = d;
        precio = p;
        stock = s;
    }

    void cargar() {
        cout << "Descripcion: ";
        cin >> descripcion;

        do {
            cout << "Precio: ";
            cin >> precio;

            if (precio <= 0) {
                cout << "El precio debe ser mayor que 0." << endl;
            }
        } while (precio <= 0);

        do {
            cout << "Stock: ";
            cin >> stock;

            if (stock < 0) {
                cout << "El stock no puede ser negativo." << endl;
            }
        } while (stock < 0);
    }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Stock: " << stock << endl;
    }

    void agregarStock(int cantidad) {
        if (cantidad > 0) {
            stock += cantidad;
        }
        else {
            cout << "La cantidad debe ser mayor que 0." << endl;
        }
    }

    void vender(int cantidad) {
        if (cantidad <= 0) {
            cout << "La cantidad debe ser mayor que 0." << endl;
        }
        else if (cantidad > stock) {
            cout << "No hay stock suficiente." << endl;
        }
        else {
            stock -= cantidad;
            cout << "Venta realizada correctamente." << endl;
        }
    }

    void modificarPrecio(float nuevoPrecio) {
        if (nuevoPrecio > 0) {
            precio = nuevoPrecio;
        }
        else {
            cout << "El precio debe ser mayor que 0." << endl;
        }
    }

    float calcularValorStock() {
        return precio * stock;
    }

    bool hayStock() {
        return stock > 0;
    }
};

int main() {

    // Se utilizan distintos constructores
    Producto producto1;
    Producto producto2(101, "Mouse", 15000);
    Producto producto3(102, "Teclado", 25000, 10);

    cout << "PRODUCTO 1" << endl;
    producto1.cargar();
    cout << endl;

    cout << "PRODUCTO 2" << endl;
    producto2.mostrar();
    cout << endl;

    cout << "PRODUCTO 3" << endl;
    producto3.mostrar();
    cout << endl;

    // Modificamos el stock del producto 2
    cout << "Agregando stock al producto 2..." << endl;
    producto2.agregarStock(20);

    // Realizamos una venta
    cout << "Vendiendo 5 unidades del producto 2..." << endl;
    producto2.vender(5);

    // Intentamos vender más unidades de las disponibles
    cout << "Intentando vender 30 unidades del producto 2..." << endl;
    producto2.vender(30);

    // Modificamos el precio
    cout << "Modificando precio del producto 3..." << endl;
    producto3.modificarPrecio(28000);

    cout << endl;
    cout << "DATOS ACTUALIZADOS" << endl;

    cout << "\nProducto 1:" << endl;
    producto1.mostrar();

    cout << "\nProducto 2:" << endl;
    producto2.mostrar();

    cout << "\nProducto 3:" << endl;
    producto3.mostrar();

    cout << endl;
    cout << "VALOR DEL STOCK" << endl;

    cout << "Producto 1: $" << producto1.calcularValorStock() << endl;
    cout << "Producto 2: $" << producto2.calcularValorStock() << endl;
    cout << "Producto 3: $" << producto3.calcularValorStock() << endl;

    cout << endl;
    cout << "PRODUCTOS CON STOCK" << endl;

    if (producto1.hayStock()) {
        cout << "Producto 1 tiene stock." << endl;
    }
    else {
        cout << "Producto 1 no tiene stock." << endl;
    }

    if (producto2.hayStock()) {
        cout << "Producto 2 tiene stock." << endl;
    }
    else {
        cout << "Producto 2 no tiene stock." << endl;
    }

    if (producto3.hayStock()) {
        cout << "Producto 3 tiene stock." << endl;
    }
    else {
        cout << "Producto 3 no tiene stock." << endl;
    }

    return 0;
}