#ifndef BOMBARDMENT_H 
#define BOMBARDMENT_H

#include<stdlib.h>
#include"DxLib.h"
#include"../CharaDefinition.h"
#include"../../Definition.h"
#include"../../Vector2.h"
#include"../Collision/Collision.h"

class Bombardment
{
public:
	Bombardment();
	~Bombardment() {}

	void Update();
	void Draw();
	void Create(int rand_);
	int Active() { return IsDraw; }
	bool Exploding() { return exploding; }
	Collision::Collider::collider collider();

private:
	void Init();

private:
	const int MAX_RADIUS{ 100 };
	const int RADIUS{ 10 };
	const int SPEED{ 15 };
	const int BLAST{ 10 };

	float dropSpeed;
	int Time_Exp{ 0 };
	int timer{ 0 };
	int radius{ 0 };
	bool IsDraw;
	bool exploding{ false };
	Vector2 bombardment;
	Vector2 texSize;
	Collision::Collider::collider Col;
};

#endif // !BOMBARDMENT_H

