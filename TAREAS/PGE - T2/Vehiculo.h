#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

class Vehiculo {
protected: // Cambiamos a protected para que las clases derivadas puedan acceder
    string marca, modelo;
    int anio;
    int ruedas;
    float capacidaddecombustible;
    double precio; // Nuevo atributo para almacenar el precio

public:
    Vehiculo();

    // Constructor parametrizado (agregamos el precio)
    Vehiculo(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible, double precio);

    // Métodos de acceso (getters)
    string getMarca() const;
    string getModelo() const;
    int getAnio() const;
    int getRuedas() const;
    float getCapacidadDeCombustible() const;
    double getPrecio() const; // Nuevo getter para el precio
    virtual void mostrarDatos() const; // Declaración del método mostrarDatos

    // Métodos de modificación (setters)
    void setMarca(string marca);
    void setModelo(string modelo);
    void setAnio(int anio);
    void setRuedas(int ruedas);
    void setCapacidadDeCombustible(float capacidaddecombustible);
    void setPrecio(double precio); // Nuevo setter para el precio
};

#endif // VEHICULO_H
