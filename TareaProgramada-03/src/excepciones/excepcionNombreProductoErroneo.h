#ifndef ExcepcionNombreProductoErroneo_H
#define ExcepcionNombreProductoErroneo_H

#include <exception>

using namespace std;

class ExcepcionNombreProductoErroneo : public exception{

    public:
    ExcepcionNombreProductoErroneo() noexcept = default;;
    ~ExcepcionNombreProductoErroneo() = default;

    virtual const char* what() const noexcept{        
        return "El nombre de un producto no puede superar los 20 caractéres";
    }
};

#endif