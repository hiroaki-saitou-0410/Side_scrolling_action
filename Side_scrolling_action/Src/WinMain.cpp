
#include"DxLib.h"
#include"Manager/InputManager.h"
#include"Manager/SceneManager.h"
#include"Manager/CursorManager.h"
#include"Manager/TextureManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int hCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(WindowSizeX, WindowSizeY, 32);
	SetMainWindowText("横スクシューティング");
	SetBackgroundColor(0, 200, 200);
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);

	//SetFontSize(37);

	auto sceneManager = SceneManager::Instance();
	auto inputManager = InputManager::Instance();
	auto cursorManager = CursorManager::Instance();
	auto textureManager = TextureManager::Instance();

	while (true)
	{
		if (ProcessMessage() == -1)break;
		if (inputManager.lock()->KeyPushed(KEY_INPUT_ESCAPE))break;
		if (sceneManager.lock()->Exit())break;
		ClearDrawScreen();
		clsDx();

		cursorManager.lock()->Update();

		inputManager.lock()->Update();
		
		sceneManager.lock()->Update();
		
		sceneManager.lock()->Draw();

		ScreenFlip();
	}
	textureManager.lock()->ReleaseTexture();
	DxLib_End();
	return 0;
}
