#include <stdio.h>
#include <string>
#include "Laboratorios.h"

using namespace std;

/// <summary>
/// Constructor de la clase cLaboratorio
/// </summary>
/// <param name="_IDlabo"></param>
/// <param name="_nombre"></param>
/// <param name="_comuna"></param>
/// <param name="_paciente1"></param>
/// <param name="_paciente2"></param>
/// <param name="_completo"></param>
cLaboratorio::cLaboratorio(string _IDlabo, string _nombre, int _comuna, cPaciente* _paciente1 = NULL, cPaciente* _paciente2 = NULL, bool _completo = false) {

	this->IDlabo = _IDlabo;
	this->nombre = _nombre;
	this->comuna = _comuna;
	this->paciente1 = _paciente1;
	this->paciente2 = _paciente2;
	this->completo = _completo;
}

cLaboratorio::~cLaboratorio() {

}
/// <summary>
/// Recibe un paciente y si hay lugar en el laboratorio recibe la muestra (apunta uno de los punteros al paciente)
/// </summary>
/// <param name="_paciente"></param>
cLaboratorio::RecibirMuestra(cPaciente* _paciente) {
	if (this->completo == false)
	{
		if (this->paciente1 == NULL)
		{
			setPaciente1(_paciente);
		}
		else
			setPaciente2(_paciente);
	}
	else 
	{
		cout << "Error: no hay espacio para analizar mas muestras." << endl;
	}
	if (this->paciente1 != NULL && this->paciente2 != NULL) 
	{
		setCompleto(true);
	}

}
/// <summary>
/// recieb paciente y cuanta cuantos sintomas tiene
/// </summary>
/// <param name="_paciente"></param>
cLaboratorio::AnalisisMuestra(cPaciente* _paciente) {
	int sintomas = 0;
	if (getFiebre(_paciente) == true)
		sintomas++;
	if (getTos(_paciente) == true)
		sintomas++;
	if (getMocos(_paciente) == true)
		sintomas++;
	if (getContactoEstrecho(_paciente) == true)
		sintomas++;
	if (getCabeza(_paciente) == true)
		sintomas++;
	if (getGarganta(_paciente) == true)
		sintomas++;
	//enum resultado covid 0 negativo 1 positivo 2 sin resultado
	if (sintomas > 2)
		setResultadoCovid(1);
	if (sintomas = 2)
		setResultadoCovid(2);
	if (sintomas < 2)
		setResultadoCovid(0);
 }
/// <summary>
/// recibe un paciente y avisa su resultado del test
/// </summary>
/// <param name="_paciente"></param>
cLaboratorio::AvisarPacientes(cPaciente* _paciente) { //asumo que el numeor de telefono es valido

	getTelefono(_paciente);
	cout << "El mensaje fue enviado correctamente a " << getTelefono(_paciente) << endl;
	_paciente == NULL; //libero la muestra


}

cLaboratorio::setCompleto(bool _completo) {
	this->completo = _completo;
}
cLaboratorio::setPaciente1(*Paciente _paciente) {
	this->paciente1 = _paciente;
}
cLaboratorio::setPaciente2(*Paciente _paciente) {
	this->paciente2 = _paciente;
}