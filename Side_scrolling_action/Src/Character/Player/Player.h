#ifndef PLAYER_H
#define PLAYER_H

#include<vector>
#include"Bullet.h"
#include"../CharacterBase.h"
#include"../../Vector2.h"
#include"../../Manager/InputManager.h"
#include"../../Manager/CursorManager.h"
#include"../../Manager/TextureManager.h"
#include"../Collision/Collision.h"

class Player:public CharacterBase
{
public:
	Player();
	virtual ~Player() { bullet.clear(); }

	void Update(bool hit_);
	void Draw(std::weak_ptr<TextureManager>textureManger);
	void BulletNoneActive(int index) { bullet.at(index).NoneActive(); }		//’e‚ÌÁ‹
	int Bullets() { return bullet.size(); }									//’e‚ÌÅ‘å”
	bool IsBulletActive(int index) { return bullet.at(index).IsAlive(); }	//’e‚Ì¶‘¶
	int HP() {return health;}
	bool GameOver() { return alive; }
	Ability UsedAbility() { return abi; }									//g‚Á‚Ä‚¢‚éƒAƒrƒŠƒeƒB
	Collision::Collider::collider BulletCollider(int index) { return bullet.at(index).Collider(); }
	Collision::Collider::collider PlayerCollider();	


private:
	void Init();
	void Status(bool hit_);

	void BulletCreate();
	void BulletUpdate();

private:
	static const int COOL_TIME{ 15 };
	static const int INIT_HEALTH{ 3 };

	std::weak_ptr<InputManager>inputManager;
	std::weak_ptr<CursorManager>cursorManager;
	std::vector<Bullet>bullet;
	Vector2 playerSize;
	Vector2 player;
	Vector2 cursor;
	int Timer{ 0 };
	int health{ 0 };
	Ability abi{none};
	Collision::Collider::collider Col;

	Vector2 barrelAnglePos;
	float radian;

};

#endif // !PLAYER_H

