#include "CuentaBancaria.h"
#include <iostream>

CuentaBancaria::CuentaBancaria(double saldoInicial, const std::string& numero)
    : saldo(saldoInicial), numeroCuenta(numero) {}

double CuentaBancaria::obtenerSaldo() const {
    return saldo;
}

const std::string& CuentaBancaria::obtenerNumeroCuenta() const {
    return numeroCuenta;
}

void CuentaBancaria::depositar(double cantidad) {
    if (cantidad > 0) {
        saldo += cantidad;
        std::cout << "Depósito exitoso. Nuevo saldo: " << saldo << std::endl;
    }
    else {
        std::cout << "Cantidad de depósito inválida." << std::endl;
    }
}

// Método virtual para retirar, implementado en clases derivadas
bool CuentaBancaria::retirar(double cantidad) {
    return false; // Implementación por defecto, siempre devuelve false
}

CuentaBancaria::~CuentaBancaria() {}
