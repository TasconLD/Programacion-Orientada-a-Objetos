//ARCHIVO BOMBILLO.H

/*
Autor: Laura Dayana Tascon
Codigo: 2438545
Fecha: 24/02/2025
*/


using namespace std;

#ifndef BOMBILLO_H
#define BOMBILLO_H
#include <string>

// Atributos privados, funciones públicas

class Bombillo
{
    private:
        string estado;

    protected:

    public:
        void encender();
        void apagar();
        string verEstado();

        Bombillo(); // Método constructor
        virtual ~Bombillo(); // Método destructor
};

#endif // BOMBILLO_H

//_______________________________________

//ARCHIVO BOMBILLO.CPP

#include "Bombillo.h"
#include <iostream> // Agregado para buenas prácticas

Bombillo::Bombillo()
{
    estado = "Apagado";
}

void Bombillo::encender() // Agregado 'void' y 'Bombillo::'
{
    estado = "Encendido";
}

void Bombillo::apagar() // Agregado 'void' y 'Bombillo::'
{
    estado = "Apagado";
}

string Bombillo::verEstado()
{
    return estado;
}

Bombillo::~Bombillo()
{
    // Destructor
}

//_______________________

//ARCHIVO MAIN

#include <iostream>
#include "Bombillo.h"
using namespace std;

int main()
{
    Bombillo miBombillo;
    cout << "Estado actual: " << miBombillo.verEstado() << endl;

    miBombillo.encender();
    cout << "Estado actual: " << miBombillo.verEstado() << endl;

    miBombillo.apagar();
    cout << "Estado actual: " << miBombillo.verEstado() << endl;

    return 0;
}
