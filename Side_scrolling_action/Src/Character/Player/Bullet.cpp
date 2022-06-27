#include "Bullet.h"

void Bullet::Update(const Vector2& EndPos)
{
	Move(EndPos);
	Delete();
}

Collision::Collider::collider Bullet::Collider()
{
	col.vec = bullet;
	col.size = bulletSize;
	return col;
}

void Bullet::Move(const Vector2& EndPos)
{
	if (createBullet)
	{
		radian = atan2(EndPos.x- bullet.xf, EndPos.y - bullet.yf);
		createBullet = false;
	}
	bullet.xf += sin(radian) * SPEED;
	bullet.yf += cos(radian) * SPEED;
}

void Bullet::Create(const Vector2& StartPos,const Vector2& playerSize)
{	
	
	if (!alive)
	{
		//player‚Ì’†SÀ•W
		Vector2 tmp = { StartPos.x + playerSize.x / 2,StartPos.y + playerSize.y / 2 };
		//Vector2 tmp = { StartPos.x ,StartPos.y};
		alive = true;
		createBullet= true;
		bullet.vec2_f(tmp.x,tmp.y);
	}
}

void Bullet::Delete()
{
	if (bullet.xf >= 1000 || bullet.xf <= 0 || bullet.yf >= 600 || bullet.yf <= 0)
	{
		alive = false;
	}
}

void Bullet::Draw(std::weak_ptr<TextureManager>textureManger)
{
	if (alive)
	{
		DrawCircle(bullet.xf, bullet.yf, bulletSize.x, GetColor(255, 255, 255));
		//DrawBoxAA(bullet.xf, bullet.yf, bullet.xf + bulletSize.x, bullet.yf + bulletSize.y, GetColor(255, 255, 255), TRUE);
		//DrawExtendGraph(bullet.xf, bullet.yf, bullet.xf + bulletSize.x, bullet.yf + bulletSize.y, textureManger.lock()->GetDivTexture("PLAYER", 2), TRUE);
	}
}
