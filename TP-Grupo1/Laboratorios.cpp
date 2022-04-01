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


/// <summary>
/// Destructor de la clase cLaboratorio
/// </summary>
cLaboratorio::~cLaboratorio() {

}

/// <summary>
/// Recibe un paciente y si hay lugar en el laboratorio recibe la muestra (apunta uno de los punteros al paciente)
/// </summary>
/// <param name="_paciente"></param>
void cLaboratorio::RecibirMuestra(cPaciente* _paciente) {
	if (_paciente != NULL) {
		if (this->completo == false) {      //si el laboratorio no esta lleno, guardo el objeto paciente en el puntero que este vacio
			if (this->paciente1 == NULL) {
				this->paciente1 = _paciente;
				cout << "Se ingreso con exito la muestra de: " << _paciente->getnombre() << " al laboratorio: " << this->nombre << endl << endl;
				system("pause");

			}
			else if (paciente1 != _paciente ) {
				this->paciente2 = _paciente;
				cout << "Se ingreso con exito la muestra de: " << _paciente->getnombre() << " al laboratorio: " << this->nombre << endl << endl;
				system("pause");
			}
			else {
				cout << "La muestra de  " << _paciente->getnombre() << " ya esta ingresada en este laboratorio " << endl << endl;
				system("pause");

			}
		}
		else {
			cout << "Error: no hay espacio para mas muestras" << endl << endl;
			system("pause");

		}
	}
	if (this->paciente1 != NULL && this->paciente2 != NULL) {
		this->completo = true;   //si los dos punteros son distintos de NULL significa que el laboratorio esta lleno
	}

}


/// <summary>
/// recibe paciente y cuanta cuantos sintomas tiene para darle un resultado del test
/// </summary>
/// <param name="_paciente"></param>
void cLaboratorio::AnalisisMuestra()    //esta hacerla con paciente1 y paciente2 PUNTEROS
{
	if (paciente1 != NULL) {
		int sintomas = 0;
		if (paciente1->getfiebre() == true)
			sintomas++;
		if (paciente1->gettos() == true)
			sintomas++;
		if (paciente1->getmocos() == true)
			sintomas++;
		if (paciente1->getcctoestrecho() == true)
			sintomas++;
		if (paciente1->getdolor_de_cabeza() == true)
			sintomas++;
		if (paciente1->getdolor_de_garganta() == true)
			sintomas++;
		//enum resultado covid 0 negativo 1 positivo 2 sin resultado
		if (sintomas >= 2)
			paciente1->setresultado_testeo(positivo);

		if (sintomas < 2)
			paciente1->setresultado_testeo(negativo);
	}
	
	if (paciente2 != NULL) {
		int sintomas = 0;
		if (paciente2->getfiebre() == true)
			sintomas++;
		if (paciente2->gettos() == true)
			sintomas++;
		if (paciente2->getmocos() == true)
			sintomas++;
		if (paciente2->getcctoestrecho() == true)
			sintomas++;
		if (paciente2->getdolor_de_cabeza() == true)
			sintomas++;
		if (paciente2->getdolor_de_garganta() == true)
			sintomas++;
		//enum resultado covid 0 negativo 1 positivo 2 sin resultado
		if (sintomas >= 2)
			paciente2->setresultado_testeo(positivo);

		if (sintomas < 2)
			paciente2->setresultado_testeo(negativo);
	}

}

/// <summary>
/// Recibe un paciente y avisa a su telefono el resultado del test
/// </summary>
/// <param name="_paciente"></param>
void cLaboratorio::AvisarPacientes() { //asumo que el numero de telefono es valido o un espacio en caso de no tener telefono
	if (paciente1 != NULL) {

		string tel = paciente1->gettelefono();
		string nom = paciente1->getnombre();
		string ape = paciente1->getapellido();
		if (tel == " ") {
			cout << "No se encontro numero de telefono" << endl << endl;
		}
		else
			cout << "El mensaje fue enviado correctamente a " <<nom <<" "<< ape<<", al telefono: "<< tel << endl << endl;  
		paciente1 = NULL; //libero la muestra
		this->completo = false;   //ahora el laboratorio no esta lleno

	}
	if (paciente2 != NULL) {

		string tel = paciente2->gettelefono();
		string nom = paciente2->getnombre();
		string ape = paciente2->getapellido();
		if (tel == " ") {
			cout << "No se encontro numero de telefono" << endl << endl;
		}
		else
			cout << "El mensaje fue enviado correctamente a " << nom << " " << ape << ", al telefono: " << tel << endl << endl;
		paciente2 = NULL; //libero la muestra
		this->completo = false;  //ahora el laboratorio no esta lleno

	}
}

/// <summary>
/// Concatena en un string los atributos del laboratorio
/// </summary>
/// <returns></returns>
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

/// <summary>
/// Imprime en pantalla los atributos del cLaboratorio
/// </summary>
void cLaboratorio::ImprimirEnPantalla() {
	string info=to_stringLabo();
	cout << info << endl;
}

/// <summary>
/// Devuelve el nombre del laboratorio
/// </summary>
/// <returns></returns>
string cLaboratorio::getNombreLabo() {
	return this->nombre;
}
