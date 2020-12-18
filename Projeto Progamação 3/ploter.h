#ifndef PLOTER_H
#define PLOTER_H
#include "sculptor.h"
#include <QWidget>

class Ploter : public QWidget
{
    Q_OBJECT
private:
    int dx,dy,dz;
    int x, y,z;
    int pz;
    int px,py,vz;
    bool putvoxel;
    bool putEsfera;
    bool putElipse;
    bool putCaixa;
    bool cutCaixa;
    bool cutvoxel;
    bool cutEsfera;
    bool cutElipse;
    bool clicado;
    int r;
    int rx,ry,rz;
    float corR;
    float corB;
    float corG;
    float a;
    int dimxq,dimyq,dimzq;
    Sculptor *matriz;


public:
    explicit Ploter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:
    //void mudaDimx(int dimx);
    //void mudaDimy(int dimy);
    //void mudaDimz(int dimz);
    void mudaRaio(int raio);
    void mudarx(int raiox);
    void mudary(int raioy);
    void mudarz(int raioz);
    void mudaDimxq(int _dimxq);
    void mudaDimyq(int _dimyq);
    void mudaDimzq(int _dimzq);
    void mudaPutvoxel();
    void mudaPutEsfera();
    void mudaPutElipse();
    void mudaPutCaixa();
    void mudacutvoxel();
    void mudacutEsfera();
    void mudacutElipse();
    void mudacutCaixa();
    void mudaCorR(int _corR);
    void mudaCorG(int _corG);
    void mudaCorB(int _corB);
    void mudaplanoZ(int z);
    void mudaDim(int _x,int _y,int _z);
    void salvar();
};

#endif // PLOTER_H
