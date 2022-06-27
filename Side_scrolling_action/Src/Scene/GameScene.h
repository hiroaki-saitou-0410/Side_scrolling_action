#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include<array>
#include"SceneBase.h"
#include"../Manager/SceneManager.h"
#include"../Manager/EnemyManager.h"
#include"../Manager/AbilityManager.h"
#include"../Character/CharaDefinition.h"
#include"../Character/Player/Player.h"

class GameScene:public SceneBase
{
public:
	GameScene();
	virtual ~GameScene() {}

	void Update();
	void Draw();

private:
	static const int MAX_SHELL{ 30 };
	std::unique_ptr<EnemyManager>enemyManager{ new EnemyManager };
	std::unique_ptr<AbilityManager>abilityManager{ new AbilityManager};
	std::shared_ptr<Player>player{new Player};
	Vector2 graund;
	//bool pause{ false };
};

#endif // !GAME_SCENE_H

