#include "Moto.h"
#include<iostream>

// Constructor por defecto (inicializa todos los atributos)
Moto::Moto() : Vehiculo(), tipoManillar("") {}

// Constructor parametrizado (llama al constructor de la clase base)
Moto::Moto(string marca, string modelo, int anio, int ruedas,
    float capacidaddecombustible, double precio, string tipoManillar)
    : Vehiculo(marca, modelo, anio, ruedas, capacidaddecombustible, precio),
    tipoManillar(tipoManillar) {}

// Setter con nombre m�s est�ndar
void Moto::setTipoDeManillar(string tipoManillar) {
    this->tipoManillar = tipoManillar;
}

// Getter con nombre m�s est�ndar
string Moto::getTipoDeManillar() const {
    return tipoManillar;
}

// M�todo est�tico para cargar una moto
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
    cout << "A�o: ";
    cin >> anio;
    cout << "N�mero de ruedas: ";
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

// M�todo est�tico para mostrar motos
void Moto::mostrarMotos(const vector<Moto>& motos) {
    cout << "\nLista de Motos:\n";
    for (const auto& moto : motos) {
        cout << "Marca: " << moto.getMarca() << ", Modelo: " << moto.getModelo()
            << ", A�o: " << moto.getAnio() << ", Ruedas: " << moto.getRuedas()
            << ", Capacidad de Combustible: " << moto.getCapacidadDeCombustible()
            << ", Tipo de Manillar: " << moto.getTipoDeManillar()
            << ", Precio: " << moto.getPrecio() << endl; // Mostrar el precio
    }
}