#ifndef SCULPTOR_H
#define SCULPTOR_H
/**
 * @brief A estrutura voxel é ultilizada para para atribucao de caracteriticas a matriz do tipo voxel
 */
struct Voxel {
    /**
   * @brief r vai receber o valor vermelho na posicao passada da matriz de voxel
   */
  float r;
  /**
   * @brief g vai receber o valor verde na posicao passada da matriz de voxel
   */
  float g;
  /**
   * @brief b vai receber o valor azul na posicao passada da matriz de voxel
   */
  float b;
  /**
   * @brief a vai receber o nivel de trasparencia na posicao da matriz especificada
   */

  float a;
  /**
   * @brief isOn vai armazenar o valor true ou false para verificar quais voxel seram desenhados
   */
  bool isOn; // Included or not
};

/**
 * @brief A classe Sculptor serve para criar esculturas tridimensionais com voxel
 */
class Sculptor
{
protected:
  Voxel ***v;
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  /**
   * @brief Sculptor Contrutor da classe que recebe tamanho da matriz para ser alocada
   * @param _nx recebe a largura da matriz
   * @param _ny recebe a altura da matriz
   * @param _nz recebe a profundidade da matriz
   */
  Sculptor(int _nx, int _ny, int _nz);
  /**
    Destructor serve para liberar o espaço da memoria alocada
   */
  ~Sculptor();
  /**
   * @brief setColor define a cor da estura a ser desenhada
   * @param r referece ao sitema de cores RGB sendo 'r' a cor vermelha podendo variar de 0 a 1
   * @param g referece ao sitema de cores RGB sendo 'g' a cor verde podendo variar de 0 a 1
   * @param b referece ao sitema de cores RGB sendo 'b' a cor azul podendo variar de 0 a 1
   * @param alpha define a transparencia do voxel a ser desenhado podendo variar de 0 a 1
   */
  void setColor(float r, float g, float b, float alpha);
  /**
   * @brief putVoxel desenha um voxel em uma posicao especifica
   * @param x posicao x a ser desenhada
   * @param y posicao y a ser desenhada
   * @param z posicao z a ser desenhada
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief cutVoxel remove um voxel em uma posicao especifica
   * @param x posicao x a ser removida
   * @param y posicao y a ser removida
   * @param z posicao z a ser removida
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief putBox cria uma caixa em um intervalo especifico
   * @param x0 posicao inicial de x
   * @param x1 posicao final de x
   * @param y0 posicao inicial de y
   * @param y1 posicao final de y
   * @param z0 posicao inicial de z
   * @param z1 posicao final de z
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief cutBox remove uma caixa em um intervalo especifico
   * @param x0 posicao inicial de x para remocao
   * @param x1 posicao final de x para remocao
   * @param y0 posicao inicial de y para remocao
   * @param y1 posicao final de y para remocao
   * @param z0 posicao inicial de z para remocao
   * @param z1 posicao final de z para remocao
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief putSphere desenha uma espera em uma posicao especificada
   * @param xcenter recebe o centro da esfera na posicao x
   * @param ycenter recebe o centro da esfera na posicao y
   * @param zcenter recebe o centro da esfera na posicao z
   * @param radius  recebe o raio da esfera a ser desenhada
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief cutSphere remove em formato de esfera dado uma posição
   * @param xcenter recebe o centro da esfera a ser removida na posicao x
   * @param ycenter recebe o centro da esfera a ser removida na posicao y
   * @param zcenter recebe o centro da esfera a ser removida na posicao z
   * @param radius  radius  recebe o raio da esfera a ser removida
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief putEllipsoid desenha uma elipse em uma posicao espeficada
   * @param xcenter recebe o centro da elipse na posicao x
   * @param ycenter recebe o centro da elipse na posicao y
   * @param zcenter recebe o centro da elipse na posicao z
   * @param rx recebe o raio da elipese em relacao ao eixo x
   * @param ry recebe o raio da elipese em relacao ao eixo y
   * @param rz recebe o raio da elipese em relacao ao eixo z
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief cutEllipsoid remove em formato de uma elipse dado uma posicao especifica
   * @param xcenter recebe o centro da elipse a ser removida na posicao x
   * @param ycenter recebe o centro da elipse a ser removida na posicao y
   * @param zcenter recebe o centro da elipse a ser removida na posicao z
   * @param rx  recebe o raio da elipe a ser removida em relacao ao eixo x
   * @param ry  recebe o raio da elipe a ser removida em relacao ao eixo y
   * @param rz  recebe o raio da elipe a ser removida em relacao ao eixo z
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief writeOFF exporta um aquivo no formato OFF
   * @param filename recebe o nome do aquivo para ser exportado
   */
  void writeOFF(char* filename);

  bool getisOn(int x,int y,int z);

  float getR(int x,int y,int z);

  float getG(int x,int y,int z);

  float getB(int x,int y,int z);
};




#endif // SCULPTOR_H
