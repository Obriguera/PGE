#ifndef COCHE_H
#define COCHE_H

#include <string>
#include<vector>
#include "Vehiculo.h"

using namespace std;

class Coche : public Vehiculo {
private:
    int numPuertas;

public:
    Coche();

    Coche(string marca, string modelo, int anio, int ruedas,
        float capacidaddecombustible, double precio, int numPuertas);

    void setNumPuertas(int numPuertas);
    int getNumPuertas() const;
    static Coche cargarCoche(); // Método estático para cargar un coche
    static void mostrarCoches(const vector<Coche>& coches); // Método estático para mostrar coches
};

#endif // COCHE_H
