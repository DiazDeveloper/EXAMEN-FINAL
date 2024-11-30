#include "Jugador.h"

Jugador::Jugador(int x, int y) : Entidad(x, y, "Images/jugador.png", 4, 4)
{
	dx = 10;
	movimiento = Derecha;
}

void Jugador::MoverTeclar(Graphics^ canvas, Movimiento movimiento)
{
	this->movimiento = movimiento;
	
	switch (movimiento)
	{
	case Derecha:
		x += dx;
		indiceAlto = 0;
		break;

	case Izquierda:
		x -= dx;
		indiceAlto = 1;
		break;

	case AtaquePunio:
		indiceAlto = 2;
		break;

	case AtaquePatada:
		indiceAlto = 3;
		break; 

	default:
		break;
	}

	if (x < 0)
	{
		x = 0;
	}

	if (x + ancho > canvas->VisibleClipBounds.Width)
	{
		x = canvas->VisibleClipBounds.Width - ancho;
	}

	indiceAncho++;
	if (indiceAncho > 3)
	{
		indiceAncho = 0;
	}

	if (movimiento == AtaquePatada)
	{
		AtacaPatada = true;
	}

	if (movimiento == AtaquePunio)
	{
		AtacaPunio = true;
	}

}

Movimiento Jugador::getMovimiento()
{
	return this->movimiento; 
}

bool Jugador::getAtacaPunio()
{
	return AtacaPunio;
}

bool Jugador::getAtacaPatada()
{
	return AtacaPatada;
}



