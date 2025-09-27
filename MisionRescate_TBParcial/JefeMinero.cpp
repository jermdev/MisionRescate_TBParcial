#include "pch.h"
#include "JefeMinero.h"
#include "iostream"
#include "string"
using namespace System;
using namespace std;


void JefeMinero::dibujarAbajo(int frame) {
	
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write("\\█/");
        Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write(" █ ");
        Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/█\\");
        Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
    }
}

void JefeMinero::dibujarArriba(int frame) {
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/█\\");
        Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write(" █ ");
        Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write("\\█/");
        Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
    }
}


void JefeMinero::dibujarIzquierda(int frame) {
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/█ ");
        Console::SetCursorPosition(x, y + 2); Console::Write("/  ");
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write("/| ");
        Console::SetCursorPosition(x, y + 2); Console::Write(" | ");
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write(" | ");
        Console::SetCursorPosition(x, y + 2); Console::Write("/  ");
    }
}

void JefeMinero::dibujarDerecha(int frame) {
    if (frame == 0) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write(" █\\");
        Console::SetCursorPosition(x, y + 2); Console::Write("  \\");
    }
    else if (frame == 1) {
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write(" █\\");
        Console::SetCursorPosition(x, y + 2); Console::Write(" | ");
    }
    else { // frame == 2
        Console::SetCursorPosition(x, y);     Console::Write(" O ");
        Console::SetCursorPosition(x, y + 1); Console::Write(" █ ");
        Console::SetCursorPosition(x, y + 2); Console::Write("  \\");
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
    case 'a': dibujarIzquierda(frame); break;
    case 'd': dibujarDerecha(frame); break;
    case 'w': dibujarArriba(frame); break;
    case 's': dibujarAbajo(frame); break;
    }
}

void JefeMinero::mover(char t, int *mapa[30][120]) {
    borrar();
    switch (t) {
    case 'w':
        if (mapa[y - 1][x] == 0 && mapa[y - 1][x + 1] == 0 && mapa[y - 1][x + 2] == 0)
        {
            y--;
            frame++;
        }
        break;
    case 's':
        if (mapa[y + 1][x] == 0 && mapa[y + 1][x + 1] == 0 && mapa[y + 1][x + 2] == 0)
        {
            y++;
            frame++;
        }
        break;
    case 'a':
        if (mapa[y][x - 1] == 0 && mapa[y + 1][x - 1] == 0 && mapa[y + 2][x - 1] == 0)
        {
            x--;
            frame++;
        }
        break;
    case 'd':
        if (mapa[y][x + 1] == 0 && mapa[y + 1][x + 1] == 0 && mapa[y + 2][x + 1] == 0)
        {
            x++;
            frame++;
        }
        break;
    }
    if (frame >= 3)
    {
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