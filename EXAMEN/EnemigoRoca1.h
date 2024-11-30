#pragma once
#include "Entidad.h"
class EnemigoRoca1 :  public Entidad
{
public:
	EnemigoRoca1(int x, int y); 
	void mover(Graphics^ canvas);
};

