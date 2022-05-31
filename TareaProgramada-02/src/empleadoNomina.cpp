#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(int _idEmpleado, string _nombre, string _apellido, string _email, int _tipoEmpleado, int _idSupervisor, float _pagoBruto){
    this->idEmpleado = _idEmpleado;
    this->nombre = _nombre;
    this->apellido = _apellido;
    this->email = _email;
    this->tipoEmpleado = _tipoEmpleado;
    this->idSupervisor = _idSupervisor;
    this->pagoBruto = _pagoBruto;
}

EmpleadoNomina::EmpleadoNomina(){
}

EmpleadoNomina::~EmpleadoNomina(){
    for(TipoEmpleado *supervisado : this->supervisados){
        delete supervisado;
    }
}

void EmpleadoNomina::calculoPago(){
    float retencion = (this->pagoBruto * 7/100);
    this->pagoNeto = this->pagoBruto - retencion;
    this->impuestoRetencion = retencion;
}

istream& operator >> (istream &entrada, EmpleadoNomina *empleado){
    entrada >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor >> empleado->idEmpleado >> empleado->pagoBruto;
    return entrada;
}