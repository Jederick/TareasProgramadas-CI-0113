#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "planilla.h"
#include "empleadoNomina.h"
#include "profesionalPorHoras.h"
#include "lectorArchivos.h"

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
    
    Planilla *planilla = new Planilla();
    LectorArchivos *lectorArchivos = new LectorArchivos(&archivoPersonas, &archivoNomina, &archivoHorasTrabajadas);
    
    lectorArchivos->llenarPlanilla(planilla);
    cout << planilla;

    return 0;
}