#pragma once
#include "Entidad.h"
class Jugador : public Entidad 
{

private:

	bool AtacaPatada;
	bool AtacaPunio;

public:

	Jugador(int x, int y);
	void MoverTeclar(Graphics^ canvas, Movimiento movimiento);
	Movimiento getMovimiento();
	bool getAtacaPunio();
	bool getAtacaPatada();

};

