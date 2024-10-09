#ifndef CUENTA_BANCARIA_H
#define CUENTA_BANCARIA_H

#include <string>

class CuentaBancaria {
protected:
    double saldo;
    std::string numeroCuenta;

public:
    CuentaBancaria(double saldoInicial, const std::string& numero);

    double obtenerSaldo() const;
    const std::string& obtenerNumeroCuenta() const;

    void depositar(double cantidad);
    virtual bool retirar(double cantidad); // Método virtual para permitir sobrescritura

    virtual ~CuentaBancaria();
};

#endif // CUENTA_BANCARIA_H
