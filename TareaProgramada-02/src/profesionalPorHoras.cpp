#include "profesionalPorHoras.h"

ProfesionalPorHoras::ProfesionalPorHoras(string _nombre, string _apellido, string _email, int _idEmpleado, int _tipoEmpleado, int _idSupervisor, int _horasEnMes, float montoPorHora){
    this->nombre = _nombre;
    this->apellido = _apellido;
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

ostream& operator << (ostream &salida, const ProfesionalPorHoras *empleado){
    salida << empleado->idEmpleado << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->email << "," << empleado->tipoEmpleado << "," << empleado->idSupervisor;

    return salida;
}

istream& operator >> (istream &entrada, ProfesionalPorHoras *empleado){
    
    
    entrada >> empleado->idEmpleado >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor;
    return entrada;
}