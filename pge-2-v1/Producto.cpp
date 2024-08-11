#include "Producto.h"
using namespace std;

// Constructor
Producto::Producto(const string& nombre, double precio, int cantidad)
    : nombre(nombre), precio(precio), cantidad(cantidad) {}

// G
string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getCantidad() const {
    return cantidad;
}

// S
void Producto::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}

void Producto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

// Método para obtener el valor total del producto
double Producto::getValorTotal() const {
    return precio * cantidad;
}
