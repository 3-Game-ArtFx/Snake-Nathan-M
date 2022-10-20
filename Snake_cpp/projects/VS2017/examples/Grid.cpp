#include "Grid.h"

int screenWidth = GetScreenWidth();
int screenHeight = GetScreenHeight();

const int tileSize = 32;

Texture2D _tileTex;

Grid::Grid(int _width, int _height) {
	width = _width;
	height = _height;
	widthPixel = width * tileSize;
	heightPixel = _height * tileSize;
	offsetX = (screenWidth - widthPixel) / 2;
	offsetY = (screenHeight - heightPixel) / 2;
}

Grid::~Grid() {

}

void Grid::SetTileTexture(Texture2D _texture) {
	_tileTex = _texture;
}

//Convert Matrix Coord to Grid Pixel Position
Vector2Int Grid::ConvertMCToGP(Vector2Int _matrixCoord) {
	return Vector2Int{ ((_matrixCoord.x * tileSize) + offsetX), ((_matrixCoord.y * tileSize) + offsetY) };
}


void Grid::Draw() {
	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	offsetX = (screenWidth - widthPixel) / 2;
	offsetY = (screenHeight - heightPixel) / 2;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			DrawTexture(_tileTex, offsetX + (i * tileSize), offsetY + (j * tileSize), GRAY);
		}
	}
}

void Grid::Update() {

}