#include "mainwindow.h"
#include "ui_mainwindow.h"
# include "dialog.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSliderRx,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudarx(int)));

    connect(ui->horizontalSliderRy,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudary(int)));

    connect(ui->horizontalSliderRz,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudarz(int)));

    connect(ui->horizontalSlidercx,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaDimxq(int)));

    connect(ui->horizontalSlidercy,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaDimyq(int)));

    connect(ui->horizontalSlidercz,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaDimzq(int)));

    connect(ui->horizontalSliderCorR,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaCorR(int)));


    connect(ui->horizontalSliderCorG,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaCorG(int)));

    connect(ui->horizontalSliderCorB,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaCorB(int)));
    connect(ui->horizontalSliderPlanoz,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(mudaplanoZ(int)));

    connect(ui->pushButtonCutCaixa,
            SIGNAL(clicked()),
            ui->widget,
            SLOT(mudacutCaixa()));

    connect(ui->pushButtonCutElipse,
            SIGNAL(clicked()),
            ui->widget,
            SLOT(mudacutElipse()));

    connect(ui->pushButtonCutvoxel,
            SIGNAL(clicked()),
            ui->widget,
            SLOT(mudacutvoxel()));

    connect(ui->pushButtonCutEsfera,
            SIGNAL(clicked()),
            ui->widget,
            SLOT(mudacutEsfera()));

    connect(ui->pushButtonSavar,
            SIGNAL(clicked()),
            ui->widget,
            SLOT(salvar()));

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonMudaTamanho_clicked()
{
    Dialog d;
    d.exec();
    dimx =d.pegaDimx();
    dimy = d.pegaDimy();
    dimz = d.pegaDimz();
    ui->widget->mudaDim(dimx.toInt(),dimy.toInt(),dimz.toInt());

}


