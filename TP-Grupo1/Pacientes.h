#pragma once
#include<iostream>
#include <string>
#include <stdio.h>
#include "CentroDeTesteo.h"
#include "Laboratorios.h"


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
    enum resultado_testeo { negativo = 0, positivo, sinresultado };


public:
    cPaciente(string name, string surname,string phone,string DNI, bool fever, bool snot, bool contact, bool head_pain, bool throat_pain, resultado_testeo result=sinresultado);

    ~cPaciente();

    string getdni();
    string gettelefono();
    string getnombre();
    string getapellido();
    bool getfiebre();
    bool gettos();
    bool getmocos(); 
    bool getcctoestrecho(); 
    bool getdolor_de_cabeza(); 
    bool getdolor_de_garganta();
    void setresultado_testeo(enum res);