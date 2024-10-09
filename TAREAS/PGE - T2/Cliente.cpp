#include "Cliente.h"
#include <iostream>

Cliente::Cliente(const std::string& nombre, int edad, const std::string& genero,
    const CuentaBancaria& cuenta)
    : Persona(nombre, edad, genero), cuentaBancaria(cuenta) {}

void Cliente::mostrarInfoCliente() const {
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Edad: " << getEdad() << std::endl;
    std::cout << "Genero: " << getGenero() << std::endl;
    std::cout << "Cuenta Bancaria: " << cuentaBancaria.obtenerNumeroCuenta() << std::endl;
    std::cout << "Saldo: " << cuentaBancaria.obtenerSaldo() << std::endl;
}

const CuentaBancaria& Cliente::obtenerCuentaBancaria() const {
    return cuentaBancaria;
}
