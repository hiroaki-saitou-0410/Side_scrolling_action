#include "Runner.h"

void Runner::Update()
{
	runner.x -= SPEED;
	ScreenOut();
}

void Runner::Draw()
{
	DrawBoxAA(runner.x, runner.y, runner.x + runnerSize.x, runner.y + runnerSize.y, GetColor(255, 0, 0), TRUE);
}

void Runner::Create()
{
	runner.x=WindowSizeX + 30;
	runner.y=500;
	alive = true;
}

bool Runner::Collision(Collision::Collider::collider targetCol)
{
	if (runner.x < targetCol.vec.x + targetCol.size.x &&
		runner.y < targetCol.vec.y + targetCol.size.y &&
		runner.x + runnerSize.x > targetCol.vec.x &&
		runner.y + runnerSize.y > targetCol.vec.y)
	{
		return true;
	}
	return false;
}

bool Runner::CircleCol(Collision::Collider::collider targetCol,bool f)
{
	if (!f)
	{
		if (runner.x + targetCol.size.x < targetCol.vec.x &&
			runner.x + runnerSize.x + targetCol.size.x > targetCol.vec.x &&
			runner.y + targetCol.size.x < targetCol.vec.y &&
			runner.y + runnerSize.y + targetCol.size.x > targetCol.vec.y)
		{
			return true;
		}

		boxPoint.L_Up = sqrtf((runner.x - targetCol.vec.x) * (runner.x - targetCol.vec.x) + (runner.y - targetCol.vec.y) * (runner.y - targetCol.vec.y));
		boxPoint.L_Down = sqrtf((runner.x - targetCol.vec.x) * (runner.x - targetCol.vec.x) + (runner.y + runnerSize.y - targetCol.vec.y) * (runner.y + runnerSize.y - targetCol.vec.y));
		boxPoint.R_Up = sqrtf(((runner.x + runnerSize.x) - targetCol.vec.x) * ((runner.x + runnerSize.x) - targetCol.vec.x) + (runner.y - targetCol.vec.y) * (runner.y - targetCol.vec.y));
		boxPoint.R_Dowm = sqrtf(((runner.x + runnerSize.x) - targetCol.vec.x) * ((runner.x + runnerSize.x) - targetCol.vec.x) + (runner.y + runnerSize.y - targetCol.vec.y) * (runner.y + runnerSize.y - targetCol.vec.y));
	}
	else
	{
		if (runner.x + targetCol.size.x < targetCol.vec.xf &&
			runner.x + runnerSize.x + targetCol.size.x > targetCol.vec.xf &&
			runner.y + targetCol.size.x < targetCol.vec.yf &&
			runner.y + runnerSize.y + targetCol.size.x > targetCol.vec.yf)
		{
			return true;
		}

		boxPoint.L_Up = sqrtf((runner.x - targetCol.vec.xf) * (runner.x - targetCol.vec.xf) + (runner.y - targetCol.vec.yf) * (runner.y - targetCol.vec.yf));
		boxPoint.L_Down = sqrtf((runner.x - targetCol.vec.xf) * (runner.x - targetCol.vec.xf) + (runner.y + runnerSize.y - targetCol.vec.yf) * (runner.y + runnerSize.y - targetCol.vec.yf));
		boxPoint.R_Up = sqrtf(((runner.x + runnerSize.x) - targetCol.vec.xf) * ((runner.x + runnerSize.x) - targetCol.vec.xf) + (runner.y - targetCol.vec.yf) * (runner.y - targetCol.vec.yf));
		boxPoint.R_Dowm = sqrtf(((runner.x + runnerSize.x) - targetCol.vec.xf) * ((runner.x + runnerSize.x) - targetCol.vec.xf) + (runner.y + runnerSize.y - targetCol.vec.yf) * (runner.y + runnerSize.y - targetCol.vec.yf));
	}

	if (boxPoint.L_Up < targetCol.size.x)return true;
	if (boxPoint.L_Down < targetCol.size.x)return true;
	if (boxPoint.R_Up < targetCol.size.x)return true;
	if (boxPoint.R_Dowm < targetCol.size.x)return true;

	return false;
}

void Runner::ScreenOut()
{
	if (runner.x <= -runnerSize.x && alive)
	{
		alive = false;
	}
}

