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

//atributos privados, funciones publicos

class Bombillo
{

    private:
        string estado;

    protected:

    public:
        void encender ();
        void apagar ();
        string verEstado();

        Bombillo(); //Metodo constructor
        virtual ~Bombillo(); // Metodo destructor



};

#endif // BOMBILLO_H

//_______________________________________

//ARCHIVO BOMBILLO.CPP

#include "Bombillo.h"

Bombillo::Bombillo()
{
    estado = "Apagado";
}

Bombillo::encender()
{
    estado = "Encendido";

}

Bombillo::apagar()
{
    estado = "Apagado";
}

string Bombillo::verEstado()
{
    return estado;
}

Bombillo::~Bombillo()
{
    //dtor
}
