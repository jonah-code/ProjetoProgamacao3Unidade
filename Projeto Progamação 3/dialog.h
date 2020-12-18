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
    /**
     * @brief pegaDimx Tem objetivo de recuperar o valor da dimesão x da  matriz
     * @return retorna o valor do elemento digitado na caixa de texto que corresponde a dimensão x da matriz
     */
    QString pegaDimx();
    /**
     * @brief pegaDimy Tem objetivo de recuperar o valor da dimesão y da  matriz
     * @return retorna o valor do elemento digitado na caixa de texto que corresponde a dimensão y da matriz
     */
    QString pegaDimy();
    /**
     * @brief pegaDimz Tem objetivo de recuperar o valor da dimesão z da  matriz
     * @return retorna o valor do elemento digitado na caixa de texto que corresponde a dimensão z da matriz
     */
    QString pegaDimz();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
