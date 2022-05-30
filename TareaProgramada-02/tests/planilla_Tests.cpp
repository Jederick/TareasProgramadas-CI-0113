#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"
#include "../src/planilla.h"

namespace{


    TEST(Planilla_Tests, Test_Agregar_Obtener_Empleado_A_Planilla){

        // Arrange - configurar el escenario
        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "24 Deborah Nurton deborah_nurton@biz.com 1 6";
        string empleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(empleado);
        
        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina();
        streamEntradaEmpleado >> empleadoEjemplo;

        Planilla *planilla = new Planilla();

        // Act - ejecute la operación
        planilla->agregarEmpleado(empleadoEjemplo);
        TipoEmpleado *empleadoEsperado = empleadoEjemplo;
        TipoEmpleado *empleadoActual = planilla->obtenerEmpleado(24);

        // Assert - valide los resultados
        EXPECT_EQ(empleadoEsperado, empleadoActual);

        //delete empleadoEjemplo;
        //delete planillaEmpleados;
    }

    
    
}