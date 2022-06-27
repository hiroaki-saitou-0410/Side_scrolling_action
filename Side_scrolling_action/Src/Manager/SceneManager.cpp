#include"SceneManager.h"

SceneManager::SceneManager():
	CurrentScene(Scene::title)
{
	NextScene();
}

void SceneManager::Update()
{
	if (PreviewScene != CurrentScene)
	{
		NextScene();
	}
	pScene->Update();
	sceneUI->Update(pScene->Get());
}

void SceneManager::Draw()
{
	pScene->Draw();
	sceneUI->Draw();
}

void SceneManager::NextScene()
{	
	switch (CurrentScene)
	{
	case Scene::title:
		pScene.reset(new TitleScene);
		sceneUI.reset(new TitleUI);
		break;
	case Scene::game:
		pScene.reset(new GameScene);
		sceneUI.reset(new GameUI);
		break;
	case Scene::result:
		pScene.reset(new ResultScene);
		sceneUI.reset(new ResultUI);
		break;
	}
	PreviewScene = CurrentScene;
}
