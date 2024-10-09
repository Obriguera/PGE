#ifndef PASAJERO_H
#define PASAJERO_H

#include <string>
using namespace std;

class Pasajero {
public:
    string nombre;
    string apellido;
    string DNI;

    Pasajero(string nombre, string apellido, string DNI);
    void mostrarInformacion() const;
};

#endif
