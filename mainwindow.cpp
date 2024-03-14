#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar la señal clicked de todos los botones dentro de frame_lateral
    QList<QPushButton *> botones = ui->fr_side->findChildren<QPushButton *>();
    for (QPushButton *btn : botones)
    {
        connect(btn, &QPushButton::clicked, this, [=]()
                { actualizarEstiloBoton(btn); });
    }

    //shadown
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setXOffset(5);
    shadowEffect->setYOffset(5);
    shadowEffect->setColor(QColor(0, 0, 0, 150)); // 150 for semi-transparent black color

    ui->bt_5->setGraphicsEffect(shadowEffect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEstiloBoton(QPushButton *botonPresionado)
{
    // Limpiar el estilo de todos los botones dentro de frame_lateral
    QList<QPushButton *> botones = ui->fr_side->findChildren<QPushButton *>();

    QString estilo = "QPushButton { }";
    for (QPushButton *btn : botones)
    {
        btn->setStyleSheet(estilo);
    }

    // Aplicar el estilo al botón presionado y a los botones con iconos específicos
    estilo = "QPushButton { "
             "color: #f2f2f2;"
             "}"
             "QPushButton#bt_0 {"
             "icon: url(:/img/icon_light/home.svg);"
             "}"
             "QPushButton#bt_1 {"
             "icon: url(:/img/icon_light/book.svg);"
             "}"
             "QPushButton#bt_2 {"
             "icon: url(:/img/icon_light/bar-chart-2.svg);"
             "}"
             "QPushButton#bt_3 {"
             "icon: url(:/img/icon_light/settings.svg);"
             "}"
             "QPushButton#bt_4 {"
             "icon: url(:/img/icon_light/bell.svg);"
             "}";
    botonPresionado->setStyleSheet(estilo);
}


