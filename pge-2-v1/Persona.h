#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
public:
    Persona(const std::string& nombre, int edad, const std::string& genero);

    std::string getNombre() const;
    int getEdad() const;
    std::string getGenero() const;

private:
    std::string nombre;
    int edad;
    std::string genero;
};

#endif // PERSONA_H
