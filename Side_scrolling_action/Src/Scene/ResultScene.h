#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include"SceneBase.h"
#include"../Manager/SceneManager.h"

class ResultScene:public SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene() {}

	void Update();
	void Draw();

private:

};

#endif // !RESULT_SCENE_H

