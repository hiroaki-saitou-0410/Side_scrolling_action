#include "ResultUI.h"

ResultUI::ResultUI()
{
	boxPos.vec2(300, 300);
	boxSize.vec2(100, 40);
	centralPos.vec2(boxSize.x / 2, boxSize.y / 2);
}

void ResultUI::Update(bool Isbool)
{
	cursorPos = CursorManager::Instance().lock()->GetMousePos();
	if (CursorHit(boxPos, centralPos, cursorPos)) {
		hit = true;
		if (cursorManager.lock()->Push(MOUSE_INPUT_LEFT))
		{
			SceneManager::Instance().lock()->SetNextScene(Scene::title);
		}
	}
	else
	{
		hit = false;
	}
}

void ResultUI::Draw()
{
	if (!hit)
	{
		DrawBox(boxPos.x - centralPos.x, boxPos.y - centralPos.y, boxPos.x + centralPos.x, boxPos.y + centralPos.y, GetColor(255,255,255), FALSE);
	}
	else {
		DrawBox(boxPos.x - centralPos.x, boxPos.y - centralPos.y, boxPos.x + centralPos.x, boxPos.y + centralPos.y, GetColor(0, 0, 0), TRUE);
	}
}
