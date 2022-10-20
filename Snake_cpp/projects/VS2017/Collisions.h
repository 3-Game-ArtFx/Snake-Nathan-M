#pragma once

#include <raylib.h>
#include "RectangleInt.h"

class Collisions {
public:
	static bool AABBCollision(const RectangleInt& rectA, const RectangleInt& rectB) {
		int xMinA = rectA.x;
		int xMaxA = rectA.x + rectA.width;
		int yMinA = rectA.y;
		int yMaxA = rectA.y + rectA.height;
		int xMinB = rectB.x;
		int xMaxB = rectB.x + rectB.width;
		int yMinB = rectB.y;
		int yMaxB = rectB.y + rectB.height;
		bool isOutside = xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB;
		return !isOutside;
	}
};