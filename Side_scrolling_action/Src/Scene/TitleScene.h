#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include"SceneBase.h"
#include"../Manager/SceneManager.h"

class TitleScene:public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene() {}

	void Update();
	void Draw();
private:
	
};

#endif // !TITLE_SCENE_H
