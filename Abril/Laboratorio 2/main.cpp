    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Daniel Escobar Escobar - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura -  2439620
    Fecha: Abril 2025
    */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <limits>
#include "donante.h"
#include "sangre.h"

// Funciones del menu principal
void mostrarMenu();
void registrarDonante(std::vector<Donante>& donantes);
void buscarDonante(const std::vector<Donante>& donantes);
void eliminarDonante(std::vector<Donante>& donantes);
void mostrarDonantes(const std::vector<Donante>& donantes);
void mostrarEstadisticas(const std::vector<Donante>& donantes);
void limpiarPantalla();
void pausar();

int main() {
    std::vector<Donante> donantes;
    int opcion;

    do {
        limpiarPantalla();
        mostrarMenu();

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, ingrese un número del 1 al 6." << std::endl;
            pausar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                registrarDonante(donantes);
                break;
            case 2:
                buscarDonante(donantes);
                break;
            case 3:
                eliminarDonante(donantes);
                break;
            case 4:
                mostrarDonantes(donantes);
                break;
            case 5:
                mostrarEstadisticas(donantes);
                break;
            case 6:
                std::cout << "Gracias por utilizar el sistema de gestión de donantes de sangre." << std::endl;
                break;
            default:
                std::cout << "Opcion inválida. Por favor, ingrese un número del 1 al 6." << std::endl;
                pausar();
        }
    } while (opcion != 6);

    return 0;
}

void mostrarMenu() {
    std::cout << "===== SISTEMA DE GESTION DE DONANTES DE SANGRE =====" << std::endl;
    std::cout << "1. Registrar donante" << std::endl;
    std::cout << "2. Buscar donante" << std::endl;
    std::cout << "3. Eliminar donante" << std::endl;
    std::cout << "4. Mostrar registro completo de donantes" << std::endl;
    std::cout << "5. Mostrar estadisticas por tipo de sangre" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Ingrese su opcion (1-6): ";
}

void registrarDonante(std::vector<Donante>& donantes) {
    limpiarPantalla();
    std::cout << "===== REGISTRAR NUEVO DONANTE =====" << std::endl;

    std::string cedula, nombre, direccion, tipoSangre, telefono;
    bool datoValido;

    // Validar cédula
    do {
        std::cout << "Ingrese la cedula (solo numeros de 6-15 dígitos): ";
        std::getline(std::cin, cedula);

        datoValido = Donante::validarCedula(cedula);

        // Verificar si la cédula ya existe
        if (datoValido) {
            auto it = std::find_if(donantes.begin(), donantes.end(),
                [&cedula](const Donante& d) { return d.getCedula() == cedula; });

            if (it != donantes.end()) {
                std::cout << "¡Error! Esta cédula ya esta registrada en el sistema." << std::endl;
                datoValido = false;
            }
        } else {
            std::cout << "¡Error! Formato de cedula invalido." << std::endl;
        }
    } while (!datoValido);

    // Validar nombre
    do {
        std::cout << "Ingrese el nombre completo: ";
        std::getline(std::cin, nombre);

        datoValido = Donante::validarNombre(nombre);
        if (!datoValido) {
            std::cout << "¡Error! Nombre invalido. Debe contener solo letras y espacios (mínimo 3 caracteres)." << std::endl;
        }
    } while (!datoValido);

    // Validar dirección
    do {
        std::cout << "Ingrese la direccion: ";
        std::getline(std::cin, direccion);

        datoValido = Donante::validarDireccion(direccion);
        if (!datoValido) {
            std::cout << "¡Error! Direccion invalida. Debe tener al menos 5 caracteres." << std::endl;
        }
    } while (!datoValido);

    // Validar tipo de sangre
    do {
        std::cout << "Ingrese el tipo de sangre (A+, A-, B+, B-, AB+, AB-, O+, O-): ";
        std::getline(std::cin, tipoSangre);

        datoValido = Sangre::esValido(tipoSangre);
        if (!datoValido) {
            std::cout << "¡Error! Tipo de sangre invalido." << std::endl;
        }
    } while (!datoValido);

    // Validar teléfono
    do {
        std::cout << "Ingrese el número de telefono (formato: 123-456-7890 o 1234567890): ";
        std::getline(std::cin, telefono);

        datoValido = Donante::validarTelefono(telefono);
        if (!datoValido) {
            std::cout << "¡Error! Formato de telefono invalido." << std::endl;
        }
    } while (!datoValido);

    // Crear y guardar el donante
    Donante nuevoDonante(cedula, nombre, direccion, Sangre(tipoSangre), telefono);
    donantes.push_back(nuevoDonante);

    std::cout << "\n¡Donante registrado exitosamente!" << std::endl;
    pausar();
}

void buscarDonante(const std::vector<Donante>& donantes) {
    limpiarPantalla();
    std::cout << "===== BUSCAR DONANTE =====" << std::endl;

    if (donantes.empty()) {
        std::cout << "No hay donantes registrados en el sistema." << std::endl;
        pausar();
        return;
    }

    std::string cedula;
    std::cout << "Ingrese la cedula del donante a buscar: ";
    std::getline(std::cin, cedula);

    auto it = std::find_if(donantes.begin(), donantes.end(),
        [&cedula](const Donante& d) { return d.getCedula() == cedula; });

    if (it != donantes.end()) {
        std::cout << "\nDonante encontrado:" << std::endl;
        std::cout << "Cedula: " << it->getCedula() << std::endl;
        std::cout << "Nombre: " << it->getNombre() << std::endl;
        std::cout << "Dirección: " << it->getDireccion() << std::endl;
        std::cout << "Tipo de sangre: " << it->getTipoSangre().getTipo() << std::endl;
        std::cout << "Telefono: " << it->getTelefono() << std::endl;
    } else {
        std::cout << "\nNo se encontro ningun donante con la cedula " << cedula << std::endl;
    }

    pausar();
}

void eliminarDonante(std::vector<Donante>& donantes) {
    limpiarPantalla();
    std::cout << "===== ELIMINAR DONANTE =====" << std::endl;

    if (donantes.empty()) {
        std::cout << "No hay donantes registrados en el sistema." << std::endl;
        pausar();
        return;
    }

    std::string cedula;
    std::cout << "Ingrese la cedula del donante a eliminar: ";
    std::getline(std::cin, cedula);

    auto it = std::find_if(donantes.begin(), donantes.end(),
        [&cedula](const Donante& d) { return d.getCedula() == cedula; });

    if (it != donantes.end()) {
        std::cout << "\nDonante encontrado:" << std::endl;
        std::cout << "Cedula: " << it->getCedula() << std::endl;
        std::cout << "Nombre: " << it->getNombre() << std::endl;
        std::cout << "Tipo de sangre: " << it->getTipoSangre().getTipo() << std::endl;

        char confirmacion;
        std::cout << "\n¿Esta seguro que desea eliminar este donante? (S/N): ";
        std::cin >> confirmacion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (confirmacion == 'S' || confirmacion == 's') {
            donantes.erase(it);
            std::cout << "\nDonante eliminado exitosamente." << std::endl;
        } else {
            std::cout << "\nOperación cancelada." << std::endl;
        }
    } else {
        std::cout << "\nNo se encontro ningun donante con la cedula " << cedula << std::endl;
    }

    pausar();
}

void mostrarDonantes(const std::vector<Donante>& donantes) {
    limpiarPantalla();
    std::cout << "===== REGISTRO COMPLETO DE DONANTES =====" << std::endl;

    if (donantes.empty()) {
        std::cout << "No hay donantes registrados en el sistema." << std::endl;
        pausar();
        return;
    }

    std::cout << std::left << std::setw(15) << "CÉDULA"
              << std::setw(30) << "NOMBRE"
              << std::setw(10) << "SANGRE"
              << std::setw(15) << "TELÉFONO"
              << "DIRECCIÓN" << std::endl;

    std::cout << std::string(80, '-') << std::endl;

    for (const auto& donante : donantes) {
        std::cout << std::left << std::setw(15) << donante.getCedula()
                  << std::setw(30) << donante.getNombre()
                  << std::setw(10) << donante.getTipoSangre().getTipo()
                  << std::setw(15) << donante.getTelefono()
                  << donante.getDireccion() << std::endl;
    }

    std::cout << "\nTotal de donantes: " << donantes.size() << std::endl;

    pausar();
}

void mostrarEstadisticas(const std::vector<Donante>& donantes) {
    limpiarPantalla();
    std::cout << "===== ESTADISTICAS POR TIPO DE SANGRE =====" << std::endl;

    if (donantes.empty()) {
        std::cout << "No hay donantes registrados en el sistema." << std::endl;
        pausar();
        return;
    }

    // Inicializar contador para cada tipo de sangre
    std::map<std::string, int> contadorTipoSangre;
    for (const auto& tipo : Sangre::getTiposValidos()) {
        contadorTipoSangre[tipo] = 0;
    }

    // Contar donantes por tipo de sangre
    for (const auto& donante : donantes) {
        contadorTipoSangre[donante.getTipoSangre().getTipo()]++;
    }

    // Mostrar las estadísticas
    std::cout << std::left << std::setw(10) << "TIPO"
              << std::setw(15) << "CANTIDAD"
              << std::setw(10) << "PORCENTAJE" << std::endl;

    std::cout << std::string(35, '-') << std::endl;

    for (const auto& tipo : Sangre::getTiposValidos()) {
        int cantidad = contadorTipoSangre[tipo];
        double porcentaje = donantes.empty() ? 0 : (static_cast<double>(cantidad) / donantes.size()) * 100;

        std::cout << std::left << std::setw(10) << tipo
                  << std::setw(15) << cantidad
                  << std::fixed << std::setprecision(2) << porcentaje << "%" << std::endl;
    }

    std::cout << "\nTotal de donantes: " << donantes.size() << std::endl;

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
    std::cout << "\nPresione Enter para continuar...";
    std::cin.get();
}
