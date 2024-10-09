#ifndef MOTO_H
#define MOTO_H

#include <string>
#include<vector>
#include "Vehiculo.h"

using namespace std;

class Moto : public Vehiculo {
private:
    string tipoManillar;

public:
    Moto();

    Moto(string marca, string modelo, int anio, int ruedas,
        float capacidaddecombustible, double precio, string tipoManillar);

    void setTipoDeManillar(string tipoManillar);
    string getTipoDeManillar() const;
    static Moto cargarMoto(); // M�todo est�tico para cargar una moto
    static void mostrarMotos(const vector<Moto>& motos); // M�todo est�tico para mostrar motos
};

#endif // MOTO_H
