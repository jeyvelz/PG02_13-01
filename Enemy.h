#pragma once
#include "Vector2.h"

class Enemy{
public: 
	/// <summary>
	/// 静的メンバー変数
	/// </summary>
	static bool isAlive_;

	/// <summary>
	/// 敵のコンストラクタ
	/// </summary>
	Enemy();

	/// <summary>
	/// 敵のデストラクタ
	/// </summary>
	~Enemy();

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();

	//描画処理
	void Draw();

	/// <summary>
	/// ゲッターとセッター
	/// </summary>
	/// <returns></returns>

	Vector2 GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }
	
	void SetPos(Vector2 pos);

private:
	Vector2 pos_;
	float speed_;
	float radius_;
};

