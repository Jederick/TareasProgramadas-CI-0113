#ifndef TIPO_EMPLEADO_H
#define TIPO_EMPLEADO_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TipoEmpleado{

    protected:
    int idEmpleado;
    int tipoEmpleado;
    int idSupervisor;
    string nombre;
    string apellido;
    string email;

    vector<TipoEmpleado*> supervisados;
    

    public:
    //virtual int calculoPago();

    int obtenerIdEmpleado();
    int obtenerTipoEmpleado();
    int obtenerIdSupervisor();

    string obtenerNombreCompleto();
    string obtenerEmail();

    vector<TipoEmpleado *> obtenerSupervisados();
    void insertarSupervisado(TipoEmpleado *nuevoSupervisado);

};

#endif