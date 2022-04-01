//#include "Pacientes.h"
//#include "Laboratorios.h"
#include "CentroDeTesteo.h"
#define N_pacientes 5
#define N_centros 3
#define N_laboratorios 3


using namespace std;

void main() {

	cPaciente** lista_pacientes = new cPaciente * [N_pacientes];               //Pido memoria dinamica 
	cLaboratorio** lista_laboratorios = new cLaboratorio * [N_laboratorios];
	cCentroDeTesteo** lista_centros = new cCentroDeTesteo * [N_centros];

	//creamos los pacientes, laboratorios y centros

	lista_pacientes[0] = new cPaciente("Sol", "Segura","1566666" ,"33657615", false, false, false, true, false);
	lista_pacientes[1] = new cPaciente("Fiorella", "Maver", "15898989","23627516", true, false, true, true, false);
	lista_pacientes[2] = new cPaciente("Rosario", "Lonzayes","334344", "52627635", false, true, false, false, true);
	lista_pacientes[3] = new cPaciente("Valentina", "Garcia", " ", "32427635", true, true, true, true, true);
	lista_pacientes[4] = new cPaciente("Martina", "Martens", "123336", "48623635", false, false, false, false, false);


	lista_laboratorios[0] = new cLaboratorio("1234", "Labo1", 12);
	lista_laboratorios[1] = new cLaboratorio("3214", "Labo2", 14);
	lista_laboratorios[2] = new cLaboratorio("4321", "Labo3", 6);

	lista_centros[0] = new cCentroDeTesteo("c123", 12, "Centro1");
	lista_centros[1] = new cCentroDeTesteo("c213", 6, "Centro2");
	lista_centros[2] = new cCentroDeTesteo("c321", 14, "Centro3");


	//asigno los pacientes a cada centro y los laboratorios a cada centro
	lista_centros[0]->AltaPaciente(lista_pacientes[0]);  //en el centro1 van los pacientes Sol y Valentina 
	lista_centros[0]->AltaPaciente(lista_pacientes[3]);
	lista_centros[0]->AsociarLaboratorio(lista_laboratorios[0]);  // lo asociamos al labo1

	lista_centros[1]->AltaPaciente(lista_pacientes[1]);  //en el centro2 van Fiorella y Rosario
	lista_centros[1]->AltaPaciente(lista_pacientes[2]);
	lista_centros[1]->AsociarLaboratorio(lista_laboratorios[2]);  // lo asociamos al labo3

	lista_centros[2]->AltaPaciente(lista_pacientes[4]);  //en el centro3 va Martina
	lista_centros[2]->AsociarLaboratorio(lista_laboratorios[1]);  // lo asociamos al labo2


	//envio las muestras de cada centro al su laboratorio asociado
	lista_centros[0]->MandarTesteos();
	lista_centros[1]->MandarTesteos();
	lista_centros[2]->MandarTesteos();

	//lista_laboratorios[0]->AnalisisMuestra();   //esto es lo que creemos que esta bien
	//lista_laboratorios[1]->AnalisisMuestra();
	//lista_laboratorios[2]->AnalisisMuestra();

	lista_laboratorios[0]->AnalisisMuestra(lista_pacientes[0]);   //creeemos que esto esta MAL pero bueno, le mandamos las muestras y las analiza
	lista_laboratorios[0]->AnalisisMuestra(lista_pacientes[3]);
	lista_laboratorios[1]->AnalisisMuestra(lista_pacientes[1]);
	lista_laboratorios[1]->AnalisisMuestra(lista_pacientes[2]);
	lista_laboratorios[2]->AnalisisMuestra(lista_pacientes[4]);

	lista_centros[0]->ImprimirEnPantalla();
	lista_centros[1]->ImprimirEnPantalla();
	lista_centros[2]->ImprimirEnPantalla();

	lista_laboratorios[0]->ImprimirEnPantalla();
	lista_laboratorios[1]->ImprimirEnPantalla();
	lista_laboratorios[2]->ImprimirEnPantalla();

	//lista_laboratorios[0]->AvisarPacientes();
	//lista_laboratorios[1]->AvisarPacientes();
	//lista_laboratorios[2]->AvisarPacientes();


}