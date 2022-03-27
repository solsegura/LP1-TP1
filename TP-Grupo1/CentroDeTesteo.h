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
	*Paciente paciente1 = NULL;
	Paciente::*Paciente paciente2 = NULL;
	*Laboratorio laboaratorio = NULL;

public:
	cCentroDeTesteo(string _IDcentro, int _comuna, string _nombre, bool _completo = false, *Paciente _paciente1 = NULL, *Paciente _paciente2 = NULL, *Laboratorio _laboratorio = NULL); //constructor, dejo los dos punteros igualados a NULL por defecto ya que todavia no lo asociamos a ningun paciente ni laboratorio
	~cCentroDeTesteo();		//destructor
	AsociarLaboratorio(Laboratorio _laboratorio);
	DesasociarLaboratorio();
	AltaPaciente(Paciente _paciente);
	BajaPaciente(Paciente _paciente);
	MandarTesteos();

};