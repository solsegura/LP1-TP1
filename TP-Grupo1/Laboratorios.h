#pragma once
#include <stdio.h>
#include <string>
#include "Pacientes.h"
#include "CentroDeTesteo.h"

using namespace std;

class cLaboratorio {
	string IDlabo;
	string nombre;
	int comuna;
	cPaciente* paciente1 = NULL;
	cPaciente* paciente2 = NULL;
	bool completo;

public:
	cLaboratorio(string _IDlabo, string _nombre, int _comuna, cPaciente* _paciente1 = NULL, cPaciente* _paciente2 = NULL, bool _completo = false);
	~cLaboratorio();
	RecibirMuestra(cPaciente* _paciente);
	AnalisisMuestra(cPaciente* _paciente);
	AvisarPacientes(cPaciente* _paciente);

	//setters de los atributos funcionales
	setCompleto(bool _completo);
	setPaciente1(*Paciente _paciente);
	setPaciente2(*Paciente _paciente);
};
