#pragma once
#ifndef CARRITO_DE_COMPRAS_H
#define CARRITO_DE_COMPRAS_H

#include "Producto.h"
using namespace std;

const int MAX_PRODUCTOS = 100; 

class CarritoDeCompras {
private:
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos;

public:
    // Constructor
    CarritoDeCompras();


    bool agregarProducto(const Producto& producto);
    
    double calcularTotal() const;
    
    int obtenerCantidadProductos() const;

  
    void obtenerProductos(Producto* productosArray, int& cantidad) const;
};

#endif 