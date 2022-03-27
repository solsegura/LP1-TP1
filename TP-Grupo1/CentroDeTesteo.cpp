#include "CentroDeTesteo.h"
#include <string>
#include <stdio.h>

using namespace std;

cCentroDeTesteo::cCentroDeTesteo(string _IDcentro, int _comuna, string _nombre, bool _completo = false, *Paciente _paciente1 = NULL, *Paciente _paciente2 = NULL, *Laboratorio _laboratorio = NULL) {
	
	this->IDcentro = _IDcentro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = _completo;
	this->paciente1 = _paciente1;
	this->Paciente = _paciente2;
	this->laboratorio = _laboratorio;
}

cCentroDeTesteo::AsociarLaboratorio(Laboratorio _laboratorio) {
	this->laboratorio = laboratorio;

}
cCentroDeTesteo::DesasociarLaboratorio() {
	this->laboratorio = NULL;
}
cCentroDeTesteo::AltaPaciente(Paciente _paciente) {
	if (this->completo == false) {
		if (this->paciente1 == NULL) {
			this->paciente1 = _paciente;
		}
		else
			this->paciente2 = _paciente;
	}
	else {
		cout << "Error: no hay espacio para mas pacientes" << endl;
	}
	if (this->paciente1 != NULL && this->paciente2 != NULL) {
		this->completo = true;
	}
}
cCentroDeTesteo::BajaPaciente(Paciente _paciente) {
	if (this->paciente1 == _paciente) //si el paciente que se desea dar de baja esta en el puntero 1, lo hacemos apuntar a NULL
		this->paciente1 = NULL;
	else if (this->paciente2 == _paciente)
		this->paciente2 = NULL; //si esta en el 2, lo hacemos apuntar a NULL
	else
		cout << "Error, ese paciente no estaba en nuestra base de datos" << endl; //si no esta en ninguno, hay error
}
cCentroDeTesteo::MandarTesteos() {
	this->*laboratorio.RecibirMuestra(paciente1);
	this->*laboratorio.RecibirMuestra(paciente2);

}
