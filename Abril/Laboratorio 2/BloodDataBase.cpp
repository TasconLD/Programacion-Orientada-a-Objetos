#include "BloodDatabase.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>      // Se añadió esta libreria para poder validar con expresiones regulares
#include <limits>
#include <cstdlib>

using namespace std;

// Constructor: al crear la base de datos, automáticamente se cargan los datos previos
BloodDatabase::BloodDatabase() {
    readDataFromFile();
}

// Método privado que lee los donantes desde el archivo y los almacena en el vector
void BloodDatabase::readDataFromFile() {
    donors.clear(); // Se limpia el vector antes de cargar
    ifstream file("donors.txt");

    if (file.is_open()) {
        string name, bloodType, id, phone, city;
        donors.clear();
        while (getline(file, name) && getline(file, bloodType) && getline(file, id) && getline(file, phone) && getline(file, city)) {

            donors.emplace_back(name, bloodType, id, phone, city);
        }
        file.close();
    }
}

// Método que guarda toda la lista de donantes en el archivo
void BloodDatabase::writeDataToFile() const {
    ofstream file("donors.txt");
    if (file.is_open()) {
        for (const auto& donor : donors) {
            file << donor.getName() << '\n' ;
            file << donor.getBloodType() << '\n';
            file << donor.getId() << '\n';
            file << donor.getPhone() << '\n';
            file << donor.getCity()<< '\n';
        }
        file.close();
    }
}

// Valida la entrada del usuario usando expresiones regulares
void BloodDatabase::validateInput(string& input, const string& pattern, const string& errorMessage) {
    regex regexPattern(pattern);
    while (!regex_match(input, regexPattern)) {
        cout << errorMessage << endl;
        getline(cin, input);
    }
}

// Solicita al usuario los datos del nuevo donante y valida cada campo
void BloodDatabase::getDonorDetails() {
    string name, bloodType, id, phone, city;

    cout << "Ingrese el nombre del donante: ";
    getline(cin, name);

    cout << "Ingrese el tipo de sangre (A, B, AB, O seguido de + o -): ";
    getline(cin, bloodType);
    validateInput(bloodType, "^(A|B|AB|O)[+-]$", "Tipo de sangre inválido. Ejemplo válido: A+");

    cout << "Ingrese la cédula del donante: ";
    getline(cin, id);
    validateInput(id, "^[0-9]{6,10}$", "Cédula inválida. Debe contener entre 6 y 10 dígitos.");

    cout << "Ingrese el teléfono del donante: ";
    getline(cin, phone);
    validateInput(phone, "^[0-9]{7,10}$", "Teléfono inválido. Debe contener entre 7 y 10 dígitos.");

    cout << "Ingrese la ciudad del donante: ";
    getline(cin, city);


    donors.emplace_back(name, bloodType, id, phone, city);
    cout << "Donante registrado exitosamente." << endl;
    waitForKeyPress();
}

// Busca un donante por nombre e imprime sus datos si existe
void BloodDatabase::searchAndDisplay() const {
    string name;
    cout << "Ingrese el nombre del donante a buscar: ";
    getline(cin, name);

    auto it = find_if(donors.begin(), donors.end(), [&](const Donor& d) {
        return d.getName() == name;
    });

    if (it != donors.end()) {
        cout << "Donante encontrado:\n";
        cout << "Nombre: " << it->getName() << endl;
        cout << "Tipo de sangre: " << it->getBloodType() << endl;
        cout << "Cédula: " << it->getId() << endl;
        cout << "Teléfono: " << it->getPhone() << endl;
        cout << "Ciudad: " << it->getCity() <<endl;
    } else {
        cout << "Donante no encontrado.\n";
    }

    waitForKeyPress();
}

// Elimina un donante por nombre si existe
void BloodDatabase::deleteDonor(const string& name) {
    auto it = remove_if(donors.begin(), donors.end(), [&](const Donor& d) {
        return d.getName() == name;
    });

    if (it != donors.end()) {
        donors.erase(it, donors.end());
        cout << "Donante eliminado exitosamente." << endl;
        writeDataToFile();
    } else {
        cout << "Donante no encontrado." << endl;
    }
}

// Muestra todos los donantes registrados en la consola
void BloodDatabase::displayAllDonors() const {
    if (donors.empty()) {
        cout << "No hay donantes registrados aún." << endl;
    } else {
        cout << "📋 Lista de donantes registrados:\n\n";
        for (const auto& d : donors) {
            cout << "Nombre: " << d.getName() << endl;
            cout << "Tipo de sangre: " << d.getBloodType() << endl;
            cout << "Cédula: " << d.getId() << endl;
            cout << "Teléfono: " << d.getPhone() << endl;
            cout << "Ciudad: " <<d.getCity() << "\n------------------------\n" <<endl;
        }
    }
    waitForKeyPress();
}

// Limpia la pantalla (truco multiplataforma básico)
void BloodDatabase::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa la pantalla hasta que el usuario presione Enter
void BloodDatabase::waitForKeyPress() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Pausa la pantalla hasta que el usuario presione Enter
void BloodDatabase::waitForKeyPress() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

