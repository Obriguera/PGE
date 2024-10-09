#include "CarritoDeCompras.h"

// Constructor
CarritoDeCompras::CarritoDeCompras() {}

// Agregar un veh�culo al carrito
bool CarritoDeCompras::agregarVehiculo(Vehiculo* vehiculo) {
    vehiculos.push_back(vehiculo);
    return true;
}

// Calcular el total de la compra (usando el precio de cada veh�culo)
double CarritoDeCompras::calcularTotal() const {
    double total = 0.0;
    for (Vehiculo* v : vehiculos) {
        total += v->getPrecio();
    }
    return total;
}

// Obtener la cantidad de veh�culos en el carrito
int CarritoDeCompras::obtenerCantidadVehiculos() const {
    return vehiculos.size();
}

// Obtener los veh�culos en el carrito
std::vector<Vehiculo*> CarritoDeCompras::obtenerVehiculos() const {
    return vehiculos;
}
