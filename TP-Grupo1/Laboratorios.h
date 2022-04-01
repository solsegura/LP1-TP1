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
	void AnalisisMuestra(cPaciente* _paciente);
	void AvisarPacientes(cPaciente* _paciente);

	//setters de los atributos funcionales
	void setCompleto(bool _completo);
	void setPaciente1(cPaciente* _paciente);
	void setPaciente2(cPaciente* _paciente);
	string getNombreLabo();

	//funciones que usaremos para imprimir en pantalla los atributos
	string to_stringLabo();
	void ImprimirEnPantalla();
};
