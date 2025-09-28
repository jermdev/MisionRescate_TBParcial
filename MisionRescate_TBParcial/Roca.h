#pragma once
#include "iostream"
#include "string"
#include "Obstaculo.h"
using namespace System;
using namespace std;
class Roca : public Obstaculo
{
private:
	int yInicial;
public:
	Roca(int x, int y) : Obstaculo(x, y, 1, 1), yInicial(y) {}
	void dibujar() override{
		Console::ForegroundColor = ConsoleColor::DarkGray;
		if (!activo) return;
		Console::SetCursorPosition(x, y);
		cout << (char)219;
		Console::ResetColor();
	}
	void mover(int(*mapa)[120]) override{
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
};

