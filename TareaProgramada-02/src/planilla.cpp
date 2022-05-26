#include "planilla.h"

Planilla::Planilla(TipoEmpleado *nuevoEmpleadoRaiz){
    this->empleadoRaiz = nuevoEmpleadoRaiz;
    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(this->empleadoRaiz->obtenerIdEmpleado(), this->empleadoRaiz) );
}

Planilla::~Planilla(){
    delete this->empleadoRaiz;
}


void Planilla::agregarEmpleado(TipoEmpleado *_nuevoEmpleado){
    TipoEmpleado *nuevoEmpleado = _nuevoEmpleado;
    TipoEmpleado *empleadoSupervisor = this->indiceEmpleados.at(nuevoEmpleado->obtenerIdSupervisor());

    empleadoSupervisor->insertarSupervisado(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(nuevoEmpleado->obtenerIdEmpleado(), nuevoEmpleado) );
}

TipoEmpleado* Planilla::obtenerEmpleado(int idEmpleado){
    return this->indiceEmpleados.at(idEmpleado);
}