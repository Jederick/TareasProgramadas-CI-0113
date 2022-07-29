#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>

using namespace std;

class ExcepcionDireccionFisicaErronea : public exception{

    public:
    ExcepcionDireccionFisicaErronea() noexcept = default;;
    ~ExcepcionDireccionFisicaErronea() = default;

    virtual const char* what() const noexcept{
        return "La direccion fiísica de una tienda no puede superar los 24 caractéres";
    }

};

class ExcepcionDireccionWebErronea : public exception{

    public:
    ExcepcionDireccionWebErronea() noexcept = default;;
    ~ExcepcionDireccionWebErronea() = default;

    virtual const char* what() const noexcept{
        return "La direccion web de una tienda no puede superar los 24 caractéres";
    }
};

class ExcepcionIdInexistente : public exception{

    public:
    ExcepcionIdInexistente() noexcept = default;;
    ~ExcepcionIdInexistente() = default;

    virtual const char* what() const noexcept{
        return "No existe ningún producto ligado a la id ingresada";
    }
};

class ExcepcionIdRepetida : public exception{

    public:
    ExcepcionIdRepetida() noexcept = default;;
    ~ExcepcionIdRepetida() = default;

    virtual const char* what() const noexcept{
        return "Ya existe un producto con la id ingresada, ingrese otra.";
    }
};

class ExcepcionNombreProductoErroneo : public exception{

    public:
    ExcepcionNombreProductoErroneo() noexcept = default;;
    ~ExcepcionNombreProductoErroneo() = default;

    virtual const char* what() const noexcept{
        return "El nombre de un producto no puede superar los 20 caractéres";
    }
};

class ExcepcionNombreProductoRepetido : public exception{

    public:
    ExcepcionNombreProductoRepetido() noexcept = default;;
    ~ExcepcionNombreProductoRepetido() = default;

    virtual const char* what() const noexcept{
        return "Ya existe un producto con este nombre, si desea agregar más existencias a un producto utilize el método .modificarProducto()";
    }
};

class ExcepcionNombreTiendaErroneo : public exception{

    public:
    ExcepcionNombreTiendaErroneo() noexcept = default;;
    ~ExcepcionNombreTiendaErroneo() = default;

    virtual const char* what() const noexcept{
        return "El nombre de una tienda no puede superar los 15 caractéres";
    }
};

class ExcepcionTelefonoErroneo : public exception{

    public:
    ExcepcionTelefonoErroneo() noexcept = default;;
    ~ExcepcionTelefonoErroneo() = default;

    virtual const char* what() const noexcept{
        return "El número de telefono de una tienda no puede superar los 8 números (caractéres)";
    }

};

#endif
