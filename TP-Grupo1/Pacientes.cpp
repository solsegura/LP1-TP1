#include "pacientes.h"


using namespace std;
/// <summary>
/// Constructor de la clase Paciente
/// </summary>
/// <param name="name"></param>
/// <param name="surname"></param>
/// <param name="fever"></param>
/// <param name="snot"></param>
/// <param name="contact"></param>
/// <param name="head_pain"></param>
/// <param name="throat_pain"></param>
/// <param name=""></param>
cPaciente::cPaciente(string name, string surname, string phone,string DNI,bool fever, bool snot, bool contact, bool head_pain, bool throat_pain) {

    this->nombre = name;
    this->apellido = surname;
    this->dni = DNI;
    this->telefono = phone;
    this->fiebre = fever;
    this->mocos = snot;
    this->cctoestrecho = contact;
    this->dolor_de_cabeza = head_pain;
    this->dolor_de_garganta = throat_pain;
    this-> resul = resultado_testeo::sinresultado;


}

/// <summary>
/// Destructor de la clase paciente
/// </summary>
cPaciente::~cPaciente() {}


/// <summary>
/// Recibe el resultado del test y lo asigna al atributo resultado_testeo
/// </summary>
/// <param name=""></param>
 void cPaciente::setresultado_testeo(resultado_testeo res) {
    this->resul = res;
    return;
}



/// <summary>
/// Devuelve el telefono del paciente
/// </summary>
string cPaciente:: gettelefono() {
    return this->telefono;
};

/// <summary>
/// Devuelve el nombre del paciente
/// </summary>
string cPaciente:: getnombre() {
    return this->nombre;
}

/// <summary>
/// Devuelve el apellido del paciente
/// </summary>
string cPaciente:: getapellido() { 
    return this->apellido;
}

/// <summary>
/// Devuelve true si el paciente tiene fiebre
/// </summary>
bool cPaciente:: getfiebre() { 
    return this->fiebre; 
}

/// <summary>
/// Devuelve true si el paciente tiene tos
/// </summary>
bool cPaciente:: gettos() { 
    return tos;
}

/// <summary>
/// Devuelve true si el paciente tiene mocos
/// </summary>
bool cPaciente:: getmocos() { 
    return mocos; 
}

/// <summary>
/// Devuelve true si el paciente es contacto estrecho
/// </summary>
bool cPaciente:: getcctoestrecho() { 
    return cctoestrecho; 


}

/// <summary>
/// Devuelve true si el paciente tiene dolor de cabeza
/// </summary>
bool cPaciente:: getdolor_de_cabeza() { 
    return dolor_de_cabeza; 
}

/// <summary>
/// Devuelve true si el paciente tiene dolor de garganta
/// </summary>
bool cPaciente:: getdolor_de_garganta() { 
    return dolor_de_garganta; 
}


/// <summary>
/// Devuelve el resultado de testeo del paciente
/// </summary>
/// <returns></returns>
resultado_testeo cPaciente::getResultadoTesteo()
{
    return this->resul;
}

/// <summary>
/// Concatena en un stringstream los atributos del paciente que vamos a imprimir
/// </summary>
/// <returns></returns>
string cPaciente::to_stringPaciente()
{
    string resultadito;
    if (this->resul == negativo)
        resultadito = "No detectable";
    if (this->resul == positivo)
        resultadito = "Detectable";
    if (this->resul == sinresultado)
        resultadito = "Sin resultado";


    stringstream ss;
    ss << "Nombre: " << this->nombre << endl;
    ss << "Apellido:  " << this->apellido << endl;
    ss << "DNI: " << this->dni << endl;
    ss << "Resultado: " << resultadito << endl;
    ss << endl;

    return  ss.str();
}


/// <summary>
/// Imprime en pantalla los atributos del paciente
/// </summary>
void cPaciente::ImprimirEnPantalla() {
    string info = to_stringPaciente();
    cout << info << endl;
}