#pragma once
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
	cLaboratorio(string _IDlabo, string _nombre, int _comuna, cPaciente* _paciente1 = NULL, cPaciente* _paciente2 = NULL, bool _completo = false);
	~cLaboratorio();
	RecibirMuestra(cPaciente* _paciente);
	AnalisisMuestra(cPaciente* _paciente);
	AvisarPacientes(cPaciente* _paciente);

	//setters de los atributos funcionales
	setCompleto(bool _completo);
	setPaciente1(cPaciente* _paciente);
	setPaciente2(cPaciente* _paciente);
	string getNombreLabo();

	//funciones que usaremos para imprimir en pantalla los atributos
	string to_stringLabo();
	ImprimirEnPantalla();
};
