#include "empleadoNomina.h"
EmpleadoNomina::EmpleadoNomina(){
}

/*EmpleadoNomina::~EmpleadoNomina(){
    for(TipoEmpleado *auxiliar: this->supervisados){
        delete auxiliar;
    }
}*/

void EmpleadoNomina::calculoPago(){
    float retencion = (this->pagoBruto * 7/100);
    this->pagoNeto = this->pagoBruto - retencion;
}

istream& operator >> (istream &entrada, EmpleadoNomina *empleado){
    entrada >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor >> empleado->idEmpleado >> empleado->pagoBruto;
    return entrada;
}