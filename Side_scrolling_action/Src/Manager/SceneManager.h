#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include"../Definition.h"
#include"../Singleton.h"
#include"../Manager/UIManager.h"
#include"../Scene/SceneBase.h"
#include"../Scene/TitleScene.h"
#include"../Scene/GameScene.h"
#include"../Scene/ResultScene.h"

class SceneManager :public Singleton<SceneManager>
{
public:

	SceneManager();
	virtual ~SceneManager() {}

	 void Update();
	 void Draw();
	 void NextScene();
	 
	 bool Exit() { return sceneUI->Exit(); }
public:
	 void SetNextScene(const Scene& scene) { CurrentScene = scene; }

private:
	std::shared_ptr<SceneBase> pScene;
	std::unique_ptr<UIBase> sceneUI;

	Scene PreviewScene;
	Scene CurrentScene;

};

#endif // !

