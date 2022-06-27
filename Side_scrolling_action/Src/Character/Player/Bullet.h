#ifndef BULLET_H
#define BULLET_H

#include<array>
#include<math.h>
#include"DxLib.h"
#include"../CharaDefinition.h"
#include"../../Vector2.h"
#include"../Collision/Collision.h"
#include"../../Manager/TextureManager.h"

class Bullet
{
public:
	Bullet() {bulletSize.vec2(2, 2); }
	~Bullet() {}

	void Update(const Vector2& CursorPos);
	void Draw(std::weak_ptr<TextureManager>textureManger);
	void Create(const Vector2& StartPos, const Vector2& playerSize);
	void NoneActive() { alive = false; }
	int IsAlive() { return alive; }
	Collision::Collider::collider Collider();
	Vector2 Pos() { return bullet; }
	float Rad() { return radian; }

private:
	void Move(const Vector2& CursorPos);
	void Delete();

private:
	static const int SPEED{ 10 };
	Vector2 bullet;
	float radian;
	float previewRadian;
	bool createBullet{ false };
	bool alive{ false };
	Vector2 bulletSize;
	Collision::Collider::collider col;
};

#endif // !BULLET_H
