#include "Juego.h"

Juego::Juego(int widht, int height)
{
	fondo = new Fondo();
	jugador = new Jugador(80, 820);

	Random r;
	for (int i = 0; i < 4; i++)
	{
		int posX = (widht / 2) + r.Next(100, 200); 
		int posY = jugador->getY();          
		rocasgolpear.push_back(new EnemigoRoca2(posX, posY)); 
	}

	for (int i = 0; i < 4; i++)
	{
		int posX = (widht / 2) + r.Next(100, 200); 
		int posY = jugador->getY();            
		rocaspatear.push_back(new EnemigoRoca1(posX, posY));
	}

}

void Juego::mostrar(Graphics^ canvas)
{
	fondo->mostrar(canvas);
	jugador->mostrar(canvas);

	for (int i = 0; i < rocasgolpear.size(); i++)
	{
		rocasgolpear[i]->mostrar(canvas);
	}

	for (int i = 0; i < rocaspatear.size(); i++)
	{
		rocaspatear[i]->mostrar(canvas);  
	}
}

void Juego::mover(Graphics^ canvas)
{
	for (int i = 0; i < rocasgolpear.size(); i++)
	{
		rocasgolpear[i]->mover(canvas);
	}

	for (int i = 0; i < rocaspatear.size(); i++)
	{
		rocaspatear[i]->mover(canvas); 
	}

	for (int i = 0; i < rocasgolpear.size(); i++)
	{
		if (rocasgolpear[i]->hayColision(jugador) && jugador->getAtacaPunio())
		{
			delete rocasgolpear[i];
			rocasgolpear.erase(rocasgolpear.begin() + i);
			break;
		}
	}

	for (int i = 0; i < rocaspatear.size(); i++)
	{
		if (rocaspatear[i]->hayColision(jugador) && jugador->getAtacaPatada())
		{
			delete rocaspatear[i];
			rocaspatear.erase(rocaspatear.begin() + i);
			break;
		}
	}

	for (int i = 0; i < rocasgolpear.size(); i++)
	{
		if (rocasgolpear[i]->hayColision(jugador))
		{
			jugador->setVidas(jugador->getVidas() - 1);
			delete rocasgolpear[i];
			rocasgolpear.erase(rocasgolpear.begin() + i);
			break;
		}
	}

	for (int i = 0; i < rocaspatear.size(); i++)
	{
		if (rocaspatear[i]->hayColision(jugador))
		{
			jugador->setVidas(jugador->getVidas() - 1);
			delete rocaspatear[i];
			rocaspatear.erase(rocaspatear.begin() + i);
			break;
		}
	}

}

void Juego::moverTeclas(Graphics^ canvas, Movimiento movimiento)
{
	jugador->MoverTeclar(canvas, movimiento);
}

int Juego::getvidastotales()
{
	return jugador->getVidas(); 
}
