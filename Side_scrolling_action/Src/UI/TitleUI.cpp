#include"TitleUI.h"

TitleUI::TitleUI()
{
	boxPos.at(0).vec2(WindowSizeX/2,400);
	boxPos.at(1).vec2(WindowSizeX /2,450);
	for (int i = 0; i < 2; i++)
	{
		boxSize.at(i).vec2(270, 40);
		centralPos.at(i).vec2(boxSize.at(i).x / 2, boxSize.at(i).y / 2);
	}
}

void TitleUI::Update(bool Isbool)
{
	cursorPos = CursorManager::Instance().lock()->GetMousePos();
	for (int i = 0; i < 2; i++)
	{
		if (CursorHit(boxPos.at(i), centralPos.at(i), cursorPos)) {
			hit.at(i) = true;
			if (cursorManager.lock()->Push(MOUSE_INPUT_LEFT))
			{
				if (i == 0)
				{
					SceneManager::Instance().lock()->SetNextScene(Scene::game);
					hit.at(i) = false;
				}
				else if(i==1)
				{
					exit = true;
				}
			}
		}
		else
		{
			hit.at(i) = false;
		}
	}
}

void TitleUI::Draw()
{
	DrawButton(0, "ゲームスタート");
	DrawButton(1, "終了");
}
