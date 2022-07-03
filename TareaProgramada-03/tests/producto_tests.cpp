#include <gtest/gtest.h>
#include <iostream>

#include "../src/producto.h"
#include "../src/excepciones/excepcionNombreProductoErroneo.h"

using namespace std;

namespace{

    TEST(Producto_tests, inicializarProducto_test){

        Producto *producto1 = new Producto(1, "Tomates", 10);

        string nombreEsperado = producto1->obtenerNombre();
        string nombreActual = "Tomates";
        
        int idEsperada = producto1->obtenerId();
        int idActual = 1;

        EXPECT_EQ(nombreEsperado, nombreActual);
        EXPECT_EQ(idEsperada, idActual);

        delete producto1;
    }

    TEST(Producto_tests, excepcionNombreProductoErroneo_test){

        EXPECT_THROW({
            Producto *producto = new Producto(1,"asdasdasdasdasdasdasd", 25);
            delete producto;
        }, ExcepcionNombreProductoErroneo);        
    }

    TEST(Producto_test, editarProducto_test){
         Producto *producto1 = new Producto(1, "Tomates", 27);
         producto1->editar(7, "rtx3080", 36);

        string nombreEsperado = producto1->obtenerNombre();
        string nombreActual = "rtx3080";

        int idEsperada = producto1->obtenerId();
        int idActual = 7;
        int exitenciasEsperadas = producto1->obtenerExistencias();
        int existenciasActuales = 36;

        EXPECT_EQ(nombreEsperado, nombreActual);
        EXPECT_EQ(idEsperada, idActual);

        delete producto1;
    }

}