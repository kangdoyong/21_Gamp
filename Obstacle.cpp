#include "Obstacle.h"

void Obstacle::Initialize()
{
	info.sizeX = 75;
	info.sizeY = 100;
	info.posX = WIN_SIZE_X / 2;
	info.posY = WIN_SIZE_Y / 2 - 200;
}

void Obstacle::Update()
{
}

void Obstacle::Render(HDC hdc)
{
	Rectangle(hdc, info.posX - info.sizeX,
		info.posY - info.sizeY,
		info.posX + info.sizeX,
		info.posY + info.sizeY);
}

void Obstacle::Release()
{
}

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}
