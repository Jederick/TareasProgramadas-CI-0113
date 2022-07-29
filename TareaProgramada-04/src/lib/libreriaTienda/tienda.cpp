#include "tienda.h"
#include "excepciones.h"

Tienda::Tienda(string _nombre, string _direccionInternet, string _direccionFisica, string _telefono){
    if(_nombre.size() > 15 || _nombre.empty() ){
        throw ExcepcionNombreTiendaErroneo();

    }else if(_direccionInternet.size() > 24 || _direccionInternet.empty() ){
        throw ExcepcionDireccionWebErronea();

    }else if(_direccionFisica.size() > 24 || _direccionFisica.empty() ){
        throw ExcepcionDireccionFisicaErronea();

    }else if(_telefono.size() > 8 || _telefono.empty() || !this->esNumero(_telefono) || _telefono.size() < 8){
        throw ExcepcionTelefonoErroneo();

    }else{
        strcpy(this->nombre, _nombre.c_str() );
        strcpy(this->direccionInternet, _direccionInternet.c_str() );
        strcpy(this->direccionFisica, _direccionFisica.c_str() );
        strcpy(this->telefono, _telefono.c_str() );
    }

}

Tienda::Tienda(){

}

Tienda::~Tienda(){
    for(Producto *producto : this->inventario){
        delete producto;
    }
}

bool Tienda::esNumero(const string& variable){
    std::string::const_iterator iterador = variable.begin();
    while(iterador != variable.end() && std::isdigit(*iterador) ){
        iterador++;
    }
    return !variable.empty() && iterador == variable.end();
}


void Tienda::agregarProducto(Producto *nuevoProducto){

    for(Producto *producto : this->inventario){
        if(producto->obtenerId() == nuevoProducto->obtenerId() ){
            throw ExcepcionIdRepetida();

        }
        if(producto->obtenerNombre() == nuevoProducto->obtenerNombre()){
            throw ExcepcionNombreProductoRepetido();

        }
    }

    this->inventario.push_back(nuevoProducto);
}

void Tienda::modificarProducto(int idProductoAModificar, int nuevaId, string nuevoNombre, int nuevasExistencias){
    bool encontrado = false;

    for(Producto *producto : this->inventario){
        if(producto->obtenerId() == idProductoAModificar){
            encontrado = true;

            for(Producto* producto2 : this->inventario){
                if(producto2->obtenerId() == nuevaId && producto2->obtenerNombre() != producto->obtenerNombre()){
                    throw ExcepcionIdRepetida();

                }
                if(producto2->obtenerNombre() == nuevoNombre && producto2->obtenerId() != producto->obtenerId() ){
                    throw ExcepcionNombreProductoRepetido();

                }
            }
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
    this->inventario.clear();
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

void Tienda::eliminarProducto(Producto *_producto){
    int indice = 0;
    bool encontrada = false;
    for(Producto *producto : this->inventario){
        if(producto == _producto){
            encontrada = true;
            delete producto;
            this->inventario.erase(inventario.begin() + indice);
        }

        indice++;
    }
    if(encontrada == false){
        throw ExcepcionIdInexistente();
    }
}

string Tienda::obtenerNombre(){
    return this->nombre;
}

string Tienda::obtenerDireccionFisica(){
    return this->direccionFisica;
}

string Tienda::obtenerDireccionInternet(){
    return this->direccionInternet;
}

string Tienda::obtenerTelefono(){
    return this->telefono;
}

vector<Producto *> Tienda::obtenerInventario(){
    return this->inventario;
}

Producto* Tienda::obtenerProducto(int idProducto){
    for(Producto *producto : this->inventario){
        if(producto->obtenerId() == idProducto){
            return producto;
        }
    }
    throw ExcepcionIdInexistente();
}

ostream& operator << (ostream &salida, const Tienda *tienda){
    salida << "Tienda " << tienda->nombre << endl;
    for(Producto *producto : tienda->inventario){
        salida << producto;
    }
    return salida;
}
