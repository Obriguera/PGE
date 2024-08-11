#include "Estudiante.h"

Estudiante::Estudiante(const std::string& nombre, int edad, float nota)
    : nombre(nombre), edad(edad), nota(nota) {}

std::string Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getEdad() const {
    return edad;
}

float Estudiante::getNota() const {
    return nota;
}
