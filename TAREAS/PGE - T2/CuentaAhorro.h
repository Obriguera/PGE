#ifndef CUENTA_AHORRO_H
#define CUENTA_AHORRO_H

#include "CuentaBancaria.h"

class CuentaAhorro : public CuentaBancaria {
public:
    CuentaAhorro(double saldoInicial, const std::string& numero);
    bool retirar(double cantidad) override; // Sobrescribe el m�todo retirar
};

#endif // CUENTA_AHORRO_H

