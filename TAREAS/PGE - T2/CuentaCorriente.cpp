#include "CuentaCorriente.h"
#include <iostream>

CuentaCorriente::CuentaCorriente(double saldoInicial, const std::string& numero, double comision)
    : CuentaBancaria(saldoInicial, numero), comisionPorRetiro(comision) {}

bool CuentaCorriente::retirar(double cantidad) {
    if (cantidad > 0 && cantidad <= saldo) {
        double cantidadTotal = cantidad + comisionPorRetiro;
        if (cantidadTotal <= saldo) {
            saldo -= cantidadTotal;
            std::cout << "Retiro exitoso. Comisi�n aplicada: " << comisionPorRetiro
                << ". Nuevo saldo: " << saldo << std::endl;
            return true; // Retiro exitoso
        }
        else {
            std::cout << "Saldo insuficiente para cubrir el retiro y la comisi�n." << std::endl;
            return false; // Retiro fallido
        }
    }
    else {
        std::cout << "Cantidad de retiro inv�lida." << std::endl;
        return false; // Retiro fallido
    }
}
