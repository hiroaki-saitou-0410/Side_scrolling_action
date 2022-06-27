#ifndef CURSOR_MANAGER_H
#define CURSOR_MANAGER_H

#include<iostream>
#include<array>
#include"DxLib.h"
#include"../Singleton.h"
#include"../Vector2.h"

class CursorManager: public Singleton<CursorManager>
{
public:
	CursorManager(){}
	virtual ~CursorManager() {}

	void Update();

	Vector2 GetMousePos() { return cursor; }
	bool Push(const int& mouseKey);

private:
	Vector2 cursor;
	
};

#endif // !CURSOR_MANAGER_H

