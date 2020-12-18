#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::pegaDimx()
{
    return ui->lineEditX->text();
}

QString Dialog::pegaDimy()
{
    return ui->lineEditY->text();
}

QString Dialog::pegaDimz()
{
    return ui->lineEditZ->text();
}
