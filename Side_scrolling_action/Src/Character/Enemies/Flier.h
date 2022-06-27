#ifndef FLIER_H
#define FLIER_H

#include<cstdlib>
#include"../CharacterBase.h"
#include"../CharaDefinition.h"
#include"../../Definition.h"
#include"../Collision/Collision.h"

class Flier:public CharacterBase
{
public:
	Flier() { flierSize.vec2(25,25); }
	virtual ~Flier() {}

	void Update();
	void Draw();

	void Create();
	void Dead() { alive = false; }
	int IsAlive() { return alive; }
	bool Collision(Collision::Collider::collider playerCol);
	bool CircleCol(Collision::Collider::collider targetCol, bool f);

private:
	void ScreenOut();
	void Circle();

private:
	static const int RANGE{ 10 };
	static const int SPEED{ 5 };
	int angle{ 0 };
	Vector2 flierSize;
	Vector2 flier;
	struct BoxPoint
	{
		float R_Up;
		float R_Dowm;
		float L_Up;
		float L_Down;
	}; BoxPoint boxPoint;
};


#endif // !FLIER_H

