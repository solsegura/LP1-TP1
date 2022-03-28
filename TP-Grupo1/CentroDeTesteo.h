#pragma once
#include <stdio.h>
#include "Pacientes.h"
#include "Laboratorios.h"
#include <string>
/*
*/


using namespace std;

class cCentroDeTesteo {
	string IDcentro;     //atributos descriptivos
	int comuna;
	string nombre;
	bool completo;		//atributos funcionales
	cPaciente* paciente1 = NULL;
	cPaciente* paciente2 = NULL;
	cLaboratorio* laboratorio = NULL;

public:
	cCentroDeTesteo(string _IDcentro, int _comuna, string _nombre, bool _completo = false, cPaciente* _paciente1 = NULL, cPaciente* _paciente2 = NULL, cLaboratorio* _laboratorio = NULL); //constructor, dejo los dos punteros igualados a NULL por defecto ya que todavia no lo asociamos a ningun paciente ni laboratorio
	~cCentroDeTesteo();		//destructor
	AsociarLaboratorio(cLaboratorio _laboratorio);
	DesasociarLaboratorio();
	AltaPaciente(cPaciente _paciente);
	BajaPaciente(cPaciente _paciente);
	MandarTesteos();

};

