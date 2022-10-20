#include "raylib.h"
#include <string>

#include <iostream>
#include <vector>

#include "Grid.h"
#include "Apple.h"
//#include "SnakePart.h"
//#include "SnakeAll.h"
#include "Collisions.h"


using namespace std;

const int SCREEN_WIDTH = 650;
const int SCREEN_HEIGHT = 650;

int timerMovement = 0;
const int maxTimerMovement = 25; //1/6s buffer for each movement

Texture2D tileTexture;
Texture2D appleTexture;
Grid gameGrid(16, 16);

Vector2Int applePos{ 2,4 }; //from {0, 0} to {n-1, n-1}
Apple apple(gameGrid, applePos);

//SnakePart snakeCore(5, 8, true);
//vector<SnakePart*> snakeVector{ &snakeCore };

//SnakeAll snake({ 5,8 });


bool newHeadTrigger = false;


int main(int argc, char* argv[])
{
    void Update();
    void Draw();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");

    //TEXTURES LOADING
    tileTexture = LoadTexture("image/tile.png");
    appleTexture = LoadTexture("image/apple.png");

    gameGrid.SetTileTexture(tileTexture);
    apple.SetItemTexture(appleTexture);

    SetTargetFPS(60);


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Update();
        Draw();
    }

    CloseWindow();

    return 0;
}

void Update() {
    timerMovement++;

    snake.Update(gameGrid);

    /*RectangleInt appleCollider = apple.GetRect();
    RectangleInt snakeCollider = snakeVector[0]->GetRect();
    bool snakeCollideApple = appleCollider.x == snakeCollider.x && appleCollider.y == snakeCollider.y;*/

    /*for (SnakePart* sp : snakeVector) {
        cout << sp->GetPos().x << endl;
    }*/


    //if (snakeCollideApple && !newHeadTrigger) {
    //    //TP APPLE
    //    apple.Collected(gameGrid);
    //    newHeadTrigger = true;
    //    /*for (SnakePart* sp : snakeVector) {
    //        cout << sp->GetPos().x << endl;
    //    }*/
    //    //SnakePart snakeBodyPart(snakeVector[0]->GetPos(), false);
    //    //snakeVector.push_back(&snakeBodyPart);
    //    /*for (SnakePart* sp : snakeVector) {
    //        cout << sp->GetPos().x << endl;
    //    }*/

    //    //SOMEWHERE AFTER IT GET A CRAZY POSITION, like overflowing
    //    // 
    //    //ADD HEAD
    //}

    if (timerMovement >= maxTimerMovement) { //buffered update
        timerMovement = 0;
        
        snake.UpdateMovement(gameGrid);


        //if (!newHeadTrigger) {
        //    for (int n = 0; n <= snakeVector.size() - 1; n++) {
        //        if (n == 0) {
        //            snakeVector[0]->UpdateMovement(gameGrid);
        //        }  
        //        /*else if (n > 0 && snakeVector.size() > 0) {
        //            snakeVector[n]->MoveTo(snakeVector[n - 1]->GetPos());
        //        }*/
        //    }
        //}
        //else {
        //    //new head, need to be put
        //    newHeadTrigger = false;
        //    //snakeVector[0]->BecameBody();
        //    /*SnakePart snakeBodyPart(testVec, false);
        //    snakeVector.push_back(&snakeBodyPart);*/
        //    //snakeVector.insert(snakeVector.begin(), &snakeBodyPart);
        //}
        
    }
    
}

void Draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("SNAKE", (SCREEN_WIDTH / 2)-40, 25, 22, WHITE);
    gameGrid.Draw();
    apple.Draw(gameGrid);

    /*snake.Draw(gameGrid);*/

    /*if (!snake.GetHead()->IsAlive()) {
        DrawText("GAME OVER", (SCREEN_WIDTH / 2) - 80, SCREEN_HEIGHT / 2 - 50, 32, WHITE);
    }*/

    EndDrawing();
}
