#ifndef VEICULO_H
#define VEICULO_H

#include<string>
using namespace std;
class veiculo {
private:
    string marca, modelo;
    int anio;
    int ruedas;
    float capacidaddecombustible;
public:

    veiculo();

    // Constructor parametrizado
    veiculo(string marca, string modelo, int anio, int ruedas, float capacidaddecombustible);

    // M�todos de acceso (getters)
    string getMarca() const;
    string getModelo() const;
    int getAnio() const;
    int getRuedas() const;
    float getCapacidadDeCombustible() const;

    // M�todos de modificaci�n (setters)
    void setMarca(string marca);
    void setModelo(string modelo);
    void setAnio(int anio);
    void setRuedas(int ruedas);
    void setCapacidadDeCombustible(float capacidaddecombustible);

};


#endif // VEICULO_H