#ifndef ExcepcionNombreTiendaErroneo_H
#define ExcepcionNombreTiendaErroneo_H

#include <exception>

using namespace std;

class ExcepcionNombreTiendaErroneo : public exception{

    public:
    ExcepcionNombreTiendaErroneo() noexcept = default;;
    ~ExcepcionNombreTiendaErroneo() = default;

    virtual const char* what() const noexcept{        
        return "El nombre de una tienda no puede superar los 15 caractéres";
    }
};

#endif