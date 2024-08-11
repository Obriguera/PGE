#include"coche.h"

coche::coche() : veiculo(), npuertas(0) {}


coche::coche(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible, int npuertas)
    : veiculo(marca, modelo, anio, ruedas, capacidaddecombustible), npuertas(npuertas) {}

int coche::getnpuertas() const { return npuertas; }


void coche::setNpuertas(int npuertas) {
    this->npuertas = npuertas;
}



