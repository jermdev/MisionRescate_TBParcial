#pragma once
#include "iostream"
#include "string"
using namespace System;
using namespace std;
class Recurso
{
private:
	int x, y;
	string cabeza, cuerpo, pies;
	bool activo;
public:
	Recurso(int x, int y, string cabeza, string cuerpo, string pies) {
		this->x = x;
		this->y = y;
		this->cabeza = cabeza;
		this->cuerpo = cuerpo;
		this->pies = pies;
		this->activo = true;
	}
	void dibujar() {
		if (!activo) return; 
		Console::SetCursorPosition(x, y);
		cout << cabeza;
		Console::SetCursorPosition(x, y + 1);
		cout << cuerpo;
		Console::SetCursorPosition(x, y + 2);
		cout << pies;
	}
	void borrar() {
		if (!activo) return;
		Console::SetCursorPosition(x, y);
		cout << "   ";
		Console::SetCursorPosition(x, y + 1);
		cout << "   ";
		Console::SetCursorPosition(x, y + 2);
		cout << "   ";
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
	bool colisionRecurso(int xj, int yj) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (xj == x + j && yj == y + i)
				{
					borrar();
					return true;
				}
			}
		}
		return false;
	}
};




