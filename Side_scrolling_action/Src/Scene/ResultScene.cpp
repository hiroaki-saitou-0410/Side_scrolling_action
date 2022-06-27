#include "ResultScene.h"

ResultScene::ResultScene()
{
}

void ResultScene::Update()
{
	if (inputManager.lock()->KeyPushed(KEY_INPUT_RETURN)) {
		SceneManager::Instance().lock()->SetNextScene(Scene::title);
	}
}

void ResultScene::Draw()
{
	DrawString(0, 0, "Result", GetColor(255, 255, 255));
}
