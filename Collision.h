#pragma once
#include "Enemy.h"
#include "Bullet.h"

class Collision{
public:
	/// <summary>
	/// 当たり判定の関数
	/// </summary>
	/// <param name="enemy">敵の変数</param>
	/// <param name="bullet">弾の変数</param>
	/// <returns>true or false</returns>
	static bool CollisionCheck(const Enemy& enemy,const Bullet& bullet);
};

