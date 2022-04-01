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
cLaboratorio::cLaboratorio(string _IDlabo, string _nombre, int _comuna) {

	this->IDlabo = _IDlabo;
	this->nombre = _nombre;
	this->comuna = _comuna;
	this->completo = false;
	this->paciente1 = NULL;
	this->paciente2 = NULL;
}

cLaboratorio::~cLaboratorio() {

}

/// <summary>
/// Recibe un paciente y si hay lugar en el laboratorio recibe la muestra (apunta uno de los punteros al paciente)
/// </summary>
/// <param name="_paciente"></param>
void cLaboratorio::RecibirMuestra(cPaciente* _paciente) {
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
void cLaboratorio::AnalisisMuestra(cPaciente* _paciente)    //esta hacerla con paciente1 y paciente2 PUNTEROS
{

	int sintomas = 0;
	if (_paciente->getfiebre() == true)
		sintomas++;
	if (_paciente->gettos() == true)
		sintomas++;
	if (_paciente->getmocos() == true)
		sintomas++;
	if (_paciente->getcctoestrecho() == true)
		sintomas++;
	if (_paciente->getdolor_de_cabeza() == true)
		sintomas++;
	if (_paciente->getdolor_de_garganta() == true)
		sintomas++;
	//enum resultado covid 0 negativo 1 positivo 2 sin resultado
	if (sintomas >= 2)
		_paciente->setresultado_testeo(positivo);

	if (sintomas < 2)
		_paciente->setresultado_testeo(negativo);
}




/// <summary>
/// Recibe un paciente y avisa a su telefono el resultado del test
/// </summary>
/// <param name="_paciente"></param>
void cLaboratorio::AvisarPacientes(cPaciente* _paciente) { //asumo que el numero de telefono es valido o un espacio en caso de no tener telefono
	
	string tel=_paciente->gettelefono();
	if (tel == " ") {
		cout << "No se encontro numero de telefono" << endl;
	}
	else
		cout << "El mensaje fue enviado correctamente a " << tel << endl;  //HACERLO CON PUNTEROS
	paciente1 = NULL; //libero la muestra
	paciente2 = NULL;

}


void cLaboratorio::setCompleto(bool _completo) {
	this->completo = _completo;
}

void cLaboratorio::setPaciente1(cPaciente* _paciente) {
	this->paciente1 = _paciente;
}
void cLaboratorio::setPaciente2(cPaciente* _paciente) {
	this->paciente2 = _paciente;
}



string cLaboratorio::to_stringLabo()
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

void cLaboratorio::ImprimirEnPantalla() {
	string info=to_stringLabo();
	cout << info << endl;
}

string cLaboratorio::getNombreLabo() {
	return this->nombre;
}
