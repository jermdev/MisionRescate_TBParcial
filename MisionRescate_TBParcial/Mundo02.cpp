#include "pch.h"
#include "Mundo02.h"

Mundo02::Mundo02() {
	palancasActivas = 8;
	jefeMinero = new JefeMinero(70, 10);
}

Mundo02::~Mundo02() {
	delete jugador;
	delete jefeMinero;

	for (Recurso* pal : palancas1 ) {
		delete pal;
	}
	for (Recurso* pal : palancas2) {
		delete pal;
	}
}

