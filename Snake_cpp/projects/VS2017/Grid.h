#pragma once

#include <raylib.h>
#include "MathHelper.h"

class Grid
{
	int width; //need to be a multiple of 32
	int height;
	int widthPixel;
	int heightPixel;

public:
	int offsetX;
	int offsetY;

	//Grid();
	Grid(int _width, int _height);
	~Grid();

	int GetWidth() const {
		return widthPixel;
	}

	int GetHeight() const {
		return heightPixel;
	}

	int GetTileHeight() const {
		return height;
	}

	int GetTileWidth() const {
		return width;
	}

	//Convert Matrix Coord to Grid Pixel Position
	Vector2Int ConvertMCToGP(Vector2Int _matrixCoord);

	void SetTileTexture(Texture2D _texture);

	void Draw();
	void Update();
};

