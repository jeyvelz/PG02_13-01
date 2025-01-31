#include "Enemy.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy() {
	pos_ = { 200.0f, 200.0f };
	speed_ = 10.0f;
	radius_ = 20.0f;
	isAlive_ = true;
}

Enemy::~Enemy() {
	isAlive_ = false;
}

void Enemy::SetPos(Vector2 pos) {
	pos_ = pos;
}

void Enemy::Move() {
	if (isAlive_ == true) {
		pos_.x += speed_;
		if (pos_.x + radius_ >= 1280.0f || pos_.x - radius_ <= 0.0f) {
			speed_ = -speed_;
		}
	}
}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);
	}
}