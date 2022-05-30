#include "profesionalPorHoras.h"

ProfesionalPorHoras::ProfesionalPorHoras(){
}

/*ProfesionalPorHoras::~ProfesionalPorHoras(){
    for(TipoEmpleado *auxiliar: this->supervisados){
        delete auxiliar;
    }
}*/

void ProfesionalPorHoras::calculoPago(){
    this->pagoNeto = this->montoPorHora * this->horasEnMes;
}

istream& operator >> (istream &entrada, ProfesionalPorHoras *empleado){
    entrada >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor >> empleado->idEmpleado >> empleado->montoPorHora >> empleado->horasEnMes;
    return entrada;
}