#pragma once
#include "MathHelper.h"
#include "Grid.h"
#include "RectangleInt.h"
#include "WholeSnake.h"

class Apple
{
    Vector2Int mPos;

public:
    Apple(Grid _grid, Vector2Int _mPos = {0,0});
    ~Apple();

    void SetItemTexture(Texture2D _itemTexture);
    
    Vector2Int RandomPosition(Vector2Int _gridSize, WholeSnake _snake);

    void Draw(Grid _grid);
    void Update();

    void Collected(Grid _grid);
    
    RectangleInt GetRect();
};