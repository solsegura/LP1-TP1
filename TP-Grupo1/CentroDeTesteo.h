#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Laboratorios.h"

using namespace std;

//class cLaboratorio;
class cCentroDeTesteo {
	string IDcentro;     //atributos descriptivos
	int comuna;
	string nombre;
	bool completo;		//atributos funcionales
	cPaciente* paciente1;
	cPaciente* paciente2;
	cLaboratorio* laboratorio;

public:
	cCentroDeTesteo(string _IDcentro, int _comuna, string _nombre); //constructor, dejo los dos punteros igualados a NULL por defecto ya que todavia no lo asociamos a ningun paciente ni laboratorio
	~cCentroDeTesteo();		//destructor
	void AsociarLaboratorio(cLaboratorio* _laboratorio);
	void DesasociarLaboratorio();
	void AltaPaciente(cPaciente* _paciente);
	void BajaPaciente(cPaciente* _paciente);
	void MandarTesteos();


	//setters de los atributos funcionales
	void setCompleto(bool _completo);
	void setLaboratorio(cLaboratorio* _laboratorio);
	void setPaciente1(cPaciente* _paciente);
	void setPaciente2(cPaciente* _paciente);

	//funciones que usaremos para imprimir en pantalla los atributos
	string to_stringCentro();
	void ImprimirEnPantalla();
};

