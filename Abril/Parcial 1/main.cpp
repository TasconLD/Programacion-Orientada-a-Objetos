#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <limits>
#include "Vehiculo.h"
#include "Auto.h"
using namespace std;

// Funciones del menu principal
void mostrarMenu();
void registrarVehiculo(vector<Vehiculo>& vehiculos);
void buscarVehiculo(const vector<Vehiculo>& vehiculos);
void eliminarVehiculo(vector<Vehiculo>& vehiculos);
void mostrarvehiculo(const vector<Vehiculo>& vehiculos);
void mostrarEstadisticas(const vector<Vehiculo>& vehiculos);
void limpiarPantalla();
void pausar();

int main() {
    vector<Vehiculo> vehiculos;
    int opcion;

    do {
        limpiarPantalla();
        mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese otra vez." << endl;
            pausar();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                registrarVehiculo(vehiculos);
                break;
            case 2:
                buscarVehiculo(vehiculo);
                break;
            case 3:
                eliminarVehiculo(vehiculos);
                break;
            case 4:
                mostrarVehiculos(vehiculos);
                break;
            case 5:
                mostrarEstadisticas(vehiculos);
                break;
            case 6:
                cout << "Gracias por utilizar el sistema de parqueadero del Centro Comercial Gran Estacion" << endl;
                break;
            default:
                cout << "Opcion inválida. Por favor, ingrese de nuevo." << endl;
                pausar();
        }
    } while (opcion != 6);

    return 0;
}

void mostrarMenu() {
    cout << "===== SISTEMA DE GESTION DE VEHICULOS EN PARQUEADERO =====" << endl;
    cout << "1. Registrar vehiculo" << endl;
    cout << "2. Buscar vehiculo" << endl;
    cout << "3. Eliminar vehiculo" << endl;
    cout << "4. Mostrar registro completo de vehiculos" << endl;
    cout << "5. Mostrar estadisticas por tipo de vehiculo" << endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese su opcion (1-6): ";
}

void registrarVehiculo(vector<vehiculo>& vehiculos) {
    limpiarPantalla();
    cout << "===== REGISTRAR NUEVO VEHICULO =====" << endl;

    string tipoAuto, placa, marca, color, hora;
    bool datoValido;

    // Validar placa
    do {
        cout << "Ingrese la placa (solo numeros y letras en mayuscula): ";
        getline(cin, placa);

        datoValido = Vehiculo::validarPlaca(placa);

        // Verificar si la placa existe
        if (datoValido) {
            auto it = find_if(vehiculos.begin(), vehiculos.end(),
                [&placa](const Vehiculo& d) { return d.getPlaca() == placa; });

            if (it != vehiculos.end()) {
                cout << "¡Error! Esta placa ya esta registrada en el sistema." << endl;
                datoValido = false;
            }
        } else {
            cout << "¡Error! Formato de placa invalido." << endl;
        }
    } while (!datoValido);

    // Validar marca
    do {
        cout << "Ingrese el nombre de la marca: ";
        getline(cin, marca);

        datoValido = Vehiculo::validarMarca(marca);
        if (!datoValido) {
            cout << "¡Error! Marca invalido. Debe contener solo letras y espacios." << endl;
        }
    } while (!datoValido);

    // Validar color
    do {
        cout << "Ingrese el color: ";
        getline(cin, color);

        datoValido = Vehiculo::validarColor(color);
        if (!datoValido) {
            cout << "¡Error! Color invalido. Ingrese otra vez." << endl;
        }
    } while (!datoValido);

    // Validar tipo de auto
    do {
        cout << "Ingrese el tipo de auto (Toyota, Mercedez-Benz, BMW, Audi, Ford): ";
        getline(cin, tipoAuto);

        datoValido = Auto::esValido(tipoAuto);
        if (!datoValido) {
            cout << "¡Error! Tipo de auto invalido." << endl;
        }
    } while (!datoValido);

    // Validar hora
    do {
        cout << "Ingrese la hora (desde 00 hasta 24): ";
        getline(cin, hora);

        datoValido = Vehiculo::validarHora(hora);
        if (!datoValido) {
            cout << "¡Error! Formato de hora invalido." << endl;
        }
    } while (!datoValido);

    // Crear y guardar el vehiculo
    Vehiculo nuevoVehiculo(Auto(tipoAuto), placa, marca, color, hora);
    vehiculos.push_back(nuevovehiculo);

    cout << "\n¡Vehiculo registrado exitosamente!" << endl;
    pausar();
}

void buscarVehiculo(const vector<Vehiculo>& vehiculos) {
    limpiarPantalla();
    cout << "===== BUSCAR VEHICULO =====" << endl;

    if (vehiculos.empty()) {
        cout << "No hay vehiculos registrados en el sistema." << endl;
        pausar();
        return;
    }

    string placa;
    cout << "Ingrese la placa del vehiculo a buscar: ";
    getline(cin, placa);

    auto it = find_if(vehiculos.begin(), vehiculos.end(),
        [&placa](const Vehiculo& d) { return d.getPlaca() == placa; });

    if (it != vehiculos.end()) {
        cout << "\nVehiculo encontrado:" << endl;
        cout << "Placa: " << it->getPlaca() << endl;
        cout << "Marca: " << it->getMarca() << endl;
        cout << "Color: " << it->getColor() << endl;
        cout << "Tipo de auto: " << it->getTipoAuto().getTipo() << endl;
        cout << "Hora: " << it->getHora() << endl;
    } else {
        cout << "\nNo se encontro ningun vehiculo con la placa " << cedula << endl;
    }

    pausar();
}

void eliminarVehiculo(vector<Vehiculo>& vehiculos) {
    limpiarPantalla();
    cout << "===== ELIMINAR VEHICULO =====" << endl;

    if (vehiculos.empty()) {
        cout << "No hay vehiculos registrados en el sistema." << endl;
        pausar();
        return;
    }

    string placa;
    cout << "Ingrese la placa del vehiculo a eliminar: ";
    getline(cin, placa);

    auto it = find_if(vehiculos.begin(), vehiculos.end(),
        [&placa](const Vehiculo d) { return d.getPlaca() == placa; });

    if (it != vehiculos.end(){
        cout << "\nVehiculo encontrado:" << endl;
        cout << "Placa: " << it->getPlaca() << endl;
        cout << "Marca: " << it->getMarca() << endl;
        cout << "Tipo de vehiculo:  " << it->getTipoAuto().getTipo() << endl;

        char confirmacion;
        cout << "\n¿Esta seguro que desea eliminar este vehiculo? (S/N): ";
        cin >> confirmacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirmacion == 'S' || confirmacion == 's') {
            donantes.erase(it);
            cout << "\nVehiculo eliminado exitosamente." << endl;
        } else {
            cout << "\nOperación cancelada." << endl;
        }
    } else {
        cout << "\nNo se encontro ningun vehiculo con la placa " << placa << endl;
    }

    pausar();
}

void mostrarVehiculos(const vector<Vehiculo>& vehiculos) {
    limpiarPantalla();
    cout << "===== REGISTRO COMPLETO DE VEHICULOS =====" << endl;

    if (vehiculos.empty()) {
        cout << "No hay vehiculos registrados en el sistema." << endl;
        pausar();
        return;
    }

    cout << left << setw(15) << "PLACA"
              << setw(30) << "MARCA"
              << setw(10) << "TIPO AUTO"
              << setw(15) << "COLOR"
              << "HORA" << endl;

    cout << string(80, '-') << endl;

    for (const auto& vehiculo : vehiculos) {
        cout << left << setw(15) << vehiculo.getPlaca()
                  << setw(30) << vehiculo.getMarca()
                  << setw(10) << vehiculo.getTipoAuto().getTipo()
                  << setw(15) << vehiculo.getColor()
                  << vehiculo.getHora() << endl;
    }

    cout << "\nTotal de vehiculos: " << vehiculos.size() << endl;

    pausar();
}

void mostrarEstadisticas(const vector<Donante>& donantes) {
    limpiarPantalla();
    cout << "===== ESTADISTICAS POR TIPO DE VEHICULOS =====" << endl;

    if (vehiculos.empty()) {
        cout << "No hay vehiculos registrados en el sistema." << endl;
        pausar();
        return;
    }

    // Inicializar contador para cada tipo de vehiculo
    map<string, int> contadorTipoAuto;
    for (const auto& tipo : Auto::getTiposValidos()) {
        contadorTipoAuto[tipo] = 0;
    }

    // Contar vehiculos por tipo de auto
    for (const auto& vehiculo : vehiculos) {
        contadorTipoAuto[vehiculo.getTipoAuto().getTipo()]++;
    }

    // Mostrar las estadísticas
    cout << left << setw(10) << "TIPO"
              << setw(15) << "CANTIDAD"
              << setw(10) << "PORCENTAJE" << endl;

    cout << string(35, '-') << endl;

    for (const auto& tipo : Auto::getTiposValidos()) {
        int cantidad = contadorTipoAuto[tipo];
        double porcentaje = vehiculos.empty() ? 0 : (static_cast<double>(cantidad) / donantes.size()) * 100;

        cout << left << setw(10) << tipo
                  << setw(15) << cantidad
                  << fixed << setprecision(2) << porcentaje << "%" << endl;
    }

    cout << "\nTotal de vehiculos: " << vehiculos.size() << endl;

    pausar();
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}
