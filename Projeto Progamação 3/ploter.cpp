#include "ploter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include "mainwindow.h"
#include "qdebug.h"
#include "cmath"
#include "sculptor.h"
#include <QMouseEvent>
#define PI 3.14


Ploter::Ploter(QWidget *parent) : QWidget(parent)
{

     x=10;
     y=10;
     z=10;
     pz=0;
     r=0;
     rx=0;
     ry=0;
     rz=0;
     corR=0;
     corB=0;
     corG=0;
     a=1;
     dimxq=0;
     dimyq=0;
     dimyq=0;
     putvoxel=false;
     putEsfera= false;
     putElipse = false;
     putCaixa = false;
     putCaixa = false;
     cutCaixa = false;
     cutvoxel = false;
     cutEsfera = false;
     cutElipse = false;
     clicado = false;
     matriz= new Sculptor(x,y,z);

}

void Ploter::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor((QColor(0,0,0)));
    pen.setWidth(2);
    painter.setBrush((brush));
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());
    int larg = width() - width()%x;
    int alt = height() - height()%y;

    for(int i=0;i<larg;i+=larg/x){
        painter.drawLine(i,0,i,alt-2);
    }
    for(int i=0;i<alt;i+=alt/y){
        painter.drawLine(0,i,larg-2,i);

        for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    if(matriz->getisOn(i,j,pz)){
                        brush.setColor(QColor(matriz->getR(i,j,pz)*255,matriz->getG(i,j,pz)*255,matriz->getB(i,j,pz)*255));
                        painter.setBrush(brush);
                        painter.drawRect(i*(larg/x),j*(alt/y),larg/x,alt/y); // pinta o quadrado
                    }
                }
            }
    }
   /*
    for(int i=0;i<x;i++){
           for(int j=0;j<y;j++){
                   painter.drawRect(i*(larg/x),j*(alt/y),larg/x,alt/y); // pinta o quadrado


                   if(clicado){
                       for(int i=0;i<x;i++){
                              for(int j=0;j<y;j++){
                       brush.setColor(QColor(100,0,0));
                       painter.setBrush(brush);
                       painter.drawRect(i*(larg/x),j*(alt/y),larg/x,alt/y);
                               }
                        }
                   }

               }
           }

    pen.setColor(QColor(255,180,0));
    painter.setPen(pen);
    painter.drawLine(0,height()/2,width(),height()/2);
    x1 = 0;
    y1 = height()/2;
    for(int i=1; i<width();i++){
        x2 = i;
        y2 = height()/2*(1- amplitude*sin(2*PI*x2/width()));
        painter.drawLine(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
    }*/
}

void Ploter::mousePressEvent(QMouseEvent *event)
{
    px=(event->x())/(width()/x);
    py=(event->y())/(height()/y); //calcula em que quadrado na vertica se encontra o mouse
    if(putvoxel){
        matriz->setColor(corR,corG,corB,a);
        //qDebug()<<"dentro";
       // qDebug()<<px;
        //qDebug()<<py;
        //qDebug()<<z;
        //qDebug()<<corR;
        //qDebug()<<corG;
        //qDebug()<<corB;
        matriz->putVoxel(px,py,pz);
        repaint();

    }if(putEsfera){
        matriz->setColor(corR,corG,corB,a);
        qDebug() <<px;
        matriz->putSphere(px,py,pz,r);
        repaint();
        qDebug() <<r;
    }if(putElipse){
        matriz->setColor(corR,corG,corB,a);
        qDebug() <<px;
        qDebug() <<rx;
        qDebug() <<ry;
        qDebug() <<rz;
        matriz->putEllipsoid(px,py,pz,rx,ry,rz);
        repaint();
    }
    if(putCaixa){
        matriz->setColor(corR,corG,corB,a);
        clicado = true;
        qDebug() <<px;
        qDebug() <<py;
        qDebug() <<z;
        matriz->putBox(px,px+dimxq,py,py+dimyq,pz,pz+dimzq);
        repaint();
    }
    if(cutvoxel){
        qDebug()<<"dentro";
        qDebug()<<px;
        qDebug()<<py;
        qDebug()<<z;
        matriz->cutVoxel(px,py,pz);
        repaint();

    }if(cutEsfera){
        qDebug() <<px;
        matriz->cutSphere(px,py,pz,r);
        repaint();
        qDebug() <<r;
    }if(cutElipse){
        qDebug() <<px;
        qDebug() <<rx;
        qDebug() <<ry;
        qDebug() <<rz;
        matriz->cutEllipsoid(px,py,pz,rx,ry,rz);
        repaint();
    }
    if(cutCaixa){        
        qDebug() <<px;
        qDebug() <<py;
        qDebug() <<dimxq;
        qDebug() <<dimyq;
        qDebug() <<dimzq;
        matriz->cutBox(px,px+dimxq,py,py+dimyq,pz,pz+dimzq);
        repaint();
    }

}

void Ploter::mouseMoveEvent(QMouseEvent *event)
{
    px=(event->x())/(width()/x);
    py=(event->y())/(height()/y);

    if(putvoxel){

        matriz->setColor(corR,corG,corB,a);
       // qDebug()<<"dentro";
        //qDebug()<<px;
       // qDebug()<<py;
        //qDebug()<<z;
        //qDebug()<<corR;
        //qDebug()<<corG;
        //qDebug()<<corB;
        matriz->putVoxel(px,py,pz);
        repaint();

    }if(putEsfera){
        matriz->setColor(corR,corG,corB,a);
        qDebug() <<px;
        matriz->putSphere(px,py,pz,r);
        repaint();
        qDebug() <<r;
    }if(putElipse){
        matriz->setColor(corR,corG,corB,a);
        qDebug() <<px;
        qDebug() <<rx;
        qDebug() <<ry;
        qDebug() <<rz;
        matriz->putEllipsoid(px,py,pz,rx,ry,rz);
        repaint();
    }
    if(putCaixa){
        matriz->setColor(corR,corG,corB,a);
        clicado = true;
        qDebug() <<px;
        qDebug() <<py;
        qDebug() <<z;
        matriz->putBox(px,px+dimxq,py,py+dimyq,pz,pz+dimzq);
        repaint();
    }
    if(cutvoxel){
        qDebug()<<"dentro";
        qDebug()<<px;
        qDebug()<<py;
        qDebug()<<z;
        matriz->cutVoxel(px,py,pz);
        repaint();

    }if(cutEsfera){
        qDebug() <<px;
        matriz->cutSphere(px,py,pz,r);
        repaint();
        qDebug() <<r;
    }if(cutElipse){
        qDebug() <<px;
        qDebug() <<rx;
        qDebug() <<ry;
        qDebug() <<rz;
        matriz->cutEllipsoid(px,py,pz,rx,ry,rz);
        repaint();
    }
    if(cutCaixa){
        qDebug() <<px;
        qDebug() <<py;
        qDebug() <<dimxq;
        qDebug() <<dimyq;
        qDebug() <<dimzq;
        matriz->cutBox(px,px+dimxq,py,py+dimyq,pz,pz+dimzq);
        repaint();
    }

}

void Ploter::mudaDimx(int dimx)
{
    x=dimx;
    repaint();
}

void Ploter::mudaDimy(int dimy)
{
    y=dimy;
    repaint();
}

void Ploter::mudaDimz(int dimz)
{
    z=dimz;
    repaint();
}

void Ploter::mudaRaio(int raio)
{
    r=raio;
}

void Ploter::mudarx(int raiox)
{
    rx=raiox;
}
void Ploter::mudary(int raioy)
{
    ry=raioy;
}
void Ploter::mudarz(int raioz)
{
    rz=raioz;
}

void Ploter::mudaDimxq(int _dimxq)
{
    dimxq=_dimxq;
}

void Ploter::mudaDimyq(int _dimyq)
{
    dimyq=_dimyq;
}

void Ploter::mudaDimzq(int _dimzq)
{
    dimzq=_dimzq;
}

void Ploter::mudaPutvoxel()
{
    qDebug()<<"clicado";
    putvoxel=true;
    putEsfera= false;
    putElipse = false;
    putCaixa = false;
    cutCaixa = false;
    cutvoxel = false;
    cutEsfera = false;
    cutElipse = false;
}

void Ploter::mudaPutEsfera()
{
    qDebug()<<"clicado";
    putvoxel=false;
    putEsfera= true;
    putElipse = false;
    putCaixa = false;
    cutCaixa = false;
    cutvoxel = false;
    cutEsfera = false;
    cutElipse = false;
}

void Ploter::mudaPutElipse()
{
    qDebug()<<"clicado";
    putvoxel=false;
    putEsfera= false;
    putElipse = true;
    putCaixa = false;
    cutCaixa = false;
    cutvoxel = false;
    cutEsfera = false;
    cutElipse = false;
}

void Ploter::mudaPutCaixa()
{
    qDebug()<<"clicado";
    putvoxel=false;
    putEsfera= false;
    putElipse = false;
    putCaixa = true;
    cutCaixa = false;
    cutvoxel = false;
    cutEsfera = false;
    cutElipse = false;
}

void Ploter::mudacutvoxel()
{
    qDebug()<<"clicou";
    putvoxel=false;
    putEsfera= false;
    putElipse = false;
    putCaixa = false;
    cutCaixa = false;
    cutvoxel = true;
    cutEsfera = false;
    cutElipse = false;
}

void Ploter::mudacutEsfera()
{
    qDebug()<<"clicou";
    putvoxel=false;
    putEsfera= false;
    putElipse = false;
    putCaixa = false;
    cutCaixa = false;
    cutvoxel = false;
    cutEsfera = true;
    cutElipse = false;
}

void Ploter::mudacutElipse()
{
    qDebug()<<"clicou";
    putvoxel=false;
    putEsfera= false;
    putElipse = false;
    putCaixa = false;
    cutCaixa = false;
    cutvoxel = false;
    cutEsfera = false;
    cutElipse = true;
}

void Ploter::mudacutCaixa()
{
    qDebug()<<"clicou";
    putvoxel=false;
    putEsfera= false;
    putElipse = false;
    putCaixa = false;
    cutCaixa = true;
    cutvoxel = false;
    cutEsfera = false;
    cutElipse = false;
}

void Ploter::mudaCorR(int _corR)
{
    corR=_corR/99.0;
}

void Ploter::mudaCorG(int _corG)
{
    corG=_corG/99.0;
}

void Ploter::mudaCorB(int _corB)
{
    corB=_corB/99.0;
}

void Ploter::mudaplanoZ(int _z)
{
    pz=_z;
    repaint();
}

void Ploter::mudaDim(int _x,int _y,int _z)
{
    delete matriz;
    x =_x;
    y=_y;
    z=_z;
    matriz = new Sculptor(x,y,z);
}
void Ploter::salvar()
{
    matriz->writeOFF("C:/Users/jns44/Desktop/teste10.off");
}
