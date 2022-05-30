#include "tipoEmpleado.h"

int TipoEmpleado::obtenerIdEmpleado(){
    return this->idEmpleado;
}

int TipoEmpleado::obtenerTipoEmpleado(){
    return this->tipoEmpleado;
}

int TipoEmpleado::obtenerIdSupervisor(){
    return this->idSupervisor;
}

string TipoEmpleado::obtenerNombreCompleto(){
    return this->nombre + " " + apellido;
}

string TipoEmpleado::obtenerNombreSupervisor(){
    return this->nombreSupervisor;
}

string TipoEmpleado::obtenerEmail(){
    return this->email;
}

void TipoEmpleado::insertarSupervisado(TipoEmpleado *nuevoSupervisado){
    this->supervisados.push_back(nuevoSupervisado);
}

void TipoEmpleado::asignarNombreSupervisor(string _nombreSupervisor){
    this->nombreSupervisor = _nombreSupervisor;
}

vector<TipoEmpleado *> TipoEmpleado::obtenerSupervisados(){
    return this->supervisados;
}

ostream& operator << (ostream &salida, TipoEmpleado *empleado){
    salida << empleado->idEmpleado << "," << empleado->nombre << " " << empleado->apellido << "," << empleado->nombreSupervisor << "," << empleado->pagoNeto;
    return salida;
}

