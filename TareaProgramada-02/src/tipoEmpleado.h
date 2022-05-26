#ifndef TIPO_EMPLEADO_H
#define TIPO_EMPLEADO_H
#include <string>
#include <vector>

using namespace std;

class TipoEmpleado{

    protected:
    int idEmpleado;
    int tipoEmpleado;
    int idSupervisor;
    string nombreCompleto;
    string email;

    vector<TipoEmpleado*> supervisados;
    

    public:
    //virtual int calculoPago();
    //virtual TipoEmpleado* crearEmpleado(TipoEmpleado* nuevoEmpleado);

    int obtenerIdEmpleado();
    int obtenerTipoEmpleado();
    int obtenerIdSupervisor();

    string obtenerNombreCompleto();
    string obtenerEmail();

    vector<TipoEmpleado *> obtenerSupervisados();
    //void insertarSupervisado(TipoEmpleado *nuevoSupervisado);    

};

#endif