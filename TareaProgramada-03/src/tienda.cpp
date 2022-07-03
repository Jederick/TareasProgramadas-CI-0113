#include "tienda.h"
#include "excepcionLimiteChar.h"
#include "excepcionIdInexistente.h"

Tienda::Tienda(string _nombre, string _direccionInternet, string _direccionFisica, string _telefono){
    if(_nombre.size() > 20 || _direccionInternet.size() > 24 || _direccionFisica.size() > 24 || _telefono.size() > 8){
        throw ExcepcionLimiteChar();
    }else{
        strcpy(this->nombre, _nombre.c_str() );
        strcpy(this->direccionInternet, _direccionInternet.c_str() );
        strcpy(this->direccionFisica, _direccionFisica.c_str() );
        strcpy(this->telefono, _telefono.c_str() ); 
    }
}

Tienda::Tienda(){
    
}

void Tienda::agregarProducto(Producto *nuevoProducto){
    this->inventario.push_back(nuevoProducto);
    //this->actualizarExistencias();
}

void Tienda::modificarProducto(int idProductoAModificar, int nuevaId, string nuevoNombre, int nuevasExistencias){
    bool encontrado = false;
    for(Producto *producto : this->inventario){
        if(producto->obtenerId() == idProductoAModificar){
            encontrado = true;
            producto->editar(nuevaId, nuevoNombre, nuevasExistencias);
        }
    }
    if(encontrado == false){
        throw ExcepcionIdInexistente();
    }
}

void Tienda::exportarEnStreamBinario(ostream *streamSalida){
    streamSalida->write( (char *)this->nombre, 15);
    streamSalida->write( (char *)this->direccionInternet, 24);
    streamSalida->write( (char *)this->direccionFisica, 24 );
    streamSalida->write( (char *)this->telefono, 8);

    for(Producto *producto : this->inventario){
        streamSalida->write( (char *)producto, sizeof(Producto) );
    }
}

void Tienda::cargarDesdeStreamBinario(istream *streamEntrada){
    streamEntrada->seekg(0, ios::end);
    int cantidadBytes = streamEntrada->tellg();
    int cantidadProductos = (cantidadBytes - 71) / sizeof(Producto);

    streamEntrada->seekg(0, ios::beg);
    streamEntrada->read( (char *)this->nombre, 15);
    streamEntrada->read( (char *)this->direccionInternet, 24);
    streamEntrada->read( (char *)this->direccionFisica, 24);
    streamEntrada->read( (char *)this->telefono, 8);
    
    for(int indice = 0; indice < cantidadProductos; indice++){
        Producto *producto = new Producto();

        streamEntrada->read( (char*)producto, sizeof(Producto) );

        this->agregarProducto(producto);
    }
}

void Tienda::eliminarProducto(int idAEliminar){
    int indice = 0;
    bool encontrada = false;
    for(Producto *producto : this->inventario){
        if(producto->obtenerId() == idAEliminar){
            encontrada = true;
            delete producto;
            this->inventario.erase(inventario.begin() + indice);
        }
        if(encontrada == false){
            throw ExcepcionIdInexistente();
        }
        indice++;
    }
}

ostream& operator << (ostream &salida, const Tienda *tienda){
    salida << "Tienda " << tienda->nombre << endl;
    for(Producto *producto : tienda->inventario){
        salida << producto;
    }
    return salida;
}