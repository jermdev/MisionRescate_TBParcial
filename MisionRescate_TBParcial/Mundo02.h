#pragma once
#include "ctime"
#include "conio.h"


#include "JefeMinero.h"
#include "Obstaculo.h"
#include "Roca.h"
#include "Recurso.h"
#include "Jugador.h"
#include "Mapas.h"
#include "vector"

using namespace std;

class Mundo02 {

private:

	Jugador* jugador;
	JefeMinero* jefeMinero;
	vector<Obstaculo*> rocas;
	vector<Recurso*> palancas1;
	vector<Recurso*> palancas2;

	int numeroPalancas;
	int jPosX, jPosY;
	int mPosX, mPosY;
	int palancasActivadas;
	int (*mapa02)[120];


	bool nivelCompletado;
public:

	Mundo02(Jugador *&jugador,int jPosX, int jPosY, int mPosX = 70, int mPosY = 15) {
		this->jugador = jugador;
		this->jPosX = jPosX;
		this->jPosY = jPosY;

		this->mPosX = mPosX;
		this->mPosY = mPosY;


		this->numeroPalancas = 10;
		palancasActivadas = 0;
		jefeMinero = new JefeMinero(this->mPosX, this->mPosY);
		mapa02 = nivel2;
		this->nivelCompletado = false;
	}
	~Mundo02() {
		delete jugador;
		delete jefeMinero;

		for (Recurso* pal : palancas1) {
			delete pal;
		}
		for (Recurso* pal : palancas2) {
			delete pal;
		}
	}

	void dibujarMapa() {
		Console::ForegroundColor = ConsoleColor::Cyan;
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				Console::SetCursorPosition(j, i);
				switch (mapa02[i][j]) {
				case 1: cout << (char)178; break;
				case 2: cout << (char)111; break;
				case 3: cout << (char)179; break;
				case 4: cout << (char)207; break;
				case 5: cout << (char)42; break;

				}
			}
		}
		Console::ResetColor();
	}
	void generarRocas() {
		
		static int contadorDeAparicionDeRocas;

		contadorDeAparicionDeRocas++;
		if (contadorDeAparicionDeRocas % 20 == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				Obstaculo* rJ = new Roca(1 + rand() % 48, 2);
				Obstaculo* rM = new Roca(51 + rand() % 48, 2);

				rocas.push_back(rM);
				rocas.push_back(rJ);
			}
		}
	}

	void dibujarBarraOxigeno(int segundosTotales, int segundosRestantes, int longitudBarra = 30) {
		int relleno = (longitudBarra * (segundosTotales - segundosRestantes)) / segundosTotales;

		Console::SetCursorPosition(1, 0);
		cout << "\r[";
		for (int i = 0; i < longitudBarra; ++i) {
			if (i < relleno) {

				cout << "#";
			}
			else {

				cout << " ";
			}
		}

		cout << "] " << "Oxigeno" << flush;
	}


	void colisionConPalancas() {
		static int i_comieso = 0;
		for (int i = i_comieso; i < numeroPalancas/2; i++) {

			Recurso* p1 = palancas1[i_comieso];
			Recurso* p2 = palancas2[i_comieso];

			bool colisionJugadorPalaca = jugador->getRectangle().IntersectsWith(p1->getRectangle());
			bool colisionJefeMineroPalaca = jefeMinero->getRectangle().IntersectsWith(p2->getRectangle());

			if (colisionJefeMineroPalaca && colisionJugadorPalaca) {

				p1->setDiseñoRecurzo(" ", "o", "¤");
				p2->setDiseñoRecurzo(" ", "o", "¤");

				palancasActivadas += 2;
				i_comieso++;
			}
 		}
	}

	void dibujarRocas() {
		for (int i = 0; i < rocas.size(); i++)
		{
			rocas[i]->mover(mapa02);
		}
	}
	void generarPalancas() {
		int espaciado = 7;
		int posX = 0;
		for (int i = 0; i < numeroPalancas/2; i++) {
			posX += espaciado;
			Recurso* p = new Recurso( posX, 11, "o", "|", "¤");
			p->setActivo(true);
			palancas1.push_back(p);
		}
		posX = 55;
		for (int i = 0; i < numeroPalancas/2; i++) {
			posX += espaciado;

			Recurso* p = new Recurso(posX, 11, "o", "|", "¤");
			p->setActivo(true);
			palancas2.push_back(p);
		}
	}

	void dibujarPalancas() {
		for (int i = 0; i < numeroPalancas/2; i++) {
			palancas1[i]->dibujar();
			palancas2[i]->dibujar();
		}
	}

	void dibujarInfo() {
		Console::SetCursorPosition(1, 27);
		cout << "Numero de palancas activadas " << palancasActivadas << endl;
		cout << "!Trabaja en equipo!";
	}

	void colisones(time_t &tiempoOxigeno) {
		Rectangle rectJugador = jugador->getRectangle();
		
		Rectangle rectJefeMinero = jefeMinero->getRectangle();

		Rectangle rectMapa = Rectangle(0, 8, 101, 6);

		colisionConPalancas();

		for (int i = 0; i < rocas.size(); i++)

		{
			if (rocas[i]->isActivo()) {
				Rectangle rectEnemigo = rocas[i]->getRectangle();

				if (rectMapa.IntersectsWith(rectEnemigo)) {
					int posXRoca = rocas[i]->getX();
					int posYAnteriorRoca = rocas[i]->getY() - 1;

					Console::ForegroundColor = ConsoleColor::Cyan;
					Console::SetCursorPosition(posXRoca, posYAnteriorRoca);

					switch (mapa02[posYAnteriorRoca][posXRoca]) {
					case 1: cout << (char)178; break;
					case 2: cout << (char)111; break;
					case 3: cout << (char)179; break;
					case 4: cout << (char)207; break;
					case 5: cout << (char)42; break;
					}
					Console::ResetColor();

				}

				if (rectJugador.IntersectsWith(rectEnemigo)) {
					tiempoOxigeno += 1;
				}

				if (rectJefeMinero.IntersectsWith(rectEnemigo)) {
					tiempoOxigeno += 1;
				}
			}
		}
	}

	void juegoParte02() {
		dibujarMapa();
		dibujarInfo();
		generarPalancas();
		time_t inicio = time(nullptr);
		time_t tOxigenoDisminuido = 0;
		while (true) {
			generarRocas();
			dibujarRocas();
			dibujarPalancas();
			
			if (_kbhit())
			{
				char tecla = _getch();
				jugador->mover(tecla, mapa02);
				jefeMinero->mover(tecla, mapa02);
			}

			dibujarInfo();

			colisones(tOxigenoDisminuido);
			time_t tiempoActual = time(nullptr);
			time_t tiempoTrascurrido = tiempoActual - inicio + tOxigenoDisminuido;
			dibujarBarraOxigeno(45, tiempoTrascurrido);

			if (tiempoTrascurrido >= 30) {
				jugador->setVivo(false);
				Console::Clear();
				cout << "Te quedaste sin oxigeno";
				break;
			}
			if (palancasActivadas == numeroPalancas) {
				nivelCompletado = true;
				Console::Clear();
				cout << "HAZ PASADO EL NIVEL 02";
				break;
			}
			_sleep(50);
		}
	}
};

