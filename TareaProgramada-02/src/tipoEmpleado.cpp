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

string TipoEmpleado::obtenerEmail(){
    return this->email;
}

void TipoEmpleado::insertarSupervisado(TipoEmpleado *nuevoSupervisado){
    this->supervisados.push_back(nuevoSupervisado);
}

vector<TipoEmpleado *> TipoEmpleado::obtenerSupervisados(){
    return this->supervisados;
}



