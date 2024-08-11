#include "Empleado.h"

Empleado::Empleado(const std::string& nombre, int edad, const std::string& genero, float salario, const std::string& cargo)
    : Persona(nombre, edad, genero), salario(salario), cargo(cargo) {}

float Empleado::getSalario() const {
    return salario;
}

std::string Empleado::getCargo() const {
    return cargo;
}
