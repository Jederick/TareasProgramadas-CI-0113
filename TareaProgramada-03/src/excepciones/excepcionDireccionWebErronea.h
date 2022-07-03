#ifndef ExcepcionDireccionWebErronea_H
#define ExcepcionDireccionWebErronea_H

#include <exception>

using namespace std;

class ExcepcionDireccionWebErronea : public exception{

    public:
    ExcepcionDireccionWebErronea() noexcept = default;;
    ~ExcepcionDireccionWebErronea() = default;

    virtual const char* what() const noexcept{        
        return "La direccion web de una tienda no puede superar los 24 caractéres";
    }
};

#endif