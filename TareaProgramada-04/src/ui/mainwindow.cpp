#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formproducto.h"
#include "formtienda.h"

#include <QMessageBox>
#include <QFileDialog>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tienda = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tienda;
}

void MainWindow::mostrarInformacionTienda(string nombreTienda, string paginaWeb, string direccionFisica, string telefono){
    QFont font = this->ui->lblDireccion->font();
    font.setPointSize(12);

    this->ui->lblTienda->setFont(font);
    this->ui->lblTienda->setText("Tienda: " + QString::fromStdString(nombreTienda) );

    this->ui->lblPaginaWeb->setFont(font);
    this->ui->lblPaginaWeb->setText("Página web: " + QString::fromStdString(paginaWeb) );

    this->ui->lblDireccion->setFont(font);
    this->ui->lblDireccion->setText("Direccion Física: " + QString::fromStdString(direccionFisica) );

    this->ui->lblTelefono->setFont(font);
    this->ui->lblTelefono->setText("Telefono: " + QString::fromStdString(telefono) );



}
/*void MainWindow::on_pushButton_clicked()
{
    if(this->ui->txtNombreTienda->text().isEmpty()){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("No se le ingresó un nombre a la tienda");
        msgbox->open();
    }
    string nombreTienda = this->ui->txtNombreTienda->text().toStdString();
    string direccionFisica = this->ui->txtDireccionTienda->text().toStdString();
    string paginaWeb = this->ui->txtWebTienda->text().toStdString();
    string numeroTelefono = this->ui->txtTelefonoTienda->text().toStdString();


    Tienda *tiendaTemporal = new Tienda(nombreTienda, paginaWeb, direccionFisica, numeroTelefono);
    this->tienda = tiendaTemporal;



    ostringstream streamSalida;
    streamSalida << tienda;
    string stringSalida = streamSalida.str();

    QString qstringSalida = QString::fromStdString(stringSalida);
    this->ui->lblResultadoTienda->setText(qstringSalida);
    delete tiendaTemporal;

}*/


void MainWindow::on_btnAgregarProducto_clicked()
{
    int id = this->ui->listaProductos->count();
    QString opcion = "Opcion nueva " + QString::number(id);

    QListWidgetItem *itemNuevo = new QListWidgetItem(opcion);
    itemNuevo->setData(1, id);

    this->ui->listaProductos->addItem(itemNuevo);
    /*FormProducto formProductoNuevo{this};
    int resultado = formProductoNuevo.exec();

    if(resultado == QDialog::Accepted){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Accion tomada");
        msgbox->setText("Producto creado");
        msgbox->open();
    }else{
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Accion tomada");
        msgbox->setText("Se ha cancelado la creación de producto");
        msgbox->open();
    }*/
}


void MainWindow::on_btnModificarProducto_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listaProductos->currentItem();
    if(itemSeleccionado == nullptr){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setText("No se seleccionó ningún item");
        msgbox->open();
    }else{

        QString idProducto = itemSeleccionado->data(1).toString();
        QString nombreProducto = "Nombre " + idProducto;
        int existencias = 100;

        FormProducto *formProducto = new FormProducto(this);
        formProducto->setWindowTitle("Agregar producto");
        formProducto->mostrarInformacion(idProducto, nombreProducto, existencias);
        formProducto->exec();

        /*QString data = itemSeleccionado->data(1).toString();
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Item");
        msgbox->setText("El item seleccionado es " + data);
        msgbox->open();*/
    }
}


void MainWindow::on_btnEliminarProducto_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listaProductos->currentItem();
    if(itemSeleccionado == nullptr){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("No se seleccionó ningún item");
        msgbox->open();
    }else{
        delete this->ui->listaProductos->currentItem();
        this->ui->listaProductos->setCurrentItem(nullptr);

    }

}

void MainWindow::on_btnCrearTienda_clicked()
{
    if(this->tienda == nullptr){
        FormTienda formTienda{this};
        formTienda.setWindowTitle("Crear tienda");
        int resultado = formTienda.exec();

        if(resultado == QDialog::Accepted){
            string nombreTienda = formTienda.obtenerNombreTienda();
            string direccionFisica = formTienda.obtenerDireccionTienda();
            string paginaWeb = formTienda.obtenerPaginaWebTienda();
            string telefono = formTienda.obtenerTelefonoTienda();

            this->mostrarInformacionTienda(nombreTienda, paginaWeb, direccionFisica, telefono);
            this->tienda = new Tienda(nombreTienda, paginaWeb, direccionFisica, telefono);

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setIcon(QMessageBox::Information);
            msgbox->setWindowTitle("Accion tomada");
            msgbox->setText("Tienda creada");
            msgbox->open();
        }
    }else{
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("Ya existe una tienda creada");
        msgbox->open();
    }

}


void MainWindow::on_btnImportarTienda_clicked()
{
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Advertencia");
    msgbox->setIcon(QMessageBox::Warning);

    msgbox->setText("Esta opción sobrescribirá los datos actuales");
    msgbox->setModal(true);
    msgbox->exec();

    QString rutaArchivo = QFileDialog::getOpenFileName(this, "Abrir archivo de datos", "", tr("Archivo de datos(*.dat);;All Files (*)") );

    if(!rutaArchivo.isEmpty()){
        string strRutaArchivo = rutaArchivo.toStdString();
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Archivo seleccionado");
        msgbox->setText(rutaArchivo);
        msgbox->open();
    }

}


void MainWindow::on_btnExportarTienda_clicked()
{
    QString rutaArchivo = QFileDialog::getSaveFileName(this,
            tr("Guardar achivo de datos"), "",
            tr("Archivo de datos(*.dat);;All Files (*)") );

    if(!rutaArchivo.isEmpty()){
        string strRutaArchivo = rutaArchivo.toStdString();
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Ruta seleccionada");
        msgbox->setText(rutaArchivo);
        msgbox->open();
    }
}

