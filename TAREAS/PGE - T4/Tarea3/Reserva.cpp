#include "Reserva.h"
#include <iostream>
using namespace std;

Reserva::Reserva(Pasajero pasajero, Vuelo& vuelo, int asiento) : pasajero(pasajero), vuelo(vuelo), asiento(asiento) {}

void Reserva::mostrarInformacionR() const {
    cout << "Reserva para: ";
    pasajero.mostrarInformacionP();
    cout << "";
    vuelo.mostrarInformacionV();
    cout << "Asiento N°: " << asiento << endl;
}