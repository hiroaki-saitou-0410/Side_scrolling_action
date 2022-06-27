#include "HeavyBomb.h"

HeavyBomb::HeavyBomb()
{
	hvyBom.x = WindowSizeX / 2;
	Init();
}

void HeavyBomb::Update()
{
	if (IsDraw && hvyBom.y <= WindowSizeY/1.5)
	{
		hvyBom.y += dropSpeed;
		dropSpeed+=0.3;
	}
	else if(hvyBom.y >= WindowSizeY / 1.5)
	{
		exploding = true;
		radius += BLAST;
		if (radius >= MAX_RADIUS)
		{
			Init();
		}
	}
}

void HeavyBomb::Draw()
{
	if (IsDraw)
	{
		DrawCircle(hvyBom.x, hvyBom.y, radius, GetColor(0, 0, 0), FALSE);
	}
}

void HeavyBomb::Init()
{
	IsDraw = false;
	exploding = false;
	radius = INIT_RADIUS;
	dropSpeed = 0;
	hvyBom.y = START_POS;
}

Collision::Collider::collider HeavyBomb::Collider()
{
	if (exploding)
	{
		texSize.vec2(radius,radius);
		Col.vec = hvyBom;
		Col.size = texSize;
		return Col;
	}
	return Collision::Collider::collider();
}

