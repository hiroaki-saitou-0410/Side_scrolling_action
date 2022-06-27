#include "InputManager.h"
#include<Windows.h>
#include"DxLib.h"

InputManager::InputManager()
{
	keyStatus.fill(0);
	state.fill(KeyState::none);
	for (int i = 0; i < KEYMAX; i++)
	{
		keyStatus.at(i) = CheckHitKey(i);
	}
}

void InputManager::Update()
{
	for (std::size_t i = 0; i < keyStatus.size(); i++)
	{
		keyStatus.at(i) = CheckHitKey(i);

		if (keyStatus.at(i) == 1 && previewKeyStatus.at(i) == 0)
		{											
			state.at(i) = KeyState::push;
		}											
		else if (keyStatus.at(i) == 1 && previewKeyStatus.at(i) == 1)
		{											
			state.at(i) = KeyState::hold;
		}											
		else if (keyStatus.at(i) == 0 && previewKeyStatus.at(i) == 1)
		{
			state.at(i) = KeyState::release;
		}
		else
		{
			state.at(i) = KeyState::none;
		}

		previewKeyStatus.at(i) = keyStatus.at(i);
	}
}

bool InputManager::KeyPushed(const int& Key)
{	
	if (state.at(Key) == KeyState::push)
	{
		return true;
	}
	return false;
}

bool InputManager::KeyHold(const int& Key)
{
	if (state.at(Key) == KeyState::hold)
	{
		return true;
	}
	return false;
}

bool InputManager::KeyRelease(const int& Key)
{
	if (state.at(Key) == KeyState::release)
	{
		return true;
	}
	return false;
}
