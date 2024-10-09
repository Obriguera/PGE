#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H

#include "CuentaBancaria.h"

class CuentaCorriente : public CuentaBancaria {
private:
    double comisionPorRetiro;

public:
    CuentaCorriente(double saldoInicial, const std::string& numero, double comision);
    bool retirar(double cantidad) override; // Sobrescribe el método retirar
};

#endif // CUENTA_CORRIENTE_H

