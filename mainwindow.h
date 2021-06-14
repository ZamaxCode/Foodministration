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
#include <QDir>
#include <QPainter>

#include "producto.h"
#include "factura.h"
#include "mesa.h"
#include "productomenu.h"

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
    void imprimirMenu();

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

private:
    Ui::MainWindow *ui;
    QList<Producto> menuProductos;
    QList<Factura> listaFacturas;
    QVarLengthArray<Mesa, 7> listaMesas;
    QSqlDatabase baseDatos;
    int mesaActual = 0;
};
#endif // MAINWINDOW_H
