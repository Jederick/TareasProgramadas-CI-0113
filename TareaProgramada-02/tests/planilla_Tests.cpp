#include <gtest/gtest.h>
#include "./../src/planilla.h"
#include "./../src/empleadoNomina.h"
#include "./../src/profesionalPorHoras.h"
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

        delete planilla;
    }

    TEST(Planilla_Tests, Test_Obtener_Total_Pagos_Netos){

        // Arrange - configurar el escenario
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4600.98);
        EmpleadoNomina *empleado2 = new EmpleadoNomina(2, "Clarissa", "Parker", "clarissa_parker@biz.com", 1, 1, 3097.50);

        ProfesionalPorHoras *empleado3 = new ProfesionalPorHoras(451, "Ryan", "Webster", "Ryan_Webster6612@hourpy.biz", 2, 2, 42.26, 55);
        ProfesionalPorHoras *empleado4 = new ProfesionalPorHoras(452, "Emmanuelle", "Tennant", "Emmanuelle_Tennant8391@deavo.com", 2, 2, 34.84, 43);
        Planilla *planilla = new Planilla(empleado1);
        planilla->agregarEmpleado(empleado2);
        planilla->agregarEmpleado(empleado3);
        planilla->agregarEmpleado(empleado4);

        // Act - ejecute la operación

        float totalPagosNetosEsperado = 10982.01;
        float totalPagosNetosActual = planilla->obtenerTotalPagosNetos();
        

        EXPECT_FLOAT_EQ(totalPagosNetosEsperado, totalPagosNetosActual);
        delete planilla;
    }

    TEST(Planilla_Tests, Test_Obtener_Total_Impuestos){

        // Arrange - configurar el escenario
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4600.98);
        EmpleadoNomina *empleado2 = new EmpleadoNomina(2, "Clarissa", "Parker", "clarissa_parker@biz.com", 1, 1, 3097.50);
        EmpleadoNomina *empleado3 = new EmpleadoNomina(3, "Harmony", "Rycroft", "harmony_rycroft@biz.com", 1, 1, 4586.42);
        EmpleadoNomina *empleado4 = new EmpleadoNomina(4, "Alan", "Patel", "alan_patel@biz.com", 1, 1, 4606.19);
        Planilla *planilla = new Planilla(empleado1);
        planilla->agregarEmpleado(empleado2);
        planilla->agregarEmpleado(empleado3);
        planilla->agregarEmpleado(empleado4);

        // Act - ejecute la operación

        float totalImpuestosEsperado = 1182.3762;
        float totalImpuestosActual = planilla->obtenerImpuestosTotales();
        

        EXPECT_FLOAT_EQ(totalImpuestosEsperado, totalImpuestosActual);
        delete planilla;
    }
}