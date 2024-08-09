#ifndef VUELO_H
#define VUELO_H

#include <string>
using namespace std;

class Vuelo {
public:
    string numeroVuelo;
    string destino;
    string origen;
    int asientosTotales;
    int asientosDisponibles;

    Vuelo(string numeroVuelo, string destino, string origen, int asientosTotales);

    void mostrarInformacion() const;
    bool reservarAsiento();
    string getNumeroVuelo() const;
};

#endif
