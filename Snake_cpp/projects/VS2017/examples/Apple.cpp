#include "Apple.h"
#include <iostream>

#include <stdlib.h> 
#include <time.h>


Texture2D _appleTexture;

using namespace std;

Apple::Apple(Grid _grid, Vector2Int _mPos) {
    
    Vector2Int _gridPosMax {_grid.GetTileWidth(), _grid.GetTileHeight()};
    Vector2Int newPos = Apple::RandomPosition(_gridPosMax);
    mPos.x = newPos.x;
    mPos.y = newPos.y;
}

Apple::~Apple() {

}

//Generate a random position on my grid
Vector2Int Apple::RandomPosition(Vector2Int _gridSize) {
    
    
    Vector2Int randPos;

    srand(time(NULL));
    randPos.x = rand() % _gridSize.x;
    srand(time(NULL)*100);
    randPos.y = rand() % _gridSize.y;

    return randPos;
}

void Apple::SetItemTexture(Texture2D _textureItem) {
    _appleTexture = _textureItem;
}

void Apple::Draw(Grid _grid) {
    Vector2Int pixelPos;
    pixelPos = _grid.ConvertMCToGP(mPos);
    //cout << pixelPos.x << " " << pixelPos.y << endl;
    DrawTexture(_appleTexture, pixelPos.x, pixelPos.y, WHITE);
}

void Apple::Update() {

}

void Apple::Collected(Grid _grid) {
    cout << "Apple Collected" << endl;
    mPos = Apple::RandomPosition( { _grid.GetTileWidth(), _grid.GetTileHeight() });
}

RectangleInt Apple::GetRect() {
    return RectangleInt{ mPos.x, mPos.y, 32,32 };
}