#pragma once

#include <iostream>

using namespace std;

struct Vector2Int {
	int x;
	int y;

	Vector2Int operator+ (const Vector2Int& other) {
		return {x + other.x, y + other.y };
	}

	Vector2Int operator+= (const Vector2Int& other) {
		return { x += other.x, y += other.y };
	}

	void Show() {
		cout << x << ", " << y << endl;
	}

};

