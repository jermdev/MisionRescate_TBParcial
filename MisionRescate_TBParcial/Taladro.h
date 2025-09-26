#pragma once
#include "iostream"
#include "string"
using namespace System;
using namespace std;
class Taladro
{
private:
	int x, y, dx;
	string cabeza, cuerpo, pies;
public:
	Taladro(int x, int y) {
		this->x = x;
		this->y = y;
		this->dx = 1;
		this->cabeza = "/-\\";
		this->cuerpo = "\\-/";
		this->pies = "o o";
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << cabeza;
		Console::SetCursorPosition(x, y + 1);
		cout << cuerpo;
		Console::SetCursorPosition(x, y + 2);
		cout << pies;
	}
	void borrar() {
		Console::SetCursorPosition(x, y);
		cout << "   ";
		Console::SetCursorPosition(x, y + 1);
		cout << "   ";
		Console::SetCursorPosition(x, y + 2);
		cout << "   ";
	}
	void mover(char* mapa[30][120]) {
		borrar();
		if (*mapa[y][x + 1] != ' ' || *mapa[y][x - 1] != ' ')
		{
			this->dx *= -1;
		}
		x += dx;
		dibujar();
	}
};

