#ifndef RESERVA_H
#define RESERVA_H

#include "Pasajero.h"
#include "Vuelo.h"

class Reserva {
public:
    Pasajero pasajero;
    Vuelo& vuelo;
    int asiento;

    Reserva(Pasajero pasajero, Vuelo& vuelo, int asiento);
    void mostrarInformacionR() const;
};

#endif