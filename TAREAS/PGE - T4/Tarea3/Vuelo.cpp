#include "Vuelo.h"
#include <iostream>
using namespace std;

Vuelo::Vuelo(string numeroVuelo, string destino, string origen, int asientosTotales) :
    numeroVuelo(numeroVuelo), destino(destino), origen(origen), asientosTotales(asientosTotales), asientosDisponibles(asientosTotales) {}

void Vuelo::mostrarInformacionV() const {
    
    cout << "Vuelo: " << numeroVuelo << ", Destino: " << destino << ", Origen: " << origen;
        //<< ", Asientos Totales: " << asientosTotales << ", Asientos Disponibles: " << asientosDisponibles << endl;
    cout << endl;
}

bool Vuelo::reservarAsiento() {
    if (asientosDisponibles > 0) {
        asientosDisponibles--;
        return true;
    }
    return false;
}

string Vuelo::getNumeroVuelo() const {
    return numeroVuelo;
}