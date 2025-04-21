    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Daniel Escobar Escobar - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura -  2439620
    Fecha: Abril 2025
    */

#include "donante.h"
#include <regex>

Donante::Donante() : cedula(""), nombre(""), direccion(""), tipoSangre(Sangre()), telefono("") {
}

Donante::Donante(const std::string& cedula, const std::string& nombre,
                 const std::string& direccion, const Sangre& tipoSangre,
                 const std::string& telefono)
    : cedula(cedula), nombre(nombre), direccion(direccion), tipoSangre(tipoSangre), telefono(telefono) {
}

std::string Donante::getCedula() const {
    return cedula;
}

void Donante::setCedula(const std::string& cedula) {
    this->cedula = cedula;
}

std::string Donante::getNombre() const {
    return nombre;
}

void Donante::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

std::string Donante::getDireccion() const {
    return direccion;
}

void Donante::setDireccion(const std::string& direccion) {
    this->direccion = direccion;
}

Sangre Donante::getTipoSangre() const {
    return tipoSangre;
}

void Donante::setTipoSangre(const Sangre& tipoSangre) {
    this->tipoSangre = tipoSangre;
}

std::string Donante::getTelefono() const {
    return telefono;
}

void Donante::setTelefono(const std::string& telefono) {
    this->telefono = telefono;
}

bool Donante::validarCedula(const std::string& cedula) {
    // Valida que la cédula tenga entre 6 y 15 dígitos
    std::regex cedulaRegex("^[0-9]{6,15}$");
    return std::regex_match(cedula, cedulaRegex);
}

bool Donante::validarNombre(const std::string& nombre) {
    // Valida que el nombre tenga letras, espacios y al menos 3 caracteres
    std::regex nombreRegex("^[A-Za-zÁáÉéÍíÓóÚúÑñ ]{3,50}$");
    return std::regex_match(nombre, nombreRegex);
}

bool Donante::validarDireccion(const std::string& direccion) {
    // Valida que la dirección tenga al menos 5 caracteres
    std::regex direccionRegex("^[A-Za-z0-9ÁáÉéÍíÓóÚúÑñ .,#-]{5,100}$");
    return std::regex_match(direccion, direccionRegex);
}

bool Donante::validarTelefono(const std::string& telefono) {
    // Valida que el teléfono tenga el formato correcto (números y guiones opcionales)
    std::regex telefonoRegex("^[0-9]{3}[-]?[0-9]{3}[-]?[0-9]{4}$");
    return std::regex_match(telefono, telefonoRegex);
}

