#ifndef ExcepcionNombreProductoRepetido_H
#define ExcepcionNombreProductoRepetido_H

#include <exception>

using namespace std;

class ExcepcionNombreProductoRepetido : public exception{

    public:
    ExcepcionNombreProductoRepetido() noexcept = default;;
    ~ExcepcionNombreProductoRepetido() = default;

    virtual const char* what() const noexcept{        
        return "Ya existe un producto con este nombre, si desea agregar más existencias a un producto utilize el método .modificarProducto()";
    }
};

#endif