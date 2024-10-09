#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm> // Necesario para find_if
#include "usuario.h"
#include "reclamo.h"

using namespace std;

// Función para limpiar la consola
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    cout << "Presione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar cualquier entrada previa
    cin.get(); // Esperar a que el usuario presione Enter
}

//funcion auxiliar
void espTeclaVolver() {
    char tecla;
    do {
        cout << "Presione 'x' para volver al menu anterior: ";
        cin >> tecla;
    } while (tecla != 'x');
}

void opcionNoImplementada() {
    cout << "Funcion no implementada aun.\n";
    espTeclaVolver();
}

// Función de conversión para estado de reclamo
string convertirEstado(int estado) {
    return (estado == 1) ? "Sí" : "No";
}

// Función de callback que acepta un reclamo y ejecuta una acción sobre él
using ReclamoCallback = void(*)(const reclamo&);

void procesarReclamos(const vector<reclamo>& reclamos, ReclamoCallback callback) {
    for (const auto& rec : reclamos) {
        callback(rec); // Ejecuta la función callback sobre cada reclamo
    }
}

void cargarUsuariosDesdeArchivo(const string& nombreArchivo, vector<usuario>& usuarios) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        usuario usr;
        getline(ss, usr.apellido, ',');
        getline(ss, usr.nusuario, ',');
        getline(ss, usr.clave, ',');
        ss >> usr.dni;
        ss.ignore();
        getline(ss, usr.gmail, ',');
        getline(ss, usr.domicilio, ',');

        usuarios.push_back(usr);
    }

    archivo.close();
}

void guardarReclamoEnArchivo(const reclamo& rec) {
    ofstream archivo("reclamos.txt", ios::app);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de reclamos." << endl;
        return;
    }

    archivo << rec.nusuario << "," << rec.apellido << "," << rec.dni << "," << rec.gmail << "," << rec.domicilio << ","
        << rec.destinatario.nusuario << "," << rec.tipo << "," << rec.descripcion << "," << rec.fecha << ","
        << rec.codigo << "," << rec.anexado << "," << rec.recepcion << "," << rec.archivado << "," << rec.anulado << endl;

    archivo.close();
}

void cargarReclamosDesdeArchivo(const string& nombreArchivo, vector<reclamo>& reclamos, const vector<usuario>& usuarios) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de reclamos." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nusuario, apellido, gmail, domicilio, destinatarioUsuario, tipo, descripcion, fecha, codigo;
        int dni, anexado, recepcion, archivado, anulado;

        getline(ss, nusuario, ',');
        getline(ss, apellido, ',');
        ss >> dni;
        ss.ignore();
        getline(ss, gmail, ',');
        getline(ss, domicilio, ',');
        getline(ss, destinatarioUsuario, ',');
        getline(ss, tipo, ',');
        getline(ss, descripcion, ',');
        getline(ss, fecha, ',');
        getline(ss, codigo, ',');
        ss >> anexado >> recepcion >> archivado >> anulado;

        usuario creador;
        for (const auto& u : usuarios) {
            if (u.nusuario == nusuario) {
                creador = u;
                break;
            }
        }

        usuario destinatario;
        for (const auto& u : usuarios) {
            if (u.nusuario == destinatarioUsuario) {
                destinatario = u;
                break;
            }
        }

        reclamo rec(creador, tipo, descripcion, fecha, destinatario, codigo, anexado, recepcion, archivado, anulado);
        reclamos.push_back(rec);
    }

    archivo.close();
}

bool iniciosesion(const string& nomusuario, const string& clave, const vector<usuario>& usuarios) {
    for (const auto& u : usuarios) {
        if ((u.nusuario == nomusuario) && (u.clave == clave)) {
            return true;
        }
    }
    return false;
}

// Funciones de filtro
void mostrarReclamoCompleto(const reclamo& rec) {
    cout << "Usuario creador: " << rec.nusuario << endl;
    cout << "Apellido creador: " << rec.apellido << endl;
    cout << "DNI creador: " << rec.dni << endl;
    cout << "Correo creador: " << rec.gmail << endl;
    cout << "Domicilio creador: " << rec.domicilio << endl;
    cout << "Destinatario: " << rec.destinatario.nusuario << endl;
    cout << "Tipo: " << rec.tipo << endl;
    cout << "Descripción: " << rec.descripcion << endl;
    cout << "Fecha: " << rec.fecha << endl;
    cout << "Código: " << rec.codigo << endl;
    cout << "Anexado: " << (rec.anexado != 0 ? to_string(rec.anexado) : "No") << endl;
    cout << "Recepción: " << (rec.recepcion == 1 ? "Recibido" : "No recibido") << endl;
    cout << "Archivado: " << (rec.archivado == 1 ? "Sí" : "No") << endl;
    cout << "Anulado: " << (rec.anulado == 1 ? "Sí" : "No") << endl;
    cout << "--------------------------" << endl;
}
void filtrarPorCodigo(const vector<reclamo>& reclamos) {
    string codigo;
    cout << "Ingrese el código del reclamo: ";
    cin >> codigo;
    bool encontrado = false;

    for (const auto& rec : reclamos) {
        if (rec.codigo == codigo) {
            mostrarReclamoCompleto(rec);  // Mostrar todos los detalles del reclamo
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron reclamos con el código proporcionado." << endl;
    }
    pausar();
}

// Filtrar por usuario y mostrar todos los detalles del reclamo
void filtrarPorUsuario(const vector<reclamo>& reclamos) {
    string usuario;
    cout << "Ingrese el nombre de usuario para filtrar: ";
    cin >> usuario;
    bool encontrado = false;

    for (const auto& rec : reclamos) {
        if (rec.nusuario == usuario || rec.destinatario.nusuario == usuario) {
            mostrarReclamoCompleto(rec);  // Mostrar todos los detalles del reclamo
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron reclamos para el usuario proporcionado." << endl;
    }
    pausar();
}

// Filtrar reclamos no recibidos y mostrar todos los detalles
void filtrarNoRecibidos(const vector<reclamo>& reclamos) {
    bool encontrado = false;

    for (const auto& rec : reclamos) {
        if (rec.recepcion == 0) {  // Mostrar solo los no recibidos
            mostrarReclamoCompleto(rec);  // Mostrar todos los detalles del reclamo
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron reclamos no recibidos." << endl;

    }
    pausar();
}
void crearNuevoReclamo(vector<reclamo>& reclamos, const usuario& creador, const vector<usuario>& usuarios) {
    limpiarPantalla();
    cout << "--- Crear Nuevo Reclamo ---\n";

    // Pedir información del reclamo
    string tipo, descripcion, destinatarioUsuario, fecha;
    cout << "Tipo de reclamo: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, tipo);

    cout << "Descripción: ";
    getline(cin, descripcion);

    cout << "Fecha (dd/mm/aaaa): ";
    getline(cin, fecha);

    cout << "Destinatario (nombre de usuario): ";
    getline(cin, destinatarioUsuario);

    // Buscar el usuario destinatario
    usuario destinatario;
    bool encontrado = false;
    for (const auto& u : usuarios) {
        if (u.nusuario == destinatarioUsuario) {
            destinatario = u;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Destinatario no encontrado.\n";
        pausar();
        return;
    }

    // Generar un código aleatorio
    random_device rd;  // Generador de números aleatorios
    mt19937 gen(rd()); // Generador Mersenne Twister
    uniform_int_distribution<> dist(10000, 99999); // Genera un número entre 10000 y 99999
    string codigo = to_string(dist(gen)); // Convertir el número a string

    // Crear el nuevo reclamo
    reclamo nuevoReclamo(creador, tipo, descripcion, fecha, destinatario, codigo);

    // Guardar en el vector de reclamos
    reclamos.push_back(nuevoReclamo);

    // Guardar el reclamo en el archivo
    guardarReclamoEnArchivo(nuevoReclamo);

    cout << "Reclamo creado con código " << codigo << " y guardado correctamente.\n";
    pausar();
}

void mostrarMenuBusqueda() {
    limpiarPantalla();
    cout << "----- Menu de Busqueda -----" << endl;
    cout << "1. Mostrar todos los reclamos" << endl;
    cout << "2. Filtrar por código" << endl;
    cout << "3. Filtrar por usuario" << endl;
    cout << "4. Filtrar reclamos no recibidos" << endl;
    cout << "5. Volver al menu principal" << endl;
    cout << "Seleccione una opción: ";
}

// Ejecuta el filtro basado en la subopción ingresada
void ejecutarFiltro(int subopcion, const vector<reclamo>& reclamos) {
    switch (subopcion) {
        int selec;
    case 1:
        for (const auto& rec : reclamos) {
            mostrarReclamoCompleto(rec);  // Mostrar todos los reclamos completos

        }
        pausar();
        //espTeclaVolver();
        break;
    case 2:
        filtrarPorCodigo(reclamos);
        break;
    case 3:
        filtrarPorUsuario(reclamos);
        break;
    case 4:
        filtrarNoRecibidos(reclamos);
        break;
    default:
        cout << "Opción no válida. Inténtelo de nuevo." << endl;
        break;
    }
}

void menuTramitesMuyAvanzados() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "--- Opciones Avanzadas de Tramites ---\n";
        cout << "1. Reiniciar \n";
        cout << "2. Anular \n";
        cout << "3. Crear Documentacion al Tramite\n";
        cout << "4. Intervenir Tramite\n";
        cout << "5. Rehacer Tramite\n";
        cout << "6. Anexar Original\n";
        cout << "7. Cambiar Destino de Tramite Enviado\n";
        cout << "8. Reactivar Tramite Archivado\n";
        cout << "9. Solicitud de Desarchivo\n";
        cout << "10. Expurgo de Tramites\n";
        cout << "11. Extractin\n";
        cout << "12. Generar Copias de Notas\n";
        cout << "13. Resumen de No Conformidades\n";
        cout << "14. Nuevo Referente\n";
        cout << "0. Volver al menu anterior\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 2:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 3:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 4:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 5:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 6:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 7:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 8:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 9:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 10:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 11:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 12:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 13:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 14:
            limpiarPantalla();
            opcionNoImplementada();
            break;
            case 0:
                break;
            default:
                limpiarPantalla();
                cout << "Opcion no valida. Intentelo de nuevo.\n";
                pausar();
                break;
        }
    } while (opcion != 0);
}

void menuTramitesAvanzados() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "--- Mas Opciones de Tramites ---\n";
        cout << "1. Transferir\n";
        cout << "2. Devolver \n";
        cout << "3. Anexar \n";
        cout << "4. Encordar \n";
        cout << "5. Desencordar \n";
        cout << "6. Desglosar \n";
        cout << "7. Expediente Electrónico\n";
        cout << "8. Resumen de Movimientos\n";
        cout << "9. Aun mas opciones...\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:limpiarPantalla();
            opcionNoImplementada();
            break;
        case 2:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 3:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 4:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 5:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 6:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 7:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 8:
            limpiarPantalla();
            opcionNoImplementada();
            break;
        case 9:
            menuTramitesMuyAvanzados();
            break;
        case 0:
            break;
        default:
            limpiarPantalla();
            cout << "Opcion no valida. Intentelo de nuevo.\n";
            pausar();
            break;
        }
    } while (opcion != 0);
}

void menuPrincipal() {
    limpiarPantalla();
        cout << "--- Menu Principal SUAC ---\n";
        cout << "1. Buscar tramites\n";

        cout << "2. Nuevo Tramite\n";
        cout << "3. Recibir y Aceptar\n";
        cout << "4. Mas opciones...\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
}

int main() {
    vector<usuario> users;
    vector<reclamo> reclamos;
    usuario sesionctiva;
    string nombre, clave;
    bool loginexitoso = false;

    // Cargar usuarios y reclamos desde los archivos
    cargarUsuariosDesdeArchivo("usuarios.txt", users);
    cargarReclamosDesdeArchivo("reclamos.txt", reclamos, users);
    int opcion;

    do {
        cout << "Nombre de usuario: ";
        cin >> nombre;
        cout << "Clave: ";
        cin >> clave;

        if (iniciosesion(nombre, clave, users)) {
            loginexitoso = true;
            cout << "Inicio de sesion exitoso.\n";
            sesionctiva = *find_if(users.begin(), users.end(), [&](const usuario& u) { return u.nusuario == nombre; });
            pausar();
            limpiarPantalla();
           
            do {
                menuPrincipal();
                cin >> opcion;

                switch (opcion) {
                case 1:
                    int subopcion;
                    do {
                        mostrarMenuBusqueda();
                        cin >> subopcion;
                        ejecutarFiltro(subopcion, reclamos);
                    } while (subopcion!=5);
                    break;

                    break;
                case 2:
                    limpiarPantalla();
                    crearNuevoReclamo(reclamos, sesionctiva, users);
                    break;
                case 3:
                    limpiarPantalla();
                    opcionNoImplementada();
                    break;
                case 4:
                    menuTramitesAvanzados();
                    break;
                case 0:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    limpiarPantalla();
                    cout << "Opcion no valida. Intentelo de nuevo.\n";
                    pausar();
                    break;
                }
            } while (opcion != 0);

        }
        else {
            limpiarPantalla();
            cout << "Nombre de usuario o clave incorrectos. Intentelo de nuevo.\n";
        }
    } while (!loginexitoso);

    return 0;
}
