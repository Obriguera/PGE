#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
#include "CuentaBancaria.h"
#include <string>

class Cliente : public Persona {
private:
    CuentaBancaria cuentaBancaria;

public:
    Cliente(const std::string& nombre, int edad, const std::string& genero,
        const CuentaBancaria& cuenta);

    void mostrarInfoCliente() const;
    const CuentaBancaria& obtenerCuentaBancaria() const;
};

#endif // CLIENTE_H
