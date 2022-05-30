#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "planilla.h"
#include "empleadoNomina.h"
#include "profesionalPorHoras.h"

using namespace std;

int main(){

    ifstream archivoPersonas("personas.txt", ifstream::in);
    if(!archivoPersonas.is_open() ){
        cerr << "No se pudo abrir el archivo personas.txt" << endl;
    }

    ifstream archivoHorasTrabajadas("horastrabajadas.txt", ifstream::in);
    if(!archivoHorasTrabajadas.is_open() ){
        cerr << "No se pudo abrir el archivo horastrabajadas.txt" << endl;
    }

    ifstream archivoNomina("nomina.txt", ifstream::in);
    if(!archivoHorasTrabajadas.is_open() ){
        cerr << "No se pudo abrir el archivo nomina.txt" << endl;
    }
    
    string linea = "";
    int tipoEmpleado = 0;
    string relleno = "";

    Planilla *planilla = new Planilla();
    EmpleadoNomina *jemplo1 = new EmpleadoNomina();

    getline(archivoPersonas, linea);
    istringstream stream(linea);
    stream >> relleno >> relleno >> relleno >> relleno >> tipoEmpleado;

    //cout << linea << endl;
    //cout << tipoEmpleado << endl;

    string lineaNomina = "";
    getline(archivoNomina, lineaNomina);
    lineaNomina = linea + " " + lineaNomina;
    istringstream streamLineaNomina(lineaNomina);

    streamLineaNomina >> jemplo1;
    planilla->agregarEmpleado(jemplo1);

    
    cout << planilla;


    archivoPersonas.close();
    archivoHorasTrabajadas.close();
    archivoNomina.close();

    TipoEmpleado ejem;



    return 0;
}