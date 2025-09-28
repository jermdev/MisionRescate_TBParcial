#pragma once
#include "iostream"
#include "string"
#include "Obstaculo.h"
using namespace System;
using namespace std;
class Taladro : public Obstaculo
{
private:
	int x, y, dx;
	string cabeza, cuerpo, pies;
public:
	Taladro(int x, int y) : Obstaculo(x, y, 3, 3), dx(1), cabeza("/-\\"), cuerpo("\\-/"), pies("o o") {}
	void dibujar() override{
		Console::SetCursorPosition(x, y);
		cout << cabeza;
		Console::SetCursorPosition(x, y + 1);
		cout << cuerpo;
		Console::SetCursorPosition(x, y + 2);
		cout << pies;
	}
	void mover(int(*mapa)[120]) override{
		borrar();
		if (mapa[y][x + 1] != ' ' || mapa[y][x - 1] != ' ')
		{
			this->dx *= -1;
		}
		x += dx;
		dibujar();
	}
};

