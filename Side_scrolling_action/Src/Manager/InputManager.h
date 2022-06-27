#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include<iostream>
#include<array>
#include"../Singleton.h"
#include"../Definition.h"

class InputManager:public Singleton <InputManager>
{
public:
	InputManager();
	virtual ~InputManager() {}

	void Update();
	
	bool KeyPushed(const int& Key);
	bool KeyHold(const int& Key);
	bool KeyRelease(const int& Key);
	
private:
	static const int KEYMAX = 256;
	std::array<bool, KEYMAX>keyStatus{};
	std::array<bool, KEYMAX>previewKeyStatus{};
	std::array<KeyState, KEYMAX>state;
};

#endif // !INPUT_MANAGER_H

