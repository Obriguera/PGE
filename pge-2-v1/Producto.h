#pragma once
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;
class Producto {
private:
    std::string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    //Producto(const std::string& nombre = "", double precio = 0.0, int cantidad = 0);
    Producto(const std::string& nombre = "", double precio = 0.0, int cantidad = 0);

    // G
    std::string  getNombre() const;
    double getPrecio() const;
    int getCantidad() const;

    //S
    void setNombre(const std::string& nombre);
    void setPrecio(double precio);
    void setCantidad(int cantidad);
    double getValorTotal() const;
};

#endif 
