#include "TitleScene.h"

TitleScene::TitleScene()
{
	//textureManger.lock()->LoadTexture("title","Res/");
}

void TitleScene::Update()
{
	if (inputManager.lock()->KeyPushed(KEY_INPUT_RETURN)) {
		SceneManager::Instance().lock()->SetNextScene(Scene::game);
	}
}

void TitleScene::Draw()
{
	DrawString(0, 0, "title", GetColor(255,255,255),TRUE);
}
