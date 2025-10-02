#pragma once

using namespace System::Drawing;
class JefeMinero {

private:

	int x, y, frame;
	

public:

	JefeMinero(int x, int y): x(x), y(y) {}
	~JefeMinero();

	void dibujarAbajo(int frame);
	void dibujarArriba(int frame);
	void dibujarIzquierda(int frame);
	void dibujarDerecha(int frame);

	void dibujarFigura(char dir);

	void borrar();

	void mover(char t, int (*mapa)[120]);

	int getX();
	int  getY();

	void setX(int x);
	void setY(int y);
	Rectangle getRectangle();
};

