#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Pasajero.h"
#include "Vuelo.h"
#include "Reserva.h"

using namespace std;

void mostrarMenu() {
    cout << "Sistema de Reservas de Vuelos\n";
    cout << "1. Mostrar todos los vuelos\n";
    cout << "2. Hacer una reserva\n";
    cout << "3. Mostrar todas las reservas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

void mostrarVuelos(const vector<Vuelo>& vuelos) 
{
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles.\n";
        return;
    }
    for (const auto& vuelo : vuelos) {
        vuelo.mostrarInformacion();
    }
}

void hacerReserva(vector<Vuelo>& vuelos, vector<Reserva>& reservas) 
{
    string nombre, apellido, DNI, numeroVuelo;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese DNI: ";
    cin >> DNI;
    cout << "Ingrese número de vuelo: ";
    cin >> numeroVuelo;

    auto it = find_if(vuelos.begin(), vuelos.end(), [&numeroVuelo](const Vuelo& v) 
        {
        return v.getNumeroVuelo() == numeroVuelo;
        });

    if (it != vuelos.end() && it->reservarAsiento()) 
    {
        int asiento = it->asientosTotales - it->asientosDisponibles; // Asignar el número de asiento
        Pasajero pasajero(nombre, apellido, DNI);
        Reserva reserva(pasajero, *it, asiento);
        reservas.push_back(reserva);
        cout << "Reserva realizada con éxito.\n";
    }
    else {
        cout << "No se pudo realizar la reserva. Verifique el número de vuelo o disponibilidad de asientos.\n";
    }
}

void mostrarReservas(const vector<Reserva>& reservas) 
{
    if (reservas.empty()) {
        cout << "No hay reservas registradas.\n";
        return;
    }
    for (const auto& reserva : reservas) {
        reserva.mostrarInformacion();
        cout << "--------------------------\n";
    }
}

int main() {
    vector<Vuelo> vuelos = {
        Vuelo("AA123", "Nueva York", "Madrid", 100),
        Vuelo("BB456", "Londres", "Barcelona", 150)
    };

    vector<Reserva> reservas;
    int opcion;

    do 
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: // Mostrar todos los vuelos
            mostrarVuelos(vuelos);
            break;
        case 2: // Hacer una reserva
            hacerReserva(vuelos, reservas);
            break;
        case 3: // Mostrar todas las reservas
            mostrarReservas(reservas);
            break;
        case 4: // Salir
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida. Por favor, intente de nuevo.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}
