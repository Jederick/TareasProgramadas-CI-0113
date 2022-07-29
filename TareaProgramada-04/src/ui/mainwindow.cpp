#include "mainwindow.h"
#include "excepciones.h"
#include "ui_mainwindow.h"
#include "formproducto.h"
#include "formtienda.h"
#include "./../lib/libreriaTienda/tienda.h"

#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

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

//TERMIANDO
void MainWindow::mostrarProductosTienda(vector<Producto* > inventario){
    for(Producto* producto : inventario){
        QString stringItemNuevo = "Id: " + QString::number(producto->obtenerId() ) + ".      Nombre: " + QString::fromStdString(producto->obtenerNombre()) + ".      Existencias en la tienda: " + QString::number(producto->obtenerExistencias());

        QListWidgetItem *itemNuevo = new QListWidgetItem(stringItemNuevo);
        itemNuevo->setData(1, producto->obtenerId() );

        this->ui->listaProductos->addItem(itemNuevo);
    }
}

//TERMINADO
void MainWindow::mostrarInformacionTienda(string nombreTienda, string paginaWeb, string direccionFisica, string telefono){
    QFont font = this->ui->lblDireccion->font();
    font.setPointSize(12);

    this->ui->lblTienda->setFont(font);
    this->ui->lblTienda->setText("Tienda: " + QString::fromStdString(nombreTienda) );

    this->ui->lblPaginaWeb->setFont(font);
    this->ui->lblPaginaWeb->setText("Página web: " + QString::fromStdString(paginaWeb) );

    this->ui->lblDireccion->setFont(font);
    this->ui->lblDireccion->setText("Direccion física: " + QString::fromStdString(direccionFisica) );

    this->ui->lblTelefono->setFont(font);
    this->ui->lblTelefono->setText("Número telefono: " + QString::fromStdString(telefono) );



}

//TERMINADO
void MainWindow::on_btnAgregarProducto_clicked()
{
    bool productoNuevoAgregado = false;

    if(this->tienda == nullptr){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setText("Se debe crear una tienda antes de agregar un producto.");
        msgbox->open();
    }else{

        FormProducto formProducto{this};
        formProducto.setWindowTitle("Agregar nuevo producto");
        int resultado = formProducto.exec();

        string nombreProducto = formProducto.obtenerNombre();
        int idProducto = formProducto.obtenerId();
        int existencias = formProducto.obtenerExistencias();

        if(resultado == QDialog::Accepted){
            QMessageBox *msgbox = new QMessageBox(this);
            try {
                Producto *producto = new Producto(idProducto, nombreProducto, existencias);
                tienda->agregarProducto(producto);
                productoNuevoAgregado = true;

            } catch(const ExcepcionNombreProductoErroneo& e){
                msgbox->setWindowTitle("ERROR");
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionNombreProductoRepetido& e){
                msgbox->setWindowTitle("ERROR");
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionIdRepetida& e){
                msgbox->setWindowTitle("ERROR");
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionExistenciasIncorrectas& e){
                msgbox->setWindowTitle("ERROR");
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionIdIncorrecta& e){
                msgbox->setWindowTitle("ERROR");
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setText(e.what());
                msgbox->open();
            }

            if(productoNuevoAgregado){
                QString stringItemNuevo ="Id: " + QString::number(idProducto) + ".      Nombre: " + QString::fromStdString(nombreProducto) + ".      Existencias en la tienda: " + QString::number(existencias);

                QListWidgetItem *itemNuevo = new QListWidgetItem(stringItemNuevo);
                itemNuevo->setData(1, idProducto);

                this->ui->listaProductos->addItem(itemNuevo);
                std::cout << this->tienda;

                msgbox->setWindowTitle("Accion tomada");
                msgbox->setIcon(QMessageBox::Information);
                msgbox->setText("Producto creado");
                msgbox->open();
            }

        }

    }

}

//TERMINADO
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
        QString nombreProducto = QString::fromStdString(tienda->obtenerProducto(idProducto.toInt() )->obtenerNombre() );
        int existencias = tienda->obtenerProducto(idProducto.toInt() )->obtenerExistencias();

        FormProducto *formProducto = new FormProducto(this);
        formProducto->setWindowTitle("Agregar producto");
        formProducto->mostrarInformacion(idProducto, nombreProducto, existencias);
        int resultado = formProducto->exec();

        if(resultado == QDialog::Accepted){
            string nuevoNombre = formProducto->obtenerNombre();
            int nuevasExistencias = formProducto->obtenerExistencias();
            bool modificado = false;

            QMessageBox *msgbox = new QMessageBox(this);
            try {
                tienda->modificarProducto(idProducto.toInt(), idProducto.toInt(), nuevoNombre, nuevasExistencias);
                modificado = true;
            } catch(const ExcepcionNombreProductoRepetido& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionIdRepetida& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionNombreProductoErroneo& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();
            } catch(const ExcepcionExistenciasIncorrectas& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();

            } catch(const ExcepcionIdIncorrecta& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();
            }

            if(modificado){
                QString stringItem = "Id: " + idProducto + ".      Nombre: " + QString::fromStdString(nuevoNombre) + ".      Existencias en la tienda: " + QString::number(nuevasExistencias);
                itemSeleccionado->setText(stringItem);

                msgbox->setIcon(QMessageBox::Information);
                msgbox->setWindowTitle("Accion completada");
                msgbox->setText("Se ha modificado el producto correctamente");
                msgbox->open();
            }
        }
    }
}

//TERMINADO
void MainWindow::on_btnEliminarProducto_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listaProductos->currentItem();

    bool eliminado = false;
    if(itemSeleccionado == nullptr){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("No se seleccionó ningún item");
        msgbox->open();
    }else{
        QString idProducto = itemSeleccionado->data(1).toString();

        try {
            tienda->eliminarProducto(tienda->obtenerProducto(idProducto.toInt()) );
            eliminado = true;
        } catch (const ExcepcionIdInexistente& e) {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setIcon(QMessageBox::Critical);
            msgbox->setWindowTitle("ERROR");
            msgbox->setText(e.what());
            msgbox->open();
        }

        if(eliminado){
            delete this->ui->listaProductos->currentItem();
            this->ui->listaProductos->setCurrentItem(nullptr);

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setIcon(QMessageBox::Information);
            msgbox->setWindowTitle("Accion realizada");
            msgbox->setText("El producto se ha eliminado correctamente");
            msgbox->open();
        }


    }

}

//TERMINADO
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


            QMessageBox *msgbox = new QMessageBox(this);
            try {
                this->tienda = new Tienda(nombreTienda, paginaWeb, direccionFisica, telefono);

            }catch (const ExcepcionNombreTiendaErroneo& e) {
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();

            }catch (const ExcepcionDireccionWebErronea& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();

            }catch(const ExcepcionDireccionFisicaErronea& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();

            }catch(const ExcepcionTelefonoErroneo& e){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText(e.what() );
                msgbox->open();
            }

            if(tienda != nullptr){
                this->mostrarInformacionTienda(nombreTienda, paginaWeb, direccionFisica, telefono);
                msgbox->setIcon(QMessageBox::Information);
                msgbox->setWindowTitle("Accion tomada");
                msgbox->setText("Tienda creada");
                msgbox->open();
            }


        }
    }else{
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("Ya existe una tienda creada");
        msgbox->open();
    }

}

//TERMINADO
void MainWindow::on_btnImportarTienda_clicked()
{
    QMessageBox *msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Advertencia");
    msgbox->setIcon(QMessageBox::Warning);
    msgbox->setText("Esta opción sobrescribirá los datos actuales");
    msgbox->setModal(true);
    msgbox->exec();

    QString rutaArchivo = QFileDialog::getOpenFileName(this,
                "Abrir archivo de datos", "",
                tr("Archivo de datos (*.dat)") );

    if (rutaArchivo != ""){
        string stringRutaArchivo = rutaArchivo.toStdString();

        ifstream archivoEntrada;
        archivoEntrada.open(stringRutaArchivo, ios::in|ios::binary);

            if (!archivoEntrada.is_open()){
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("Error al leer archivo");
                msgbox->setText("No se ha podido abrir el archivo");
                msgbox->open();
            }

            this->tienda = new Tienda();
            this->tienda->cargarDesdeStreamBinario(&archivoEntrada);

            this->mostrarInformacionTienda(this->tienda->obtenerNombre(), this->tienda->obtenerDireccionInternet(), this->tienda->obtenerDireccionFisica(), this->tienda->obtenerTelefono() );
            this->ui->listaProductos->clear();

            mostrarProductosTienda(this->tienda->obtenerInventario());

            msgbox->setWindowTitle("Accion realizada");
            msgbox->setText("Se ha cargado la nueva tienda");
            msgbox->open();

    }

}


void MainWindow::on_btnExportarTienda_clicked()
{
    if(this->tienda == nullptr){
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setIcon(QMessageBox::Critical);
        msgbox->setText("Se debe crear una tienda antes de exportarla.");
        msgbox->setModal(true);
        msgbox->exec();
    }else{
        QString rutaArchivo = QFileDialog::getSaveFileName(this,
                "Guardar achivo de datos", "",
                tr("Archivo de datos(*.dat)") );

        if (rutaArchivo != ""){
            string stringRutaArchivo = rutaArchivo.toStdString();

            ofstream archivoSalida;
            archivoSalida.open(stringRutaArchivo, ios::out|ios::binary);

            if (!archivoSalida.is_open()){
                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setIcon(QMessageBox::Critical);
                msgbox->setWindowTitle("ERROR");
                msgbox->setText("No se puido crear el archivo");
                msgbox->open();
            }

            this->tienda->exportarEnStreamBinario(&archivoSalida);
        }
    }
}

