#include "producto.h"
#include "excepciones.h"
#include <exception>

Producto::Producto(int _id, string _nombre, int cantidad){
    this->id = _id;
    this->existencias = cantidad;
    if(_nombre.size() > 20 || _nombre.empty() ){
        throw ExcepcionNombreProductoErroneo();
    }else if(cantidad <= 0){
        throw ExcepcionExistenciasIncorrectas();
    }else if(_id <= 0){
        throw ExcepcionIdIncorrecta();
    }
    strcpy(this->nombre, _nombre.c_str() );

}

Producto::~Producto(){

}

void Producto::editar(int nuevaId, string nuevoNombre, int nuevasExistencias){
    this->id = nuevaId;  
    if(nuevoNombre.size() > 20 || nuevoNombre.empty() ){
        throw ExcepcionNombreProductoErroneo();
    }else if(nuevasExistencias <= 0){
        throw ExcepcionExistenciasIncorrectas();
    }else if(nuevaId <= 0){
        throw ExcepcionIdIncorrecta();
    }else{
        strcpy(this->nombre, nuevoNombre.c_str() );
        this->existencias = nuevasExistencias;
    }
}

Producto::Producto(){

}

int Producto::obtenerId(){
    return this->id;
}

int Producto::obtenerExistencias(){
    return this->existencias;
}

string Producto::obtenerNombre(){
    return this->nombre;
}

ostream& operator << (ostream &salida, const Producto *producto){
    salida << "Id: " << producto->id << ". Nombre: " << producto->nombre << ". Existencias en la tienda: " << producto->existencias << endl;
    return salida;
}
