#include "BloodDatabase.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;

// Mostrar las opciones de los departamentos
void BloodDatabase::displayProvinces() {
    cout << "Elige el departamento:\n";
    cout << "1. Putumayo\n";
    cout << "2. Cauca\n";
    cout << "3. Valle del Cauca\n";
    cout << "4. Amazonas\n";
    cout << "5. Risaralda\n";
    cout << "6. Antioquia\n";
    cout << "7. Norte de Santander\n";
}

// Limpiar la consola (para diferentes sistemas operativos)
void BloodDatabase::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Esperar que el usuario presione una tecla para continuar
void BloodDatabase::waitForKeyPress() {
    cout << "Presiona cualquier tecla para continuar...";
    cin.ignore();
    cin.get();
}

// Validar la entrada de datos numéricos
int BloodDatabase::getValidatedInput(const string& prompt) {
    int value;
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            if (!all_of(input.begin(), input.end(), ::isdigit)) {
                throw invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = stoi(input);
            break;
        } catch (const invalid_argument& e) {
            cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << endl;
        } catch (const out_of_range&) {
            cout << "Entrada fuera de rango. Por favor ingrese un número válido." << endl;
        }
    }
    return value;
}

// Obtener los detalles de un nuevo donante
void BloodDatabase::getDonorDetails() {
    clearConsole();
    cout << "Ingrese los detalles del donante\n";

    Donor newDonor;
    newDonor.donorId = getValidatedInput("Id: ");
    
    cout << "Nombre: ";
    string name;
    getline(cin, name);
    if (!Donor::validateName(name)) {
        cout << "Nombre inválido. Solo se permiten letras y espacios.\n";
        return;
    }
    newDonor.name = name;

    cout << "Dirección: ";
    getline(cin, newDonor.address);

    displayProvinces();
    newDonor.district = getValidatedInput("Departamento (ingrese el número correspondiente): ");

    cout << "Tipo de sangre: ";
    string bloodType;
    getline(cin, bloodType);
    if (!Donor::validateBloodType(bloodType)) {
        cout << "Tipo de sangre inválido. Ingrese un tipo válido (A+, B-, etc.).\n";
        return;
    }
    newDonor.bloodType = bloodType;

    cout << "Número: ";
    int phone;
    cin >> phone;
    cin.ignore(); // Limpiar el buffer
    if (!Donor::validatePhoneNumber(phone)) {
        cout << "Número inválido. Debe tener exactamente 10 dígitos.\n";
        return;
    }
    newDonor.number = phone;

    donors.push_back(newDonor);
}

// Guardar los datos de los donantes en el archivo
void BloodDatabase::writeDataToFile() {
    ofstream outfile(fileName, ios::app);

    if (!outfile) {
        cout << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    Donor newDonor = donors.back();
    outfile << newDonor.donorId << ",    " << newDonor.name << ",    " << newDonor.address << ",    " << newDonor.district << ",    " << newDonor.bloodType << ",    " << newDonor.number << endl;

    outfile.close();
}

// Mostrar todos los donantes registrados
void BloodDatabase::showAllDonors() const {
    clearConsole();
    if (donors.empty()) {
        cout << "No hay donantes registrados.\n";
    } else {
        cout << "Donantes registrados:\n";
        for (const auto& donor : donors) {
            cout << "Nombre: " << donor.name << "\n";
            cout << "Dirección: " << donor.address << "\n";
            cout << "Departamento: " << donor.district << "\n";
            cout << "Tipo de sangre: " << donor.bloodType << "\n";
            cout << "Número: " << donor.number << "\n\n";
        }
    }
    waitForKeyPress();
}

// Buscar y mostrar los donantes según el nombre
void BloodDatabase::searchAndDisplay() const {
    clearConsole();
    string name;
    cout << "Ingrese el nombre del donante a buscar: ";
    getline(cin, name);

    bool found = false;
    for (const auto& donor : donors) {
        if (donor.name == name) {
            cout << "Donante encontrado:\n";
            cout << "Nombre: " << donor.name << "\n";
            cout << "Dirección: " << donor.address << "\n";
            cout << "Departamento: " << donor.district << "\n";
            cout << "Tipo de sangre: " << donor.bloodType << "\n";
            cout << "Número: " << donor.number << "\n\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Donante no encontrado.\n";
    }

    waitForKeyPress();
}

// Eliminar un donante de la lista
void BloodDatabase::deleteDonor(const string& donorName) {
    auto it = remove_if(donors.begin(), donors.end(), [&donorName](const Donor& donor) {
        return donor.name == donorName;
    });

    if (it != donors.end()) {
        donors.erase(it, donors.end());
        cout << "Donante eliminado con éxito.\n";
    } else {
        cout << "Donante no encontrado.\n";
    }
}

// Mostrar el menú principal en consola
int main() {
    string donorName;
    BloodDatabase database;
    int choice;

    while (true) {
        BloodDatabase::clearConsole();

        cout << " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        cout << "1. Registrar donante\n";
        cout << "2. Buscar donante\n";
        cout << "3. Eliminar donante\n";
        cout << "4. Ver todos los donantes\n";  // Nueva opción
        cout << "5. Salir\n";
        cout << "Ingrese su elección: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        switch (choice) {
            case 1:
                database.getDonorDetails();
                database.writeDataToFile();
                break;
            case 2:
                database.searchAndDisplay();
                break;
            case 3:
                cout << "Ingrese el nombre del donante a eliminar: ";
                getline(cin, donorName);
                database.deleteDonor(donorName);
                BloodDatabase::waitForKeyPress();
                break;
            case 4:
                database.showAllDonors(); // Llamada a la nueva opción
                break;
            case 5:
                cout << "Gracias por usar el Sistema de la Cruz Roja" << endl;
                return 0;
            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
                BloodDatabase::waitForKeyPress();
                break;
        }
    }

    return 0;
}

// Método para esperar a que el usuario presione una tecla antes de continuar
void BloodDatabase::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.get(); // Espera por la entrada de una tecla
}
