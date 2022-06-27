#include "Bombardment.h"

Bombardment::Bombardment()
{
	Init();
}

void Bombardment::Update()
{
	if (IsDraw && timer <= Time_Exp)
	{
		bombardment.x += SPEED;
		bombardment.y += dropSpeed;
		dropSpeed += 0.5;
		timer++;
	}
	else if (timer >=Time_Exp)
	{
		exploding = true;
		radius += BLAST;
		if (radius >= MAX_RADIUS)
		{
			Init();
		}	
	}
}

void Bombardment::Draw()
{
	if (IsDraw)
	{
		DrawCircle(bombardment.x, bombardment.y, radius, GetColor(47, 79, 79),TRUE);
	}
}

void Bombardment::Create(int rand_)
{
	IsDraw = true;
	bombardment.y = -30 + rand_ % 70;
	Time_Exp = 30 + rand_ % 15;

}

Collision::Collider::collider Bombardment::collider()
{
	if (exploding)
	{
		texSize.vec2(radius, radius);
		Col.vec = bombardment;
		Col.size = texSize;
		return Col;
	}
	return Collision::Collider::collider();
}

void Bombardment::Init()
{
	IsDraw = false;
	exploding = false;
	dropSpeed = 0;
	bombardment.x = -15;
	timer = 0;
	radius = RADIUS;
}
