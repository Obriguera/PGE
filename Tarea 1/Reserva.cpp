#include "Reserva.h"
#include <iostream>
using namespace std;

Reserva::Reserva(Pasajero pasajero, Vuelo& vuelo, int asiento) : pasajero(pasajero), vuelo(vuelo), asiento(asiento) {}

void Reserva::mostrarInformacion() const {
    cout << "Reserva para: ";
    pasajero.mostrarInformacion();
    cout << "Vuelo: ";
    vuelo.mostrarInformacion();
    cout << "Asiento N°: " << asiento << endl;
}
