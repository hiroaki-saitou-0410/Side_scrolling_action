#include "GameScene.h"

GameScene::GameScene()
{
	graund.vec2(0, 525);
	textureManger.lock()->LoadTexture("BackGraund", "Res/stg01_obj/mecha_tile.png");
	textureManger.lock()->LoadDivTexture("PLAYER", "Res/stg01_obj/cannon.png", 3, 3, 1, 32, 32);

}

void GameScene::Update()
{
	if (inputManager.lock()->KeyPushed(KEY_INPUT_RETURN)) {
		SceneManager::Instance().lock()->SetNextScene(Scene::result);
	}
	
	if (inputManager.lock()->KeyPushed(KEY_INPUT_P) && !pause)
	{
		pause = true;
	}
	else if (inputManager.lock()->KeyPushed(KEY_INPUT_P) && pause)
	{
		pause = false;
	}

	if (!pause)
	{
		if (!player->GameOver())
		{
			SceneManager::Instance().lock()->SetNextScene(Scene::result);
		}

		if (!inputManager.lock()->KeyHold(KEY_INPUT_Z))
		{
			player->Update(enemyManager->HitTheEnemy());
			enemyManager->Update(player, abilityManager);
			abilityManager->Update(player);
		}
	}
}

void GameScene::Draw()
{
	DrawGraph(0, 0, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(320, 0, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(640, 0, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(960,0, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(0, 320, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(320, 320, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(640, 320, textureManger.lock()->GetTexture("BackGraund"), FALSE);
	DrawGraph(960, 320, textureManger.lock()->GetTexture("BackGraund"), FALSE);

	//DrawBox(0, 0, WindowSizeX, WindowSizeY, GetColor(200, 200, 200), TRUE);//”wŒi
	
	player->Draw(textureManger);
	enemyManager->Draw();
	abilityManager->Draw();

	DrawBox(graund.x, graund.y, WindowSizeX, WindowSizeY, GetColor(150, 0, 0), TRUE);//’n–Ê
	DrawString(100, 0, "Game", GetColor(0, 0, 0));
}
