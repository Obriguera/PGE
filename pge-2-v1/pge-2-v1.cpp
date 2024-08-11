#include <iostream>
#include <vector>
// Clases hijas de vehiculo
#include "coche.h"
#include "moto.h"
// Clases hijas de persona
#include "Empleado.h"
#include "Estudiante.h"
// Clase que usa a producto
#include "CarritoDeCompras.h"
#include "Producto.h"

using namespace std;

// Función para mostrar el menú y obtener la opción del usuario
int mostrarMenu() {
    int opcion;
    cout << "\n--- Menu ---\n";
    cout << "1. Cargar un coche\n";
    cout << "2. Cargar una moto\n";
    cout << "3. Mostrar todos los coches\n";
    cout << "4. Mostrar todas las motos\n";
    cout << "5. Cargar empleado\n";
    cout << "6. Mostrra lista de empleados\n";
    cout << "7. Cargar productos\n";
    cout << "8. mostrar carrito\n";
    cout << "9. mostrar productos del carrito\n";
    cout << "10. mostrar productos que se venden\n";
    cout << "11. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();  // Limpiar el buffer de entrada
    return opcion;
}
void cargarProducto(CarritoDeCompras& carrito) {
    string nombre;
    double precio;
    int cantidad;

    cout << "Ingrese los datos del producto:\n";
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Precio: ";
    cin >> precio;
    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore();  // Limpiar el buffer de entrada

    Producto nuevoProducto(nombre, precio, cantidad);
    if (carrito.agregarProducto(nuevoProducto)) {
        cout << "Producto agregado exitosamente al carrito.\n";
    }
    else {
        cout << "El carrito está lleno. No se pudo agregar el producto.\n";
    }
}
// Función para cargar un coche en el vector
void cargarCoche(vector<coche>& coches) {
    string marca, modelo;
    int anio, ruedas, npuertas;
    float capacidadCombustible;

    cout << "Ingrese los datos del coche:\n";
    cout << "Marca: ";
    getline(cin, marca);
    cout << "Modelo: ";
    getline(cin, modelo);
    cout << "Año: ";
    cin >> anio;
    cout << "Número de ruedas: ";
    cin >> ruedas;
    cout << "Capacidad de combustible (litros): ";
    cin >> capacidadCombustible;
    cout << "Número de puertas: ";
    cin >> npuertas;
    cin.ignore();  // Limpiar el buffer de entrada

    coche nuevoCoche(marca, modelo, anio, ruedas, capacidadCombustible, npuertas);
    coches.push_back(nuevoCoche);

    cout << "Coche agregado exitosamente!\n";
}
void cargarEmpleado(vector<Empleado>& empleados) {
    string nombre, genero, cargo;
    int edad;
    float salario;

    cout << "Ingrese los datos del empleado:\n";
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Edad: ";
    cin >> edad;
    cin.ignore(); // Limpiar el buffer de entrada
    cout << "Género: ";
    getline(cin, genero);
    cout << "Salario: ";
    cin >> salario;
    cin.ignore(); // Limpiar el buffer de entrada
    cout << "Cargo: ";
    getline(cin, cargo);

    Empleado nuevoEmpleado(nombre, edad, genero, salario, cargo);
    empleados.push_back(nuevoEmpleado);

    cout << "Empleado agregado exitosamente!\n";
}
// Función para cargar una moto en el vector
void cargarMoto(vector<moto>& motos) {
    string marca, modelo, tipoDeManillar;
    int anio, ruedas;
    float capacidadCombustible;

    cout << "Ingrese los datos de la moto:\n";
    cout << "Marca: ";
    getline(cin, marca);
    cout << "Modelo: ";
    getline(cin, modelo);
    cout << "Año: ";
    cin >> anio;
    cout << "Número de ruedas: ";
    cin >> ruedas;
    cout << "Capacidad de combustible (litros): ";
    cin >> capacidadCombustible;
    cin.ignore();  // Limpiar el buffer de entrada
    cout << "Tipo de manillar: ";
    getline(cin, tipoDeManillar);

    moto nuevaMoto(marca, modelo, anio, ruedas, capacidadCombustible, tipoDeManillar);
    motos.push_back(nuevaMoto);

    cout << "Moto agregada exitosamente!\n";
}

// Función para mostrar todos los coches en el vector
void mostrarCoches(const vector<coche>& coches) {
    cout << "\nLista de Coches:\n";
    for (const auto& coche : coches) {
        cout << "Marca: " << coche.getMarca() << ", Modelo: " << coche.getModelo()
            << ", Año: " << coche.getAnio() << ", Ruedas: " << coche.getRuedas()
            << ", Capacidad de Combustible: " << coche.getCapacidadDeCombustible()
            << ", Número de Puertas: " << coche.getnpuertas() << endl;
    }
}
void mostrarCarrito(const CarritoDeCompras& carrito) {
    cout << "\nContenido del carrito:\n";
    Producto productos[MAX_PRODUCTOS]; // Usa la constante global directamente
    int cantidad;

    carrito.obtenerProductos(productos, cantidad);

    if (cantidad == 0) {
        cout << "El carrito está vacío.\n";
        return;
    }

    for (int i = 0; i < cantidad; ++i) {
        cout << "Nombre: " << productos[i].getNombre()
            << ", Precio: " << productos[i].getPrecio()
            << ", Cantidad: " << productos[i].getCantidad()
            << ", Valor Total: " << productos[i].getValorTotal() << endl;
    }

    cout << "Total del carrito: " << carrito.calcularTotal() << endl;
}
// Función para mostrar todas las motos en el vector
void mostrarMotos(const vector<moto>& motos) {
    cout << "\nLista de Motos:\n";
    for (const auto& moto : motos) {
        cout << "Marca: " << moto.getMarca() << ", Modelo: " << moto.getModelo()
            << ", Año: " << moto.getAnio() << ", Ruedas: " << moto.getRuedas()
            << ", Capacidad de Combustible: " << moto.getCapacidadDeCombustible()
            << ", Tipo de Manillar: " << moto.getManillar() << endl;
    }
}
void mostrarEmpleados(const vector<Empleado>& empleados) {
    cout << "\nLista de Empleados:\n";
    for (const auto& empleado : empleados) {
        cout << "Nombre: " << empleado.getNombre() << ", Edad: " << empleado.getEdad()
            << ", Género: " << empleado.getGenero() << ", Salario: " << empleado.getSalario()
            << ", Cargo: " << empleado.getCargo() << endl;
    }
}
void mostrarProductos(const vector<Producto>& productos) {
    cout << "\nLista de productos:\n";
    if (productos.empty()) {
        cout << "No hay productos en el vector.\n";
        return;
    }

    for (const auto& producto : productos) {
        cout << "Nombre: " << producto.getNombre()
            << ", Precio: " << producto.getPrecio()
            << ", Cantidad: " << producto.getCantidad()
            << ", Valor Total: " << producto.getValorTotal() << endl;
    }
}
int main() {
    vector<coche> coches;  // Vector para almacenar coches
    vector<moto> motos;    // Vector para almacenar motos
    vector<Producto> productos;
    vector<Empleado> empleados;
    CarritoDeCompras carrito;
    productos.push_back(Producto("Producto A", 10.99, 3));
    productos.push_back(Producto("Producto B", 5.49, 10));
    productos.push_back(Producto("Producto C", 20.00, 2));
    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
        case 1:
            cargarCoche(coches);
            break;
        case 2:
            cargarMoto(motos);
            break;
        case 3:
            mostrarCoches(coches);
            break;
        case 4:
            mostrarMotos(motos);
            break;
        case 5:
            // Por ejemplo, opción para cargar empleados
            cargarEmpleado(empleados);
            break;
        case 6: // Opción para mostrar empleados
            mostrarEmpleados(empleados);
            break;
            // Otras opciones...
        case 7:
            cargarProducto(carrito);
            break;
        case 9:
            mostrarCarrito(carrito);
            break;
        case 10:
            mostrarProductos(productos);
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 11);

    return 0;
}