#include <gtest/gtest.h>

#include "../src/tipoEmpleado.h"
#include "../src/empleadoNomina.h"
#include "../src/profesionalPorHoras.h"

namespace{

   TEST(TipoEmpleado_Tests, Test_Obtener_ID_Empleado){
        
        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "24 Deborah Nurton deborah_nurton@biz.com 1 6";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        int idEsperada = 24;
        int idActual = empleadoEjemplo->obtenerIdEmpleado();

        EXPECT_EQ(idEsperada, idActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_ID_Supervisor){

        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "199 Remy Bryson remy_bryson@biz.com 1 95";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        int idEsperada = 95;
        int idActual = empleadoEjemplo->obtenerIdSupervisor();

        EXPECT_EQ(idEsperada, idActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Nombre_Empleado){

        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "15 Stella Rossi stella_rossi@biz.com 1 4";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        string nombreEsperado = "Stella Rossi";
        string nombreActual = empleadoEjemplo->obtenerNombreCompleto();

        EXPECT_EQ(nombreEsperado, nombreActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Pago_Neto){

        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "15 Stella Rossi stella_rossi@biz.com 1 4 15 4523.48";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;

        empleadoEjemplo->calculoPago();
        float pagoNetoEsperado = 4206.8364;
        float pagoNetoActual = empleadoEjemplo->obtenerPagoNeto();

        EXPECT_FLOAT_EQ(pagoNetoEsperado, pagoNetoActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Impuesto_Retencion){

        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "15 Stella Rossi stella_rossi@biz.com 1 4 15 4523.48";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;

        empleadoEjemplo->calculoPago();
        float impuestoEsperado = 316.6436;
        float impuestoActual = empleadoEjemplo->obtenerImpuestoRetencion();

        EXPECT_FLOAT_EQ(impuestoEsperado, impuestoActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Asignar_Nombre_Supervisor){
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        empleadoEjemplo->asignarNombreSupervisor("Denis Tyler");
        
        string nombreEsperado = "Denis Tyler";
        string nombreActual = empleadoEjemplo->obtenerNombreSupervisor();

        EXPECT_EQ(nombreEsperado, nombreActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_EmpleadoNomina_Tests, Test_Calculo_Pago){
        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "74 Danny Vallory danny_vallory@biz.com 1 27 74 3115.70";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        empleadoEjemplo->calculoPago();
        float pagoNetoEsperado = 2897.60;
        float pagoNetoActual = empleadoEjemplo->obtenerPagoNeto();

        EXPECT_FLOAT_EQ(pagoNetoEsperado, pagoNetoActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_ProfesionalPorHoras_Tests, Test_Calculo_Pago){
        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "460 Selena Eyres Selena_Eyres942@corti.com 2 221 460 32.53 90";
        string lineaEmpleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(lineaEmpleado);
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        empleadoEjemplo->calculoPago();
        float pagoNetoEsperado = 2927.7;
        float pagoNetoActual = empleadoEjemplo->obtenerPagoNeto();

        EXPECT_FLOAT_EQ(pagoNetoEsperado, pagoNetoActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Insertar_Supervisado){
        
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4600.98);
        EmpleadoNomina *empleado2 = new EmpleadoNomina(2, "Clarissa", "Parker", "clarissa_parker@biz.com", 1, 1, 3097.50);

        
        empleado1->insertarSupervisado(empleado2);
        string nombreSupervisadoEsperado = "Clarissa Parker";
        string nombreSupervisadoActual = empleado2->obtenerNombreCompleto();

        EXPECT_EQ(nombreSupervisadoEsperado, nombreSupervisadoActual);

    }
}