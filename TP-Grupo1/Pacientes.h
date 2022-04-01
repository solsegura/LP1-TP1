#pragma once
#include<iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdio.h>


enum resultado_testeo { negativo , positivo, sinresultado };
using namespace std;

class cPaciente
{

private:

    string dni;
    string telefono;
    string nombre;
    string apellido;
    bool fiebre;
    bool tos;
    bool mocos;
    bool cctoestrecho;
    bool dolor_de_cabeza;
    bool dolor_de_garganta;
    resultado_testeo resul;


public:
    cPaciente(string name, string surname, string phone, string DNI, bool fever, bool snot,
    bool contact, bool head_pain, bool throat_pain);

    ~cPaciente();


    string gettelefono();   //getter de telefono del paciente, lo usamos en Laboratorios.cpp en el metodo AvisarPaciente
    string getnombre();     //getter del nombre del paciente, lo usamos en Laboratorios.cpp y Centro de Testeos.cpp
    string getapellido();   //idem 
    bool getfiebre();    //todos los getters de sintomas los usamos en AnalizarMuestra en Laboratorios.cpp
    bool gettos();
    bool getmocos();
    bool getcctoestrecho();
    bool getdolor_de_cabeza();
    bool getdolor_de_garganta();
    resultado_testeo getResultadoTesteo();  
    void setresultado_testeo(resultado_testeo res);

    //funciones que usaremos para imprimir en pantalla los atributos
    string to_stringPaciente();
    void ImprimirEnPantalla();
};