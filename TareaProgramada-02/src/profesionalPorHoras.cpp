#include "profesionalPorHoras.h"

ProfesionalPorHoras::ProfesionalPorHoras(int _idEmpleado, string _nombre, string _apellido, string _email, int _tipoEmpleado, int _idSupervisor, float _montoPorHora, float _horasEnMes){
    this->idEmpleado = _idEmpleado;
    this->nombre = _nombre;
    this->apellido = _apellido;
    this->email = _email;
    this->tipoEmpleado = _tipoEmpleado;
    this->idSupervisor = _idSupervisor;
    this->horasEnMes = _horasEnMes;
    this->montoPorHora = _montoPorHora;
}

ProfesionalPorHoras::ProfesionalPorHoras(){
}

ProfesionalPorHoras::~ProfesionalPorHoras(){
    for(TipoEmpleado *supervisado : this->supervisados){
            delete supervisado;
    }
}

void ProfesionalPorHoras::calculoPago(){
    this->pagoNeto = this->montoPorHora * this->horasEnMes;
}

istream& operator >> (istream &entrada, ProfesionalPorHoras *empleado){
    entrada >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor >> empleado->idEmpleado >> empleado->montoPorHora >> empleado->horasEnMes;
    return entrada;
}