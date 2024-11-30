#include "EnemigoRoca2.h"

EnemigoRoca2::EnemigoRoca2(int x, int y) : Entidad(x, y, "Images/rocagolpear.png", 1, 1)
{
	dx = 40;
}

void EnemigoRoca2::mover(Graphics^ canvas)
{
	x -= dx;
}
