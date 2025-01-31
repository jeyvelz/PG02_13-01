#include "Collision.h"
#include <iostream>

bool Collision::CollisionCheck(const Enemy& enemy, const Bullet& bullet) {
	float x = enemy.GetPos().x - bullet.GetPos().x;
	float y = enemy.GetPos().y - bullet.GetPos().y;

	float distance = sqrtf(x * x + y * y);
	float minDistance = bullet.GetRadius() + enemy.GetRadius();

	if (minDistance >= distance) {

		return true;
	}
	return false;
}
