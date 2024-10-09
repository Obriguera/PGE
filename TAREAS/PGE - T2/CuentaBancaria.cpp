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
        std::cout << "Dep�sito exitoso. Nuevo saldo: " << saldo << std::endl;
    }
    else {
        std::cout << "Cantidad de dep�sito inv�lida." << std::endl;
    }
}

// M�todo virtual para retirar, implementado en clases derivadas
bool CuentaBancaria::retirar(double cantidad) {
    return false; // Implementaci�n por defecto, siempre devuelve false
}

CuentaBancaria::~CuentaBancaria() {}
