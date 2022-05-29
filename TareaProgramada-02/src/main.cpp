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

    ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras("Tyler", "Denis", "denis_tyler@biz.com", 1, 1, 1, 10, 10.5);
    Planilla *planilla  = new Planilla();
    planilla->agregarEmpleado(empleadoEjemplo);
    
    archivoPersonas.close();
    archivoHorasTrabajadas.close();
    archivoNomina.close();


    return 0;
}