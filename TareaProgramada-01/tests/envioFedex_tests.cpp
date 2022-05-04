#include "./../src/envioFedex.h"
#include "./../src/tipoEnvio.h"
#include <gtest/gtest.h>

namespace{

    TEST(Test_EnvioFedex_CalculoEnvio, DistanciaMenorQuinientosKM_PesoMenorDiezKG){

        // Arrange - configurar el escenario
        EnvioFedex* envioFedex = new EnvioFedex(200, 5);

        // Act - ejecute la operación
        float actual = envioFedex->calculoEnvio();
        float esperada = 35.00;
        delete envioFedex;
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
    TEST(Test_EnvioFedex_CalculoEnvio, DistanciaMayorQuinientosKM){

        // Arrange - configurar el escenario
        EnvioFedex* envioFedex = new EnvioFedex(600, 5);

        // Act - ejecute la operación
        float actual = envioFedex->calculoEnvio();
        float esperada = 50.00;
        delete envioFedex;
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
    TEST(Test_EnvioFedex_CalculoEnvio, PesoMayorDiezKG){

        // Arrange - configurar el escenario
        EnvioFedex* envioFedex = new EnvioFedex(200, 15);

        // Act - ejecute la operación
        float actual = envioFedex->calculoEnvio();
        float esperada = 45.00;
        delete envioFedex;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
    TEST(Test_EnvioFedex_CalculoEnvio, DistanciaMayorQuinientosKM_PesoMayorDiezKG){

         // Arrange - configurar el escenario
        EnvioFedex* envioFedex = new EnvioFedex(600, 15);

        // Act - ejecute la operación
        float actual = envioFedex->calculoEnvio();
        float esperada = 60.00;
        delete envioFedex;
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
    
}