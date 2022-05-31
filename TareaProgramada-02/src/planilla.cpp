#include "planilla.h"

Planilla::Planilla(TipoEmpleado* _empleadoRaiz){
    this->empleadoRaiz = _empleadoRaiz;
    this->empleadoRaiz->calculoPago();
    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(_empleadoRaiz->obtenerIdEmpleado(), _empleadoRaiz) );
}

Planilla::Planilla(){
}

Planilla::~Planilla(){
    delete this->empleadoRaiz;
}

void Planilla::agregarEmpleado(TipoEmpleado *_nuevoEmpleado){
    if(this->empleadoRaiz == nullptr){
        _nuevoEmpleado->calculoPago();
        this->empleadoRaiz = _nuevoEmpleado;
        this->empleadoRaiz->asignarNombreSupervisor(_nuevoEmpleado->obtenerNombreCompleto());
    }else{

        TipoEmpleado *empleadoSupervisor = this->indiceEmpleados.at(_nuevoEmpleado->obtenerIdSupervisor());
        _nuevoEmpleado->asignarNombreSupervisor(empleadoSupervisor->obtenerNombreCompleto() );
        _nuevoEmpleado->calculoPago();
        empleadoSupervisor->insertarSupervisado(_nuevoEmpleado);
    }
    this->indiceEmpleados.insert(pair<int, TipoEmpleado*>(_nuevoEmpleado->obtenerIdEmpleado(), _nuevoEmpleado) );
}

TipoEmpleado* Planilla::obtenerEmpleado(int idEmpleado){
    return this->indiceEmpleados.at(idEmpleado);
}

float Planilla::obtenerTotalPagosNetos(){
    float totalPagosNetos = 0;
    for(auto par = begin(this->indiceEmpleados); par != end(this->indiceEmpleados); par++){
        totalPagosNetos += par->second->obtenerPagoNeto();
    }
    return totalPagosNetos;
}

void Planilla::obtenerPagosBrutosTotales(){}
void Planilla::obtenerImpuestosTotales(){}

ostream& operator << (ostream &salida, const Planilla *planilla){
    for(auto par = begin(planilla->indiceEmpleados); par != end(planilla->indiceEmpleados); par++){
        salida << (par->second) << endl;
    }

    return salida;
}