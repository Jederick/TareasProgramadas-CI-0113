#include "formtienda.h"
#include "ui_formtienda.h"

FormTienda::FormTienda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormTienda)
{
    ui->setupUi(this);
}

FormTienda::~FormTienda()
{
    delete ui;
}

std::string FormTienda::obtenerNombreTienda(){
    return this->ui->leNombreTienda->text().toStdString();
}

std::string FormTienda::obtenerDireccionTienda(){
    return this->ui->leDireccionFisica->text().toStdString();
}

std::string FormTienda::obtenerPaginaWebTienda(){
    return this->ui->lePaginaWeb->text().toStdString();
}

std::string FormTienda::obtenerTelefonoTienda(){
    return this->ui->leTelefono->text().toStdString();
}
