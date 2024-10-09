#include "Empleado.h"
#include <iostream>

// Inicializar la variable estática
int Empleado::siguienteId = 1;

Empleado::Empleado(const std::string& nombre, int edad, const std::string& genero, float salario, const std::string& cargo)
    : Persona(nombre, edad, genero), salario(salario), cargo(cargo), idEmpleado(siguienteId++) {}

Empleado Empleado::cargarEmpleado() {
    std::string nombre, genero, cargo;
    int edad;
    float salario;
        
    cout << "Ingrese los datos del empleado:\n";
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Edad: ";
    cin >> edad;
    cout << "Genero: ";
    cin >> genero;
    cout << "Salario: ";
    cin >> salario;
    cout << "Cargo: ";
    cin >> cargo;
    cin.ignore();

    return Empleado(nombre, edad, genero, salario, cargo);
}

float Empleado::getSalario() const {
    return salario;
}

std::string Empleado::getCargo() const {
    return cargo;
}

int Empleado::getIdEmpleado() const {
    return idEmpleado;
}

void Empleado::mostrarEmpleados(const vector<Empleado>& empleados) {
    cout << "\nLista de Empleados:\n";
    for (const auto& Empleado : empleados) {
        cout << "Nombre: " << Empleado.getNombre() << ", Edad: " << Empleado.getEdad()
			<< ", Genero: " << Empleado.getGenero() << ", Salario: " << Empleado.getSalario()
			<< ", Cargo: " << Empleado.getCargo() << ", ID: " << Empleado.getIdEmpleado() << endl;
    }
}