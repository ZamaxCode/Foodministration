#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include <QList>
#include <QVarLengthArray>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
#include <QPainter>
#include <QDateTime>

#include "producto.h"
#include "factura.h"
#include "mesa.h"
#include "productomenu.h"
#include "pedidorealizado.h"
#include "facturaimpresa.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlQueryModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inicializarListaMesas();
    void cargarMenuProductos();
    void cargarListaFacturas();
    void almacenarFacturaEnBD(const Factura f);
    void imprimirMenu();
    void imprimirPedidos();
    void validarGeneracionFactura();
    void imprimirFactura();
    void imprimirHistorialDeFacturas();
    void actualizarSemaforos(const int pos);

protected:
    void paintEvent(QPaintEvent *pe);

private slots:
    void on_mesa_1PB_clicked();

    void on_mesa_2PB_clicked();

    void on_mesa_3PB_clicked();

    void on_mesa_4PB_clicked();

    void on_mesa_5PB_clicked();

    void on_mesa_6PB_clicked();

    void on_mesa_7PB_clicked();

    void on_volverPB_clicked();

    void on_activarMesaPB_clicked();

    void on_regresarPB_clicked();

    void on_agregarPedidoSignal(int id, int cantidad);

    void on_entregarPedidoSignal(Producto p);

    void on_eliminarPedidoSignal(Producto p);

    void on_meserosCB_currentTextChanged(const QString &arg1);

    void on_facturaPB_clicked();

    void on_okPB_clicked();

    void on_historialFacturasPB_clicked();

    void on_apagarPB_clicked();

    void on_pagesSW_currentChanged(int arg1);

    void on_anteriorPB_clicked();

    void on_siguientePB_clicked();

    void on_regresarAPB_clicked();

    void on_helpPB_clicked();

private:
    Ui::MainWindow *ui;
    QList<Producto> menuProductos;
    QList<Factura> listaFacturas;
    QVarLengthArray<Mesa, 7> listaMesas;
    QSqlDatabase baseDatos;
    int mesaActual = 0;
    int id_Ticket_Producto = 1;
    int ayudaCont = 0;
};
#endif // MAINWINDOW_H
