#include "producto.h"
#include "excepcionLimiteChar.h"
#include <exception>

Producto::Producto(int _id, string _nombre, int cantidad){
    this->id = _id;
    this->existencias = cantidad;
    if(_nombre.size() > 20){
        throw ExcepcionLimiteChar();
    }
    strcpy(this->nombre, _nombre.c_str() );
    
}

Producto::~Producto(){

}

void Producto::editar(int nuevaId, string nuevoNombre, int nuevasExistencias){
    this->id = nuevaId;
    this->existencias = nuevasExistencias;
    if(nuevoNombre.size() > 20){
        throw ExcepcionLimiteChar();
    }else{
        strcpy(this->nombre, nuevoNombre.c_str() );
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