#include "Fondo.h"

Fondo::Fondo() : Entidad(0, 0, "Images/fondo.png", 1, 1)
{
}

void Fondo::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	ancho = canvas->VisibleClipBounds.Width; 
	alto = canvas->VisibleClipBounds.Height; 
	canvas->DrawImage(sprite, 0, 0, ancho, alto); 
}
