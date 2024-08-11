#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
public:
    Estudiante(const std::string& nombre, int edad, float nota);

    std::string getNombre() const;
    int getEdad() const;
    float getNota() const;

private:
    std::string nombre;
    int edad;
    float nota;
};

#endif // ESTUDIANTE_H
