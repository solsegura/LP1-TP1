#pragma once
#include<iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Pacientes.h"

using namespace std;

class cLaboratorio {
private:
	string IDlabo;
	string nombre;
	int comuna;
	cPaciente* paciente1;
	cPaciente* paciente2;
	bool completo;

public:
	cLaboratorio(string _IDlabo, string _nombre, int _comuna);  
	~cLaboratorio();
	void RecibirMuestra(cPaciente* _paciente);
	void AnalisisMuestra();
	void AvisarPacientes();

	
	string getNombreLabo();  //getter del atributo nombre que usamos en CentroDeTesteos.cpp en el metodo to_strigCentro

	
	string to_stringLabo();  //funciones que usaremos para imprimir en pantalla los atributos
	void ImprimirEnPantalla();
};
