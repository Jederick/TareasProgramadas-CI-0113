#include "formproducto.h"
#include "ui_formproducto.h"

FormProducto::FormProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormProducto)
{
    ui->setupUi(this);
}

FormProducto::~FormProducto()
{
    delete ui;
}

void FormProducto::mostrarInformacion(QString id, QString nombre, int existencias){
    this->ui->leId->setText(id);
    this->ui->leId->setReadOnly(true);

    this->ui->leNombre->setText(nombre);
    this->ui->leExistencias->setText(QString::number(existencias));
}

std::string FormProducto::obtenerId(){
    return this->ui->leId->text().toStdString();
}

std::string FormProducto::obtenerNombre(){
    return this->ui->leNombre->text().toStdString();
}

int FormProducto::obtenerExistencias(){
    return this->ui->leExistencias->text().toInt();
}
