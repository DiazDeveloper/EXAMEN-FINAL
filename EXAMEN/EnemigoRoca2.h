#pragma once
#include "Entidad.h"
class EnemigoRoca2 : public Entidad
{
public:
	EnemigoRoca2(int x, int y);
	void mover(Graphics^ canvas);
};

