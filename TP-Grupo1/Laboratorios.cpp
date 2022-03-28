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


/// <summary>
/// Recibe un paciente y si hay lugar en el laboratorio recibe la muestra (apunta uno de los punteros al paciente)
/// </summary>
/// <param name="_paciente"></param>
cLaboratorio::RecibirMuestra(cPaciente* _paciente) {
	if (this->completo == false)
	{
		if (this->paciente1 == NULL)
		{
			this->paciente1 = _paciente;   //despues hacete un setter de esto (yo recien lo cambie en el mio)
		}
		else
			this->paciente2 = _paciente;
	}
	else 
	{
		cout << "Error: no hay espacio para analizar mas muestras." << endl;
	}

}

cLaboratorio::AnalisisMuestra(cPaciente* _paciente) {



 }
cLaboratorio::AvisarPacientes(cPaciente* _paciente) {


}