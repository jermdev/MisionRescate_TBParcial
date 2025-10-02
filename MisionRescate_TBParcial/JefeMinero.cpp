#include "pch.h"
#include "JefeMinero.h"
#include "iostream"
#include "string"
using namespace System;
using namespace std;


void JefeMinero::dibujarAbajo(int frame) {
	
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     cout << " O " ;
        Console::SetCursorPosition(x, y + 1); cout << "\\▓/" ;
        Console::SetCursorPosition(x, y + 2); cout << "/ \\" ;
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << " ▓ ";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << "/Q\\";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
}

void JefeMinero::dibujarArriba(int frame) {
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << "/Q\\";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << " Q ";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << "\\Q/";
        Console::SetCursorPosition(x, y + 2); cout << "/ \\";
    }
}


void JefeMinero::dibujarIzquierda(int frame) {
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << "/▓ ";
        Console::SetCursorPosition(x, y + 2); cout << "/  ";
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << "/▓ ";
        Console::SetCursorPosition(x, y + 2); cout << " | ";
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     cout << " O " ;
        Console::SetCursorPosition(x, y + 1); cout << " Q " ;
        Console::SetCursorPosition(x, y + 2); cout << "/  " ;
    }
}

void JefeMinero::dibujarDerecha(int frame) {
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << " ▓\\";
        Console::SetCursorPosition(x, y + 2); cout << "  \\";
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << " ▓\\";
        Console::SetCursorPosition(x, y + 2); cout << " | ";
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     cout << " O ";
        Console::SetCursorPosition(x, y + 1); cout << " Q ";
        Console::SetCursorPosition(x, y + 2); cout << "  \\";
    }
}

void JefeMinero::borrar() {
	Console::SetCursorPosition(x, y);
	cout << "   ";
	Console::SetCursorPosition(x, y + 1);
	cout << "   ";
	Console::SetCursorPosition(x, y + 2);
	cout << "   ";
}

void JefeMinero::dibujarFigura( char dir ) {
    switch (dir) {
    case 72: dibujarArriba(JefeMinero::frame); break;
    case 80: dibujarAbajo(JefeMinero::frame); break;
    case 77: dibujarDerecha(JefeMinero::frame); break;
    case 75: dibujarIzquierda(JefeMinero::frame); break;
    }
}

void JefeMinero::mover(char t, int (*mapa)[120]) {

    if (t != 72 && t != 80 && t != 77 && t != 75) {
        return;
    }


    borrar();
    switch (t) {
    case 72:
        if (mapa[y - 1][x] == 0 && mapa[y - 1][x + 1] == 0 && mapa[y - 1][x + 2] == 0)
        {
            y--;
            frame++;
        }
        break;
    case 80:
        if (mapa[y + 1][x] == 0 && mapa[y + 1][x + 1] == 0 && mapa[y + 1][x + 2] == 0)
        {
            y++;
            frame++;
            
        }
        break;
    case 75:
        if (mapa[y][x - 1] == 0 && mapa[y + 1][x - 1] == 0 && mapa[y + 2][x - 1] == 0)
        {
            x--;
            frame++;
        }
        break;
    case 77:
        if (mapa[y][x + 1] == 0 && mapa[y + 1][x + 1] == 0 && mapa[y + 2][x + 1] == 0)
        {
            x++;
            frame++;
        }
        break;
    }
    if (JefeMinero::frame >= 3) {
        this->frame = 0;
    }
    dibujarFigura(t);
}

int JefeMinero::getX() {
	return this->x;
}

int JefeMinero::getY() {
	return this->y;
}

void JefeMinero::setX(int x) { this->x = x; }
void JefeMinero::setY(int y) { this->y = y; }

Rectangle JefeMinero::getRectangle() {
    return Rectangle(x, y, 3, 3);
}