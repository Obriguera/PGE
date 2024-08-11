#include <iostream>
#include<string>
#include"veiculo.h"


// Constructor por defecto
veiculo::veiculo() : marca(""), modelo(""), anio(0), ruedas(0), capacidaddecombustible(0.0) {}

// Constructor parametrizado
veiculo::veiculo(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible)
    : marca(marca), modelo(modelo), anio(anio), ruedas(ruedas), capacidaddecombustible(capacidaddecombustible) {}

// Métodos Getter
string veiculo::getMarca() const { return marca; }
string veiculo::getModelo() const { return modelo; }
int veiculo::getAnio() const { return anio; }
int veiculo::getRuedas() const { return ruedas; }
float veiculo::getCapacidadDeCombustible() const { return capacidaddecombustible; }

// Métodos Setter
void veiculo::setMarca(string marca) { this->marca = marca; }
void veiculo::setModelo(string modelo) { this->modelo = modelo; }
void veiculo::setAnio(int anio) { this->anio = anio; }
void veiculo::setRuedas(int ruedas) { this->ruedas = ruedas; }
void veiculo::setCapacidadDeCombustible(float capacidaddecombustible) { this->capacidaddecombustible = capacidaddecombustible; }