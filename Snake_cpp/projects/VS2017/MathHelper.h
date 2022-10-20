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

	/*bool operator==(const Vector2Int& a, const Vector2Int& b) {
		if (a.x == b.x && a.y == b.y) {
			return true;
		}
		else {
			return false;
		}
	}*/

	bool operator==(const Vector2Int& other) {
		return (x == other.y && y == other.y);
	}

	void Show() {
		cout << x << ", " << y << endl;
	}

};

