#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include"DxLib.h"
#include"../Manager/InputManager.h"
#include"../Manager/TextureManager.h"

class SceneBase
{
public:

	SceneBase(){
		inputManager = InputManager::Instance();
		textureManger = TextureManager::Instance();
	}
	virtual ~SceneBase() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool Get() { return pause; }

protected:
	std::weak_ptr<InputManager>inputManager;
	std::weak_ptr<TextureManager>textureManger;
	bool pause{ false };
};

#endif // !SceneBase

