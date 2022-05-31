#include "lectorArchivos.h"

LectorArchivos::LectorArchivos(istream *_archivoPersonas, istream *_archivosNomina, istream *_archivosHorasTrabajadas){
    this->archivoPersonas = _archivoPersonas;
    this->archivoNomina = _archivosNomina;
    this->archivoHorasTrabajadas = _archivosHorasTrabajadas;
}

LectorArchivos::~LectorArchivos(){
}

void LectorArchivos::llenarPlanilla(Planilla *planilla){

    int tipoEmpleado = 0;
    string linea = "";
    string relleno = "";

    while(getline( *(this->archivoPersonas), linea) ){
        istringstream streamLinea(linea);
        streamLinea >> relleno >> relleno >> relleno >> relleno >> tipoEmpleado;

        //Si el empleado es de nomina
        if(tipoEmpleado == 1){

            string lineaNomina = "";

            getline(*(this->archivoNomina), lineaNomina);
            lineaNomina = linea + " " + lineaNomina;
            istringstream streamLineaNomina(lineaNomina);

            EmpleadoNomina *nuevoEmpleadoNomina = new EmpleadoNomina();
            streamLineaNomina >> nuevoEmpleadoNomina;

            planilla->agregarEmpleado(nuevoEmpleadoNomina);
            

        //si el empleado es profesional por horas
        }else if(tipoEmpleado == 2){
            string lineaHorasTrabajadas = "";

            getline(*(this->archivoHorasTrabajadas), lineaHorasTrabajadas);
            lineaHorasTrabajadas = linea + " " + lineaHorasTrabajadas;
            istringstream streamLineaNomina(lineaHorasTrabajadas);

            ProfesionalPorHoras *nuevoProfesionalPorHoras = new ProfesionalPorHoras();
            streamLineaNomina >> nuevoProfesionalPorHoras;

            planilla->agregarEmpleado(nuevoProfesionalPorHoras);


        }else{
            cout << "No existe este tipo de empleado" << endl;
            return;
        }
    }

}

string LectorArchivos::obtenerResumen(Planilla *planilla){
    float subtotal = planilla->obtenerTotalPagosNetos();
    float impuestosTotales = planilla->obtenerImpuestosTotales();
    float total = subtotal + impuestosTotales;
    
    string resumen = "Subtotal: " + to_string(subtotal) + ". Total impuestos a retener: " + to_string(impuestosTotales) + ". Total: " + to_string(total);
    return resumen;
}