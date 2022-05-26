#include "profesionalPorHoras.h"

ProfesionalPorHoras::ProfesionalPorHoras(string _nombreCompleto, string _email, int _idEmpleado, int _tipoEmpleado, int _idSupervisor, int _horasEnMes, float montoPorHora){
    this->nombreCompleto = _nombreCompleto;
    this->email = _email;
    this->idEmpleado = _idEmpleado;
    this->tipoEmpleado = _tipoEmpleado;
    this->idSupervisor = _idSupervisor;
}

/*ProfesionalPorHoras::~ProfesionalPorHoras(){
    for(TipoEmpleado *auxiliar: this->supervisados){
        delete auxiliar;
    }
}*/