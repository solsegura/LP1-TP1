#include "CentroDeTesteo.h"
#include "Laboratorios.h"
#include <string>
#include <stdio.h>

using namespace std;
/// <summary>
/// Constructor de la clase Centro de Testeo
/// </summary>
/// <param name="_IDcentro"></param>
/// <param name="_comuna"></param>
/// <param name="_nombre"></param>
/// <param name="_completo"></param>
/// <param name="_paciente1"></param>
/// <param name="_paciente2"></param>
/// <param name="_laboratorio"></param>
cCentroDeTesteo::cCentroDeTesteo(string _IDcentro, int _comuna, string _nombre, bool _completo = false, cPaciente* _paciente1 = NULL, cPaciente* _paciente2 = NULL, cLaboratorio* _laboratorio = NULL) {
	
	this->IDcentro = _IDcentro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = _completo;
	this->paciente1 = _paciente1;
	this->Paciente = _paciente2;
	this->laboratorio = _laboratorio;
}

/// <summary>
/// Destructor
/// </summary>
cCentroDeTesteo::~cCentroDeTesteo() {

}


/// <summary>
/// Asocia el centro de testeo al laboratorio recibido por parametro
/// </summary>
/// <param name="_laboratorio"></param>
cCentroDeTesteo::AsociarLaboratorio(cLaboratorio _laboratorio) {
	this->laboaratorio = &_laboratorio;

}

/// <summary>
/// Desasocia el centro de testeo del laboratorio
/// </summary>
cCentroDeTesteo::DesasociarLaboratorio() {
	this->laboratorio = NULL;
}

/// <summary>
/// Da de alta un nuevo paciente si el centro no esta completo, sino informa que esta completo
/// </summary>
/// <param name="_paciente"></param>
cCentroDeTesteo::AltaPaciente(cPaciente _paciente) {
	if (this->completo == false) {
		if (this->paciente1 == NULL) {
			this->paciente1 = &_paciente;
		}
		else
			this->paciente2 = &_paciente;
	}
	else {
		cout << "Error: no hay espacio para mas pacientes" << endl;
	}
	if (this->paciente1 != NULL && this->paciente2 != NULL) {
		this->completo = true;
	}
}

/// <summary>
/// Da de baja un paciente cuando este ya tiene el resultado del test
/// </summary>
/// <param name="_paciente"></param>
cCentroDeTesteo::BajaPaciente(cPaciente _paciente) {
	if (_paciente.ResultadoTesteo != "Sin resultado") {
		if (this->paciente1 == _paciente) { //si el paciente que se desea dar de baja esta en el puntero 1, lo hacemos apuntar a NULL  y cambiamos el estado de completo ya que se libera un lugar
			this->paciente1 = NULL;
			this->completo = false
		}
		else if (this->paciente2 == _paciente) {
			this->paciente2 = NULL; //si esta en el 2, lo hacemos apuntar a NULL y cambiamos el estado de completo ya que se libera un lugar
			this->completo = false;
		}
		else
			cout << "Error, ese paciente no estaba en nuestra base de datos" << endl; //si no esta en ninguno, hay error
	}
}

/// <summary>
/// Envia la muestra de un paciente al laboratorio
/// </summary>
cCentroDeTesteo::MandarTesteos() {
	this->laboratorio->RecibirMuestra(paciente1);
	this->laboratorio->RecibirMuestra(paciente2);

}


