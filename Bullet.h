#pragma once
#include "Vector2.h"

class Bullet {
public:
	/// <summary>
	/// 弾のコンストラクタ
	/// </summary>
	Bullet();
	/// <summary>
	/// 弾のデストラクタ
	/// </summary>
	~Bullet() = default;

	/// <summary>
	/// 弾の更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 弾の描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 弾の位置をセットする関数
	/// </summary>
	/// <param name="pos">プレイヤーの位置</param>
	void SetPos(Vector2 pos);

	Vector2 GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

private:
	/// <summary>
	///  弾のメンバー変数
	/// </summary>
	Vector2 pos_;
	float speed_;
	float radius_;
public:
	bool isShot_;
};

