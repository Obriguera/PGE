#include "Persona.h"

Persona::Persona(const std::string& nombre, int edad, const std::string& genero)
    : nombre(nombre), edad(edad), genero(genero) {}

std::string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

std::string Persona::getGenero() const {
    return genero;
}
