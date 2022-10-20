#include "SnakeBodyPart.h"

SnakeBodyPart::SnakeBodyPart()
{
	x = 1;
	y = 1;
}

SnakeBodyPart::SnakeBodyPart(int _posX, int _posY)
{
	x = _posX;
	y = _posY;
}

SnakeBodyPart::~SnakeBodyPart()
{

}

void SnakeBodyPart::Update()
{

}

void SnakeBodyPart::Draw(Grid _grid)
{
	Vector2Int pixelPos;
	pixelPos = _grid.ConvertMCToGP({x,y});
	DrawRectangle(pixelPos.x, pixelPos.y, 32, 32, WHITE);
}
