#include "pacientes.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
/// <summary>
/// Constructor de la clase Paciente
/// </summary>
/// <param name="name"></param>
/// <param name="surname"></param>
/// <param name="fever"></param>
/// <param name="snot"></param>
/// <param name="contact"></param>
/// <param name="head_pain"></param>
/// <param name="throat_pain"></param>
/// <param name=""></param>
cPaciente::cPaciente(string name, string surname, bool fever, bool snot, bool contact, bool head_pain, bool throat_pain, enum result == sinresultado) {

    this->nombre = name;
    this->apellido = surname;
    this->fiebre = fever;
    this->mocos = snot;
    this->cctoestrecho = contact;
    this->dolor_de_cabeza = head_pain;
    this->dolor_de_garganta = throat_pain;
    this->resultado_testeo = result;


}

/// <summary>
/// Destructor de la clase paciente
/// </summary>
cPaciente::~cPaciente() {}


/// <summary>
/// Recibe el resultado del test y lo asigna al atributo resultado_testeo
/// </summary>
/// <param name=""></param>
cPaciente:: setresultado_testo(resul) {
    this->resultado_testeo = resul;
}

/// <summary>
/// Devuelve el DNI del paciente
/// </summary>
cPaciente:: getdni() {
    return this -> dni;
};

/// <summary>
/// Devuelve el telefono del paciente
/// </summary>
cPaciente:: gettelefono() {
    return this->telefono;
};

/// <summary>
/// Devuelve el nombre del paciente
/// </summary>
cPaciente:: getnombre() {
    return this->nombre;
}

/// <summary>
/// Devuelve el apellido del paciente
/// </summary>
cPaciente:: getapellido() { 
    return this->apellido;
}

/// <summary>
/// Devuelve true si el paciente tiene fiebre
/// </summary>
cPaciente:: getfiebre() { 
    return this->fiebre; 
}

/// <summary>
/// Devuelve true si el paciente tiene tos
/// </summary>
cPaciente:: gettos() { 
    return tos;
}

/// <summary>
/// Devuelve true si el paciente tiene mocos
/// </summary>
cPaciente:: getmocos() { 
    return mocos; 
}

/// <summary>
/// Devuelve true si el paciente es contacto estrecho
/// </summary>
cPaciente:: getcctoestrecho() { 
    return cctoestrecho; 


}

/// <summary>
/// Devuelve true si el paciente tiene dolor de cabeza
/// </summary>
cPaciente:: getdolor_de_cabeza() { 
    return dolor_de_cabeza; 
}

/// <summary>
/// Devuelve true si el paciente tiene dolor de garganta
/// </summary>
cPaciente:: getdolor_de_garganta() { 
    return dolor_de_garganta; 
}