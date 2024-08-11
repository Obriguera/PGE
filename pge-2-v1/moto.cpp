#include"moto.h"

moto::moto() : veiculo(), tipoDeManillar("") {}


moto::moto(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible, string tipoDeManillar)
    : veiculo(marca, modelo, anio, ruedas, capacidaddecombustible), tipoDeManillar(tipoDeManillar){}

string moto::getManillar() const { return tipoDeManillar; }


void moto::setmanillar(string tipoDeManillar) {
    this->tipoDeManillar = tipoDeManillar;
}