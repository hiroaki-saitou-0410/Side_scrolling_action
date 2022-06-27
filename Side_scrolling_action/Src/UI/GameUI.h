#ifndef GAME_UI_H
#define GAME_UI_H

#include"UIBase.h"
#include"../Manager/SceneManager.h"

class GameUI:public UIBase
{
public:
	GameUI();
	~GameUI() = default;

	void Update(bool Isbool);
	void Draw();

private:
	const static int ARRAY_SIZE{ 2 };

	std::weak_ptr<CursorManager>cursorManager;
	Vector2 cursorPos;
	bool pause{ false };
};

#endif // !GAME_UI_H

