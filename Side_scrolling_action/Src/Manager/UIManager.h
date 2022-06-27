#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include"../Definition.h"
#include"../Singleton.h"
#include"../UI/UIBase.h"
#include"../UI/TitleUI.h"
#include"../UI/GameUI.h"
#include"../UI/ResultUI.h"

class UIManager :public Singleton<UIManager>
{
public:
	UIManager();
	virtual ~UIManager() = default;

	virtual void Update(bool Isbool);
	void Draw();

	void NextUI();
	void SetNextUI(const Scene& scene) { CurrentUI = scene; }

private:
	std::unique_ptr<UIBase>pUI;
	Scene PreviewUI;
	Scene CurrentUI;
};

#endif // !UI_MANAGER_H

