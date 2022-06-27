#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H

#include<time.h>
#include"../Singleton.h"
#include"array"
#include"../Character/Ability/HeavyBomb.h"
#include"../Character/Ability/Bombardment.h"
#include"../Character/Player/Player.h"

class AbilityManager :public Singleton<AbilityManager>
{
public:
	AbilityManager();
	~AbilityManager() {}

	void Update(std::shared_ptr<Player>player);
	void Draw();
	Collision::Collider::collider AbiCollider();
	Collision::Collider::collider BombardmentCollider(int index) { return bombardment.at(index).collider(); }
	int FireBullets() { return bullet; }		//砲撃の弾の最大数
	bool ActiveAbility(){ return activeAbility; }	//アビリティを使っているか
	bool BombExploding() { return heavy->Exploding(); }

private:
	void AbiCreate();
	void AbiUpdate();

private:
	static const int FIRE_BULLETS{ 20 };
	static const int COOL_TIME{ 10 };

	std::unique_ptr<HeavyBomb>heavy{ new HeavyBomb };
	std::array<Bombardment,FIRE_BULLETS> bombardment;
	Ability Abi{ Ability::none };
	Collision::Collider::collider Col;
	Collision::Collider::Fan fan;
	bool activeAbility;
	bool fullcreate{ true };
	int timer{ 10 };
	int bullet{ 0 };
};

#endif // !ABILITY_MANAGER_H

