#include"UIManager.h"

UIManager::UIManager()
{
}

void UIManager::Update(bool Isbool)
{
	if (PreviewUI != CurrentUI)
	{
		NextUI();
	}
	pUI->Update(Isbool);
}

void UIManager::Draw()
{
	pUI->Draw();
}

void UIManager::NextUI()
{
	switch (CurrentUI)
	{
	case Scene::title: pUI.reset(new TitleUI);
		break;
	case Scene::game:pUI.reset(new GameUI);
		break;
	case Scene::result:pUI.reset(new ResultUI);
		break;
	}
	PreviewUI = CurrentUI;
}