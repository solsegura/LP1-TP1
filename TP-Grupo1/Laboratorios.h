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
	RecibirMuestra(cPaciente* _paciente, bool _completo);
	AnalisisMuestra(cPciente* _paciente);
	AvisarPacientes(cPaciente* _paciente);
};
