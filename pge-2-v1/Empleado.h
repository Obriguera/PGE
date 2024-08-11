#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
public:
    Empleado(const std::string& nombre, int edad, const std::string& genero, float salario, const std::string& cargo);

    float getSalario() const;
    std::string getCargo() const;

private:
    float salario;
    std::string cargo;
};

#endif // EMPLEADO_H
