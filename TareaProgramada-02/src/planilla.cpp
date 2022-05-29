#include "planilla.h"

Planilla::Planilla(TipoEmpleado *nuevoEmpleadoRaiz){
    this->empleadoRaiz = nuevoEmpleadoRaiz;
    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(this->empleadoRaiz->obtenerIdEmpleado(), this->empleadoRaiz) );
}

Planilla::Planilla(){
}

Planilla::~Planilla(){
    delete this->empleadoRaiz;
}


void Planilla::agregarEmpleado(TipoEmpleado *_nuevoEmpleado){
    if(this->empleadoRaiz == nullptr){
        this->empleadoRaiz = _nuevoEmpleado;
    }else{

        TipoEmpleado *empleadoSupervisor = this->indiceEmpleados.at(_nuevoEmpleado->obtenerIdSupervisor());
        empleadoSupervisor->insertarSupervisado(_nuevoEmpleado);
    }
    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(_nuevoEmpleado->obtenerIdEmpleado(), _nuevoEmpleado) );
}

TipoEmpleado* Planilla::obtenerEmpleado(int idEmpleado){
    return this->indiceEmpleados.at(idEmpleado);
}