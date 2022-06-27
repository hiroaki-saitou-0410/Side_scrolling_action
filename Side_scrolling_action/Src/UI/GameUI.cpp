#include "GameUI.h"

GameUI::GameUI()
{
	boxPos.at(0).vec2(300, 300);
	boxPos.at(1).vec2(700, 300);
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		boxSize.at(i).vec2(220, 40);
		centralPos.at(i).vec2(boxSize.at(i).x / 2, boxSize.at(i).y / 2);
	}
}

void GameUI::Update(bool Isbool)
{
	pause = Isbool;
	if (Isbool)
	{
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			cursorPos = CursorManager::Instance().lock()->GetMousePos();
			if (CursorHit(boxPos.at(i), centralPos.at(i), cursorPos)) {
				hit.at(i) = true;
				if (cursorManager.lock()->Push(MOUSE_INPUT_LEFT))
				{
					if (i == 0)
					{
						SceneManager::Instance().lock()->SetNextScene(Scene::title);
						hit.at(i) = false;
					}
					else if (i == 1)
					{
						
					}
				}
			}
			else
			{
				hit.at(i) = false;
			}
		}
		
	}
}

void GameUI::Draw()
{
	if (pause)
	{
		SetDrawBright(180, 180, 180);
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			DrawButton(0,"タイトルに戻る");
			DrawButton(1,"リセット");

			if (cursorManager.lock()->Push(MOUSE_INPUT_LEFT) && CursorHit(boxPos.at(i), centralPos.at(i), cursorPos))
			{
				SetDrawBright(255, 255, 255);
			}
		}
	}
	else
	{
		SetDrawBright(255, 255, 255);
	}
}
