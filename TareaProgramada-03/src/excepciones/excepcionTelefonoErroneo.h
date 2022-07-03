#ifndef ExcepcionTelefonoErroneo_H
#define ExcepcionTelefonoErroneo_H

#include <exception>

using namespace std;

class ExcepcionTelefonoErroneo : public exception{

    public:
    ExcepcionTelefonoErroneo() noexcept = default;;
    ~ExcepcionTelefonoErroneo() = default;

    virtual const char* what() const noexcept{        
        return "El número de telefono de una tienda no puede superar los 8 números (caractéres)";
    }
    
};

#endif