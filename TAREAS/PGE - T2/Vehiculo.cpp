#include <iostream>
#include <string>
#include "Vehiculo.h"

// Constructor por defecto
Vehiculo::Vehiculo() : marca(""), modelo(""), anio(0), ruedas(0), capacidaddecombustible(0.0), precio(0.0) {}

// Constructor parametrizado (incluyendo el precio)
Vehiculo::Vehiculo(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible, double precio)
    : marca(marca), modelo(modelo), anio(anio), ruedas(ruedas),
    capacidaddecombustible(capacidaddecombustible), precio(precio) {}

// Métodos Getter
string Vehiculo::getMarca() const { return marca; }
string Vehiculo::getModelo() const { return modelo; }
int Vehiculo::getAnio() const { return anio; }
int Vehiculo::getRuedas() const { return ruedas; }
float Vehiculo::getCapacidadDeCombustible() const { return capacidaddecombustible; }
// Nuevo getter para el precio
double Vehiculo::getPrecio() const {
    return precio;
}
// Implementación del método mostrarDatos
void Vehiculo::mostrarDatos() const {
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Año: " << anio << endl;
    cout << "Ruedas: " << ruedas << endl;
    cout << "Capacidad de Combustible: " << capacidaddecombustible << " litros" << endl;
}

// Métodos Setter
void Vehiculo::setMarca(string marca) { this->marca = marca; }
void Vehiculo::setModelo(string modelo) { this->modelo = modelo; }
void Vehiculo::setAnio(int anio) { this->anio = anio; }
void Vehiculo::setRuedas(int ruedas) { this->ruedas = ruedas; }
void Vehiculo::setCapacidadDeCombustible(float capacidaddecombustible) { this->capacidaddecombustible = capacidaddecombustible; }
// Nuevo setter para el precio
void Vehiculo::setPrecio(double precio) {
    this->precio = precio;
}