#include <Novice.h>

#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

bool Enemy::isAlive_ = false;

const char kWindowTitle[] = "GC1B_07_ジョシュア_ジュナイディ_PG02_13-01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;

	enemy2->SetPos({ 400.0f, 300.0f });

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Update(keys, preKeys);

		///敵の移動処理
		if (enemy1 != nullptr) {
			enemy1->Move();
		}
		if (enemy2 != nullptr) {
			enemy2->Move();
		}

		///リスポーン処理
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive_ = true;
		}

		///当たり判定
		if (enemy1 != nullptr) {
			if (Collision::CollisionCheck(*enemy1, *player->bullet_)) {
				Enemy::isAlive_ = false;
			}
		}

		if (enemy2 != nullptr) {
			if (Collision::CollisionCheck(*enemy2, *player->bullet_)) {
				Enemy::isAlive_ = false;
			}
		}
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/// 
		player->Draw();

		if (enemy1 != nullptr) {
			enemy1->Draw();
		}
		if (enemy2 != nullptr) {
			enemy2->Draw();
		}
		
		Novice::ScreenPrintf(0, 0, "enemy1 isAlive: %d", Enemy::isAlive_);
		Novice::ScreenPrintf(0, 20, "enemy2 isAlive: %d", Enemy::isAlive_);
		Novice::ScreenPrintf(0, 40, "WASD : Player Move");
		Novice::ScreenPrintf(0, 60, "Shoot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemy1;
	delete enemy2;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
