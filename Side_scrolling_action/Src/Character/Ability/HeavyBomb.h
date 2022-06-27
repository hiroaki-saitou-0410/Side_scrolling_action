#ifndef HEAVY_BOMB_H
#define HEAVY_BOMB_H

#include"DxLib.h"
#include"../CharaDefinition.h"
#include"../../Definition.h"
#include"../../Vector2.h"
#include"../Collision/Collision.h"

class HeavyBomb
{
public:
	HeavyBomb();
	~HeavyBomb() {}

	void Update();
	void Draw();
	void Create() { IsDraw = true; }
	bool Active() { return IsDraw; }
	bool Exploding() { return exploding; }
	Collision::Collider::collider Collider();

private:
	void Init();

private:
	const float START_POS{ -20 };
	const int BLAST{ 10 };
	const int INIT_RADIUS{ 10 };
	const int MAX_RADIUS{ 600 };

	float dropSpeed;
	Vector2 hvyBom;
	Vector2 texSize;
	int radius{ 10 };
	bool exploding{ false };
	bool IsDraw;
	Collision::Collider::collider Col;
};

#endif // !HEAVY_BOMB_H


