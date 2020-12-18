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
    /**
     * @brief mudaRaio Tem como objetivo mudar o raio da esfera
     * @param raio recebe o valor do raio da esfera a ser desenhada
     */
    void mudaRaio(int raio);
    /**
     * @brief mudarx Tem como objetivo mudar o raio x da elipse
     * @param raiox recebe o raio referente ao eixo x da elipse a ser desenhada
     */
    void mudarx(int raiox);
    /**
     * @brief mudary Tem como objetivo mudar o raio y da elipse
     * @param raioy recebe o raio referente ao eixo x da elipse a ser desenhada
     */
    void mudary(int raioy);
    /**
     * @brief mudarz Tem como objetivo mudar o raio z da elipse
     * @param raioz recebe o raio referente ao eixo z da elipse a ser desenhada
     */
    void mudarz(int raioz);
    /**
     * @brief mudaDimxq Tem como objetivo mudar a dimensao x da caixa
     * @param _dimxq recebe a dimesão x da caixa a ser desenhada
     */
    void mudaDimxq(int _dimxq);
    /**
     * @brief mudaDimyq Tem como objetivo mudar a dimensao y da caixa
     * @param _dimyq recebe a dimesão y da caixa a ser desenhada
     */
    void mudaDimyq(int _dimyq);
    /**
     * @brief mudaDimzq Tem como objetivo mudar a dimensao zda caixa
     * @param _dimzq recebe a dimesão z da caixa a ser desenhada
     */
    void mudaDimzq(int _dimzq);
    /**
     * @brief mudaPutvoxel Ao ser chamada seta a funcao para desenhar um voxel
     */
    void mudaPutvoxel();
    /**
     * @brief mudaPutEsfera Ao ser chamada seta a funcao para desenhar uma esfera
     */
    void mudaPutEsfera();
    /**
     * @brief mudaPutElipse Ao ser chamada seta a funcao para desenhar uma elipse
     */
    void mudaPutElipse();
    /**
     * @brief mudaPutCaixa Ao ser chamada seta a funcao para desenhar uma caixa
     */
    void mudaPutCaixa();
    /**
     * @brief mudacutvoxel Ao ser chamada seta a funcao para remover um voxel
     */
    void mudacutvoxel();
    /**
     * @brief mudacutEsfera Ao ser chamada seta a funcao para remover uma esfera
     */
    void mudacutEsfera();
    /**
     * @brief mudacutElipse Ao ser chamada seta a funcao para remover um elipse
     */
    void mudacutElipse();
    /**
     * @brief mudacutCaixa Ao ser chamada seta a funcao para remover um caixa
     */
    void mudacutCaixa();
    /**
     * @brief mudaCorR muda o parametro de cor vermelha
     * @param _corR recebe o valor da cor vermelha
     */
    void mudaCorR(int _corR);
    /**
     * @brief mudaCorG mudaCorR muda o parametro de cor verde
     * @param _corG recebe o valor da cor verde
     */
    void mudaCorG(int _corG);
    /**
     * @brief mudaCorB mudaCorR muda o parametro de cor azul
     * @param _corB recebe o valor da cor azul
     */
    void mudaCorB(int _corB);
    /**
     * @brief mudaplanoZ Muda a profundidade do plano xy
     * @param z recebe o valor da profundidade
     */
    void mudaplanoZ(int z);
    /**
     * @brief mudaDim muda as dimesoes da matriz
     * @param _x recebe dimensao x
     * @param _y recebe dimensao y
     * @param _z recebe dimensao z
     */
    void mudaDim(int _x,int _y,int _z);
    /**
     * @brief salvar salva o arquivo no formato off
     */
    void salvar();
};

#endif // PLOTER_H
