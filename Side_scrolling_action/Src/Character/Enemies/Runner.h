#ifndef RUNNER_H
#define RUNNER_H

#include<cstdlib>
#include<math.h>
#include"../CharacterBase.h"
#include"../../Definition.h"
#include"../Collision/Collision.h"

class Runner:public CharacterBase
{
public:
	Runner() {
		runner.vec2(WindowSizeX + 30, 500);
		runnerSize.vec2(25, 25);
	}
	virtual ~Runner(){}

	void Update();
	void Draw();
	
	void Create();
	void Dead(){ alive = false; }
	int IsAlive() { return alive; }
	bool Collision(Collision::Collider::collider targetCol);
	bool CircleCol(Collision::Collider::collider targetCol, bool f);

private:
	void ScreenOut();

private:
	static const int SPEED = 2;
	Vector2 runner;
	Vector2 runnerSize;
	struct BoxPoint
	{
		float R_Up;
		float R_Dowm;
		float L_Up;
		float L_Down;
	}; BoxPoint boxPoint;
};

#endif // !RUNNER_H

