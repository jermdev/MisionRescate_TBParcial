#pragma once
#include "JefeMinero.h"
#include "Obstaculo.h"
#include "Recurso.h"
#include "Jugador.h"
#include "vector"

using namespace std;

class Mundo02 {

private:

	Jugador* jugador;
	JefeMinero* jefeMinero;
	vector<Obstaculo*> obstaculos;
	vector<Recurso*> palancas1;
	vector<Recurso*> palancas2;

	int palancasActivas;
	int** mapa02[30][130];

public:

	Mundo02() {
		palancasActivas = 8;
		jefeMinero = new JefeMinero(70, 10);
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

	void setJugador();
	void dibujarMapa();
	void generarObstaculos();
	void generarPalancas();

	void dibujarInfo();

	void juegoParte02();
};

