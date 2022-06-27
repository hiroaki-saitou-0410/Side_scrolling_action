#ifndef RESULT_UI_H
#define RESULT_UI_H

#include"UIBase.h"
#include"../Manager/CursorManager.h"
#include"../Manager/SceneManager.h"

class ResultUI:public UIBase
{
public:
	ResultUI();
	~ResultUI() = default;

	void Update(bool Isbool);
	void Draw();

private:
	std::weak_ptr<CursorManager>cursorManager;
	Vector2 cursorPos;
	Vector2 boxPos;
	Vector2 boxSize;
	Vector2 centralPos;
	bool hit{ false };
};

#endif // !RESULT_UI_H

