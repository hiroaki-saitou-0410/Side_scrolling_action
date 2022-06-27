#ifndef TITLE_UI_H
#define TITLE_UI_H

#include"UIBase.h"
#include"../Manager/SceneManager.h"
#include"../Manager/CursorManager.h"

class TitleUI:public UIBase
{
public:
	TitleUI();
	virtual ~TitleUI() = default;

	void Update(bool Isbool);
	void Draw();
	//void DrawButton(int index,std::string name);

private:
	const static int ARRAY_SIZE{ 2 };

	std::weak_ptr<CursorManager>cursorManager;
	Vector2 cursorPos;
};

#endif // !TITLE_UI_H

