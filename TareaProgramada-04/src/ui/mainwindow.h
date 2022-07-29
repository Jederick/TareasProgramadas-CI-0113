#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./../lib/libreriaTienda/tienda.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnAgregarProducto_clicked();

    void on_btnModificarProducto_clicked();

    void on_btnEliminarProducto_clicked();

    void on_btnCrearTienda_clicked();

    void on_btnImportarTienda_clicked();

    void on_btnExportarTienda_clicked();


    void mostrarInformacionTienda(string nombreTienda, string paginaWeb, string direccionFisica, string telefono);

    void mostrarProductosTienda(vector<Producto *> inventario);

private:
    Ui::MainWindow *ui;
    Tienda *tienda;
};
#endif // MAINWINDOW_H
