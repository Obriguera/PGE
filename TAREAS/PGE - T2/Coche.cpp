#include "Coche.h"
#include <iostream>

// Constructor por defecto (llama al constructor de la clase base)
Coche::Coche() : Vehiculo(), numPuertas(0) {}

// Constructor parametrizado (llama al constructor de la clase base)
Coche::Coche(string marca, string modelo, int anio, int ruedas,
    float capacidaddecombustible, double precio, int numPuertas)
    : Vehiculo(marca, modelo, anio, ruedas, capacidaddecombustible, precio),
    numPuertas(numPuertas) {}

// Setter y getter con nombres más estándar
void Coche::setNumPuertas(int numPuertas) {
    this->numPuertas = numPuertas;
}

int Coche::getNumPuertas() const {
    return numPuertas;
}

Coche Coche::cargarCoche() {
    string marca, modelo;
    int anio, ruedas, numPuertas;
    float capacidadCombustible;
    double precio;

    cout << "Ingrese los datos del coche:\n";
    cout << "Marca: ";
    getline(cin, marca);
    cout << "Modelo: ";
    getline(cin, modelo);
    cout << "Año: ";
    cin >> anio;
    cout << "Número de ruedas: ";
    cin >> ruedas;
    cout << "Capacidad de combustible (litros): ";
    cin >> capacidadCombustible;
    cout << "Número de puertas: ";
    cin >> numPuertas;
    cout << "Precio: ";
    cin >> precio;
    cin.ignore();

    return Coche(marca, modelo, anio, ruedas, capacidadCombustible, precio, numPuertas);
}

void Coche::mostrarCoches(const vector<Coche>& coches) {
    cout << "\nLista de Coches:\n";
    for (const auto& coche : coches) {
        cout << "Marca: " << coche.getMarca() << ", Modelo: " << coche.getModelo()
            << ", Año: " << coche.getAnio() << ", Ruedas: " << coche.getRuedas()
            << ", Capacidad de Combustible: " << coche.getCapacidadDeCombustible()
            << ", Número de Puertas: " << coche.getNumPuertas()
            << ", Precio: " << coche.getPrecio() << endl; // Mostrar el precio
    }
}