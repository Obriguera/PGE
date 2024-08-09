#include "Pasajero.h"
#include <iostream>
using namespace std;

Pasajero::Pasajero(string nombre, string apellido, string DNI) : nombre(nombre), apellido(apellido), DNI(DNI) {}

void Pasajero::mostrarInformacion() const {
    cout << "Nombre: " << nombre << ", Apellido: " << apellido << ", DNI: " << DNI << endl;
}
