#include <iostream>
#include <vector>
#include "Coche.h"
#include "Moto.h"
#include "Empleado.h"
#include "CarritoDeCompras.h"
#include "Cliente.h"
#include "CuentaCorriente.h"
#include "CuentaAhorro.h"

using namespace std;

static int mostrarMenuPrincipal() {
    int opcion;
    cout << "\n--- Menu Principal ---\n";
    cout << "1. Gestion de Inventario\n";
    cout << "2. Gestion de Empleados\n";
    cout << "3. Procesar Venta\n";
    cout << "4. Gestion de Clientes\n";  
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

static int mostrarSubMenuInventario() {
    int opcion;
    cout << "\n--- Submenu de Inventario ---\n";
    cout << "1. Cargar un coche al inventario\n";
    cout << "2. Cargar una moto al inventario\n";
    cout << "3. Mostrar inventario de coches\n";
    cout << "4. Mostrar inventario de motos\n";
    cout << "5. Mostrar inventario completo\n";
    cout << "6. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

static int mostrarSubMenuEmpleados() {
    int opcion;
    cout << "\n--- Submenu de Empleados ---\n";
    cout << "1. Cargar empleado\n";
    cout << "2. Mostrar lista de empleados\n";
    cout << "3. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

static int mostrarSubMenuClientes() {
    int opcion;
    std::cout << "\n--- Submenu de Clientes ---\n";
    std::cout << "1. Cargar cliente\n";
    std::cout << "2. Mostrar lista de clientes\n";
    std::cout << "3. Volver al menu principal\n";
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void procesarCompra(CarritoDeCompras& carrito, CuentaBancaria& cuentaCliente,
    std::vector<Coche>& coches, std::vector<Moto>& motos) {
    if (carrito.obtenerCantidadVehiculos() == 0) {
        std::cout << "El carrito está vacío. No se puede procesar la compra.\n";
        return;
    }

    double totalCompra = carrito.calcularTotal();
    if (cuentaCliente.retirar(totalCompra)) {
        std::cout << "Compra realizada con éxito. Saldo restante: " << cuentaCliente.obtenerSaldo() << std::endl;

       
        std::vector<Vehiculo*> vehiculosComprados = carrito.obtenerVehiculos();
        for (Vehiculo* vehiculo : vehiculosComprados) {
            if (dynamic_cast<Coche*>(vehiculo) != nullptr) {
                
                for (auto it = coches.begin(); it != coches.end(); ++it) {
                    if (&(*it) == vehiculo) {
                        coches.erase(it);
                        break;
                    }
                }
            }
            else if (dynamic_cast<Moto*>(vehiculo) != nullptr) {
                // Es una moto, buscar y eliminar de motos
                for (auto it = motos.begin(); it != motos.end(); ++it) {
                    if (&(*it) == vehiculo) {
                        motos.erase(it);
                        break;
                    }
                }
            }
        }

          // Vaciar el carrito después de la compra
    }
    else {
        std::cout << "Saldo insuficiente para realizar la compra.\n";
    }
}

void mostrarInventarioCompleto(const vector<Coche>& coches, const vector<Moto>& motos) {
    cout << "\nInventario Completo:\n";
    if (!coches.empty()) {
        cout << "\nCoches:\n";
        Coche::mostrarCoches(coches);
    }
    else {
        cout << "No hay coches disponibles en el inventario.\n";
    }
    if (!motos.empty()) {
        cout << "\nMotos:\n";
        Moto::mostrarMotos(motos);
    }
    else {
        cout << "No hay motos disponibles en el inventario.\n";
    }
}

int main() {
    vector<Coche> coches;
    vector<Moto> motos;
    vector<Empleado> empleados;
    vector<Cliente> clientes;  // Vector para almacenar clientes
    CarritoDeCompras carrito;

    CuentaBancaria* cuentaCliente = nullptr;

    int opcionPrincipal;
    do {
        opcionPrincipal = mostrarMenuPrincipal();
        switch (opcionPrincipal) {
        case 1: { // Gestión de Inventario
            int opcionInventario;
            do {
                opcionInventario = mostrarSubMenuInventario();
                switch (opcionInventario) {
                case 1: {
                    Coche nuevoCoche = Coche::cargarCoche();
                    coches.push_back(nuevoCoche);
                    break;
                }
                case 2: {
                    Moto nuevaMoto = Moto::cargarMoto();
                    motos.push_back(nuevaMoto);
                    break;
                }
                case 3:
                    Coche::mostrarCoches(coches);
                    break;
                case 4:
                    Moto::mostrarMotos(motos);
                    break;
                case 5:
                    mostrarInventarioCompleto(coches, motos);
                    break;
                case 6:
                    break; // Volver al menú principal
                default:
                    cout << "Opcion no valida. Intente nuevamente.\n";
                    break;
                }
            } while (opcionInventario != 6);
            break;
        }
        case 2: { // Gestión de Empleados
            int opcion_empleado;
            do {
                opcion_empleado = mostrarSubMenuEmpleados();
                switch (opcion_empleado) {
                case 1: {
                    Empleado nuevoEmpleado = Empleado::cargarEmpleado();
                    empleados.push_back(nuevoEmpleado);
                    break;
                }
                case 2: {
                    cout << "\nLista de Empleados:\n";
                    Empleado::mostrarEmpleados(empleados);
                    break;
                }
                case 3:
                    break; // Volver al menú principal
                default:
                    cout << "Opcion no valida. Intente nuevamente.\n";
                    break;
                }
            } while (opcion_empleado != 3);
            break;
        }
        case 3: { // Procesar Venta
            int tipoCuenta;
            cout << "\n¿Que tipo de cuenta tiene el cliente?\n";
            cout << "1. Cuenta Corriente\n";
            cout << "2. Cuenta de Ahorro\n";
            cout << "Seleccione una opcion: ";
            cin >> tipoCuenta;
            cin.ignore();

            double saldoInicial;
            string numeroCuenta;
            double comision = 0.0;

            cout << "Ingrese los datos de la cuenta:\n";
            cout << "Saldo inicial: ";
            cin >> saldoInicial;
            cin.ignore();
            cout << "Número de cuenta: ";
            getline(cin, numeroCuenta);

            if (tipoCuenta == 1) {
                cout << "Comisión por retiro: ";
                cin >> comision;
                cin.ignore();
                cuentaCliente = new CuentaCorriente(saldoInicial, numeroCuenta, comision);
            }
            else if (tipoCuenta == 2) {
                cuentaCliente = new CuentaAhorro(saldoInicial, numeroCuenta);
            }
            else {
                cout << "Tipo de cuenta inválido. No se puede procesar la compra.\n";
                break;
            }

            mostrarInventarioCompleto(coches, motos);
            procesarCompra(carrito, *cuentaCliente, coches, motos);

            delete cuentaCliente;
            cuentaCliente = nullptr;

            break;
        }
        case 4: { // Gestión de Clientes
            int opcionCliente;
            do {
                opcionCliente = mostrarSubMenuClientes();
                switch (opcionCliente) {
                case 1: {
                    std::string nombre, genero, numeroCuenta;
                    int edad;
                    double saldoInicial;

                    std::cout << "Ingrese el nombre del cliente: ";
                    std::getline(std::cin, nombre);
                    std::cout << "Ingrese la edad del cliente: ";
                    std::cin >> edad;
                    std::cin.ignore();
                    std::cout << "Ingrese el genero del cliente: ";
                    std::getline(std::cin, genero);
                    std::cout << "Ingrese el numero de cuenta bancaria: ";
                    std::getline(std::cin, numeroCuenta);
                    std::cout << "Ingrese el saldo inicial: ";
                    std::cin >> saldoInicial;
                    std::cin.ignore();

                    CuentaBancaria cuenta(saldoInicial, numeroCuenta);
                    Cliente nuevoCliente(nombre, edad, genero, cuenta);
                    clientes.push_back(nuevoCliente);
                    break;
                }
                case 2: {
                    std::cout << "\nLista de Clientes:\n";
                    for (const auto& cliente : clientes) {
                        cliente.mostrarInfoCliente();
                        std::cout << "-----------------\n";
                    }
                    break;
                }
                case 3:
                    break; // Volver al menú principal
                default:
                    std::cout << "Opcion no valida. Intente nuevamente.\n";
                    break;
                }
            } while (opcionCliente != 3);
            break;
        }
        case 5:
            break; // Salir
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
            break;
        }
    } while (opcionPrincipal != 5);

    return 0;
}
