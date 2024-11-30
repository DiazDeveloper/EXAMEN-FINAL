#pragma once
#include "Entidad.h"
class Fondo : public Entidad
{
public:
	Fondo(); 
	void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);

};

