#include "Moto.h"
#include<iostream>

// Constructor por defecto (inicializa todos los atributos)
Moto::Moto() : Vehiculo(), tipoManillar("") {}

// Constructor parametrizado (llama al constructor de la clase base)
Moto::Moto(string marca, string modelo, int anio, int ruedas,
    float capacidaddecombustible, double precio, string tipoManillar)
    : Vehiculo(marca, modelo, anio, ruedas, capacidaddecombustible, precio),
    tipoManillar(tipoManillar) {}

// Setter con nombre más estándar
void Moto::setTipoDeManillar(string tipoManillar) {
    this->tipoManillar = tipoManillar;
}

// Getter con nombre más estándar
string Moto::getTipoDeManillar() const {
    return tipoManillar;
}

// Método estático para cargar una moto
Moto Moto::cargarMoto() {
    string marca, modelo, tipoManillar;
    int anio, ruedas;
    float capacidadCombustible;
    double precio;

    cout << "Ingrese los datos de la moto:\n";
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
    cout << "Tipo de manillar: ";
    getline(cin, tipoManillar);
    cout << "Precio: ";
    cin >> precio;
    cin.ignore();

    return Moto(marca, modelo, anio, ruedas, capacidadCombustible, precio, tipoManillar);
}

// Método estático para mostrar motos
void Moto::mostrarMotos(const vector<Moto>& motos) {
    cout << "\nLista de Motos:\n";
    for (const auto& moto : motos) {
        cout << "Marca: " << moto.getMarca() << ", Modelo: " << moto.getModelo()
            << ", Año: " << moto.getAnio() << ", Ruedas: " << moto.getRuedas()
            << ", Capacidad de Combustible: " << moto.getCapacidadDeCombustible()
            << ", Tipo de Manillar: " << moto.getTipoDeManillar()
            << ", Precio: " << moto.getPrecio() << endl; // Mostrar el precio
    }
}