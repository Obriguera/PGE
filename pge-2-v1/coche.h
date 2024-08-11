#ifndef COCHE_H
#define COCHE_H


#include <iostream>
#include<string>
#include"veiculo.h"

using namespace std;
class coche :public veiculo {
private:
    int npuertas;

public:
    coche();

    coche(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible, int npuertas);

    void setNpuertas(int npuertas);

    // Getter for npuertas
    int getnpuertas() const;


};

#endif // COCHE_H