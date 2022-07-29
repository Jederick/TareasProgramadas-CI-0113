#ifndef FORMPRODUCTO_H
#define FORMPRODUCTO_H

#include <QDialog>

namespace Ui {
class FormProducto;
}

class FormProducto : public QDialog
{
    Q_OBJECT

public:
    explicit FormProducto(QWidget *parent = nullptr);
    ~FormProducto();

    void mostrarInformacion(QString id, QString nombre, int existencias);
    int obtenerId();
    std::string obtenerNombre();
    int obtenerExistencias();

private:
    Ui::FormProducto *ui;

};

#endif // FORMPRODUCTO_H
