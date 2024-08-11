#ifndef MOTO_H
#define MOTO_H


#include <iostream>
#include<string>
#include"veiculo.h"

using namespace std;
class moto :public veiculo {
private:
    string  tipoDeManillar;

public:
    moto();

    moto(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible, string  tipoDeManillar);

    void setmanillar(string  tipoDeManillar);

    // Getter for npuertas
    string getManillar() const;


};

#endif // MOTO_H#pragma once
