#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(string _nombreCompleto, string _email, int _idEmpleado, int _tipoEmpleado, int _idSupervisor, float _pagoBruto){
    this->nombreCompleto = _nombreCompleto;
    this->email = _email;
    this->idEmpleado = _idEmpleado;
    this->tipoEmpleado = _tipoEmpleado;
    this->idSupervisor = _idSupervisor;
    this->pagoBruto = _pagoBruto;
}

/*EmpleadoNomina::~EmpleadoNomina(){
    for(TipoEmpleado *auxiliar: this->supervisados){
        delete auxiliar;
    }
}*/