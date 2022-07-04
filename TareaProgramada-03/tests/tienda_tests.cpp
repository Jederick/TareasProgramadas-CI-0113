#include <gtest/gtest.h>
#include <sstream>
#include <fstream>

#include "../src/tienda.h"
#include "../src/excepciones/excepcionIdInexistente.h"
#include "../src/excepciones/excepcionDireccionFisicaErronea.h"
#include "../src/excepciones/excepcionDireccionWebErronea.h"
#include "../src/excepciones/excepcionIdInexistente.h"
#include "../src/excepciones/excepcionNombreTiendaErroneo.h"
#include "../src/excepciones/excepcionNombreProductoRepetido.h"
#include "../src/excepciones/excepcionTelefonoErroneo.h"
#include "../src/excepciones/excepcionIdRepetida.h"

using namespace std;

namespace{
    TEST(Tienda_tests, consultarYAgregarProductos_tests){
        
        Tienda *tienda = new Tienda("Papayaparaya", "frutilla.com", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 50);
        Producto *producto2 = new Producto(2, "papaya", 95);
        tienda->agregarProducto(producto1);
        tienda->agregarProducto(producto2);

        ostringstream streamSalida;
        streamSalida << tienda;

        string salidaEsperada = "Tienda Papayaparaya\nId: 1. Nombre: aguacate. Existencias en la tienda: 50\nId: 2. Nombre: papaya. Existencias en la tienda: 95\n";
        string salidaActual = streamSalida.str();

        EXPECT_EQ(salidaEsperada, salidaActual);
        delete tienda;

    }

    TEST(Tienda_tests, modificarProductos_tests){
        
        Tienda *tienda = new Tienda("Papayaparaya", "ice", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 35);
        Producto *producto2 = new Producto(2, "papaya", 78);
        tienda->agregarProducto(producto1);
        tienda->agregarProducto(producto2);
        tienda->modificarProducto(1, 5, "fanta", 27);
        tienda->modificarProducto(2, 97, "taza", 50);

        ostringstream streamSalida;
        streamSalida << tienda;

        string salidaEsperada = "Tienda Papayaparaya\nId: 5. Nombre: fanta. Existencias en la tienda: 27\nId: 97. Nombre: taza. Existencias en la tienda: 50\n";
        string salidaActual = streamSalida.str();

        EXPECT_EQ(salidaEsperada, salidaActual);
        
        delete tienda;

    }

    TEST(Tienda_tests, eliminarProducto_tests){
                
        Tienda *tienda = new Tienda("Papayaparaya", "frutilla.com", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 100);
        Producto *producto2 = new Producto(2, "papaya", 75);
        tienda->agregarProducto(producto1);
        tienda->agregarProducto(producto2);
        tienda->eliminarProducto(1);

        ostringstream streamSalida;
        streamSalida << tienda;

        string salidaEsperada = "Tienda Papayaparaya\nId: 2. Nombre: papaya. Existencias en la tienda: 75\n";
        string salidaActual = streamSalida.str();

        EXPECT_EQ(salidaEsperada, salidaActual);

        delete tienda;
    }

    TEST(Tienda_tests, excepcionIdInexistente_test){

        Tienda *tienda = new Tienda("Papayaparaya", "frutilla.com", "frente de pali", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 250);
        tienda->agregarProducto(producto1);
        
          EXPECT_THROW({
            tienda->modificarProducto(5, 7, "cuchara", 100);
        }, ExcepcionIdInexistente);

        EXPECT_THROW({
            tienda->eliminarProducto(4);
        }, ExcepcionIdInexistente);  

        delete tienda;
    }

    TEST(Tienda_tests, exportarYCargarArchivoBinario_test){

        Tienda *tiendaAExportar = new Tienda("Papayaparaya", "frutilla.com", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 50);
        Producto *producto2 = new Producto(2, "papaya", 95);
        tiendaAExportar->agregarProducto(producto1);
        tiendaAExportar->agregarProducto(producto2);

        //Exportar archivo binario
        ofstream archivoSalida;
        archivoSalida.open("tienda_test.dat", ios::out|ios::binary);
        if(!archivoSalida.is_open()){
            cerr << "No se pudo abrir el archivo tienda_test.dat";
        }
        
        tiendaAExportar->exportarEnStreamBinario(&archivoSalida);
        archivoSalida.close();
        //Cargar archivo binario
        Tienda *tiendaACargar = new Tienda();

        ifstream archivoEntrada;
        archivoEntrada.open("tienda_test.dat", ios::in|ios::binary);
        if(!archivoEntrada.is_open()){
            cerr << "No se pudo abrir el archivo tienda_test.dat";
        }
        tiendaACargar->cargarDesdeStreamBinario(&archivoEntrada);
        archivoEntrada.close();

        //Probar resultados
        ostringstream streamTiendaAExportar;
        streamTiendaAExportar << tiendaAExportar;

        ostringstream streamTiendaACargar;
        streamTiendaACargar << tiendaACargar;

        string salidaEsperada = "Tienda Papayaparaya\nId: 1. Nombre: aguacate. Existencias en la tienda: 50\nId: 2. Nombre: papaya. Existencias en la tienda: 95\n";
        string actualExportado = streamTiendaAExportar.str();
        string actualCargado = streamTiendaACargar.str();
        
        delete tiendaACargar;
        delete tiendaAExportar;
        
        EXPECT_EQ(salidaEsperada, actualExportado);
        EXPECT_EQ(salidaEsperada, actualCargado);
        
    }

    TEST(Tienda_tests, excepcionNombreTiendaErroneo_test){

        EXPECT_THROW({
            Tienda *tienda = new Tienda("Papayaparayaasdasdasdasdasdasd", "frutilla.com", "frente de pollolandia", "27951413");
            delete tienda;
        }, ExcepcionNombreTiendaErroneo);        
        
    }

    TEST(Tienda_tests, excepcionDireccionWebErronea_test){

        EXPECT_THROW({
            Tienda *tienda = new Tienda("Papayaparaya", "frutilla.comasdasdasdasdasdasdasdasdasd", "frente de pollolandia", "27951413");
            delete tienda;
        }, ExcepcionDireccionWebErronea);        
    }

    TEST(Tienda_tests, excepcionDireccionFisica_test){

        EXPECT_THROW({
            Tienda *tienda = new Tienda("Papayaparay", "frutilla.com", "frente de pollolandiaasdasdasdasdasdasdasdasdasd", "27951413");
            delete tienda;
        }, ExcepcionDireccionFisicaErronea);        
    }

    TEST(Tienda_tests, excepcionTelefonoErroneo_test){

        EXPECT_THROW({
            Tienda *tienda = new Tienda("Papayaparay", "frutilla.com", "frente de pollolandia", "279514138785");
            delete tienda;
        }, ExcepcionTelefonoErroneo);        
    }

    TEST(Tienda_tests, excepcionNombreProductoRepetido_test){

        Tienda *tienda = new Tienda("Tecstore", "tecstore.com", "frente de maxipali", "88776655");
        Producto *producto = new Producto(1, "audifonos", 50);
        Producto *producto2 = new Producto(2, "USB", 70);
        Producto *producto3 = new Producto(3, "audifonos", 20);
        tienda->agregarProducto(producto);
        tienda->agregarProducto(producto2);

        EXPECT_THROW({
            tienda->agregarProducto(producto3);
        }, ExcepcionNombreProductoRepetido);

        EXPECT_THROW({
            tienda->modificarProducto(2, 2, "audifonos", 25);
        }, ExcepcionNombreProductoRepetido);     

        delete tienda;
    }

    TEST(Tienda_tests, excepcionIdRepetida_test){

        Tienda *tienda = new Tienda("Tecstore", "tecstore.com", "frente de maxipali", "88776655");
        Producto *producto = new Producto(1, "audifonos", 50);
        Producto *producto2 = new Producto(1, "USB", 70);
        Producto *producto3 = new Producto(2, "monitor", 20);

        tienda->agregarProducto(producto);
        tienda->agregarProducto(producto3);

        EXPECT_THROW({
            tienda->agregarProducto(producto2);
        }, ExcepcionIdRepetida);

        EXPECT_THROW({
            tienda->modificarProducto(2, 1, "mouse", 25);
        }, ExcepcionIdRepetida);     

        delete tienda;
    }
}