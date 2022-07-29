#ifndef FORMTIENDA_H
#define FORMTIENDA_H

#include <QIntValidator>

#include <QDialog>

namespace Ui {
class FormTienda;
}

class FormTienda : public QDialog
{
    Q_OBJECT

public:
    explicit FormTienda(QWidget *parent = nullptr);
    ~FormTienda();
    std::string obtenerNombreTienda();
    std::string obtenerDireccionTienda();
    std::string obtenerPaginaWebTienda();
    std::string obtenerTelefonoTienda();

private:
    Ui::FormTienda *ui;


};

#endif // FORMTIENDA_H
