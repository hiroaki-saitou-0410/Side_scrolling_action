#ifndef LASER_H
#define LASER_H

#include<math.h>
#include"DxLib.h"
#include"../CharaDefinition.h"
#include"../../Definition.h"
#include"../../Vector2.h"
#include"../Collision/Collision.h"

class Laser
{
public:
	Laser();
	~Laser() {}

	void Update();
	void Draw();
	void Create() { IsDraw = true; }
	bool Active() { return IsDraw; }
	Collision::Collider::Fan Fan();

private:
	void Init();

private:
	Vector2 laser;
	Vector2 texSize;
	float angle;
	bool IsDraw;
	Collision::Collider::Fan fan;

};

#endif // !LASER_H
