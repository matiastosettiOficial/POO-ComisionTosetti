//
// Created by Matias on 21-Sep-26.
//
#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombre;
    string telefono;
    string direccion;

public:
    Cliente(string nombre, string telefono, string direccion) {
        this->nombre = nombre;
        this->telefono = telefono;
        this->direccion = direccion;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Direccion: " << direccion << endl;
    }
};


class Producto {
private:
    string nombre;
    double precio;
    string categoria;

public:
    Producto(string nombre, double precio, string categoria) {
        this->nombre = nombre;
        this->precio = precio;
        this->categoria = categoria;
    }

    double getPrecio() {
        return precio;
    }

    void mostrar() {
        cout << "Producto: " << nombre << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Precio: $" << precio << endl;
    }
};


class DetallePedido {
private:
    Producto producto;
    int cantidad;

public:

    // Constructor por defecto en una clase composición
    DetallePedido()
        : producto("", 0, "") {
        this->cantidad = 0;
    }

    // Constructor con parámetros en clase de composición
    DetallePedido(Producto producto, int cantidad)
        : producto(producto){
        this->cantidad = cantidad;
    }

    double calcularSubtotal() {
        return producto.getPrecio() * cantidad;
    }

    void mostrar() {
        producto.mostrar();
        cout << "Cantidad: " << cantidad << endl;
        cout << "Subtotal: $" << calcularSubtotal() << endl;
    }
};


class Pedido {
private:
    int numero;
    string estado;

    Cliente cliente;

    // Composición: un pedido tiene varios detalles
    DetallePedido detalles[10];

    int cantidadDetalles;

public:

    Pedido(int numero,
           Cliente cliente,
           DetallePedido detalleInicial)
        : cliente(cliente),
          detalles{detalleInicial} {

        this->numero = numero;
        this->estado = "Pendiente";
        cantidadDetalles = 1;
    }

    void agregarDetalle(DetallePedido detalle) {

        if (cantidadDetalles < 10) {
            detalles[cantidadDetalles] = detalle;
            cantidadDetalles++;
        }else {
            cout << "no hay más lugar para mas productos" << endl;
        }
    }

    double calcularTotal() {

        double total = 0;

        for (int i = 0; i < cantidadDetalles; i++) {
            total += detalles[i].calcularSubtotal();
        }

        return total;
    }

    void cambiarEstado(string nuevoEstado) {
        estado = nuevoEstado;
    }

    void mostrar() {

        cout << "===== PEDIDO =====" << endl;

        cout << "Numero: " << numero << endl;
        cout << "Estado: " << estado << endl;

        cout << "\n--- Cliente ---" << endl;
        cliente.mostrar();

        cout << "\n--- Detalles ---" << endl;

        for (int i = 0; i < cantidadDetalles; i++) {

            cout << "\nDetalle " << i + 1 << endl;

            detalles[i].mostrar();
        }

        cout << "\nTOTAL: $" << calcularTotal() << endl;
    }
};


int main() {

    // Creamos los productos
    Producto hamburguesa(
        "Hamburguesa completa",
        8500,
        "Comida"
    );

    Producto pizza(
        "Pizza muzzarella",
        12000,
        "Comida"
    );

    Producto gaseosa(
        "Gaseosa",
        2500,
        "Bebida"
    );


    // Creamos el cliente
    Cliente cliente(
        "Carlos Gomez",
        "3515555555",
        "Av. Colon 1234"
    );


    // Creamos los detalles
    DetallePedido detalle1(
        hamburguesa,
        2
    );

    DetallePedido detalle2(
        pizza,
        1
    );

    DetallePedido detalle3(
        gaseosa,
        3
    );


    // Creamos el pedido
    Pedido pedido(
        1001,
        cliente,
        detalle1
    );

    // Agregamos los otros detalles
    pedido.agregarDetalle(detalle2);
    pedido.agregarDetalle(detalle3);


    // Mostramos el pedido
    pedido.mostrar();


    cout << "\n--- Cambiando estado ---" << endl;

    pedido.cambiarEstado("En preparacion");

    pedido.mostrar();


    return 0;
}
