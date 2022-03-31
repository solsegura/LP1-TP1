#include "Laboratorios.h"
#include <stdio.h>
#include <string>

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
/// recibe paciente y cuanta cuantos sintomas tiene para darle un resultado del test
/// </summary>
/// <param name="_paciente"></param>
cLaboratorio::AnalisisMuestra(cPaciente _paciente)
{

	int sintomas = 0;
	if (_paciente->getfiebre() == true)
		sintomas++;
	if (_paciente->gettos() == true)
		sintomas++;
	if (_paciente->getmocos == true)
		sintomas++;
	if (_paciente->getcctoestrecho == true)
		sintomas++;
	if (_paciente->getdolor_de_cabeza == true)
		sintomas++;
	if (_paciente->getdolor_de_garganta == true)
		sintomas++;
	//enum resultado covid 0 negativo 1 positivo 2 sin resultado
	if (sintomas > 2)
		_paciente->setresultado_testeo(1);
	if (sintomas = 2)
		_paciente->setresultado_testeo(2);
	if (sintomas < 2)
		_paciente->setresultado_testeo(0);
}




/// <summary>
/// Recibe un paciente y avisa a su telefono el resultado del test
/// </summary>
/// <param name="_paciente"></param>
cLaboratorio::AvisarPacientes(cPaciente* _paciente) { //asumo que el numero de telefono es valido o un espacio en caso de no tener telefono
	string tel=_paciente->gettelefono();
	if (tel == " ") {
		cout << "No se encontro numero de telefono" << endl;
	}
	else
		cout << "El mensaje fue enviado correctamente a " << tel << endl;
	paciente1 = NULL; //libero la muestra
	paciente2 = NULL;

}


cLaboratorio::setCompleto(bool _completo) {
	this->completo = _completo;
}

cLaboratorio::setPaciente1(cPaciente* _paciente) {
	this->paciente1 = _paciente;
}
cLaboratorio::setPaciente2(cPaciente* _paciente) {
	this->paciente2 = _paciente;
}



string cLaboratorio::to_stringCentro()
{
	stringstream ss;
	ss << "ID: " << this->IDlabo << endl;
	ss << "Comuna:  " << to_string(this->comuna) << endl;
	ss << "nombre: " << this->nombre << endl;
	if (paciente1 != NULL) {
		ss << "Paciente: " << paciente1->getnombre() << " " << paciente1->getapellido() << endl;
	}
	if (paciente2 != NULL) {
		ss << "Paciente: " << paciente2->getnombre() << " " << paciente2->getapellido() << endl;
	}
	return  ss.str();
}

cLaboratorio::ImprimirEnPantalla() {
	string info=to_stringCentro();
	cout << info << endl;
}

string cLaboratorio::getNombreLabo() {
	return this->nombre;
}
