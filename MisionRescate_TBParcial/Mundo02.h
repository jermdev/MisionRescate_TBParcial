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

	Mundo02(){}
	~Mundo02(){}

	void setJugador() {}
	void dibujarMapa(){}
	void generarObstaculos(){}
	void generarPalancas() {}

	void dibujarInfo() {}

	void juegoParte02() {}
};

