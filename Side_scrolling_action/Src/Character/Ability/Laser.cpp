#include "Laser.h"

Laser::Laser()
{
	Init();

	//中心座標 0,0
	// 範囲(角度) 
	// 長さ WindowSizeY
	// 方向(角度) laser
}

void Laser::Update()
{
	if (IsDraw)
	{
		if (angle <= 90)
		{
			laser.x += cos(angle * 3.14f / 180.0f) * 70;
			//laser.y -= sin(angle * 3.14f / 180.0f) * 70;
			angle++;
		}
		else
		{
			Init();
		}
		
	}
}

void Laser::Draw()
{
	if (IsDraw)
	{
		DrawLineAA(0,0, laser.x, WindowSizeY, GetColor(0, 0, 0),15);
		//DrawLineAA(-10, -10, laser.x, WindowSizeX+ laser.y, GetColor(0, 0, 0),15);
	}
	DrawFormatStringF(50, 300, GetColor(0, 0, 0), "%d,texSizeX%d", laser.x, laser.y);
}

Collision::Collider::Fan Laser::Fan()
{
	fan.vec = {0,0};
	fan.degree = laser.x;
	fan.directionDegree = angle;
	fan.length = sqrt(WindowSizeX * WindowSizeX + WindowSizeY * WindowSizeY);
	return fan;
}

void Laser::Init()
{
	laser.vec2(0,0);
	texSize.vec2(sqrtf((laser.x * laser.x) + (WindowSizeX * WindowSizeX)), WindowSizeY);
	angle=0;
	IsDraw=false;
}
