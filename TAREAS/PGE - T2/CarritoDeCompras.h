#ifndef CARRITO_DE_COMPRAS_H
#define CARRITO_DE_COMPRAS_H

#include "Vehiculo.h" // Incluir Vehiculo.h en lugar de Producto.h
#include <vector>

using namespace std;

class CarritoDeCompras {
private:
    std::vector<Vehiculo*> vehiculos; // Almacenar punteros a objetos Vehiculo

public:
    // Constructor
    CarritoDeCompras();
    bool agregarVehiculo(Vehiculo* vehiculo); // Modificado para recibir Vehiculo*
    double calcularTotal() const;
    int obtenerCantidadVehiculos() const; // Renombrado
    std::vector<Vehiculo*> obtenerVehiculos() const; // Renombrado y devuelve vector
};

#endif 
