#include <stdio.h>
#include <string>
#include "Laboratorios.h"

using namespace std;

cLaboratorio::cLaboratorio(string _IDlabo, string _nombre, int _comuna, cPaciente* _paciente1 = NULL, cPaciente* _paciente2 = NULL, bool _completo = false) {

	this->IDlabo = _IDlabo;
	this->nombre = _nombre;
	this->comuna = _comuna;
	this->paciente1 = _paciente1;
	this->paciente2 = _paciente2;
}

cLaboratorio::RecibirMuestra(cPaciente* _paciente, bool _completo) {
	if (this->completo == false)
	{
		if (this->paciente1 == NULL)
		{
			this->paciente1 = _paciente;
		}
		else
			this->paciente2 = _paciente;
	}
	else 
	{
		cout << "Error: no hay espacio para analizar mas muestras." << endl;
	}

}
cLaboratorio::AnalisisMuestra(cPciente* _paciente) {



 }
cLaboratorio::AvisarPacientes(cPciente* _paciente) {


}