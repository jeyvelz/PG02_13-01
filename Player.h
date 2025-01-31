#pragma once
#include "Bullet.h"

class Player {
public:
	/// <summary>
	/// 弾クラスのポインター変数
	/// </summary>
	Bullet* bullet_;

	/// <summary>
	/// プレイヤーのコンストラクタ
	/// </summary>
	Player();
	/// <summary>
	/// プレイヤーのデストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// プレイヤーの更新処理
	/// </summary>
	/// <param name="keys">キー入力</param>
	/// <param name="preKeys">前キー入力</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// プレイヤーと弾の描画処理
	/// </summary>
	void Draw();

private:
	Vector2 pos_;
	float speed_;
	float radius_;
};

