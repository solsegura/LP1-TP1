#include "CentroDeTesteo.h"


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
cCentroDeTesteo::cCentroDeTesteo(string _IDcentro, int _comuna, string _nombre) {

	this->IDcentro = _IDcentro;
	this->comuna = _comuna;
	this->nombre = _nombre;
	this->completo = false;
	this->paciente1 = NULL;
	this->paciente2 = NULL;
	this->laboratorio = NULL;
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
void cCentroDeTesteo::AsociarLaboratorio(cLaboratorio* _laboratorio) {
	this->laboratorio=_laboratorio;

}

/// <summary>
/// Desasocia el centro de testeo del laboratorio
/// </summary>
void cCentroDeTesteo::DesasociarLaboratorio() {
	this->laboratorio = NULL;
}

/// <summary>
/// Da de alta un nuevo paciente si el centro no esta completo, sino informa que esta completo
/// </summary>
/// <param name="_paciente"></param>
void cCentroDeTesteo::AltaPaciente(cPaciente* _paciente) {
	if (_paciente != NULL) {
		if (this->completo == false) {
			if (this->paciente1 == NULL) {
				this->paciente1 = _paciente;
				cout << "Se ingreso con exito al paciente: " << _paciente->getnombre() << endl;
				system("pause");

			}
			else if (paciente1 != _paciente) {
				this->paciente2 = _paciente;
				cout << "Se ingreso con exito al paciente: " << _paciente->getnombre() << endl;
				system("pause");
			}
			else {
				cout << "El paciente " << _paciente->getnombre() << " ya esta ingresado en el centro de testeos " << this->nombre << endl << endl;
				system("pause");

			}
		}
		else {
			cout << "Error: no hay espacio para mas pacientes" << endl << endl;
			system("pause");

		}
	}
	if (this->paciente1 != NULL && this->paciente2 != NULL) {
		this->completo = true;
	}
}

/// <summary>
/// Da de baja un paciente cuando este ya tiene el resultado del test
/// </summary>
/// <param name="_paciente"></param>
void cCentroDeTesteo::BajaPaciente(cPaciente* _paciente) {
	if (_paciente->getResultadoTesteo() != sinresultado) {
		if (this->paciente1 == _paciente) { //si el paciente que se desea dar de baja esta en el puntero 1, lo hacemos apuntar a NULL  y cambiamos el estado de completo ya que se libera un lugar
			this->paciente1 = NULL;
			this->completo = false;
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
void cCentroDeTesteo::MandarTesteos() {
	this->laboratorio->RecibirMuestra(paciente1);
	this->laboratorio->RecibirMuestra(paciente2);

}

 /// <summary>
 /// Imprime en pantalla los atributos
 /// </summary>
void cCentroDeTesteo::ImprimirEnPantalla() {
	string Imprimir = to_stringCentro();
	cout << Imprimir;
}

/// <summary>
/// Concatena los atributos del centro de testeos en un string
/// </summary>
/// <returns></returns>
string cCentroDeTesteo::to_stringCentro() {
	//se cargan los datos en el string 
	stringstream ss;
	ss << "Nombre: " << nombre << endl;
	ss << "Comuna:  " << to_string(comuna) << endl;
	ss << "ID: " << IDcentro << endl;
	if (paciente1 != NULL) {
		ss << "Paciente: " << paciente1->getnombre() << " " << paciente1->getapellido() << endl;
	}
	if (paciente2 != NULL) {
		ss << "Paciente: " << paciente2->getnombre() << " " << paciente2->getapellido() << endl;
	}
	if (laboratorio != NULL) {
		ss << "Laboratorio: " << laboratorio->getNombreLabo() << endl;
	}
	ss << endl;
	return  ss.str();
}