#include "Flier.h"

void Flier::Update()
{
	Circle();
	ScreenOut();
}

void Flier::Draw()
{
	DrawBoxAA(flier.x, flier.y, flier.x + flierSize.x, flier.y + flierSize.y, GetColor(255, 0, 0), TRUE);	
}

void Flier::Create()
{
	if (!alive)
	{
		alive = true;
		int Difference = rand() % RANGE;
		flier.y = WindowSizeY/2 + 5 * Difference;
		flier.x = WindowSizeX + flierSize.x;
	}
}

bool Flier::Collision(Collision::Collider::collider targetCol)
{
	if (flier.x < targetCol.vec.x + targetCol.size.x &&
		flier.y < targetCol.vec.y + targetCol.size.y &&
		flier.x + flierSize.x > targetCol.vec.x &&
		flier.y + flierSize.y > targetCol.vec.y)
	{
		return true;
	}
	return false;
}

bool Flier::CircleCol(Collision::Collider::collider targetCol, bool f)
{
	if (!f)
	{
		if (flier.x + targetCol.size.x < targetCol.vec.x &&
			flier.x + flierSize.x + targetCol.size.x > targetCol.vec.x &&
			flier.y + targetCol.size.x < targetCol.vec.y &&
			flier.y + flierSize.y + targetCol.size.x > targetCol.vec.y)
		{
			return true;
		}

		boxPoint.L_Up = sqrtf((flier.x - targetCol.vec.x) * (flier.x - targetCol.vec.x) + (flier.y - targetCol.vec.y) * (flier.y - targetCol.vec.y));
		boxPoint.L_Down = sqrtf((flier.x - targetCol.vec.x) * (flier.x - targetCol.vec.x) + (flier.y + flierSize.y - targetCol.vec.y) * (flier.y + flierSize.y - targetCol.vec.y));
		boxPoint.R_Up = sqrtf(((flier.x + flierSize.x) - targetCol.vec.x) * ((flier.x + flierSize.x) - targetCol.vec.x) + (flier.y - targetCol.vec.y) * (flier.y - targetCol.vec.y));
		boxPoint.R_Dowm = sqrtf(((flier.x + flierSize.x) - targetCol.vec.x) * ((flier.x + flierSize.x) - targetCol.vec.x) + (flier.y + flierSize.y - targetCol.vec.y) * (flier.y + flierSize.y - targetCol.vec.y));
	}
	else
	{
		if (flier.x + targetCol.size.x < targetCol.vec.xf &&
			flier.x + flierSize.x + targetCol.size.x > targetCol.vec.xf &&
			flier.y + targetCol.size.x < targetCol.vec.y &&
			flier.y + flierSize.y + targetCol.size.x > targetCol.vec.yf)
		{
			return true;
		}

		boxPoint.L_Up = sqrtf((flier.x - targetCol.vec.xf) * (flier.x - targetCol.vec.xf) + (flier.y - targetCol.vec.yf) * (flier.y - targetCol.vec.yf));
		boxPoint.L_Down = sqrtf((flier.x - targetCol.vec.xf) * (flier.x - targetCol.vec.xf) + (flier.y + flierSize.y - targetCol.vec.yf) * (flier.y + flierSize.y - targetCol.vec.yf));
		boxPoint.R_Up = sqrtf(((flier.x + flierSize.x) - targetCol.vec.xf) * ((flier.x + flierSize.x) - targetCol.vec.xf) + (flier.y - targetCol.vec.yf) * (flier.y - targetCol.vec.yf));
		boxPoint.R_Dowm = sqrtf(((flier.x + flierSize.x) - targetCol.vec.xf) * ((flier.x + flierSize.x) - targetCol.vec.xf) + (flier.y + flierSize.y - targetCol.vec.yf) * (flier.y + flierSize.y - targetCol.vec.yf));
	}
	
	if (boxPoint.L_Up < targetCol.size.x)return true;
	if (boxPoint.L_Down < targetCol.size.x)return true;
	if (boxPoint.R_Up < targetCol.size.x)return true;
	if (boxPoint.R_Dowm < targetCol.size.x)return true;
	
	return false;
}

void Flier::ScreenOut()
{
	if (flier.x <= -flierSize.x && alive)
	{
		alive = false;
		angle = 0;
	}
}

void Flier::Circle()
{
	if (alive)
	{
		//flier.x += sin(angle * 3.14f / 180.0f) * SPEED;
		flier.y -= cos(angle * 3.14f / 180.0f) * SPEED;
		flier.x -= 2;
		angle += 5;

	}
}
