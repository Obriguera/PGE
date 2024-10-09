#include "CuentaAhorro.h"
#include <iostream>

CuentaAhorro::CuentaAhorro(double saldoInicial, const std::string& numero)
    : CuentaBancaria(saldoInicial, numero) {}

bool CuentaAhorro::retirar(double cantidad) {
    if (cantidad > 0 && cantidad <= saldo) {
        saldo -= cantidad;
        std::cout << "Retiro exitoso. Nuevo saldo: " << saldo << std::endl;
        return true; // Retiro exitoso
    }
    else {
        std::cout << "Cantidad de retiro inválida o saldo insuficiente." << std::endl;
        return false; // Retiro fallido
    }
}
