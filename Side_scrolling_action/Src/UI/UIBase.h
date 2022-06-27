#ifndef UI_BASE_H
#define UI_BASE_H

#include"DxLib.h"
#include"../Definition.h"
#include"../Vector2.h"
#include"../Manager/CursorManager.h"

class UIBase
{
public:
	UIBase() {
		cursorManager = CursorManager::Instance();
	}
	virtual ~UIBase() = default;

	virtual void Update(bool pause) {}
	virtual void Draw() = 0;

	bool Exit() { return exit; }

	bool CursorHit(Vector2 pos, Vector2 centralPos, Vector2 targetboxPos)
	{
		if (pos.x - centralPos.x < targetboxPos.x &&
			pos.y - centralPos.y < targetboxPos.y &&
			pos.x + centralPos.x > targetboxPos.x &&
			pos.y + centralPos.y > targetboxPos.y)
		{
			return true;
		}
		return false;
	}

protected:

	//@brief É{É^ÉìÇ∆ï∂éöÇÃê∂ê¨
	//@param index îzóÒî‘çÜ
	//@param name ï∂éö
	void DrawButton(int index, std::string name)
	{
		if (!hit.at(index))
		{
			DrawBox(boxPos.at(index).x - centralPos.at(index).x, boxPos.at(index).y - centralPos.at(index).y, boxPos.at(index).x + centralPos.at(index).x, boxPos.at(index).y + centralPos.at(index).y, GetColor(255, 255, 255), FALSE);
			DrawString(boxPos.at(index).x - centralPos.at(index).x, boxPos.at(index).y - centralPos.at(index).y, name.c_str(), GetColor(255, 255, 255));
		}
		else {
			DrawBox(boxPos.at(index).x - centralPos.at(index).x, boxPos.at(index).y - centralPos.at(index).y, boxPos.at(index).x + centralPos.at(index).x, boxPos.at(index).y + centralPos.at(index).y, GetColor(0, 0, 0), TRUE);
			DrawString(boxPos.at(index).x - centralPos.at(index).x, boxPos.at(index).y - centralPos.at(index).y, name.c_str(), GetColor(255, 255, 255));
		}
	}
	
private:
	std::weak_ptr<CursorManager>cursorManager;

protected:
	const static int ARRAY_SIZE{ 2 };

	bool exit{ false };
	std::array<Vector2, ARRAY_SIZE>boxPos;
	std::array<Vector2, ARRAY_SIZE>centralPos;
	std::array<Vector2, ARRAY_SIZE>boxSize;
	std::array<bool, 2> hit;
};

#endif // !UI_BASE_H

