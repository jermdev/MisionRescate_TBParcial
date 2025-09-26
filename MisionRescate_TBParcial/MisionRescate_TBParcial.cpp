#include "pch.h"
#include "Mundo1.h"
#include "Jugador.h"
#include "iostream"
#include "string"
using namespace System;
using namespace std;

int main() {
	Console::Clear();
	Console::CursorVisible = false;
	Jugador* player = new Jugador(88, 13);
	Mundo1* mundo = new Mundo1(player, 88, 13);
	mundo->juegoParte1();


	return 0;
}

