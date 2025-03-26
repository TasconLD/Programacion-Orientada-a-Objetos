/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Aerolínea Copa Airlines
Program: Pasajero.h
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>
using namespace std;

class Pasajero
{
    public:
        //contructor y destructor
        Pasajero(string nombre, string cedula, string tipo, int numeroSilla);
        virtual ~Pasajero();

        //sets
        void setNombre(string _nombre);
        void setCedula(string _cedula);
        void setTipo(string _tipo);
        void setNumeroSilla(int _numeroSilla);

        //gets
        string getNombre();
        string getCedula();
        string getTipo();
        int getNumeroSilla();

    protected:

    private:
        //Atributos
        string nombre;
        string cedula;
        string tipo;
        int numeroSilla;
};

#endif // PASAJERO_H
_______________________________________________

/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Aerolínea Copa Airlines
Program: Avion.h
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#ifndef AVION_H
#define AVION_H
#include <vector>
#include "Pasajero.h"

class Avion
{
    public:
        //constructor y destructor
        Avion(int numeroVuelo, int sillasTurista, int sillasEjecutivas);
        virtual ~Avion();

        //sets
        void setNumVuelo(int _numeroVuelo);
        void setSillasTurista(int _sillasTurista);
        void setSillasEjecutivas(int _sillasEjecutivas);

        //gets
        int getNumVuelo();
        int getSillasTurista();
        int getSillasEjecutivas();

        //pasajeros
         void insertarPasajero(string nombre, string cedula, string tipo);
         void mostrarPasajeros(string tipo);
         int obtenerSillaPorCedula(string cedula);

    protected:

    private:
        //Atributos
        int numeroVuelo;
        int sillasTurista;
        int sillasEjecutivas;
        vector <Pasajero> pasajeros;

};

#endif // AVION_H
___________________________________________________________________-


/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Aerolinea Copa Airlines
Program: Aerolinea.h
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <vector>
#include "Avion.h"

class Aerolinea
{
    public:
        //ctor y dtor
        Aerolinea();
        virtual ~Aerolinea();

        //admin. vuelos
        void crearVuelo(int numeroVuelo, int sillasTurista, int sillasEjecutivas);
        Avion& obtenerAvion(int numeroVuelo);

    protected:

    private:
        //Atributos
        vector <Avion> aviones;
};

#endif // AEROLINEA_H

__________________________________

PASAJERO CPP

/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Banco AV Villas
Program: Pasajero.cpp
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#include "Pasajero.h"
#include <string>
using namespace std;

Pasajero::Pasajero(string _nombre, string _cedula, string _tipo, int _numeroSilla)
{
    nombre = _nombre;
    cedula = _cedula;
    tipo = _tipo;
    numeroSilla = _numeroSilla;
}

void Pasajero::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Pasajero::setCedula(string _cedula)
{
    cedula = _cedula;
}
void Pasajero::setTipo(string _tipo)
{
    tipo = _tipo;
}
void Pasajero::setNumeroSilla(int _numeroSilla)
{
    numeroSilla = _numeroSilla;
}

string Pasajero::getNombre()
{
    return nombre;
}
string Pasajero::getCedula()
{
    return cedula;
}
string Pasajero::getTipo()
{
    return tipo;
}
int Pasajero::getNumeroSilla()
{
    return numeroSilla;
}

Pasajero::~Pasajero()
{
    //destructor
}
_______________________________________________-

AVION CPP

/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Aerolínea Copa Airlines
Program: Avion.cpp
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#include "Avion.h"
#include <iostream>
using namespace std;

Avion::Avion(int _numeroVuelo, int _sillasTurista, int _sillasEjecutivas)
{
    numeroVuelo  = _numeroVuelo;
    sillasTurista = _sillasTurista;
    sillasEjecutivas = _sillasEjecutivas;
}

void Avion::setNumVuelo(int _numeroVuelo)
{
    numeroVuelo  = _numeroVuelo;
}
void Avion::setSillasTurista(int _sillasTurista)
{
    sillasTurista  = _sillasTurista;
}
void Avion::setSillasEjecutivas(int _sillasEjecutivas)
{
    sillasEjecutivas  = _sillasEjecutivas;
}

int Avion::getNumVuelo()
{
    return numeroVuelo;
}
int Avion::getSillasTurista()
{
    return sillasTurista;
}
int Avion::getSillasEjecutivas()
{
    return sillasEjecutivas;
}

void Avion::insertarPasajero(string nombre, string cedula, string tipo)
{
    int numeroSilla = pasajeros.size() + 1;
    pasajeros.push_back(Pasajero(nombre, cedula, tipo, numeroSilla));
    cout << "Pasajero agregado exitosamente - Silla #" << numeroSilla << endl;
}
void Avion::mostrarPasajeros(string tipo)
{
    cout << "Pasajeros en clase " << tipo << ":\n";
    for (Pasajero pasajero : pasajeros){
        if (pasajero.getTipo() == tipo){
            cout << "Nombre: " << pasajero.getNombre() << " - Cedula: " << pasajero.getCedula() << " - Silla: #" << pasajero.getNumeroSilla() << endl;
        }
    }
}
int Avion::obtenerSillaPorCedula(string cedula)
{
    for (Pasajero pasajero : pasajeros){
        if (pasajero.getCedula() == cedula) {
            return pasajero.getNumeroSilla();
        }
    } return -1;
}

Avion::~Avion()
{
    //dtor
}

________________________________________-

AEROLINEA CPP

/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Aerolinea Copa Airlines
Program: Aerolinea.cpp
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#include "Aerolinea.h"

Aerolinea::Aerolinea()
{
    //ctor
}

void Aerolinea::crearVuelo(int numeroVuelo, int sillasTurista, int sillasEjecutivas) {
    aviones.push_back(Avion(numeroVuelo, sillasTurista, sillasEjecutivas));
}

Avion& Aerolinea::obtenerAvion(int numeroVuelo) {
    for (Avion& avion : aviones) {
        if (avion.getNumVuelo() == numeroVuelo) {
            return avion;
        }
    }
}

Aerolinea::~Aerolinea()
{
    //dtor
}

_______________________________________________

MAIN CPP

/*
Laboratorio #1
Clase: Fundamentos de programación orientada a objetos
Grupo: 80
Project: Aerolínea Copa Airlines
Program: main.cpp
Date: 13/03/2025
Integrantes:
 - Elbert Leandro Moreno - 2436884
 - Karen Dayana Hoyos    - 2417774
 - Laura Dayana Tascón   - 2438545
 - Jesús Giovanny Mora   - 2439620
*/

#include "Aerolinea.h"
#include <iostream>
using namespace std;

string almacenarDato(string message)
{
    string dato = "";
    cout << message;
    getline(cin, dato);
    return dato;
}

int main()
{
    Aerolinea aerolinea;

    int opcion;

    do {
        cout << "\n1. Crear vuelo" << endl;
        cout << "2. Insertar Pasajero" << endl;
        cout << "3. Mostrar Pasajeros por tipo de sillas" << endl;
        cout << "4. Consultar numero de silla por cedula" << endl;
        cout << "5. Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1){

            int numeroVuelo = stoi(almacenarDato("\nIngrese numero de vuelo: "));
            int sillasTurista = stoi(almacenarDato("Ingrese cantidad de sillas turista: "));
            int sillasEjecutivas = stoi(almacenarDato("Ingrese cantidad de sillas ejecutivas: "));
            aerolinea.crearVuelo(numeroVuelo, sillasTurista, sillasEjecutivas);
            cout << "Vuelo creado exitosamente.\n" << endl;
        }

        else if (opcion == 2){

            int numeroVuelo;
            cout << "\nIngrese numero de vuelo: "; cin >> numeroVuelo;
            cin.ignore();
            Avion& avion = aerolinea.obtenerAvion(numeroVuelo);
            string nombre = almacenarDato("Ingrese nombre: ");
            string cedula = almacenarDato("Ingrese cedula: ");
            string tipo = almacenarDato("Ingrese tipo de silla [ turista - ejecutivo ]: ");
            avion.insertarPasajero(nombre, cedula, tipo);
        }

        else if (opcion == 3){

            int numeroVuelo;
            string tipo;
            cout << "\nIngrese numero de vuelo: "; cin >> numeroVuelo;
            cin.ignore();
            Avion avion = aerolinea.obtenerAvion(numeroVuelo);
            cout << "Ingrese tipo de sillas a imprimir [ turista - ejecutivo ]: "; getline(cin, tipo);
            avion.mostrarPasajeros(tipo);
        }

        else if (opcion == 4){

            int numeroVuelo;
            cout << "\nIngrese numero de vuelo: "; cin >> numeroVuelo;
            cin.ignore();
            Avion avion = aerolinea.obtenerAvion(numeroVuelo);
            string cedula = almacenarDato("Ingrese cedula: ");
            int silla = avion.obtenerSillaPorCedula(cedula);
            if (silla != -1) {
                cout << "El numero de silla es: #" << silla << endl;
            } else {
                cout << "Pasajero no encontrado." << endl;
            }
        }
    } while (opcion != 5);

    return 0;
}








