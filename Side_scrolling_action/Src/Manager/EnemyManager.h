#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include<vector>
#include"../Singleton.h"
#include"../Character/Ability/Laser.h"
#include"../Character/Ability/HeavyBomb.h"
#include"InputManager.h"
#include"../Character/Enemies/Runner.h"
#include"../Character/Enemies/Flier.h"
#include"../Character/Player/Player.h"
#include"AbilityManager.h"

class EnemyManager:public Singleton<EnemyManager>
{
public:
	EnemyManager();
	virtual ~EnemyManager();

	void Update(std::shared_ptr<Player> player_, std::unique_ptr<AbilityManager>& abilityManager);
	void Draw();
	void CreateEnemies();
	void UpdateEnemies();
	void EnemiesCollision();
	void BulletCollision();
	void AbiCollision(std::unique_ptr<AbilityManager>& abilityManager);
	bool HitTheEnemy() { return hit; }

private:
	std::vector<Flier>flier;
	std::vector<Runner>runner;
	std::weak_ptr<Player>player;
	std::weak_ptr<InputManager>inputManager = InputManager::Instance();
	Collision::Collider::collider playerCol;
	Collision::Collider::collider bulletCol;
	Collision::Collider::collider AbilityCol;
	Collision::Collider::collider InitCol;
	Ability abi;

	bool hit{ false };
};

#endif // !ENEMY_MANAGER_H

