#pragma once
#include "iostream"
#include "string"
using namespace System;
using namespace std;
class Jugador
{
private:
    int x, y, minero, frame;
	bool vivo;
public:
	Jugador(int x, int y) {
		this->x = x;
		this->y = y;
		this->minero = 1;
		this->vivo = true;
        this->frame = 0;
	}
	void borrar() {
		Console::SetCursorPosition(x, y);
		cout << "   ";
		Console::SetCursorPosition(x, y + 1);
		cout << "   ";
		Console::SetCursorPosition(x, y + 2);
		cout << "   ";
	}
    // --- IZQUIERDA ---
    void DibujarIzquierda(int frame) {
        if (frame == 0) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write("/| ");
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

    // --- DERECHA ---
    void DibujarDerecha(int frame) {
        if (frame == 0) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write(" |\\");
            Console::SetCursorPosition(x, y + 2); Console::Write("  \\");
        }
        else if (frame == 1) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write(" |\\");
            Console::SetCursorPosition(x, y + 2); Console::Write(" | ");
        }
        else { // frame == 2
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write(" | ");
            Console::SetCursorPosition(x, y + 2); Console::Write("  \\");
        }
    }

    // --- ARRIBA (frontal) ---
    void DibujarArriba(int frame) {
        if (frame == 0) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write("/|\\");
            Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
        }
        else if (frame == 1) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write(" | ");
            Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
        }
        else { // frame == 2
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write("\\|/");
            Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
        }
    }

    // --- ABAJO (trasera) ---
    void DibujarAbajo(int frame) {
        if (frame == 0) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write("\\|/");
            Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
        }
        else if (frame == 1) {
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write(" | ");
            Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
        }
        else { // frame == 2
            Console::SetCursorPosition(x, y);     Console::Write(" O ");
            Console::SetCursorPosition(x, y + 1); Console::Write("/|\\");
            Console::SetCursorPosition(x, y + 2); Console::Write("/ \\");
        }
    }

    void DibujarFigura(char dir) {
        switch (dir) {
        case 'a': DibujarIzquierda(frame); break;
        case 'd': DibujarDerecha(frame); break;
        case 'w': DibujarArriba(frame); break;
        case 's': DibujarAbajo(frame); break;
        }
    }
	// matriz[filas][columnas]
	// 1 = pared
    void mover(char tecla, int(*mapa)[120]) {
        borrar();
		switch (tecla) {
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
        DibujarFigura(tecla);
	}
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    int getMineros() {
        return this->minero;
    }
    bool getVivo() {
        return this->vivo;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setVivo(bool vivo) {
        this->vivo = vivo;
    }
    void perderMineros() {
        minero--;
    }
    void aumentarMineros() {
        minero++;
    }
};

