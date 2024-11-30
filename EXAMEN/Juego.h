#pragma once
#include "Fondo.h"
#include "Jugador.h"
#include "EnemigoRoca1.h"
#include "EnemigoRoca2.h"
#include <vector>
class Juego
{
private:
	Jugador* jugador;
	Fondo* fondo;
	vector <EnemigoRoca1*> rocaspatear;
	vector <EnemigoRoca2*> rocasgolpear;

public:
	Juego(int widht, int height);
	void mostrar(Graphics^ canvas);
	void mover(Graphics^ canvas);
	void moverTeclas(Graphics^ canvas, Movimiento movimiento);
	int getvidastotales();

	int rocasDestruidas;
	int golpesDados;
	int patadasDadas;

};

