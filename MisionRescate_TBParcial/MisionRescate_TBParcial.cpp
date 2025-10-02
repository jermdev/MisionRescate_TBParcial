#include "pch.h"
#include "Mundo1.h"
#include "Mundo02.h"
#include "Jugador.h"
#include "iostream"
#include "string"
#include "Mapas.h"
using namespace System;
using namespace std;

int main() {
	Console::Clear();
	Console::CursorVisible = false;
	Jugador* player = new Jugador(35, 13);
	/*Mundo1* mundo = new Mundo1(player, 88, 13);
	mundo->juegoParte1();*/
	Mundo02* mundo02 = new Mundo02(player, player->getX(), player->getY());
	mundo02->juegoParte02();

	
	return 0;
}

