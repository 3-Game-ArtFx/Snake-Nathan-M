#include "WholeSnake.h"

WholeSnake::WholeSnake()
{
	snakeVector.push_back(SnakeBodyPart());
	dir = { 1,0 };
	isAlive = true;
	//positionWhereToAddTail = { snakeVector[0].GetPosition().x + dir.x, snakeVector[0].GetPosition().y + dir.y };
	lastPositionOfAllBody.push_back(snakeVector[0].GetPosition());
}

WholeSnake::~WholeSnake()
{
	snakeVector.~vector();
	lastPositionOfAllBody.~vector();
}

void WholeSnake::Update(Grid _grid)
{
	if (isAlive) {
		WholeSnake::InputCheck();
		WholeSnake::OutOfBoundsCheck(_grid);
		
	}
}


void WholeSnake::InputCheck() {
	if (IsKeyDown(KEY_UP) && dir.y != 1)
		dir = { 0,-1 };
	else if (IsKeyDown(KEY_DOWN) && dir.y != -1)
		dir = { 0,1 };
	else if (IsKeyDown(KEY_LEFT) && dir.x != 1)
		dir = { -1,0 };
	else if (IsKeyDown(KEY_RIGHT) && dir.x != -1)
		dir = { 1,0 };
}

void WholeSnake::OutOfBoundsCheck(Grid _grid)
{
	SnakeBodyPart* head = &snakeVector[0];

	//cout << head.x << endl;
	if (head->GetPosition().x < 0 || head->GetPosition().x >= _grid.GetTileWidth() || head->GetPosition().y < 0 || head->GetPosition().y >= _grid.GetTileHeight()) {
		cout << "DEAD" << endl;
		isAlive = false;
	}
}

void WholeSnake::HeadCollideWithBodyCheck()
{
	SnakeBodyPart* head = &snakeVector[0];

	for (int i = 1; i < snakeVector.size(); i++) {
		if (head->GetPosition().x == snakeVector[i].GetPosition().x && head->GetPosition().y == snakeVector[i].GetPosition().y)
		{
			cout << "DEAD" << endl;
			isAlive = false;
		}
	}
}



void WholeSnake::AddTail(int _x, int _y) //actually it add a tail but it's ok
{
	//snakeVector.insert(snakeVector.begin(), SnakeBodyPart(_x, _y));
	snakeVector.push_back(SnakeBodyPart(_x, _y));
	cout << "NEW BODY" << endl;

}

void WholeSnake::UpdateMovement(Grid _grid)
{
	WholeSnake::SaveAllPosition(); //save all the current positions

	SnakeBodyPart* head = &snakeVector[0];
	head->AddToPosition(dir.x, dir.y);

	if (snakeVector.size() > 1) {
		for (int n = 1; n < snakeVector.size(); n++) {
			snakeVector[n].SetPosition(lastPositionOfAllBody[n - 1].x, lastPositionOfAllBody[n - 1].y);
		}
	}

	WholeSnake::HeadCollideWithBodyCheck();
}


void WholeSnake::Draw(Grid _grid)
{
	if (isAlive) {
		for (SnakeBodyPart _body : snakeVector) {
			_body.Draw(_grid);
		}
	}
}
