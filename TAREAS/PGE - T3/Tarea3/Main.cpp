#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Pasajero.h"
#include "Vuelo.h"
#include "Reserva.h"

using namespace std;

void pausarPantalla() {
    cout << "\nPresione cualquier tecla para volver al menu principal...";
    cin.ignore();  // Limpiar el buffer de entrada
    cin.get();     // Esperar a que se presione una tecla
}

void limpiarPantalla() {
    system("cls");
}

void mostrarMenu() {
    cout << "Sistema de Reservas de Vuelos\n";
    cout << "1. Mostrar todos los vuelos\n";
    cout << "2. Hacer una reserva\n";
    cout << "3. Mostrar todas las reservas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

void mostrarVuelos(const vector<Vuelo>& vuelos) {
    limpiarPantalla();
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles.\n";
        return;
    }
    for (const auto& vuelo : vuelos) {
        vuelo.mostrarInformacionV();
        cout << "\n";
    }
    pausarPantalla();
    limpiarPantalla();
}

void mostrarReservas(const vector<Reserva>& reservas){
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

void MostrarReserva(const Reserva& res) {
    cout << "Reserva exitosa, desea ver los datos de su reserva? (S/N): " << endl;
    char respuesta;
    cin >> respuesta;

    respuesta = toupper(respuesta);

    bool detalleReserva = (respuesta == 'S');

    if (detalleReserva) {
        cout << " Pasajero: " << res.pasajero.nombre << " de apellido " << res.pasajero.apellido << endl;
        cout << "con DNI: " << res.pasajero.DNI << " en asiento " << res.asiento << endl;
        cout << "al vuelo con origen : " << res.vuelo.origen << " con destino " << res.vuelo.destino << endl;
    }
    else if (respuesta == 'N') {
        // Retorna al menu principal
    }
    else {
        cout << "Respuesta no valida." << endl;
    }
    
    pausarPantalla();
    limpiarPantalla();
}

void procesarDatos2(const std::vector<Reserva>& reservas, void (*callback)(const Reserva&))
{
    for (const Reserva& reserva : reservas)
    {
        callback(reserva);
    }
}

void hacerReserva(vector<Vuelo>& vuelos, vector<Reserva>& reservas) {
    limpiarPantalla();
    string nombre, apellido, DNI, numeroVuelo;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese DNI: ";
    cin >> DNI;
    cout << "Ingrese numero de vuelo: ";
    cin >> numeroVuelo;

    auto it = find_if(vuelos.begin(), vuelos.end(), [&numeroVuelo](const Vuelo& v) {
        return v.getNumeroVuelo() == numeroVuelo;
        });

    if (it != vuelos.end() && it->reservarAsiento()) {
        int asiento = it->asientosTotales - it->asientosDisponibles; // Asignar el número de asiento
        Pasajero pasajero(nombre, apellido, DNI);
        Reserva reserva(pasajero, *it, asiento);
        reservas.push_back(reserva);
        procesarDatos2(reservas, MostrarReserva);
    }
    else {
        cout << "No se pudo realizar la reserva. Verifique el número de vuelo o disponibilidad de asientos.\n";
        pausarPantalla();
    }
    limpiarPantalla();
}

void ProcesarDatos(int opcion, vector<Reserva>& reservas, vector<Vuelo>& vuelos, void (*callback)(const Reserva&)) {
    if (opcion == 1) {
        mostrarVuelos(vuelos);
    }
    else if (opcion == 2) {
        hacerReserva(vuelos, reservas); // Llamar directamente a hacerReserva en este caso
    }

}

void procesarMenu(int opcion, vector<Reserva>& reservas, vector<Vuelo>& vuelos) {
    switch (opcion) {
    case 1: // Mostrar todos los vuelos
        system("cls");
        ProcesarDatos(1, reservas, vuelos, nullptr); // Llama a mostrarVuelos directamente
        break;
    case 2: // Hacer una reserva
        ProcesarDatos(2, reservas, vuelos, nullptr); // Llama a hacerReserva directamente
        break;
    case 3: // Mostrar todas las reservas
        mostrarReservas(reservas);
        break;
    case 4: // Salir
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