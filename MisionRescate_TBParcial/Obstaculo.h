#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
class Obstaculo 
{
protected:
	int x, y, alto, ancho;
	bool activo;
public:
	Obstaculo(int px, int py,int alto, int ancho) {
		this->x = px;
		this->y = py;
		this->activo = true;
		this->alto = alto;
		this->ancho = ancho;
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	bool isActivo() {
		return this->activo;
	}
	void setActivo(bool activo) {
		this->activo = activo;
	}
	virtual void dibujar() = 0;
	virtual void mover(int(*mapa)[120]) = 0;

	void borrar() {
		if (activo) {
			for (int i = 0; i < alto; i++)
			{
				for (int j = 0; j < ancho; j++)
				{
					Console::SetCursorPosition(x + j, y + i);
					cout << " ";
				}
			}
		}
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};

