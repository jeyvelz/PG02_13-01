#include "Novice.h"
#include "Player.h"

const float windowRight = 1280.0f;
const float windowLeft = 0.0f;
const float windowTop = 0.0f;
const float windowBottom = 720.0f;

Player::Player() {
	pos_ = { 400.f, 600.f };
	speed_ = 8.f;
	radius_ = 30.f;
	bullet_ = new Bullet;
}

Player::~Player() {
	delete bullet_;
}

void Player::Update(char* keys, char* preKeys) {
	/// プレイヤーの移動処理
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	/// 弾を撃つ処理
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (bullet_->isShot_ == false) {
			bullet_->SetPos({ pos_.x, pos_.y });
			bullet_->isShot_ = true;
		}
	}
	/// 弾の更新処理
	bullet_->Update();

	/// プレイヤーは画面内に移動させる
	if (pos_.x - radius_ <= windowLeft ) {
		pos_.x = windowLeft + radius_;
	}
	if (pos_.x + radius_ >= windowRight) {
		pos_.x = windowRight - radius_;
	}
	if (pos_.y - radius_ <= windowTop) {
		pos_.y = windowTop + radius_;
	}
	if (pos_.y + radius_ >= windowBottom) {
		pos_.y = windowBottom - radius_;
	}
}

void Player::Draw() {
	// 弾の描画
	bullet_->Draw();

	// プレイヤーの描画
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, GREEN, kFillModeSolid);
}