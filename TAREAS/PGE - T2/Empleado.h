#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"
#include <string>
#include<vector>
using namespace std;

class Empleado : public Persona {
public:
    Empleado(const std::string& nombre, int edad, const std::string& genero, float salario, const std::string& cargo);

    float getSalario() const;
    std::string getCargo() const;
    int getIdEmpleado() const; // Nuevo m�todo para obtener el ID
    static Empleado cargarEmpleado();
    static void mostrarEmpleados(const vector<Empleado>& empleados); // M�todo est�tico para mostrar empleados
private:
    float salario;
    std::string cargo;
    int idEmpleado; // Nuevo atributo para almacenar el ID
    static int siguienteId; // Variable est�tica para generar IDs �nicos
};

#endif // EMPLEADO_H

