#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Pasajero.h"
#include "Vuelo.h"
#include "Reserva.h"

using namespace std;

// Función para pausar la pantalla
void pausarPantalla() {
    cout << "\nPresione cualquier tecla para volver al menu principal...";
    cin.ignore();
    cin.get();
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    system("cls");
}

// Función para mostrar el menú
void mostrarMenu() 
{
    cout << "Sistema de Reservas de Vuelos\n";
    cout << "1. Mostrar todos los vuelos\n";
    cout << "2. Hacer una reserva\n";
    cout << "3. Mostrar todas las reservas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Función para mostrar los vuelos disponibles
void mostrarVuelos(const vector<Vuelo>& vuelos) {
    limpiarPantalla();
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles.\n";
        pausarPantalla();
        limpiarPantalla();
        return;
    }
    for (const auto& vuelo : vuelos) {
        

        vuelo.mostrarInformacionV();
        cout << "\n";
    }
    pausarPantalla();
    limpiarPantalla();
}

// Función para mostrar todas las reservas
void mostrarReservas(const vector<Reserva>& reservas) {
    limpiarPantalla();
    if (reservas.empty()) {
        cout << "No hay reservas registradas.\n";
        pausarPantalla();
        limpiarPantalla();
        return;
    }
    for (const auto& reserva : reservas) {
        reserva.mostrarInformacionR();
        cout << "--------------------------\n";
    }
    pausarPantalla();
    limpiarPantalla();
}

// Callback para notificar a los pasajeros sobre una reserva exitosa
void notificarReservaExitosa(const Reserva& reserva) {
    cout << "Reserva exitosa para el pasajero :" << reserva.pasajero.nombre << " " << reserva.pasajero.apellido << ".\n";
}

// Callback para permitir a los pasajeros consultar los detalles de su reserva
void consultarDetallesReserva(const Reserva& reserva) {
    cout << "Desea ver los detalles de su reserva? (S/N): ";
    char respuesta;
    cin >> respuesta;
    respuesta = toupper(respuesta);

    if (respuesta == 'S') {
        reserva.mostrarInformacionR();
    }
    else if (respuesta == 'N') {
        cout << "Volviendo al menú principal...\n";
    }
    else {
        cout << "Respuesta no valida.\n";
    }

    pausarPantalla();
    limpiarPantalla();
}

// Función para realizar una reserva
void hacerReserva(vector<Vuelo>& vuelos, vector<Reserva>& reservas) {
    limpiarPantalla();
    string nombre, apellido, DNI, numeroVuelo;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese DNI: ";
    cin >> DNI;
    limpiarPantalla();
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles.\n";
        pausarPantalla();
        limpiarPantalla();
        return;
    }
    for (const auto& vuelo : vuelos) {
        vuelo.mostrarInformacionV();
        cout << "\n";
    }
    cout << "Ingrese numero de vuelo a elegir: ";
    cin >> numeroVuelo;

    auto it = find_if(vuelos.begin(), vuelos.end(), [&numeroVuelo](const Vuelo& v) {
        return v.getNumeroVuelo() == numeroVuelo;
        });
    limpiarPantalla();
    if (it != vuelos.end() && it->reservarAsiento()) {
        int asiento = it->asientosTotales - it->asientosDisponibles;
        Pasajero pasajero(nombre, apellido, DNI);
        Reserva reserva(pasajero, *it, asiento);
        reservas.push_back(reserva);

        // Notificación y consulta de detalles usando callbacks
        notificarReservaExitosa(reserva);
        consultarDetallesReserva(reserva);
    }
    else {
        cout << "No se pudo realizar la reserva. Verifique el número de vuelo o disponibilidad de asientos.\n";
        pausarPantalla();
    }
    limpiarPantalla();
}

// Función para procesar las opciones del menú
void procesarMenu(int opcion, vector<Reserva>& reservas, vector<Vuelo>& vuelos) {
    switch (opcion) {
    case 1:
        mostrarVuelos(vuelos);
        break;
    case 2:
        hacerReserva(vuelos, reservas);
        break;
    case 3:
        mostrarReservas(reservas);
        break;
    case 4:
        cout << "Saliendo del sistema...\n";
        break;
    default:
        cout << "Opcion no valida. Por favor, intente de nuevo.\n";
        pausarPantalla();
        limpiarPantalla();
        break;
    }
}


int main() {
    vector<Vuelo> vuelos = {
        Vuelo("AA123", "Nueva York", "Madrid", 100),
        Vuelo("BB456", "Londres", "Barcelona", 150)
    };

    vector<Reserva> reservas;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        procesarMenu(opcion, reservas, vuelos);
    } while (opcion != 4);

    return 0;
}
