#include "arbol.h"

Arbol::Arbol(TipoEmpleado *nuevoEmpleadoRaiz){
    this->empleadoRaiz = nuevoEmpleadoRaiz;
    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(this->empleadoRaiz->obtenerIdEmpleado(), this->empleadoRaiz) );
}

Arbol::~Arbol(){
    delete this->empleadoRaiz;
}

void Arbol::agregarEmpleado(TipoEmpleado *_nuevoEmpleado){
    TipoEmpleado *nuevoEmpleado = _nuevoEmpleado;
    TipoEmpleado *empleadoSupervisor = this->indiceEmpleados.at(nuevoEmpleado->obtenerIdSupervisor());

    empleadoSupervisor->insertarSupervisado(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(nuevoEmpleado->obtenerIdEmpleado(), nuevoEmpleado) );
}

TipoEmpleado* Arbol::obtenerEmpleado(int idEmpleado){
    TipoEmpleado *empleadoAuxiliar = this->indiceEmpleados.at(idEmpleado);
    return empleadoAuxiliar;

}