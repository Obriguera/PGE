#include "CarritoDeCompras.h"
#include "CarritoDeCompras.h"
#include <cstring> // Para std::strcmp
#include <algorithm>

// Cons
CarritoDeCompras::CarritoDeCompras() : cantidadProductos(0) {}

// añadir un producto al carrito
bool CarritoDeCompras::agregarProducto(const Producto& producto) {
    if (cantidadProductos < MAX_PRODUCTOS) {
        productos[cantidadProductos++] = producto;
        return true;
    }
    return false; // El carrito está lleno
}

// Método para calcular el total de la compra
double CarritoDeCompras::calcularTotal() const {
    double total = 0.0;
    for (int i = 0; i < cantidadProductos; ++i) {
        total += productos[i].getValorTotal();
    }
    return total;
}

int CarritoDeCompras::obtenerCantidadProductos() const {
    return cantidadProductos;
}


void CarritoDeCompras::obtenerProductos(Producto* productosArray, int& cantidad) const {
    cantidad = cantidadProductos;
    for (int i = 0; i < cantidadProductos; ++i) {
        productosArray[i] = productos[i];
    }
}
