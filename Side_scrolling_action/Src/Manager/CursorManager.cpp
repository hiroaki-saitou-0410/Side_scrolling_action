#include "CursorManager.h"

void CursorManager::Update()
{
	GetMousePoint(&cursor.x, &cursor.y);
}

bool CursorManager::Push(const int& mouseKey)
{
	if ((GetMouseInput() & mouseKey))
	{
		return true;
	}
	return false;
}
