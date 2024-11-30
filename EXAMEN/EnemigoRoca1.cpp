#include "EnemigoRoca1.h"

EnemigoRoca1::EnemigoRoca1(int x, int y) : Entidad(x, y, "Images/rocapatear.png", 1, 1)
{
	dx = 40;
}

void EnemigoRoca1::mover(Graphics^ canvas)
{
	x = -dx;
}
