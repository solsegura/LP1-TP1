#pragma once
#include <stdio.h>
#include <string.h>
#include "Paciente.h"
#include "Laboratorios.h"


/*
*/


using namespace std;

class CentroDeTesteo {
	string IDcentro;     //atributos descriptivos
	int comuna;
	string nombre;
	bool completo;		//atributos funcionales
	*Paciente paciente1 = NULL;
	*Paciente paciente2 = NULL;
	*Laboratorio laboaratorio = NULL;

public:
	CentroDeTesteo(string IDcentro, int comuna, string nombre, bool completo = false,*Paciente paciente = NULL, *Laboratorio laboratorio = NULL); //constructor, dejo los dos punteros igualados a NULL por defecto ya que todavia no lo asociamos a ningun paciente ni laboratorio
	~CentroDeTesteo();		//destructor
	AsociarLaboratorio(Laboratorio laboratorio);
	DesasociarLaboratorio();
	AltaPaciente(Paciente paciente);
	BajaPaciente(Paciente paciente);
	MandarTesteos();

};