#ifndef DIALOG_H
#define DIALOG_H
#include <QString>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString pegaDimx();
    QString pegaDimy();
    QString pegaDimz();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
