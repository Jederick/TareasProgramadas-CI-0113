#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(string _nombre, string _apellido, string _email, int _idEmpleado, int _tipoEmpleado, int _idSupervisor, float _pagoBruto){
    this->nombre = _nombre;
    this->apellido = _apellido;
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

ostream& operator << (ostream &salida, const EmpleadoNomina *empleado){
    salida << empleado->idEmpleado << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->email << "," << empleado->tipoEmpleado << "," << empleado->idSupervisor;

    return salida;
}

istream& operator >> (istream &entrada, EmpleadoNomina *empleado){
    
    
    entrada >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor;
    return entrada;
}