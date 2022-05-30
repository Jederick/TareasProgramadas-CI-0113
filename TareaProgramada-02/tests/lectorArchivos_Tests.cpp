#include <gtest/gtest.h>
#include "../src/lectorArchivos.h"


namespace{

    TEST(LectorArchivos_Tests, Test_Llenar_Planilla){

        // Arrange - configurar el escenario
        ostringstream streamSalidaPersonas;
        streamSalidaPersonas << "1 Denis Tyler denis_tyler@biz.com 1 1" << endl;
        streamSalidaPersonas << "2 Clarissa Parker clarissa_parker@biz.com 1 1" << endl;
        streamSalidaPersonas << "451 Ryan Webster Ryan_Webster6612@hourpy.biz 2 2" << endl;
        streamSalidaPersonas << "452 Emmanuelle Tennant Emmanuelle_Tennant8391@deavo.com 2 2" << endl;
        string personas = streamSalidaPersonas.str();
        istringstream streamEntradaPersonas(personas);


        ostringstream streamSalidaNomina;
        streamSalidaNomina << "1 4600.98" << endl;
        streamSalidaNomina << "2 3097.50" << endl;
        string nominas = streamSalidaNomina.str();
        istringstream streamEntradaNomina(nominas);
        

        ostringstream streamSalidaHorasTrabajadas;
        streamSalidaHorasTrabajadas << "451 42.26 55" << endl;
        streamSalidaHorasTrabajadas << "452 34.84 43" << endl;
        string horasTrabajadas = streamSalidaHorasTrabajadas.str();
        istringstream streamEntradaHorasTrabajadas(horasTrabajadas);
        
        Planilla *planilla = new Planilla();
        LectorArchivos *lectorArchivos = new LectorArchivos(&streamEntradaPersonas, &streamEntradaNomina, &streamEntradaHorasTrabajadas);
        
        // Act - ejecute la operación

        lectorArchivos->llenarPlanilla(planilla);

        string nombreEsperado1 = "Denis Tyler";
        string nombreActual1 = planilla->obtenerEmpleado(1)->obtenerNombreCompleto();

        int idEsperada2  = 2;
        int idActual2 = planilla->obtenerEmpleado(2)->obtenerIdEmpleado();

        string nombreSupervisorEsperado3 = "Clarissa Parker";
        string nombreSupervisorActual3 = planilla->obtenerEmpleado(451)->obtenerNombreSupervisor();

        int idSupervisorEsperada4 = 2;
        int idSupervisorActual4 = planilla->obtenerEmpleado(452)->obtenerIdSupervisor();

        // Assert - valide los resultados
        EXPECT_EQ(nombreEsperado1, nombreActual1);
        EXPECT_EQ(idEsperada2, idActual2);
        EXPECT_EQ(nombreSupervisorEsperado3, nombreSupervisorActual3);
        EXPECT_EQ(idSupervisorEsperada4, idSupervisorActual4);
        
    
    }

}