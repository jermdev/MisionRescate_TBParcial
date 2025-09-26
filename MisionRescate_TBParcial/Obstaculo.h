#pragma once
#include "iostream"
#include "string"
using namespace System;
using namespace std;
class Obstaculo
{
private:
	int x, y, yInicial;
	bool activo;
public:
	Obstaculo(int x, int y) {
		this->x = x;
		this->y = y;
		this->yInicial = y;
		this->activo = true;
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Gray;
		if (!activo) return;
		Console::SetCursorPosition(x, y);
		cout << (char)219;
		Console::ResetColor();
	}
	void borrar() {
		if (!activo) return;
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	void mover(int(*mapa)[120]) {
		borrar();
		if (mapa[y + 1][x] == 0 || y < 25)
		{
			y++;
			dibujar();
		}
		else
		{
			activo = false;
		}
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	bool IsActivo() {
		return this->activo;
	}
	void setActivo(bool activo) {
		this->activo = activo;
	}
	bool colisionObstaculo(int xj, int yj) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (xj == x + j && yj == y + i && activo)
				{
					return true;
				}
			}
		}
		return false;
	}
};

